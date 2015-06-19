<?php
// $Id: oprop_subscribers.admin.inc,v 1.1.6.2 2009-12-28 13:31:23 fini Exp $

/**
 * @file Administer Oprop subscription feeds
 */

/**
 * Oprop subscriber feed settings.
 */
function oprop_subscribers_settings() {
  $form = array();
  $form['oprop_subscribers_provide_feeds'] = array(
    '#type' => 'checkbox',
    '#title' => t('Provide subscriber feed(s)'),
    '#description' => t('Provide a subscriber feed for use by Oprop.'),
    '#default_value' => variable_get('oprop_subscribers_provide_feeds', FALSE),
  );

  if (variable_get('oprop_subscribers_provide_feeds', FALSE)) {
    $feeds = array(
      l('Default feed (all)', 'oprop/subscribers/all'),
    );
    foreach (module_invoke_all('oprop_subscribers') as $name => $desc) {
      $feeds[] = l($desc['title'], 'oprop/subscribers/' . $name);
    }


    
    $form['oprop_subscribers_feed_list'] = array(
      '#type' => 'fieldset',
      '#title' => 'Feeds',
      '#description' => theme('item_list', array('items' => $feeds))
    );

  }
  return system_settings_form($form);
}
