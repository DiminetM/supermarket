/**
 * @file
 * Js code for the Filtering Price for Catalog page.
 */
(function($) {
  Drupal.behaviors.tm_utility = {
    attach: function(context, settings) {
      $('.slider-widget-wrapper', context).each(function() {
        var $slider_wrapper = $(this);
        var $min_input = $slider_wrapper.find('input:first');
        var $max_input = $slider_wrapper.find('input:last');

        // Setup default values.
        if ($min_input.val() == '') {
          $min_input.val($slider_wrapper.data('min'));
        }
        if ($max_input.val() == '') {
          $max_input.val($slider_wrapper.data('max'));
        }


        // Create slider.
        $('.slider-widget').remove();
        var $slider = $('<div class="slider-widget" />').appendTo($slider_wrapper).slider({
          range: true,
          min: $slider_wrapper.data('min'),
          max: $slider_wrapper.data('max'),
          step: 0.01,
          values: [$min_input.val(), $max_input.val()],
          slide: function(event, ui) {
            $min_input.val(ui.values[0]);
            $max_input.val(ui.values[1]);

            // Change button in click in label for slider work.
            $min_input.change();
          }
        });

        // Min and max fields behaviors.
        $min_input.keyup(function() {
          $slider.slider('values', 0, this.value);
        });
        $max_input.keyup(function() {
          $slider.slider('values', 1, this.value);
        });
      });
    }
  };
})(jQuery);
