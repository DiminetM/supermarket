<?php
/**
 * @file
 * peytz_multilingual.variable.inc
 */

/**
 * Implements hook_variable_realm_default_variables().
 */
function peytz_multilingual_variable_realm_default_variables() {
$realm_variables = array();
  $realm_variables['language']['da'] = array();
  $realm_variables['language']['en'] = array();
  $realm_variables['language']['nb'] = array(
  'menu_main_links_source' => 'menu-main-menu-no',
  'menu_secondary_links_source' => 'menu-secondary-menu-no',
);

return $realm_variables;
}
