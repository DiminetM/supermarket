<?php

function test_market_from_system_theme_settings_alter(&$form, $form_state){
  $form['breadcrum_delimiter'] = array(
    '#type' => 'textfield',
    '#title' => t('breadcrum delimiter'),
    '#size' => 4,
  );
  $form['use_twiter'] = array(
    '#type' => 'checkbox',
    '#title' => t(''),
  );

  $form['twiter_search_term'] = array(
    '#type' => 'textfield',
    '#title' => t('Use Twiter for site slogan'),
  );
}
