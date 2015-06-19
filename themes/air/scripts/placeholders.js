/**
 * @file
 * Adds label placeholder functionality.
 *
 * This script checks if browser supports HTML5 
 * placeholders, and adds functionality based on
 * result.
 *
 * @todo Extend Drupal.support object with other 
 * relevant tests and methods.
 */
(function($){
  Drupal.support = {
    placeholder: function() {
      // Check if browser support HTML5 placeholders
      var i = document.createElement('input');

      return 'placeholder' in i;
    }
  }; 

	Drupal.behaviors.placeholder = {
    attach: function (context) {   
      // Check on state and process inputs
      $('input[type="text"], input[type="password"], input[type="email"]', context).once(function () { 	
      	
      	// Create reference to input
      	var input = $(this);
      	
      	var label = input.parents('form').find('label[for=' + input.attr('id') + ']');
      	
      	// Abort if class "no-placeholder" is set
      	if (input.hasClass('no-placeholder')) return;
      	
      	// Check browser support
      	if (!Drupal.support.placeholder()) {
      	  
      		// Abort if no label found
      		if (!label.length) return;
      		
      		// Tell the browser we're using placeholders via js  
      		$(this).parent().addClass('js-input-ph');
      		
      		// Check if input is pre-filled
      		if (input.attr('value').length > 0) {
      			input.parent().addClass('pre-filled');

            // Don't show label
      			label.hide();
      			
      			return;
      		}
      
      		// Set placeholder initial state
      		!(input.val() || document.activeElement == this) ? label.show() : label.hide();
      
      		// Add event handlers
      		input.focus(function () {
      			// Hide placeholder
      			label.hide();
      		}).blur(function () {
      			// Show placeholder
      			!input.val() ? label.fadeIn('fast') : label.hide();
      		});
      		label.click(function () {
      			// Give focus to input
      			input.focus();
      		});
      
      		// Insert placeholder
      		label.text(label.text().replace(/\s*:\s*$/, '')).addClass('placeholder').insertBefore(input);      	
      	} else {      	  
      	  // Add HTML5 placeholders
      	  label.hide();
      	  
      	  input.attr('placeholder', label.text());
      	}
      });
    }
  }

}(jQuery));
