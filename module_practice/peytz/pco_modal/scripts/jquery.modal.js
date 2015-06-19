/**
 * Modal jQuery plugin
 * ------------------------
 * A simple modal plug-in optimized for Drupal.
 *
 * 2011 Peytz & Co.
 */

(function($){
	$.fn.drupmodal = function(options) {
	
			var settings = {
			  'key'				: '',
			  'feed'			: ''
			};
			
			// If options exist, lets merge them
			// with any default settings
			var opt = $.extend(settings, options);
	
			var xhr;
	
			/** 
			 * Create necessary markup scaffold.
			 */
			var bg = $('<div id="modal-overlay" />').hide(); //.appendTo(modal);
			var modal = $('<div id="modal-window" />').appendTo(bg);
			var inner = $('<div id="modal-inner" />').appendTo(modal);
			var header = $('<div class="header" />').appendTo(inner);
			var heading = $('<div class="title" />').appendTo(header);
			var close = $('<a href="" class="close" />').text(Drupal.t('Close')).appendTo(header);
			var container = $('<div class="modal-content" />').appendTo(inner);

			// Show loading message
			var loading = $('<div class="loading" />').text(Drupal.t('Fetching content, please wait...'));			
						
			// Reposition modal window
			var modalReposition = function() {	
				modal.css('top', Math.max(Math.round(($(window).height() - modal.outerHeight()) / 2), 0)).css('left', Math.round(($(window).width() - modal.outerWidth()) / 2));
			};
		
			// Display content in modal window
			var modalDisplay = function(content) {
				// Reset main
				container.empty();

				// Append content to modal
				if (content) content.appendTo(container);
					
				// Attach placeholder behavior
				Drupal.attachBehaviors();
					
				// Reposition
				modalReposition();
			};
			
			var modalLoad = function(href) {
				// Check href and assign appropriate action
				if (href.match(/^\//)) {
					modalAjax(href);
				} 
				// /[-+]?[0-9]*\.?[0-9]*/
				else if (href.match('^\http:\//maps.google.com')) {
					modalGeo(href);
				} 
				else {
					modalExternal(href);
				} 
			}
			
			// Display Google Map in a modal window
			var modalGeo = function(href) {				
			
				// Locate latlng in string
				var geo = href.substring(60);
			
				// Reset main
				container.empty();
				
				// Append map wrapper
				var mapDiv = $('<div id="map" />').appendTo(container);
				
				$('div#modal-window').addClass('geo');
				
				modalReposition();
				
				var position = geo.split(',');
				
				// Initialize Google Map
				window.init = function() {
					var mainLatlng = new google.maps.LatLng(position[0], position[1]);
				  var myOptions = {
				    zoom: 14,
				    center: mainLatlng,
				    mapTypeId: google.maps.MapTypeId.ROADMAP
				  }
				  var map = new google.maps.Map(document.getElementById('map'), myOptions);
				  
				  overlay = new google.maps.OverlayView();
		      overlay.draw = function() {};
		      overlay.setMap(map);
				  
				  setMarkers(map);
				}
       
				function setMarkers(map) {
					var url = opt.feed;
					var title = heading.text();
					var loading = heading.text('Loading...');
					
					// Get XML file and parse it.
					$.get(url, function(xml){
						$(xml).find("node").each(function(i){
						  // Create variables for common fields
						  // Add or change these to create your own
							var name = $(this).find('navn').text();
							var street = $(this).find('street').text();
							var city = $(this).find('city').text();
							var zip = $(this).find('zip').text();
							var link = $(this).find('link').text();
							var term = $(this).find('term').text();
							
							// create a new LatLng point for the marker
							var lat = $(this).find('lat').text();
							var lng = $(this).find('lng').text();
							var point = new google.maps.LatLng(parseFloat(lat),parseFloat(lng));	
							
							// Activate custom info bubble
							google.maps.event.addListener(marker, 'click', function(){
							  displayPoint(point, marker, i);				
							});
							
							google.maps.event.addListener(map, 'zoom_changed', function(){
							  $('#message').remove();
							});

							// Reapply header title when load is done														
							heading.text(title);
						
							function displayPoint(point, marker, i) {
								$('#message').remove();
								
								var divPixel = overlay.getProjection().fromLatLngToDivPixel(point); 
								var target = overlay.getPanes().floatPane;
								
								if (name == Drupal.settings.title) {
									var facts = '<strong>' + name + '</strong>' + '<p>' + street + '<br />' + zip + ' ' + city + '</p>';
								} else {
									var facts = '<strong>' + name + '</strong>' + '<p>' + street + '<br />' + zip + ' ' + city + '</p>' + link;
								}
																			
								$('<div id="message" />').html(facts).appendTo(target).css({ top: Math.round(divPixel.y - 12), left: divPixel.x });
								
								map.panTo(point);								
							}
						});
						
					});
				}
				
				// Load Google Maps API
				$.getScript('http://maps.google.com/maps/api/js?sensor=false&callback=init&key=' + opt.key);
			}
			
			// Load AJAX
			var modalAjax = function(href) {
        modalDisplay(loading);
								 
				$('div#modal-window').addClass('ajax');
				
				// Abort any active HTTP request
				if (xhr) xhr.abort();
		
				// Make XML HTTP request
				xhr = $.ajax({
					url: '/modal' + href, // Run through modal handler
					error: function() {
						// Display error
						modalError('The content could not be loaded.');
					},
					success: function(data) {					  
						// Display messages and HTML		
						modalDisplay($(data).find('> div.messages, > div.content form').submit(modalSubmit).end());
					}
				});
			};
			
			// Submit form
			var modalSubmit = function() {
			
				// Create reference to submitted form
				var form = $(this);
				
				// Leave non-modal forms be
				if (!form.attr('action').match(/^\/modal\//)) return;
				
				// Abort any active HTTP request
				if (xhr) xhr.abort();
		
				// Make XML HTTP request
				xhr = $.ajax({
					url:      form.attr('action'),
					type:     'POST',
					data :    form.serialize(),
					error:    function() {
						// Display error
						modalError('The content could not be loaded.');
					},
					success: function(data) {
						// Display messages and HTML
						modalDisplay($(data).find('> div.messages, > div.content form').submit(modalSubmit()).end());
					}
				});
		
				return false;
			};
			
			// Load external content
			var modalExternal = function(href) {
				$('div#modal-window').addClass('ext');
			
				modalDisplay($('<div class="external" />').append($('<iframe />').attr('src', href)));
			};
			
			// Display error message in modal window
			var modalError = function(error) {
				modalDisplay($('<div class="error" />').text(Drupal.t(error)));
			};
			
			// Start loop
			return this.each(function() {				
				//Listen for clicks on objects passed to the plugin
        $(this).click(function(e) {
        
          // Check if we're on an iPhone or Android capable mobile device
          if (navigator.userAgent.match(/iPhone/i) || navigator.userAgent.match(/iPod/i) || navigator.userAgent.match(/Android/i)) return;
       
          //Append the dark background to the document body
					$('body').append(bg);
					          
					// Transfer title to modal window					
					heading.text($(this).attr('title'));

          var modalClass = $(this).attr('rel').replace(/([^\]]*)\[([^\]]+)\]/g, function() { 
            return arguments[2];
          });          
          
          //Add unique class for each node
          $('div#modal-window').addClass(modalClass);
            
					bg.fadeIn();

					modal.show();
					
					//Prevent the anchor link from loading
					e.preventDefault();
					
					//Activate a listener 
					$(document).keydown(handleEscape);	
					
					close.click(modalHide);
					
					modalLoad($(this).attr('href'));
				});
			});
		
		  //Our function for hiding the modalbox
			function modalHide() {
				$(document).unbind("keydown", handleEscape);
				
				$('div#modal-window').removeClass();
				
				var remove = function() { $(this).remove(); };
				bg.fadeOut(remove);
				modal.hide();
				
				modalReposition();
					
				// Abort any active HTTP request
				if (xhr) xhr.abort();
					
				return false;
			}
			
			//Our function that listens for escape key.
			function handleEscape(e) {
				if (e.keyCode == 27) {
					modalHide();
				}
			}
			
		};
})(jQuery);