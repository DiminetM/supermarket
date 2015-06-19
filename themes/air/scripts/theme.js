(function ($) {
  $( document ).ready(function() {

    // Get link text from a tag
    var btnTxt = $('.pane-node-field-related-webform h2 a').text();
    // Then removw link
    $('.pane-node-field-related-webform h2 a');

    // Then clone h2 and add link text to h2
    var h2Cloned = $('.pane-node-field-related-webform h2').text(btnTxt).clone().addClass('cloned'),
    defaultText = $('.pane-node-field-related-webform h2').text();

    $('.pane-node-field-related-webform').prepend(h2Cloned);

    $('.pane-node-field-related-webform article.node-webform').hide();

    $('h2.cloned').click( function(){
      $('.pane-node-field-related-webform article.node-webform').toggle();

      if($('.pane-node-field-related-webform article.node-webform').is(':visible')){
        $(this).text('X');
      } else {
        $(this).text(defaultText);
      }

      $(this).toggleClass('active');
    });
  });
})(jQuery);


//$('.video-filter').wrap('<div class="video-container" />');
(function ($) {

  Drupal.behaviors.exampleModule = {
    attach: function (context, settings) {
      // Din seje kode her
      $('.video-filter').wrap('<div class="video-container" />');
   }
  };

//  Drupal.behaviors.RelatedForm = {
//    attach: function (context, settings) {
//
//    // Get link text from a tag
//    var btnTxt = $('.pane-node-field-related-webform h2 a').text();
//    // Then removw link
//    $('.pane-node-field-related-webform h2 a');
//
//    // Then clone h2 and add link text to h2
//    var h2Cloned = $('.pane-node-field-related-webform h2').text(btnTxt).clone().addClass('cloned'),
//    defaultText = $('.pane-node-field-related-webform h2').text();
//
//    $('.pane-node-field-related-webform').prepend(h2Cloned);
//
//    $('.pane-node-field-related-webform article.node-webform').hide();
//
//    $('h2.cloned').click( function(){
//      $('.pane-node-field-related-webform article.node-webform').toggle();
//
//      if($('.pane-node-field-related-webform article.node-webform').is(':visible')){
//        $(this).text('X');
//      } else {
//        $(this).text(defaultText);
//      }
//
//       $(this).toggleClass('active');
//      });
//    }
//  };

  Drupal.behaviors.peytzTrackEvent = {
    attach: function (context) {
      if (typeof _gaq != 'undefined') {
        $('#webform-client-form-306', context).submit(function() {
          _gaq.push(['_trackEvent', 'Tilmeld', 'Klik', 'Morgeninspiration', , false]);
        });
        $('form').each(function() {
          var id = this.id.toString();
          if (id.indexOf("webform-client-form-127") != -1) {
            $('#' + this.id, context).submit(function() {
              _gaq.push(['_trackEvent', 'Tilmeld', 'Klik', 'Nyhedsbrev', , false]);
            });
          }
        });
      }
    }
  };

  Drupal.behaviors.Morninginspiration = {
    attach: function (context, settings) {

      $('.view-morgeninspiration .gray').attr('data-cta-msg', Drupal.t('Arrangement er afholdt'));

      var handler = $('.view-morgeninspiration .views-row');

      handler.wookmark({
          // Prepare layout options.
          autoResize: true, // This will auto-update the layout when the browser window is resized.
          align: 'left',
          container: $('.view-morgeninspiration'), // Optional, used for some extra CSS styling
          offset: 30, // Optional, the distance between grid items
          outerOffset: 0, // Optional, the distance to the containers border
          itemWidth: 299, // Optional, the width of a grid item
      });
     }
   };


  Drupal.behaviors.employeeDescription = {
    attach: function (context) {
      if($.trim($('.link-to-description').html()).length) {
        $('.prose').css('display', 'none');
      }
      $('.link-to-description a').click(function() {
        $('.link-to-description').css('display', 'none');
        $('.prose').css('display', 'block');
      });
    }
  };

  Drupal.behaviors.Morninginspiration = {
    attach: function (context, settings) {

      $('.view-morgeninspiration .gray').attr('data-cta-msg', Drupal.t('Arrangement er afholdt'));

      var handler = $('.view-morgeninspiration .views-row');

      handler.wookmark({
          // Prepare layout options.
          autoResize: true, // This will auto-update the layout when the browser window is resized.
          align: 'left',
          container: $('.view-morgeninspiration'), // Optional, used for some extra CSS styling
          offset: 30, // Optional, the distance between grid items
          outerOffset: 0, // Optional, the distance to the containers border
          itemWidth: 299, // Optional, the width of a grid item
      });
     }
   };

})(jQuery);
