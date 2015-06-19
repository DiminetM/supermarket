<?php
/**
 * @file
 * peytz_multilang_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function peytz_multilang_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
    'language' => 'und',
    'i18n_mode' => '0',
  );
  // Exported menu: menu-main-menu-no.
  $menus['menu-main-menu-no'] = array(
    'menu_name' => 'menu-main-menu-no',
    'title' => 'Main menu (NO)',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => '0',
  );
  // Exported menu: menu-secondary-menu.
  $menus['menu-secondary-menu'] = array(
    'menu_name' => 'menu-secondary-menu',
    'title' => 'Secondary menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => '0',
  );
  // Exported menu: menu-secondary-menu-no.
  $menus['menu-secondary-menu-no'] = array(
    'menu_name' => 'menu-secondary-menu-no',
    'title' => 'Secondary menu (NO)',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Main menu');
  t('Main menu (NO)');
  t('Secondary menu');
  t('Secondary menu (NO)');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
