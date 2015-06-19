<?php

/**
 * @file
 * Signup box content type definitions.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Peytz Mail signup box'),
  'description' => t('Newsletter signup box with multiple lists option.'),
  'single' => TRUE,
  'defaults' => array(),
  'category' => array(t('Peytz'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function peytz_mail_signup_box_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  if (!empty($conf['override_title']) && !empty($conf['override_title_text'])) {
    $block->title = check_plain($conf['override_title_text']);
  }
  else {
    $block->title = t('Newsletter signup');
  }
  if (!empty($conf)) {
    $block->content = drupal_get_form('peytz_mail_subscribe_form', $conf);
  }

  return $block;

}

/**
 * Edit form callback for the content type.
 */
function peytz_mail_signup_box_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  // Name field settings.
  $form['name_field_setting'] = array(
    '#type' => 'select',
    '#title' => t('Name field setup'),
    '#multiple' => FALSE,
    '#description' => t('Select to display the name field as a single full name field, as first name and last name fields, or turned off.'),
    '#options' => array(
      0 => 'Disabled',
      'single' => 'Single field',
      'double' => 'Double fields',
    ),
    '#default_value' => (!empty($conf['name_field_setting']) ? $conf['name_field_setting'] : 0),
  );

  $form['lists'] = array(
    '#type' => 'fieldset',
    '#title' => t('Newsletter lists'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $options = array();
  $mailinglists = peytz_mail_get_mailing_lists();
  foreach ($mailinglists as $list) {
    $options[$list['id']] = $list['title'];
  }
  $selected_options = array();
  $conf_newsletter_lists = unserialize($conf['newsletter_lists']);
  if (!empty($conf_newsletter_lists)) {
    foreach ($conf_newsletter_lists as $conf_list) {
      $selected_options[] = $conf_list['id'];
    }
  }

  if (!empty($mailinglists)) {
    $form['lists']['newsletter_lists'] = array(
      '#type' => 'select',
      '#title' => t('Newsletter lists'),
      '#multiple' => TRUE,
      '#description' => t('Select which newsletter lists this sign up box is connected to. If multiple lists are selected they will be presented as checkboxes in the sign up box.'),
      '#options' => $options,
      '#default_value' => $selected_options,
    );
    $form['lists']['hide_newsletter_lists'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide newsletter lists from users.'),
      '#default_value' => !empty($conf['hide_newsletter_lists']) ? $conf['hide_newsletter_lists'] : -1,
      '#description' => t('Check this if the users are not allowed to select which lists to join.'),
    );
  }
  else {
    $form['lists']['no_lists'] = array(
      '#markup' => t('No public newsletter lists found. Please check your Peytz Mail configuration.'),
    );
  }

  $form['signup_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Signup settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['signup_settings']['skip_confirm'] = array(
    '#type' => 'checkbox',
    '#title' => t('Skip confirmation mails.'),
    '#default_value' => !empty($conf['skip_confirm']) ? $conf['skip_confirm'] : -1,
  );

  $form['signup_settings']['skip_welcome'] = array(
    '#type' => 'checkbox',
    '#title' => t('Skip welcome mails.'),
    '#default_value' => !empty($conf['skip_welcome']) ? $conf['skip_welcome'] : -1,
  );

  return $form;
}

/**
 * Submit form callback for the content type.
 */
function peytz_mail_signup_box_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf'] = $form_state['values'];

  if (isset($form_state['values']['newsletter_lists'])) {
    $mailinglists = peytz_mail_get_mailing_lists();

    $selected_lists = array();
    foreach ($form_state['values']['newsletter_lists'] as $list) {
      $selected_lists[] = $mailinglists[$list];
    }

    $form_state['conf']['newsletter_lists'] = serialize($selected_lists);
  }
}

/**
 * Panels admin render panel.
 */
function peytz_mail_signup_box_content_type_admin_info($subtype, $conf, $contexts) {
  $block = new stdClass();
  $list_conf = unserialize($conf['newsletter_lists']);
  $list_titles = array();
  foreach ($list_conf as $list) {
    $list_titles[] = $list['title'];
  }
  $block->title = t(
    'Newsletter signup box<br />%lists',
    array(
      '%lists' => implode(", ", $list_titles),
    )
  );
  return $block;
}