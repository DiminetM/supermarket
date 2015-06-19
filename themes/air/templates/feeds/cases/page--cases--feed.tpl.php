<?php
/**
 * @file
 * Alpha's theme implementation to display a single Drupal page.
 */
?>
<?php if (isset($page['content'])) : ?>
  <?php print render($page['content']['system_main']['main']); ?>
<?php endif; ?>
