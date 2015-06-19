// Check for mobile devices function
function check_if_mobile() {
  var isMobile = {
    Android: function() {
      return navigator.userAgent.match(/Android/i);
    },
    BlackBerry: function() {
      return navigator.userAgent.match(/BlackBerry/i);
    },
    iOS: function() {
      return navigator.userAgent.match(/iPhone|iPad|iPod/i);
    },
    Opera: function() {
     return navigator.userAgent.match(/Opera Mini/i);
    },
    Windows: function() {
      return navigator.userAgent.match(/IEMobile/i);
    },
    Symbian: function() {
      return navigator.userAgent.match(/Symbian/i);
    },
    webOS: function() {
      return navigator.userAgent.match(/webOS/i);
    },
    any: function() {
      return (isMobile.Android()
        || isMobile.BlackBerry()
        || isMobile.iOS()
        || isMobile.Opera()
        || isMobile.Windows()
        || isMobile.Symbian()
        || isMobile.webOS()
        || (window.innerWidth < 640)
      );
    }
  };

  if (isMobile.any()) {
    return navigator.userAgent;
  }
}

(function($,sr){
  /**
   * Debounce function. Helps us time resize event.
   *
   * http://unscriptable.com/index.php/2009/03/20/debouncing-javascript-methods/
   */
  var debounce = function (func, threshold, execAsap) {
    var timeout;

    return function debounced () {
      var obj = this, args = arguments;
      function delayed () {
        if (!execAsap)
          func.apply(obj, args);
        timeout = null;
      };

      if (timeout)
        clearTimeout(timeout);
      else if (execAsap)
        func.apply(obj, args);

      timeout = setTimeout(delayed, threshold || 100);
    };
  }

  // Smartresize
  jQuery.fn[sr] = function(fn) { return fn ? this.bind('resize', debounce(fn)) : this.trigger(sr); };

})(jQuery,'smartresize');

(function ($) {
  $(document).ready(function(){
    // Alter panels_ajax_tabs return callback function on ajax tab loading
    // with adding custom js for user image flip on hover event.
    Drupal.behaviors.panels_ajax_tabs = {
      attach: function(context) {
        $('.panels-ajax-tab-tab:not(.panels-ajax-tabs-processed)', context).once('panels-ajax-tabs-once', function() {
          // We need to push the state when the page first loads
          // so we know which tab is the first one loaded.
          if ($(this).parent().hasClass('active') && $(this).data('url-enabled') == 1) {
            if (typeof window.history.pushState != 'undefined') {
              window.history.replaceState({'tab':$(this).data('panel-name')}, $(this).html(), $(this).attr('href'));
            }
          }

          $(this).click(function(e) {
            e.preventDefault();
            // Push the history.
            if (typeof window.history.pushState != 'undefined' && $(this).data('url-enabled') == 1) {
              window.history.pushState({'tab':$(this).data('panel-name')}, $(this).html(), $(this).attr('href'));
            }

            if (!$(this).parent().hasClass('active')) {
              $(this).panels_ajax_tabs_trigger();
            }
          })
          .css('cursor', 'pointer')
          .addClass('panels-ajax-tabs-processed');

          // Trigger a click event on the first tab to load it.
          $('.pane-panels-ajax-tab-tabs', context).each(function() {
            var tabs = $('.panels-ajax-tab-tab:not(.panels-ajax-tabs-first-loaded)', this);
            var firstTab = tabs.first();
            var target_id = firstTab.data('target-id');
            var preloaded = $('#panels-ajax-tab-container-' + target_id).data('panels-ajax-tab-preloaded');
            var currentTab;

            if (preloaded === '') {
              currentTab = firstTab;
              firstTab.trigger('click');
            }
            else {
              currentTab = tabs.filter('*[data-panel-name="' + preloaded + '"]');
              // Prime the cache from the preloaded content.
              currentTab.data('panels-ajax-tab-cache', $('#panels-ajax-tab-container-' + target_id).html());
            }
            currentTab.addClass('panels-ajax-tabs-first-loaded');
            currentTab.parent().addClass('active');
          });
        });

        /**
         * @author Anders Hal
         *
         * Flips profile pictures.
         */
        $('img[data-hover]').hover(function() {
            $(this).attr('tmp', $(this).attr('src')).attr('src', $(this).attr('data-hover')).attr('data-hover', $(this).attr('tmp')).removeAttr('tmp');
        }).each(function() {
            $('<img />').attr('src', $(this).attr('data-hover'));
        });
      }
    }

    // Show newsletter pop-up if site was opened not on a mobile device.
    if (!check_if_mobile()) {
      jQuery('#pco_slidebox').show();
    }

    // Init modal
    $('a[rel*=modal]').drupmodal();

    /**
     * @author Anders Hal
     *
     * Flips profile pictures
     */
    $('img[data-hover]').hover(function() {
        $(this).attr('tmp', $(this).attr('src')).attr('src', $(this).attr('data-hover')).attr('data-hover', $(this).attr('tmp')).removeAttr('tmp');
    }).each(function() {
        $('<img />').attr('src', $(this).attr('data-hover'));
    });

    // Set current viewport
    var w = $(document).width();
    var nav = $('div[role="navigation"] nav');
    var menu = $('div[role="navigation"] nav').find('ul');

    function navhead(width) {
      if (width < 480) {
        // Set click event on menu header
        $('div[role="navigation"] nav h2').click(function(){
          var target = $(this).parent();

          !target.hasClass('active') ? nav.addClass('active') : nav.removeClass('active');
        });

        nav.addClass('nav-processed');
      }
    }

    /**
     * @author Kalms
     *
     * Creates select elements to replace lists
     */
    function selectlists() {
      $('div.view-display-id-vocabulary_departments, div.view-display-id-employees_az').each(function() {

        // Set document width
        w = $(document).width();

        // Locate and set lists
        var list = $(this).find('.item-list');

        // Locate and set list elements
        var el = $(this).find('.item-list li');

        if (w < 770 && !$(this).hasClass('selectlist-processed')) {
          // Remove origin ul/ol
          list.hide();

          // Append select element
          var select = $(this).find('.view-content').append('<select />');

          // Build options
          el.each(function(){
            var target = $(this).find('a').attr('href');
            var txt = $(this).find('a').text();

            $('<option value="' + target + '" />').appendTo(select.find('select')).append(txt);
          });

          $(select.find('select')).change(function() {
            window.location.href = $(this).val();
          });

          // Set state
          $(this).addClass('selectlist-processed');

        }

        if (w > 770 && $(this).hasClass('selectlist-processed')) {
          var select = $(this).find('select');

          // Kill select
          select.remove();

          // Show lists
          list.show();

          // Remove state
          $(this).removeClass('selectlist-processed')
        }

      });
    }

    // Init navhead()
    navhead(w);

    // Init selectlists()
    selectlists();

    /**
     * Execute functions based on window width.
     *
     * @see debounce()
     */
    $(window).smartresize(function() {
      w = $(document).width();

      // Init navhead
      if (!nav.hasClass('nav-processed')) { navhead(w); }

      // Init selectlists()
      selectlists();
    });
  });

})(jQuery);
