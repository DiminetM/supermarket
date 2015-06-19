<?php
/**
 * @file
 * tm_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function tm_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'Manufacture views',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'manufacure' => 'manufacure',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
        ),
        'parent' => NULL,
        'class' => '',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
      ),
      1 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 3,
          1 => 2,
          2 => 4,
        ),
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'carousel',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'carousel' => array(
        'type' => 'region',
        'title' => 'carousel',
        'width' => '100',
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'img',
          1 => 'desc',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'img' => array(
        'type' => 'region',
        'title' => 'img',
        'width' => '332',
        'width_type' => 'px',
        'parent' => '3',
        'class' => '',
      ),
      'desc' => array(
        'type' => 'region',
        'title' => 'desc',
        'width' => '458',
        'width_type' => 'px',
        'parent' => '3',
        'class' => '',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(),
        'parent' => '1',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'product_image' => NULL,
      'description' => NULL,
      'image_galery' => NULL,
      'related_product' => NULL,
      'carousel' => NULL,
      'img' => NULL,
      'desc' => NULL,
      'carousele' => NULL,
      'car' => NULL,
    ),
    'desc' => array(
      'style' => 'default',
    ),
    'carousele' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd8f29dba-f941-40ae-b397-e08bda9fc0f2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-799fd047-e571-4e5b-bb93-bb62d38acc6e';
    $pane->panel = 'carousel';
    $pane->type = 'block';
    $pane->subtype = 'views-partners-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'custom-jcarousel manufacture-jcarousel-partners',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '799fd047-e571-4e5b-bb93-bb62d38acc6e';
    $display->content['new-799fd047-e571-4e5b-bb93-bb62d38acc6e'] = $pane;
    $display->panels['carousel'][0] = 'new-799fd047-e571-4e5b-bb93-bb62d38acc6e';
    $pane = new stdClass();
    $pane->pid = 'new-b8c1e791-e6bc-494a-9469-0a93e0f9d1e7';
    $pane->panel = 'desc';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_creation_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'short',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
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
    $pane->locks = array();
    $pane->uuid = 'b8c1e791-e6bc-494a-9469-0a93e0f9d1e7';
    $display->content['new-b8c1e791-e6bc-494a-9469-0a93e0f9d1e7'] = $pane;
    $display->panels['desc'][0] = 'new-b8c1e791-e6bc-494a-9469-0a93e0f9d1e7';
    $pane = new stdClass();
    $pane->pid = 'new-76ba470d-b815-4d5f-a8aa-a5c31953c826';
    $pane->panel = 'desc';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Description :',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '76ba470d-b815-4d5f-a8aa-a5c31953c826';
    $display->content['new-76ba470d-b815-4d5f-a8aa-a5c31953c826'] = $pane;
    $display->panels['desc'][1] = 'new-76ba470d-b815-4d5f-a8aa-a5c31953c826';
    $pane = new stdClass();
    $pane->pid = 'new-eeda5d83-ea37-402d-8e31-4aac178ff915';
    $pane->panel = 'desc';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_partners';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 1,
      ),
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'eeda5d83-ea37-402d-8e31-4aac178ff915';
    $display->content['new-eeda5d83-ea37-402d-8e31-4aac178ff915'] = $pane;
    $display->panels['desc'][2] = 'new-eeda5d83-ea37-402d-8e31-4aac178ff915';
    $pane = new stdClass();
    $pane->pid = 'new-ca5ea8d8-0ae4-4a10-bbcf-b25d77cba627';
    $pane->panel = 'desc';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_adress';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'ca5ea8d8-0ae4-4a10-bbcf-b25d77cba627';
    $display->content['new-ca5ea8d8-0ae4-4a10-bbcf-b25d77cba627'] = $pane;
    $display->panels['desc'][3] = 'new-ca5ea8d8-0ae4-4a10-bbcf-b25d77cba627';
    $pane = new stdClass();
    $pane->pid = 'new-02799e21-32c3-43ad-8fe9-95400370714f';
    $pane->panel = 'img';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'image_style' => '',
        'image_link' => '',
      ),
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
    $pane->locks = array();
    $pane->uuid = '02799e21-32c3-43ad-8fe9-95400370714f';
    $display->content['new-02799e21-32c3-43ad-8fe9-95400370714f'] = $pane;
    $display->panels['img'][0] = 'new-02799e21-32c3-43ad-8fe9-95400370714f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 6;
  $handler->conf = array(
    'title' => 'Product views',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Taxonomy term from Node (on Node: Category [field_product_category])',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_product_category-node-taxonomy_term',
        'delta' => 0,
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
              'products' => 'products',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
        ),
        'parent' => NULL,
        'class' => '',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
      ),
      1 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 5,
          1 => 3,
          2 => 2,
          3 => 4,
        ),
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'carousel',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'carousel' => array(
        'type' => 'region',
        'title' => 'carousel',
        'width' => '100',
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'img',
          1 => 'desc',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'img' => array(
        'type' => 'region',
        'title' => 'img',
        'width' => '360',
        'width_type' => 'px',
        'parent' => '3',
        'class' => '',
      ),
      'desc' => array(
        'type' => 'region',
        'title' => 'desc',
        'width' => '440',
        'width_type' => 'px',
        'parent' => '3',
        'class' => '',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(),
        'parent' => '1',
        'class' => '',
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(),
        'parent' => '1',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'product_image' => NULL,
      'description' => NULL,
      'image_galery' => NULL,
      'related_product' => NULL,
      'carousel' => NULL,
      'img' => NULL,
      'desc' => NULL,
      'carousele' => NULL,
      'car' => NULL,
      'fghjk' => NULL,
      'img_' => NULL,
      'descript' => NULL,
    ),
    'desc' => array(
      'style' => 'default',
    ),
    'carousele' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd8f29dba-f941-40ae-b397-e08bda9fc0f2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d0d04368-12ac-45e3-911f-c6bb99d9da82';
    $pane->panel = 'carousel';
    $pane->type = 'views';
    $pane->subtype = 'realted_product';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '4',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'context' => array(
        0 => 'relationship_entity_from_field:field_product_category-node-taxonomy_term_1.tid',
        1 => '',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'custom-jcarousel product-jcarousel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd0d04368-12ac-45e3-911f-c6bb99d9da82';
    $display->content['new-d0d04368-12ac-45e3-911f-c6bb99d9da82'] = $pane;
    $display->panels['carousel'][0] = 'new-d0d04368-12ac-45e3-911f-c6bb99d9da82';
    $pane = new stdClass();
    $pane->pid = 'new-165fd7f5-5594-4583-9816-648967768ca0';
    $pane->panel = 'desc';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_product_id';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => 'Product ID :',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '165fd7f5-5594-4583-9816-648967768ca0';
    $display->content['new-165fd7f5-5594-4583-9816-648967768ca0'] = $pane;
    $display->panels['desc'][0] = 'new-165fd7f5-5594-4583-9816-648967768ca0';
    $pane = new stdClass();
    $pane->pid = 'new-a87b1c9a-07b2-4321-8bde-7eb6bd7fd866';
    $pane->panel = 'desc';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Description :',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a87b1c9a-07b2-4321-8bde-7eb6bd7fd866';
    $display->content['new-a87b1c9a-07b2-4321-8bde-7eb6bd7fd866'] = $pane;
    $display->panels['desc'][1] = 'new-a87b1c9a-07b2-4321-8bde-7eb6bd7fd866';
    $pane = new stdClass();
    $pane->pid = 'new-f0fa3ddf-2331-422c-b9c8-c7593a0e5f32';
    $pane->panel = 'desc';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_product_category';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => 'Category:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f0fa3ddf-2331-422c-b9c8-c7593a0e5f32';
    $display->content['new-f0fa3ddf-2331-422c-b9c8-c7593a0e5f32'] = $pane;
    $display->panels['desc'][2] = 'new-f0fa3ddf-2331-422c-b9c8-c7593a0e5f32';
    $pane = new stdClass();
    $pane->pid = 'new-c423dc1e-2e1e-4b65-94a4-b69f914c3870';
    $pane->panel = 'desc';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_product_manufacturer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'view_mode' => 'token',
        'links' => 1,
        'link' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => 'Manufacture :',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'c423dc1e-2e1e-4b65-94a4-b69f914c3870';
    $display->content['new-c423dc1e-2e1e-4b65-94a4-b69f914c3870'] = $pane;
    $display->panels['desc'][3] = 'new-c423dc1e-2e1e-4b65-94a4-b69f914c3870';
    $pane = new stdClass();
    $pane->pid = 'new-624efb49-438e-454c-9c7d-02f444c34b84';
    $pane->panel = 'desc';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_price';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '624efb49-438e-454c-9c7d-02f444c34b84';
    $display->content['new-624efb49-438e-454c-9c7d-02f444c34b84'] = $pane;
    $display->panels['desc'][4] = 'new-624efb49-438e-454c-9c7d-02f444c34b84';
    $pane = new stdClass();
    $pane->pid = 'new-5b5e59d2-9bf5-4912-bffa-a00e8435ebe4';
    $pane->panel = 'img';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => '1',
      'delta_offset' => '1',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'image_style' => 'style-img300',
        'image_link' => '',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array(
      'type' => 'none',
      'regions' => array(
        'img' => 'img',
      ),
    );
    $pane->uuid = '5b5e59d2-9bf5-4912-bffa-a00e8435ebe4';
    $display->content['new-5b5e59d2-9bf5-4912-bffa-a00e8435ebe4'] = $pane;
    $display->panels['img'][0] = 'new-5b5e59d2-9bf5-4912-bffa-a00e8435ebe4';
    $pane = new stdClass();
    $pane->pid = 'new-b2aa6998-945b-4122-a8fe-e882262a4d37';
    $pane->panel = 'img';
    $pane->type = 'views';
    $pane->subtype = 'carousel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '3',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'context' => array(
        0 => '',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'custom-jcarousel image-jcarousel',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b2aa6998-945b-4122-a8fe-e882262a4d37';
    $display->content['new-b2aa6998-945b-4122-a8fe-e882262a4d37'] = $pane;
    $display->panels['img'][1] = 'new-b2aa6998-945b-4122-a8fe-e882262a4d37';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Webform',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'webform' => 'webform',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Contact';
  $display->uuid = 'c6056cc7-bdd4-4f36-bf48-503530fcbc18';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f2acf0e9-fb3a-4be9-a443-a1d8c4088d05';
    $pane->panel = 'center';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:webform';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'view_mode' => 'full',
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
    $pane->locks = array();
    $pane->uuid = 'f2acf0e9-fb3a-4be9-a443-a1d8c4088d05';
    $display->content['new-f2acf0e9-fb3a-4be9-a443-a1d8c4088d05'] = $pane;
    $display->panels['center'][0] = 'new-f2acf0e9-fb3a-4be9-a443-a1d8c4088d05';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f2acf0e9-fb3a-4be9-a443-a1d8c4088d05';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 7;
  $handler->conf = array(
    'title' => 'Banner',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'banner' => 'banner',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => array(
        'corner_location' => 'panel',
      ),
    ),
    'center' => array(
      'style' => 'rounded_corners',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8a180d05-c1e9-4501-a46b-32957f0c7004';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c176fe45-7cb6-4b73-bea7-e42e8fded1a7';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image_baner';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'banner_style',
        'image_link' => 'content',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c176fe45-7cb6-4b73-bea7-e42e8fded1a7';
    $display->content['new-c176fe45-7cb6-4b73-bea7-e42e8fded1a7'] = $pane;
    $display->panels['center'][0] = 'new-c176fe45-7cb6-4b73-bea7-e42e8fded1a7';
    $pane = new stdClass();
    $pane->pid = 'new-4543f040-3506-4dd4-b7fb-08cbcea3b072';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4543f040-3506-4dd4-b7fb-08cbcea3b072';
    $display->content['new-4543f040-3506-4dd4-b7fb-08cbcea3b072'] = $pane;
    $display->panels['center'][1] = 'new-4543f040-3506-4dd4-b7fb-08cbcea3b072';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'keywords',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term',
          'settings' => array(
            'vid' => '3',
            2 => array(),
            3 => array(),
            1 => array(),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c112b033-b75c-4872-a33d-eff62de3ae2e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9830af2a-ab1a-40d3-aa18-7c01cf3984bb';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'keywords-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9830af2a-ab1a-40d3-aa18-7c01cf3984bb';
    $display->content['new-9830af2a-ab1a-40d3-aa18-7c01cf3984bb'] = $pane;
    $display->panels['center'][0] = 'new-9830af2a-ab1a-40d3-aa18-7c01cf3984bb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function tm_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'categories';
  $page->task = 'page';
  $page->admin_title = 'Category';
  $page->admin_description = '';
  $page->path = 'category/!category_name';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'category_name' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'term',
        'vids' => array(
          2 => '2',
          4 => 0,
          3 => 0,
          1 => 0,
        ),
        'breadcrumb' => 1,
        'transform' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_categories_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'categories';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Taxonomy vocabulary from Taxonomy term (on taxonomy_term_data.vocabulary)',
        'keyword' => 'taxonomy_vocabulary',
        'name' => 'entity_from_schema:vid-taxonomy_term-taxonomy_vocabulary',
        'context' => 'argument_term_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'category',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '100',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'category' => array(
        'type' => 'region',
        'title' => 'Category',
        'width' => '280',
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
      'center' => NULL,
      'category' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6e292eea-fb33-480c-aa37-4b024307dce5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-730b952b-bcf2-4b43-93ec-df94dbf234b3';
    $pane->panel = 'category';
    $pane->type = 'views';
    $pane->subtype = 'category_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '730b952b-bcf2-4b43-93ec-df94dbf234b3';
    $display->content['new-730b952b-bcf2-4b43-93ec-df94dbf234b3'] = $pane;
    $display->panels['category'][0] = 'new-730b952b-bcf2-4b43-93ec-df94dbf234b3';
    $pane = new stdClass();
    $pane->pid = 'new-a6556788-3d09-4f5a-bdbb-0fb2a7b28fa4';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'categorys_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '8',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'context' => array(
        0 => 'argument_term_1.name',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a6556788-3d09-4f5a-bdbb-0fb2a7b28fa4';
    $display->content['new-a6556788-3d09-4f5a-bdbb-0fb2a7b28fa4'] = $pane;
    $display->panels['center'][0] = 'new-a6556788-3d09-4f5a-bdbb-0fb2a7b28fa4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['categories'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'contact';
  $page->task = 'page';
  $page->admin_title = 'Contact';
  $page->admin_description = 'contact';
  $page->path = 'contacts';
  $page->access = array();
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Contact',
    'name' => 'main-menu',
    'weight' => '3',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_contact_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'contact';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => '',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '100',
        'width_type' => '%',
        'children' => array(
          0 => 2,
          1 => 1,
          2 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(),
        'parent' => 'main',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '2_',
          1 => '3',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '1_',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      '1_' => array(
        'type' => 'region',
        'title' => '1',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      '2_' => array(
        'type' => 'region',
        'title' => '2',
        'width' => '710',
        'width_type' => 'px',
        'parent' => '1',
        'class' => '',
      ),
      3 => array(
        'type' => 'region',
        'title' => '3',
        'width' => '211',
        'width_type' => 'px',
        'parent' => '1',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'carousel' => NULL,
      'carousel2' => NULL,
      'menu_category' => NULL,
      '1_' => NULL,
      '2_' => NULL,
      3 => array(
        'corner_location' => 'panel',
      ),
    ),
    '1_' => array(
      'style' => 'default',
    ),
    3 => array(
      'style' => 'rounded_corners',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2109ac56-4979-4031-93a1-4f40f974f95c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-65847b0a-65a0-459d-931e-2dee26d572eb';
    $pane->panel = '1_';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->locks = array();
    $pane->uuid = '65847b0a-65a0-459d-931e-2dee26d572eb';
    $display->content['new-65847b0a-65a0-459d-931e-2dee26d572eb'] = $pane;
    $display->panels['1_'][0] = 'new-65847b0a-65a0-459d-931e-2dee26d572eb';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['contact'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ctalog';
  $page->task = 'page';
  $page->admin_title = 'Catalog';
  $page->admin_description = '';
  $page->path = 'catalog';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Catalog',
    'name' => 'main-menu',
    'weight' => '1',
    'parent' => array(
      'type' => 'tab',
      'title' => '',
      'name' => 'main-menu',
      'weight' => '2',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_ctalog_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'ctalog';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'filtre',
          1 => 'catalog',
        ),
        'parent' => 'main',
      ),
      'filtre' => array(
        'type' => 'region',
        'title' => 'filtre',
        'width' => '231',
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => '',
      ),
      'catalog' => array(
        'type' => 'region',
        'title' => 'Catalog',
        'width' => '684.5',
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
      'filters' => NULL,
      'catalog' => NULL,
      'filtre' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6e292eea-fb33-480c-aa37-4b024307dce5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-39eb8b95-c235-4dad-af99-63c3ace92b01';
    $pane->panel = 'catalog';
    $pane->type = 'views_panes';
    $pane->subtype = 'Catalog-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'path' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '39eb8b95-c235-4dad-af99-63c3ace92b01';
    $display->content['new-39eb8b95-c235-4dad-af99-63c3ace92b01'] = $pane;
    $display->panels['catalog'][0] = 'new-39eb8b95-c235-4dad-af99-63c3ace92b01';
    $pane = new stdClass();
    $pane->pid = 'new-3099a950-c96d-4560-8727-a19ff6843381';
    $pane->panel = 'filtre';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-Catalog-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'filter-form',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3099a950-c96d-4560-8727-a19ff6843381';
    $display->content['new-3099a950-c96d-4560-8727-a19ff6843381'] = $pane;
    $display->panels['filtre'][0] = 'new-3099a950-c96d-4560-8727-a19ff6843381';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ctalog'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'keywords';
  $page->task = 'page';
  $page->admin_title = 'Keywords';
  $page->admin_description = '';
  $page->path = 'keywords/!keyword_name';
  $page->access = array(
    'plugins' => array(),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'keyword_name' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'term',
        'vids' => array(
          3 => '3',
          4 => 0,
          2 => 0,
          1 => 0,
        ),
        'breadcrumb' => 1,
        'transform' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_keywords_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'keywords';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Taxonomy vocabulary from Taxonomy term (on taxonomy_term_data.vocabulary)',
        'keyword' => 'taxonomy_vocabulary',
        'name' => 'entity_from_schema:vid-taxonomy_term-taxonomy_vocabulary',
        'context' => 'argument_term_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'keywords',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '100',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'keywords' => array(
        'type' => 'region',
        'title' => 'keywords',
        'width' => '238',
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
      'left' => NULL,
      'right' => NULL,
      'keywords' => NULL,
      'center' => NULL,
    ),
    'center' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6e292eea-fb33-480c-aa37-4b024307dce5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-25eeb49c-8d24-4f91-acbf-a9a4e74659ea';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'keywords_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '8',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'context' => array(
        0 => 'argument_term_1.name',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '25eeb49c-8d24-4f91-acbf-a9a4e74659ea';
    $display->content['new-25eeb49c-8d24-4f91-acbf-a9a4e74659ea'] = $pane;
    $display->panels['center'][0] = 'new-25eeb49c-8d24-4f91-acbf-a9a4e74659ea';
    $pane = new stdClass();
    $pane->pid = 'new-582b2eda-2c5f-4449-ba7c-a2b44047fb0f';
    $pane->panel = 'keywords';
    $pane->type = 'views';
    $pane->subtype = 'keywords_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '582b2eda-2c5f-4449-ba7c-a2b44047fb0f';
    $display->content['new-582b2eda-2c5f-4449-ba7c-a2b44047fb0f'] = $pane;
    $display->panels['keywords'][0] = 'new-582b2eda-2c5f-4449-ba7c-a2b44047fb0f';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['keywords'] = $page;

  return $pages;

}
