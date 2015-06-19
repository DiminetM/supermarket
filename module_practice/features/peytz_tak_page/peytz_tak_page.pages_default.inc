<?php
/**
 * @file
 * peytz_tak_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function peytz_tak_page_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -20;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Taxonomy term from Node (on Node: Department)',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_department-node-taxonomy_term',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '0',
            'paths' => 'node/128',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flex_ws';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
      'right' => NULL,
      'header' => NULL,
      'full' => NULL,
      'left' => NULL,
      'full-1' => NULL,
      'left-3' => NULL,
      'right-3' => NULL,
      'left-4' => NULL,
      'right-4' => NULL,
      'left-5' => NULL,
      'middle-5' => NULL,
      'right-5' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '33dda6d6-1e89-4490-a3db-43202399cf89';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-377d85c9-9ac8-4640-99f0-5939b26371a0';
    $pane->panel = 'full';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '377d85c9-9ac8-4640-99f0-5939b26371a0';
    $display->content['new-377d85c9-9ac8-4640-99f0-5939b26371a0'] = $pane;
    $display->panels['full'][0] = 'new-377d85c9-9ac8-4640-99f0-5939b26371a0';
    $pane = new stdClass();
    $pane->pid = 'new-a21098ea-295a-4fa9-a05c-4280da1ba0bf';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'om_os_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = 'a21098ea-295a-4fa9-a05c-4280da1ba0bf';
    $display->content['new-a21098ea-295a-4fa9-a05c-4280da1ba0bf'] = $pane;
    $display->panels['header'][0] = 'new-a21098ea-295a-4fa9-a05c-4280da1ba0bf';
    $pane = new stdClass();
    $pane->pid = 'new-4aa00cf0-3a1d-4c02-8254-e071daa72e3e';
    $pane->panel = 'left';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 1,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '4aa00cf0-3a1d-4c02-8254-e071daa72e3e';
    $display->content['new-4aa00cf0-3a1d-4c02-8254-e071daa72e3e'] = $pane;
    $display->panels['left'][0] = 'new-4aa00cf0-3a1d-4c02-8254-e071daa72e3e';
    $pane = new stdClass();
    $pane->pid = 'new-093dbdb2-f87a-40bb-ab62-16b1d2f24301';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_related';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'node_reference_default',
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '093dbdb2-f87a-40bb-ab62-16b1d2f24301';
    $display->content['new-093dbdb2-f87a-40bb-ab62-16b1d2f24301'] = $pane;
    $display->panels['right'][0] = 'new-093dbdb2-f87a-40bb-ab62-16b1d2f24301';
    $pane = new stdClass();
    $pane->pid = 'new-311d739f-ffa9-412c-8b62-becdc9b2b5b7';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'employees-employee_contact_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'relationship_entity_from_field:field_department-node-taxonomy_term_1',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = '';
    $pane->uuid = '311d739f-ffa9-412c-8b62-becdc9b2b5b7';
    $display->content['new-311d739f-ffa9-412c-8b62-becdc9b2b5b7'] = $pane;
    $display->panels['right'][1] = 'new-311d739f-ffa9-412c-8b62-becdc9b2b5b7';
    $pane = new stdClass();
    $pane->pid = 'new-96796d92-e43e-4e67-ab4f-bbf5a7367b80';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'vocabularies-vocabulary_categories';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = '';
    $pane->uuid = '96796d92-e43e-4e67-ab4f-bbf5a7367b80';
    $display->content['new-96796d92-e43e-4e67-ab4f-bbf5a7367b80'] = $pane;
    $display->panels['right'][2] = 'new-96796d92-e43e-4e67-ab4f-bbf5a7367b80';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-4aa00cf0-3a1d-4c02-8254-e071daa72e3e';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_10';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -19;
  $handler->conf = array(
    'title' => 'TAK! page',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Taxonomy term from Node (on Node: Department)',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_department-node-taxonomy_term',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'node/128
node/432',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'page' => 'page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
  );
  $display = new panels_display();
  $display->layout = 'flex_ws';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
      'right' => NULL,
      'header' => NULL,
      'full' => NULL,
      'left' => NULL,
      'full-1' => NULL,
      'left-3' => NULL,
      'right-3' => NULL,
      'left-4' => NULL,
      'right-4' => NULL,
      'left-5' => NULL,
      'middle-5' => NULL,
      'right-5' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '015ace6f-734a-4010-9334-1fd17950f508';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-17e9faa8-5de0-4713-8b42-0af1faf214eb';
    $pane->panel = 'full';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 0,
      'override_title_text' => 'Arrangementer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '17e9faa8-5de0-4713-8b42-0af1faf214eb';
    $display->content['new-17e9faa8-5de0-4713-8b42-0af1faf214eb'] = $pane;
    $display->panels['full'][0] = 'new-17e9faa8-5de0-4713-8b42-0af1faf214eb';
    $pane = new stdClass();
    $pane->pid = 'new-1edb1280-bbfe-4e8c-96ae-8e7616165639';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'om_os_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '1edb1280-bbfe-4e8c-96ae-8e7616165639';
    $display->content['new-1edb1280-bbfe-4e8c-96ae-8e7616165639'] = $pane;
    $display->panels['header'][0] = 'new-1edb1280-bbfe-4e8c-96ae-8e7616165639';
    $pane = new stdClass();
    $pane->pid = 'new-9b4a75cc-3f3c-440e-ab28-60a3f6627919';
    $pane->panel = 'left';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 1,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '9b4a75cc-3f3c-440e-ab28-60a3f6627919';
    $display->content['new-9b4a75cc-3f3c-440e-ab28-60a3f6627919'] = $pane;
    $display->panels['left'][0] = 'new-9b4a75cc-3f3c-440e-ab28-60a3f6627919';
    $pane = new stdClass();
    $pane->pid = 'new-1638fb60-e996-4f29-9fda-751d1acaa503';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'webform-client-block-127';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1638fb60-e996-4f29-9fda-751d1acaa503';
    $display->content['new-1638fb60-e996-4f29-9fda-751d1acaa503'] = $pane;
    $display->panels['right'][0] = 'new-1638fb60-e996-4f29-9fda-751d1acaa503';
    $pane = new stdClass();
    $pane->pid = 'new-a2baff98-7b2e-467c-8789-a2834f7d1419';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_related';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'node_reference_default',
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Relateret',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = '';
    $pane->uuid = 'a2baff98-7b2e-467c-8789-a2834f7d1419';
    $display->content['new-a2baff98-7b2e-467c-8789-a2834f7d1419'] = $pane;
    $display->panels['right'][1] = 'new-a2baff98-7b2e-467c-8789-a2834f7d1419';
    $pane = new stdClass();
    $pane->pid = 'new-aae04022-ad0b-4698-98e3-c0a2446cd84e';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'vocabularies-vocabulary_categories';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = '';
    $pane->uuid = 'aae04022-ad0b-4698-98e3-c0a2446cd84e';
    $display->content['new-aae04022-ad0b-4698-98e3-c0a2446cd84e'] = $pane;
    $display->panels['right'][2] = 'new-aae04022-ad0b-4698-98e3-c0a2446cd84e';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-9b4a75cc-3f3c-440e-ab28-60a3f6627919';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_10'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_5';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Basic page',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Taxonomy term from Node (on Node: Department)',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_department-node-taxonomy_term',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'page' => 'page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '0',
            'paths' => 'node/128
node/432',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flex_ws';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
      'right' => NULL,
      'header' => NULL,
      'full' => NULL,
      'left' => NULL,
      'full-1' => NULL,
      'left-3' => NULL,
      'right-3' => NULL,
      'left-4' => NULL,
      'right-4' => NULL,
      'left-5' => NULL,
      'middle-5' => NULL,
      'right-5' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'df96b38d-b28c-4b9e-b4c3-fbd016f8963b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9429bc12-0b0f-4bd5-940e-53c2559456ab';
    $pane->panel = 'full';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 0,
      'override_title_text' => 'Arrangementer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '9429bc12-0b0f-4bd5-940e-53c2559456ab';
    $display->content['new-9429bc12-0b0f-4bd5-940e-53c2559456ab'] = $pane;
    $display->panels['full'][0] = 'new-9429bc12-0b0f-4bd5-940e-53c2559456ab';
    $pane = new stdClass();
    $pane->pid = 'new-357d2851-30c2-4897-a4f9-5ac123c64bbd';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'om_os_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '357d2851-30c2-4897-a4f9-5ac123c64bbd';
    $display->content['new-357d2851-30c2-4897-a4f9-5ac123c64bbd'] = $pane;
    $display->panels['header'][0] = 'new-357d2851-30c2-4897-a4f9-5ac123c64bbd';
    $pane = new stdClass();
    $pane->pid = 'new-6ffef7fa-6521-4287-b3ef-3ac5f2a17035';
    $pane->panel = 'left';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 1,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '6ffef7fa-6521-4287-b3ef-3ac5f2a17035';
    $display->content['new-6ffef7fa-6521-4287-b3ef-3ac5f2a17035'] = $pane;
    $display->panels['left'][0] = 'new-6ffef7fa-6521-4287-b3ef-3ac5f2a17035';
    $pane = new stdClass();
    $pane->pid = 'new-fa937612-f171-4519-87cd-2a4803368e4d';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'webform-client-block-127';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '0',
            'paths' => 'node/342',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => 'Få vores nyhedsbrev - og vind',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fa937612-f171-4519-87cd-2a4803368e4d';
    $display->content['new-fa937612-f171-4519-87cd-2a4803368e4d'] = $pane;
    $display->panels['right'][0] = 'new-fa937612-f171-4519-87cd-2a4803368e4d';
    $pane = new stdClass();
    $pane->pid = 'new-0735fff3-23c1-4d15-8102-0fa621518a9f';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_related';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'node_reference_default',
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Relateret',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = '';
    $pane->uuid = '0735fff3-23c1-4d15-8102-0fa621518a9f';
    $display->content['new-0735fff3-23c1-4d15-8102-0fa621518a9f'] = $pane;
    $display->panels['right'][1] = 'new-0735fff3-23c1-4d15-8102-0fa621518a9f';
    $pane = new stdClass();
    $pane->pid = 'new-6996b68b-ccc9-4eef-8f84-307fb2ec169f';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'vocabularies-vocabulary_categories';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = '';
    $pane->uuid = '6996b68b-ccc9-4eef-8f84-307fb2ec169f';
    $display->content['new-6996b68b-ccc9-4eef-8f84-307fb2ec169f'] = $pane;
    $display->panels['right'][2] = 'new-6996b68b-ccc9-4eef-8f84-307fb2ec169f';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-6ffef7fa-6521-4287-b3ef-3ac5f2a17035';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_5'] = $handler;

  return $export;
}
