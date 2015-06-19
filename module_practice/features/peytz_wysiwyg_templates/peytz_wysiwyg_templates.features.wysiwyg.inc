<?php
/**
 * @file
 * peytz_wysiwyg_templates.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function peytz_wysiwyg_templates_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: wysiwyg_
  $profiles['wysiwyg_'] = array(
    'format' => 'wysiwyg_',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Strike' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Link' => 1,
          'Image' => 1,
          'Blockquote' => 1,
          'RemoveFormat' => 1,
          'Format' => 1,
          'Table' => 1,
        ),
        'imce' => array(
          'imce' => 1,
        ),
        'video_filter' => array(
          'video_filter' => 1,
        ),
        'templates' => array(
          'Templates' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 0,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 0,
      'block_formats' => 'p,address,pre,h2,h3',
      'css_setting' => 'self',
      'css_path' => '%b%t/styles/css/wysiwyg.css',
      'css_classes' => '',
    ),
    'rdf_mapping' => array(),
  );

  return $profiles;
}
