<?php
/**
 * @file
 * This file provides administration form for the module.
 */

/**
 * Provides form for cookie control popup.
 */
function pco_cookie_admin_form($form_state) {

  global $language;
  $languages = language_list('enabled');

  $popup_settings = pco_cookie_get_settings();

  foreach ($languages[1] as $lan) {
    $form[$lan->language] = array(
      '#type' => 'fieldset',
      '#title' => t('For %language language', array('%language' => $lan->name))
    );

    $form[$lan->language][$lan->language . '_popup_info'] = array(
      '#type' => 'textarea',
      '#title' => t('Popup message'),
      '#default_value' => isset($popup_settings[$lan->language . '_popup_info']) ? $popup_settings[$lan->language . '_popup_info'] : '',
      '#required' => $language->name == $lan->name ? TRUE : FALSE,
      '#description' => t('Set the info text. For orange text: &lt;span class="orange-text"&gt;orange text&lt;/span&gt;'),
    );
  }

  $form['popup_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Popup height in pixels'),
    '#default_value' => isset($popup_settings['popup_height']) ? $popup_settings['popup_height'] : '',
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => FALSE,
    '#description' => t('Enter an integer value for a desired height in pixels or leave empty for automatically adjusted height. Do not set this value if you are using responsive theme.'),
  );

  $form['popup_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Popup width in pixels or a percentage value'),
    '#default_value' => isset($popup_settings['popup_width']) ? $popup_settings['popup_width'] : '100%',
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => TRUE,
    '#description' => t('Set the width of the popup. This can be either an integer value or percentage of the screen width. For example: 200 or 50%'),
  );

  $form['popup_delay'] = array(
    '#type' => 'textfield',
    '#title' => t('Popup time delay in seconds'),
    '#default_value' => isset($popup_settings['popup_delay']) ? $popup_settings['popup_delay'] : 1,
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => TRUE,
  );

  $form['save'] = array(
    '#type'  => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Validates form for cookie controll popup.
 */
function pco_cookie_admin_form_validate($form, &$form_state) {
  global $language;
  $ln = $language-> language;

  if (!preg_match('/^[1-9][0-9]{0,4}$/', $form_state['values']['popup_height']) && !empty($form_state['values']['popup_height'])) {
    form_set_error('popup_height', t('Height must be an integer value .'));
  }
  if (!preg_match('/^[1-9][0-9]{0,4}$/', $form_state['values']['popup_delay'])) {
    form_set_error('popup_delay', t('Delay must be an integer value.'));
  }
  if (!preg_match('/^[1-9][0-9]{0,4}\%?$/', $form_state['values']['popup_width'])) {
    form_set_error('popup_width', t('Width must be an integer or a percentage value.'));
  }
}

/*
 * Save form for cookie controll popup.
*/
function pco_cookie_admin_form_submit($form, &$form_state) {
  $languages = language_list('enabled');
  $cookie_popup_settings = array();
  foreach ($languages[1] as $lan) {
    $cookie_popup_settings[$lan->language . '_popup_info'] = $form_state['values'][$lan->language . '_popup_info'];
  }
  $cookie_popup_settings['popup_height'] = $form_state['values']['popup_height'];
  $cookie_popup_settings['popup_delay'] = $form_state['values']['popup_delay'];
  $cookie_popup_settings['popup_width'] = $form_state['values']['popup_width'];

  variable_set('pco_cookie', $cookie_popup_settings);
  drupal_set_message(t('The configuration options have been saved.'));
}
