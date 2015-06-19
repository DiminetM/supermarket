<?php
/**
 * @file
 * Describe hooks provided by the Peytz Mail module.
 */

/**
 * Subscribe form modification hook.
 *
 * This is an example of adding a gender select box to the sign up form, but
 * only for a signup form connected to the mailinglist with the id
 * test_mailinglist.
 *
 * @param array $form
 *   The form array to alter.
 * @param array $list_id
 *   Mailing list ids to filter on.
 */
function hook_peytz_mail_subscribe_form_fields(&$form, $list_id = array()) {
  // Lets support receiving $list_ids both as an array and a string.
  if (!array($list_id)) {
    $list_id = array($list_id);
  }

  // Validate against mainling list ids which fields to add.
  if (!empty($list_id) && array_key_exists('test_mailinglist', $list_id)) {
    $form['peytz_mail_custom_field_gender'] = array(
      '#type' => 'select',
      '#title' => t('Gender'),
      '#multiple' => FALSE,
      '#options' => array('male' => 'Man', 'female' => 'Woman'),
    );
  }
}
