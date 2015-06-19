<?php
/**
 * @file
 * peytz_wysiwyg_templates.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function peytz_wysiwyg_templates_filter_default_formats() {
  $formats = array();

  // Exported format: WYSIWYG+.
  $formats['wysiwyg_'] = array(
    'format' => 'wysiwyg_',
    'name' => 'WYSIWYG+',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'video_filter' => array(
        'weight' => -1,
        'status' => 1,
        'settings' => array(
          'video_filter_width' => 400,
          'video_filter_height' => 400,
          'video_filter_autoplay' => 0,
          'video_filter_related' => 0,
          'video_filter_html5' => 1,
        ),
      ),
      'filter_autop' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
