<?php

/**
 * @file
 * Facebook Likebox Template.
 */

global $language;
$current_lang = 'en_US';
if ($language->language == 'ru') {
  $current_lang = 'ru_RU';
}
?>

<iframe
src="//www.facebook.com/plugins/likebox.php?href=<?php echo $fb_url; ?>&locale=<?php echo $current_lang; ?>&width=<?php echo $fb_width; ?>&colorscheme=<?php echo $fb_colorscheme; ?>&show_faces=<?php echo $fb_show_faces; ?>&bordercolor&stream=<?php echo $fb_stream; ?>&header=<?php echo $fb_header; ?>&height=<?php echo $fb_height; ?>&show_border=<?php echo $fb_show_border; ?>&force_wall=<?php echo $fb_force_wall; ?>"
scrolling="<?php echo $fb_scrolling; ?>"
frameborder="0"
style="border: none; overflow: hidden; width: <?php echo $fb_width; ?><?php echo $fb_width_units; ?>; height: <?php echo $fb_height; ?>px;"
allowTransparency="true">
</iframe>
