<?php

/**
 * @file
 * Contains the class to extend views display plugins with
 * Filter by Current Language.
 */

/**
 * The plugin to filter view's results by current site language.
 */
class views_fbcl_plugin_filter extends views_handler_filter {

  function option_definition() {
    $options = parent::option_definition();
    $options['language'] = array('default' => FALSE);

    return $options;
  }

  /*
   * This method is used to create the options form for the Views UI when creating a view
   * we use the standard drupal form api to return a form array, with the settings
   * we want to capture.
   */

  function options_form(&$form, &$form_state) {

    $form['language'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use Filter by Current site language'),
      '#default_value' => $this->options['language'],
    );
  }

  /**
   * Display the filter on the administrative summary
   */
  function admin_summary() {
    return ($this->options['language']) ? t('Yes') : t('No');
  }

  /**
   * The query method is responsible for actually running our filter.
   */
  function query() {
    global $language;

    $this->table_alias = $this->table;
    if (empty($this->table_alias)) {
      return;
    }

    if ($this->options['language']/* && $user->uid != 1*/) {
      $this->query->add_where(0, "$this->table_alias.language", $language->language, "=");
    }
  }

}
