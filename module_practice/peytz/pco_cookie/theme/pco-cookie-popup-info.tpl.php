<?php
/**
 * @file
 * This is a template file for a pop-up prompting user to give their consent for
 * the website to set cookies.
 *
 * When overriding this template it is important to note that jQuery will use
 * the following classes to assign actions to buttons:
 *
 * agree-button      - agree to setting cookies
 *
 * Variables available:
 * - $message:  Contains the text that will be display whithin the pop-up
 */
?>

<div>
  <div class ="popup-content info">
    <div id="popup-text">
      <?php print $message ?>
    </div>
    <div id="popup-buttons">
      <input type="button" class="agree-button" value="<?php print t("OK"); ?>">
    </div>
  </div>
</div>
