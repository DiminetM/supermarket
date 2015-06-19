;(function ($) {
  Drupal.behaviors.pcoSlidebox = {
    attach: function(context, settings) {
      if (settings.pcoSlidebox) {
        // Check for exising slidebox cookie
        if ($.cookie('pco_slidebox') == null) {
          // Set to default of 'open' if not previously set
          $.cookie('pco_slidebox', 'open', { path: '/' });
        }

        $('#slidebox_cookie').hide();

        $(window).scroll(function() {
          var distanceTop = ($('footer').offset().top) * 0.4;
          if  ($(window).scrollTop() >= distanceTop) {
            if ($.cookie('pco_slidebox') == 'open') {
              $('#pco_slidebox').animate({'right':'0px'}, settings.pcoSlidebox.showTime);
              $('#pco_slidebox_manual').hide();
              $('#pco_slidebox_cookie').hide();
            }
          }
          else {
            $('#pco_slidebox').stop(true).animate({'right': '-' + ($('#pco_slidebox').width() + 30) + 'px'}, settings.pcoSlidebox.hideTime);
            $('#pco_slidebox_manual').show();
            $('#pco_slidebox_cookie').hide();
          }
        });

        $('#pco_slidebox .close').click(function(){
          $('#pco_slidebox').stop(true).animate({'right': '-' + ($('#pco_slidebox').width() + 30) + 'px'}, settings.pcoSlidebox.hideTime);
          $('#pco_slidebox_manual').show();
          $(window).unbind();
          if ($.cookie('pco_slidebox') != 'closed') {
            $('#pco_slidebox_cookie').show();
          }
        });

        $('#pco_slidebox_manual .open').click(function() {
          $('#pco_slidebox').animate({'right':'0px'}, settings.pcoSlidebox.showTime);
          $('#pco_slidebox_manual').hide();
          $('#pco_slidebox_cookie').hide();
        });

        // Offer the user the ability to set the Slidebox to be persistently closed
        $('#pco_slidebox_cookie .set').click(function() {
          $.cookie('pco_slidebox', 'closed', { path: '/' });
          $('#pco_slidebox_cookie').hide();
        });
      }
    }
  };
})(jQuery);

