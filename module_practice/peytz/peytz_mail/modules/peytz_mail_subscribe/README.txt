General:
========
This module supplies a way to sign up to newsletter lists on a Peytz Mail
account. It also comes with helpers for contacting the Peytz Mail API functions.
Other modules may include additional signup form fields using a hook.

Installation:
=============

1. Enable module
2. Set up permissions.
3. Go to admin/config/peytz_mail/settings
     a. Select the 'Service URL protocol', most likely you will use the default.
     b. Enter the path to your Peytz Mail account in 'Service URL'.
     c. Enter your Peytz Mail API key.
     d. Save.
4. There is now a pane (placed under "Peytz") and a block, which both
   can be set up to sign up to selected newsletter lists.
5. Done.

Hooks:
======
hook_peytz_mail_subcribe_form_fields
This hook allows other modules to alter the sign up form to add additional
fields to submit to Peytz Mail.
