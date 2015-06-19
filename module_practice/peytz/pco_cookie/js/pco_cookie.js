(function ($) {
  Drupal.behaviors.pco_cookie = {
    attach: function(context, settings) {
      $('body').not('.sliding-popup-processed').addClass('sliding-popup-processed').each(function() {
        try {
          if (!Drupal.pco_cookie.cookiesEnabled()) {
            return;
          }
          var status = Drupal.pco_cookie.getCurrentStatus();
          if (status == 0) {
            Drupal.pco_cookie.createPopup(Drupal.settings.pco_cookie.popup_html_info);
          } else {
            return;
          }
        }
        catch(e) {
          return;
        }
      });
    }
  }

  Drupal.pco_cookie = {};

  Drupal.pco_cookie.createPopup = function(html) {
    var popup = $(html)
      .attr({"id": "sliding-popup"})
      .height(Drupal.settings.pco_cookie.popup_height)
      .width(Drupal.settings.pco_cookie.popup_width)
      .hide();

    popup.prependTo("body");
    var height = popup.height();
    popup.show()
      .attr({"class": "sliding-popup-top"})
      .css({"top": -1 * height})
      .animate({top: 0}, Drupal.settings.pco_cookie.popup_delay);

    Drupal.pco_cookie.attachEvents();
  }

  Drupal.pco_cookie.attachEvents = function() {
    $('.agree-button').click(function(){
      var next_status = 1;
      Drupal.pco_cookie.setStatus(next_status);
      Drupal.pco_cookie.changeStatus(next_status);
    });
  }

  Drupal.pco_cookie.getCurrentStatus = function() {
    var search = 'cookie-agreed=';
    var offset = document.cookie.indexOf(search);
    if (offset < 0) {
      return 0;
    }
    offset += search.length;
    var end = document.cookie.indexOf(';', offset);
    if (end == -1) {
      end = document.cookie.length;
    }
    var value = document.cookie.substring(offset, end);
    return parseInt(value);
  }

  Drupal.pco_cookie.changeStatus = function(value) {
    var status = Drupal.pco_cookie.getCurrentStatus();
    if(status == 0) {
      return;
    }
    if(status == 1) {
      $(".sliding-popup-top").slideUp(Drupal.settings.pco_cookie.popup_delay, function () {
        $("#sliding-popup").remove();
      });
    }
  }

  Drupal.pco_cookie.setStatus = function(status) {
    var date = new Date();
    // Set cookie for 90 days.
    date.setDate(date.getDate() + 90);
    document.cookie = "cookie-agreed" + "="+status+";expires=" + date.toUTCString() + ";path=" + Drupal.settings.basePath;
  }

  Drupal.pco_cookie.cookiesEnabled = function() {
    var cookieEnabled = (navigator.cookieEnabled) ? true : false;
      if (typeof navigator.cookieEnabled == "undefined" && !cookieEnabled) {
        document.cookie="testcookie";
        cookieEnabled = (document.cookie.indexOf("testcookie") != -1) ? true : false;
      }
    return (cookieEnabled);
  }

})(jQuery);