(function ($) {
  // Hide norwegian work phone if is not selected support(tid:17) department.
  Drupal.behaviors.employeeWorkPhoneNo = {
    attach: function (context) {
      var department = $('#edit-field-department-und').val();
      // Hide norwegian work phone when page load. (For NO site department can be array because it's multiselect)
      if (($.isArray(department) && $.inArray('17', department)) || (!$.isArray(department) && department != 17)) {
        $('#edit-field-work-number-country-code-n').css('display', 'none');
        $('#edit-field-work-number-no').css('display', 'none');
      }
      // Display norwegian work phone in dependence of selected department.
      $('#edit-field-department-und').change(function() {
        var department = $('#edit-field-department-und').val();
        if (($.isArray(department) && $.inArray('17', department)) || (!$.isArray(department) && department != 17)) {
          $('#edit-field-work-number-country-code-n').css('display', 'none');
          $('#edit-field-work-number-no').css('display', 'none');
        }
        else {
          $('#edit-field-work-number-country-code-n').css('display', 'block');
          $('#edit-field-work-number-no').css('display', 'block');
        }
      });
    }
  };

  // Format phone numbers.
  Drupal.behaviors.employeePhoneFormat = {
    attach: function (context) {
      // Array with ids of fields in that need to erase spaces.
      var phones = ["#edit-field-work-number-und-0-value", "#edit-field-mobile-number-und-0-value", "#edit-field-work-number-no-und-0-value"];
      // Walk phone array and erase spaces.
      $.each(phones, function(i, val) {
        if ($(val).length) {
          $(val).bind('keyup', function() {
            $(this).val($(this).val().replace(/\s+/g,""));
          });
        }
      });
    }
  };
})(jQuery);
