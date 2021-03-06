<?php
/**
 * @file
 * peytz_blocks_export.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function peytz_blocks_export_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-zopim'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(
      0 => 'da',
    ),
    'i18n_mode' => 0,
    'machine_name' => 'zopim',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'air' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'air',
        'weight' => 0,
      ),
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-zopim_no'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(
      0 => 'nb',
    ),
    'i18n_mode' => 0,
    'machine_name' => 'zopim_no',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'air' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'air',
        'weight' => 0,
      ),
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
