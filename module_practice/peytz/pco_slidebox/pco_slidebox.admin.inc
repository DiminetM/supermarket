<?php

/**
 * @file
 *   Contains administrative forms and callbacks for Slidebox.
 */

/**
 * Menu callback. Displays the administration settings.
 */
function pco_slidebox_admin_settings() {
  $form = array();

  $form['display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Slidebox Display Options'),
    '#collapsible' => FALSE
  );

  $form['display']['pco_slidebox_show_time'] = array(
    '#title' => t('Slidebox Show Time'),
    '#description' => t('Number of miliseconds during which Slidebox should slide out'),
    '#type' => 'textfield',
    '#default_value' => variable_get('pco_slidebox_show_time', 300)
  );

  $form['display']['pco_slidebox_hide_time'] = array(
    '#title' => t('Slidebox Hide Time'),
    '#description' => t('Number of miliseconds during which Slidebox should slide back in'),
    '#type' => 'textfield',
    '#default_value' => variable_get('pco_slidebox_hide_time', 100)
  );

  return system_settings_form($form);
}

