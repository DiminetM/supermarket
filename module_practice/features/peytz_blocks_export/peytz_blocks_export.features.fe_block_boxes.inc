<?php
/**
 * @file
 * peytz_blocks_export.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function peytz_blocks_export_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Indsætter chat på sitet.';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'zopim';
  $fe_block_boxes->body = '<!--Start of Zopim Live Chat Script-->
<script type="text/javascript">
window.$zopim||(function(d,s){var z=$zopim=function(c){z._.push(c)},$=z.s=
d.createElement(s),e=d.getElementsByTagName(s)[0];z.set=function(o){z.set.
_.push(o)};z._=[];z.set._=[];$.async=!0;$.setAttribute(\'charset\',\'utf-8\');
$.src=\'//cdn.zopim.com/?c68MrkBGU08yGSwboIlfzgQhsi5EgO9b\';z.t=+new Date;$.
type=\'text/javascript\';e.parentNode.insertBefore($,e)})(document,\'script\');
</script>
<!--End of Zopim Live Chat Script-->';

  $export['zopim'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Setter inn chat på nettstedet.';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'zopim_no';
  $fe_block_boxes->body = '<!--Start of Zopim Live Chat Script-->
<script type="text/javascript">
window.$zopim||(function(d,s){var z=$zopim=function(c){z._.push(c)},$=z.s=
d.createElement(s),e=d.getElementsByTagName(s)[0];z.set=function(o){z.set.
_.push(o)};z._=[];z.set._=[];$.async=!0;$.setAttribute(\'charset\',\'utf-8\');
$.src=\'//cdn.zopim.com/?c68MrkBGU08yGSwboIlfzgQhsi5EgO9b\';z.t=+new Date;$.
type=\'text/javascript\';e.parentNode.insertBefore($,e)})(document,\'script\');
</script>
<!--End of Zopim Live Chat Script-->
<script type="text/javascript">$zopim(function() {
// Insert API calls below this line
$zopim.livechat.setLanguage(\'no\');
// Insert API calls above this line
})
</script>';

  $export['zopim_no'] = $fe_block_boxes;

  return $export;
}
