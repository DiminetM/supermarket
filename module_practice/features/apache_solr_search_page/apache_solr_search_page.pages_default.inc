<?php
/**
 * @file
 * apache_solr_search_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function apache_solr_search_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'Apache_solr_search_page';
  $page->task = 'page';
  $page->admin_title = 'Apache Solr';
  $page->admin_description = '';
  $page->path = 'search/solr/!query';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'query' => array(
      'id' => 1,
      'identifier' => 'Search query',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 1,
      ),
    ),
  );
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_Apache_solr_search_page_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'Apache_solr_search_page';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Search page',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flex';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'full' => NULL,
      'left' => NULL,
      'right' => NULL,
      'left-1' => NULL,
      'right-1' => NULL,
      'left-2' => NULL,
      'middle-2' => NULL,
      'right-2' => NULL,
      'full-1' => NULL,
      'left-3' => NULL,
      'right-3' => NULL,
      'left-4' => NULL,
      'right-4' => NULL,
      'left-5' => NULL,
      'middle-5' => NULL,
      'right-5' => NULL,
      'left-3-2' => NULL,
      'left-3-3' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Søgning "%keywords:html_safe"';
  $display->uuid = '2164d615-33b1-43ef-bfb4-81b1b0093b64';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-26f18598-2ea4-455d-8902-a0293fe5e8f8';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'soegning_title';
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
    $pane->uuid = '26f18598-2ea4-455d-8902-a0293fe5e8f8';
    $display->content['new-26f18598-2ea4-455d-8902-a0293fe5e8f8'] = $pane;
    $display->panels['header'][0] = 'new-26f18598-2ea4-455d-8902-a0293fe5e8f8';
    $pane = new stdClass();
    $pane->pid = 'new-db079ec4-4ccc-4770-8637-b72a74ece605';
    $pane->panel = 'left';
    $pane->type = 'search_result';
    $pane->subtype = 'search_result';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'apachesolr_search',
      'log' => 1,
      'override_empty' => 0,
      'empty_title' => '',
      'empty' => '',
      'empty_format' => 'plain_text',
      'override_no_key' => 0,
      'no_key_title' => '',
      'no_key' => '',
      'no_key_format' => 'plain_text',
      'context' => 'argument_string_1',
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
    $pane->locks = '';
    $pane->uuid = 'db079ec4-4ccc-4770-8637-b72a74ece605';
    $display->content['new-db079ec4-4ccc-4770-8637-b72a74ece605'] = $pane;
    $display->panels['left'][0] = 'new-db079ec4-4ccc-4770-8637-b72a74ece605';
    $pane = new stdClass();
    $pane->pid = 'new-49907cc0-3a3f-4d9b-a8bd-e5d6c425a1b0';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'apachesolr_search-sort';
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
    $pane->locks = '';
    $pane->uuid = '49907cc0-3a3f-4d9b-a8bd-e5d6c425a1b0';
    $display->content['new-49907cc0-3a3f-4d9b-a8bd-e5d6c425a1b0'] = $pane;
    $display->panels['right'][0] = 'new-49907cc0-3a3f-4d9b-a8bd-e5d6c425a1b0';
    $pane = new stdClass();
    $pane->pid = 'new-154c860f-ede8-45d3-b79b-7d01a7f52c78';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Filtrér på indholdstype',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = '';
    $pane->uuid = '154c860f-ede8-45d3-b79b-7d01a7f52c78';
    $display->content['new-154c860f-ede8-45d3-b79b-7d01a7f52c78'] = $pane;
    $display->panels['right'][1] = 'new-154c860f-ede8-45d3-b79b-7d01a7f52c78';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-db079ec4-4ccc-4770-8637-b72a74ece605';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['Apache_solr_search_page'] = $page;

  return $pages;

}
