<?php

/**
 * @file
 * Implements the display extender. It adds a checkbox to allow displays
 * filter by current site language.
 */

/**
 * Implementation of hook_views_handlers().
 */
function views_fbcl_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views_fbcl') . '/includes',
    ),
    'handlers' => array(
      // register our custom filter, with the class/file name and parent class
      'views_fbcl_plugin_filter' => array(
        'parent' => 'views_handler_filter',
      )
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */
function views_fbcl_views_data() {
  $data = array();

  // All included tables which will be affected on filters
  $tables = array(
    'users',
    'taxonomy_term_data',
    'node'
  );

  foreach ($tables as $table) {
    // The flexible date filter.
    $data[$table]['views_fbcl'] = array(
      'group' => t('Views FBCL'),
      'real field' => 'views_fbcl',
      'title' => t('Views Filter by Current Site Language'),
      'help' => t("Extends views's displays to get content filtered by current site language"),
      'filter' => array(
        'handler' => 'views_fbcl_plugin_filter'
      ),
    );
  }

  return $data;
}
