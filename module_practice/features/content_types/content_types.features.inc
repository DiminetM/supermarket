<?php
/**
 * @file
 * content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function content_types_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function content_types_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: slideshow_frontpage
  $nodequeues['slideshow_frontpage'] = array(
    'name' => 'slideshow_frontpage',
    'title' => 'Slideshow frontpage',
    'subqueue_title' => '',
    'size' => 8,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'teaser',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: slideshow_frontpage_no
  $nodequeues['slideshow_frontpage_no'] = array(
    'name' => 'slideshow_frontpage_no',
    'title' => 'Slideshow frontpage NO',
    'subqueue_title' => '',
    'size' => 8,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'teaser',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function content_types_node_info() {
  $items = array(
    'case' => array(
      'name' => t('Cases'),
      'base' => 'node_content',
      'description' => t('Use <em>cases</em> for ...'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'client' => array(
      'name' => t('Client'),
      'base' => 'node_content',
      'description' => t('Use the \'Client\' content type for adding client logos and links to their websites.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'job' => array(
      'name' => t('Job'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Simpel side'),
      'base' => 'node_content',
      'description' => t('Brug <em>simple sider</em> til dit statiske indhold, som f.eks. en "om os"-side.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'product' => array(
      'name' => t('Produkt'),
      'base' => 'node_content',
      'description' => t('Use <em>product</em> for...'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'teaser' => array(
      'name' => t('Teaser'),
      'base' => 'node_content',
      'description' => t('Use <em>teaser</em> for ...'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'testimonial' => array(
      'name' => t('Testimonial'),
      'base' => 'node_content',
      'description' => t('Use <em>testimonial</em> for customer testimonials.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webformular'),
      'base' => 'node_content',
      'description' => t('Opret en ny formular eller et nyt spørgeskema. Resultater og statistik gemmes og er tilgængelige for priviligerede brugere.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
