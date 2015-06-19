<?php
/**
 * @file
 * tm_front_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tm_front_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front_pages';
  $page->task = 'page';
  $page->admin_title = 'Front Pages';
  $page->admin_description = 'Front Pages';
  $page->path = 'frontpages';
  $page->access = array();
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Home',
    'name' => 'main-menu',
    'weight' => '0',
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
  $handler->name = 'page_front_pages_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'front_pages';
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
        'width' => '770',
        'width_type' => 'px',
        'parent' => '1',
        'class' => '',
      ),
      3 => array(
        'type' => 'region',
        'title' => '3',
        'width' => '190',
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
      3 => NULL,
    ),
    '1_' => array(
      'style' => 'default',
    ),
    3 => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2109ac56-4979-4031-93a1-4f40f974f95c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-de699ae1-8dfd-44b3-9960-0bcc2072aaf2';
    $pane->panel = '1_';
    $pane->type = 'block';
    $pane->subtype = 'views-carousele_new_product-block';
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
      'css_class' => 'custom-jcarousel home-jcarousel-newProduct',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'de699ae1-8dfd-44b3-9960-0bcc2072aaf2';
    $display->content['new-de699ae1-8dfd-44b3-9960-0bcc2072aaf2'] = $pane;
    $display->panels['1_'][0] = 'new-de699ae1-8dfd-44b3-9960-0bcc2072aaf2';
    $pane = new stdClass();
    $pane->pid = 'new-e2973f5b-ca55-4231-b4d3-bc261fcd2d3a';
    $pane->panel = '2_';
    $pane->type = 'views';
    $pane->subtype = 'top_vizite_product';
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
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'custom-jcarousel home-jcarousel-topVisited',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e2973f5b-ca55-4231-b4d3-bc261fcd2d3a';
    $display->content['new-e2973f5b-ca55-4231-b4d3-bc261fcd2d3a'] = $pane;
    $display->panels['2_'][0] = 'new-e2973f5b-ca55-4231-b4d3-bc261fcd2d3a';
    $pane = new stdClass();
    $pane->pid = 'new-ff1de386-a2be-40fd-8573-ffc92212959c';
    $pane->panel = '3';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-category-menu';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'category-product',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ff1de386-a2be-40fd-8573-ffc92212959c';
    $display->content['new-ff1de386-a2be-40fd-8573-ffc92212959c'] = $pane;
    $display->panels['3'][0] = 'new-ff1de386-a2be-40fd-8573-ffc92212959c';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_pages'] = $page;

  return $pages;

}
