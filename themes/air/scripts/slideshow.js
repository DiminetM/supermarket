/**
 * @file slideshow.js
 *
 * Adds slideshow functionality
 */
(function($){
	Drupal.behaviors.slideshow = {
	 attach: function (context) {
 		// Parse every related divs
 		$('div.view-slideshow-frontpage', context).once(function () {
  		// Set optional behavior
  		var options = {
  			interval: 5000,
  			duration: 500,
  			lineheight: 1,
  			height: 'auto',
  			hoverpause: true,
  			pager: true,
  			nav: true
  		};
  
  		return $(this).each(function() {
  		
  			var obj = $(this);
  
  			// Store pager and slide li
  			var slides = $('.item-list li', obj);
  			var pager = $('#slide-progress li', obj);
  
  			// Set initial current and next slide index values
  			var current = 0;
  			
  			var next = current+1;
  			// Shaky
  			var el = slides.eq(current);
  			var prev = current == 0 ? slides.length-1 : current-1;
  
  			// Hide all slides, fade in the first, add active class to first slide
  			slides.hide().eq(current).fadeIn(options.duration).addClass('active');
  			
  			// Build pager
  			if (pager.length) {
  				pager.eq(current).addClass('active');
  			} else if (options.pager) {
  				obj.append('<ul id="slide-progress"></ul>');
  				slides.each(function(index) {
  					$('#slide-progress', obj).append('<li><a href="#"><span>' + index + '</span></a></li>');
  				});
  				pager = $('#slide-progress li', obj);
  				pager.eq(current).addClass('active');
  			}
  			
  			// Build nav
  			if (options.nav) {
  			  // Append navigation
  			  obj.append('<ul id="slide-nav"><li class="next"><a href=""></a></li><li class="prev"><a href=""></a></li></ul>');
  			  
  			  // Store the nav li
  			  var nav = $('#slide-nav li');

  			  $('a', nav).click(function(){
  			    // Stop the timer
  			    clearTimeout(obj.play);
  			    
            $(this).parent().hasClass('next') ? rotate(next) : rotate(prev);
            
  			    return false;
  			  });
  			}
  
  			// Rotate to selected slide on pager click
  			if (pager) {
  				$('a', pager).click(function() {
  					// Stop the timer
  					clearTimeout(obj.play);
  					
  					// Set the slide index based on pager index
  					next = $(this).parent().index();
  					
  					// Get current position
  					position = $(this).parent().prevAll().length;
  					
  					// Rotate slides
  					rotate(position);
  					
  					return false;
  				});
  			}
  
  			// Rotate slides
  			var rotate = function(pos) {
  			  // Stop the timer
  			  clearTimeout(obj.play);
  			  
  				slides.eq(current).fadeOut(options.duration).removeClass('active')
  					.end().eq(pos).fadeIn(options.duration).addClass('active').queue(function(){
  						// Add rotateTimer function to end of animation queue
  						// This prevents animation buildup caused by requestAnimationFrame
  						// rotateTimer starts a timer for the next rotate
  						rotateTimer();
  						
  						$(this).dequeue()
  				});
  
  				// Update pager to reflect slide change
  				if (pager) {
  					pager.eq(current).removeClass('active').end().eq(pos).addClass('active');
  				}
  
  				// Update current, next and prev vars
  				current = pos;
  				next = current >= slides.length-1 ? 0 : current+1;
  				prev = current == 0 ? slides.length-1 : current-1;
  			};
  			
  			// Create a timer to control slide rotation interval
  			var rotateTimer = function(){
  				obj.play = setTimeout(function(){
  					// Trigger slide rotate function at end of timer
  					rotate(next);
  				}, options.interval);
  			};
  			
  			// Start the timer for the first time
  			rotateTimer();

        // Pause slideshow on hover
  			if (options.hoverpause) {
  				slides.hover(function(){
  					clearTimeout(obj.play);
  				}, function(){
  					rotateTimer();
  				});
  			}
  			
  		});
 		});
	 }
	}		
	
	/**
	 * Small slider
	 */
	Drupal.behaviors.slide = {
	 attach: function (context) {
 		// Parse every related divs
 		$('div.image.slideshow', context).once(function () {
  		// Set optional behavior
  		var options = {
  			duration: 500,
  			lineheight: 1,
  			pager: true
  		};
  
  		return $(this).each(function() {
  		
  			var obj = $(this);
  
  			// Store pager and slide li
  			var slides = $('.item-list li', obj);
  			var pager = $('#slide-thumbs figure', obj);
  
  			// Set initial current and next slide index values
  			var current = 0;
  			
  			var next = current+1;
  			// Shaky
  			var el = slides.eq(current);
  			var prev = current == 0 ? slides.length-1 : current-1;
  			
  			var setHeight = function(pos) {
  			  var height = slides.eq(pos).find('img').height();
					slides.eq(pos).parents('div.image.slideshow').find('.item-list').height(height);
  			}
  			
  			// Set state
  			obj.addClass('slide-processed');
  
  			// Hide all slides, fade in the first, add active class to first slide
  			slides.hide().eq(current).fadeIn(options.duration, function(){
  			  setHeight(current);
  			}).addClass('active');
  			// Build pager
  			if (pager.length) {
  				pager.eq(current).addClass('active');
  			} else if (options.pager) {
  				obj.append('<div id="slide-thumbs" class="thumbs"></div>');
  				slides.each(function(index) {
  				  var str = $(this).find('img').attr('src');
  				  // This regex could be made more "intelligent"
  				  // i.e check for "styles/<target>/public" instead.
  				  var src = str.replace(/\bstyles\W+(?:\w+\W+){1,6}?public\b/i, "styles/73x43/public");
  				  
  					$('#slide-thumbs', obj).append('<div class="item"><a href="#"><img src="' + src + '" alt="" /></a></div>');
  				});
  				pager = $('#slide-thumbs div.item', obj);
  				
  				pager.eq(current).addClass('active');
  			}
        
  			// Rotate to selected slide on pager click
  			if (pager) {
  				$('a', pager).click(function() {	
  					// Set the slide index based on pager index
  					next = $(this).parent().index();
  					
  					// Get current position
  					position = $(this).parent().prevAll().length;
  					
  					// Rotate slides
  					rotate(position);
  					
  					return false;
  				});
  			}
  
  			// Rotate slides
  			var rotate = function(pos) {  			  
  				slides.eq(current).fadeOut(options.duration, function(){
  				  // Set container height
  				  // setHeight(pos);  				  
  				}).removeClass('active')
  					.end().eq(pos).fadeIn(options.duration, function(){
  					  setHeight(pos);
  					}).addClass('active').queue(function(){  						  						
  						$(this).dequeue()
  				});
  
  				// Update pager to reflect slide change
  				if (pager) {
  					pager.eq(current).removeClass('active').end().eq(pos).addClass('active');
  				}
  
  				// Update current, next and prev vars
  				current = pos;
  				next = current >= slides.length-1 ? 0 : current+1;
  				prev = current == 0 ? slides.length-1 : current-1;
  			};
  			
  			/**
  			 * Check on window resize event.
  			 *
  			 * @see base.js
  			 */
  			$(window).smartresize(function() {
  			  // Set container height
          setHeight(current);
        });
  			
  		});
 		});
	 }
	}
}(jQuery));
