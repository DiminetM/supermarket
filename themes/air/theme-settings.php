<?php

/**
 * Implements hook_form_system_theme_settings_alter() function.
 *
 * @param $saved_settings
 *   An array of saved settings for this theme.
 * @return
 *   A form array.
 */
function air_form_system_theme_settings_alter(&$form, $form_state) {
  // Development
  $form['development'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Development'),
    '#description' => t('These settings are meant for use during development of themes.'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
  );
  $form['development']['air_rebuild_registry'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Rebuild theme registry'),
    '#description'   => t('Automatically rebuild the theme registry during theme development (will affect performance greatly).'),
    '#default_value' => theme_get_setting('air_rebuild_registry'),
  );
}

