<?php
// $Id: oprop_api.admin.inc,v 1.2 2011-04-19 07:39:03 ys Exp $

/**
 * @file
 * Admin functions for the Oprop API module.
 */

/**
 * Form builder; configure the Oprop API system.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function oprop_api_admin_settings($form, &$form_state) {
  global $CUSTOMER;
  $customer_name = variable_get('peytz_customer_name', $CUSTOMER->name);

  $form['oprop_api_general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
    '#description' => !empty($customer_name) ? t('View customer <a href="!url">@customer-name</a> in VIP.', array('!url' => _oprop_customer_base_uri(), '@customer-name' => $customer_name)) : '',
  );
  $form['oprop_api_general']['peytz_customer_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Customer'),
    '#description' => t('Peytz customer name. Set this, if you want to use a specific customer. If empty, it will use "%customer_name".', array('%customer_name' => $customer_name)),
    '#default_value' => variable_get('peytz_customer_name', ''),
  );
  $form['oprop_api_general']['oprop_api_server'] = array(
    '#type' => 'textfield',
    '#title' => t('Server'),
    '#description' => t('Oprop Server URI (e.g. http://vip.peytz.dk/). Set this only if you want to use a specific server.'),
    '#default_value' => variable_get('oprop_api_server', ''),
  );
  $form['oprop_api_general']['oprop_api_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#description' => t('Oprop login username. This is the name of a VIP user with the necessary Oprop permissions.'),
    '#default_value' => variable_get('oprop_api_username', 'soap'),
  );
  $form['oprop_api_general']['oprop_api_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#description' => t('Oprop login password.'),
    '#default_value' => variable_get('oprop_api_password', ''),
  );

  $form['oprop_api_cache'] = array(
    '#type' => 'fieldset',
    '#title' => t('Caching'),
  );
  $form['oprop_api_cache']['oprop_api_cache_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable caching'),
    '#description' => t('Enable caching of SOAP calls to the Oprop server.'),
    '#default_value' => variable_get('oprop_api_cache_enabled', TRUE),
  );

  $form['oprop_api_lists'] = array(
    '#type' => 'fieldset',
    '#title' => t('List settings'),
  );
  $form['oprop_api_lists']['oprop_api_default_lists'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Default subscribable lists'),
    '#description' => t('The lists for this customer that are available for subscription.'),
    '#options' => oprop_api_public_lists(),
    '#default_value' => variable_get('oprop_api_default_lists', array_keys(oprop_api_public_lists())),
  );
  $form['oprop_api_lists']['oprop_api_show_on_useredit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show on User Edit page'),
    '#description' => t('Whether a list of mailing lists should be shown on the user edit page for subscribtion and unsubscription. Alternatively, the block can be activated.'),
    '#default_value' => variable_get('oprop_api_show_on_useredit', FALSE),
  );
  $form['oprop_api_lists']['oprop_api_send_invitation'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send invitation on subscribe'),
    '#description' => t('Send an invitation message to the user when she subscribes to a mailing list.'),
    '#default_value' => variable_get('oprop_api_send_invitation', FALSE),
  );

  $form['oprop_api_messages'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Messages'),
    '#description' => t('Messages used by signup forms.'),
  );
  $form['oprop_api_messages']['oprop_api_messages_subscribe'] = array(
    '#type' => 'textfield',
    '#title' => t('Subscribe message'),
    '#description' => t('Message to user when subscribed.'),
    '#default_value' => variable_get('oprop_api_messages_subscribe', ''),
  );
  $form['oprop_api_messages']['oprop_api_messages_unsubscribe'] = array(
    '#type' => 'textfield',
    '#title' => t('Unsubscribe message'),
    '#description' => t('Message to user when unsubscribed.'),
    '#default_value' => variable_get('oprop_api_messages_unsubscribe', ''),
  );
  $form['oprop_api_messages']['oprop_api_messages_subscribe_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Subscribe path'),
    '#description' => t('Path to redirect user to when subscribed.'),
    '#default_value' => variable_get('oprop_api_messages_subscribe_path', ''),
  );
  $form['oprop_api_messages']['oprop_api_messages_unsubscribe_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Unsubscribe path'),
    '#description' => t('Path to redirect user to when unsubscribed.'),
    '#default_value' => variable_get('oprop_api_messages_unsubscribe_path', ''),
  );

  $form['oprop_api_optin'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Opt-in'),
    '#description' => t('Opt-in presents an extra checkbox in the subscription form, requiring the user to accept terms.'),
  );
  $form['oprop_api_optin']['oprop_api_optin_checkbox_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Checkbox text'),
    '#default_value' => variable_get('oprop_api_optin_checkbox_text', ''),
    '#description' => t('The text to display next to the checkbox. HTML allowed, subject to translation. Empty text disables feature.'),
  );
  $form['oprop_api_optin']['oprop_api_optin_required_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Error message'),
    '#default_value' => variable_get('oprop_api_optin_required_message', 'You must accept the terms in order to subscribe.'),
    '#description' => t("Text displayed if the user didn't opt in, subject to translation."),
  );

  return system_settings_form($form);
}
