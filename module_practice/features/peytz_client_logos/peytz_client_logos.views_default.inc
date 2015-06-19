<?php
/**
 * @file
 * peytz_client_logos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function peytz_client_logos_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'client_logos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Client logos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Test';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Forbindelse: Nodekø: Kø */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'slideshow_frontpage' => 0,
    'client_logos' => 0,
  );
  /* Felt: Indhold: Client logo */
  $handler->display->display_options['fields']['field_client_logo']['id'] = 'field_client_logo';
  $handler->display->display_options['fields']['field_client_logo']['table'] = 'field_data_field_client_logo';
  $handler->display->display_options['fields']['field_client_logo']['field'] = 'field_client_logo';
  $handler->display->display_options['fields']['field_client_logo']['label'] = '';
  $handler->display->display_options['fields']['field_client_logo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_client_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_client_logo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_client_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_client_logo']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_client_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Felt: Indhold: Client logo mouse over */
  $handler->display->display_options['fields']['field_client_logo_mouse_over']['id'] = 'field_client_logo_mouse_over';
  $handler->display->display_options['fields']['field_client_logo_mouse_over']['table'] = 'field_data_field_client_logo_mouse_over';
  $handler->display->display_options['fields']['field_client_logo_mouse_over']['field'] = 'field_client_logo_mouse_over';
  $handler->display->display_options['fields']['field_client_logo_mouse_over']['label'] = '';
  $handler->display->display_options['fields']['field_client_logo_mouse_over']['element_type'] = '0';
  $handler->display->display_options['fields']['field_client_logo_mouse_over']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_client_logo_mouse_over']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_client_logo_mouse_over']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_client_logo_mouse_over']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_client_logo_mouse_over']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Felt: Indhold: Client link */
  $handler->display->display_options['fields']['field_client_link']['id'] = 'field_client_link';
  $handler->display->display_options['fields']['field_client_link']['table'] = 'field_data_field_client_link';
  $handler->display->display_options['fields']['field_client_link']['field'] = 'field_client_link';
  $handler->display->display_options['fields']['field_client_link']['label'] = '';
  $handler->display->display_options['fields']['field_client_link']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_client_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_client_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_client_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_client_link']['click_sort_column'] = 'url';
  /* Sorteringskriterie: Nodekø: Placering */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'client' => 'client',
  );
  /* Filterkriterie: Indhold: Sprog */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'nb' => 'nb',
  );

  /* Display: Client Logos */
  $handler = $view->new_display('panel_pane', 'Client Logos', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Besøg vores kunder';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'client' => 'client',
  );
  /* Filterkriterie: Indhold: Sprog */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'da' => 'da',
    'en' => 'en',
  );
  $handler->display->display_options['pane_title'] = 'Client logos';
  $handler->display->display_options['pane_description'] = 'Client logos';
  $handler->display->display_options['pane_category']['name'] = 'Peytz & Co.';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Client Logos NO */
  $handler = $view->new_display('panel_pane', 'Client Logos NO', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Besøg vores kunder';
  $handler->display->display_options['pane_title'] = 'Client logos NO';
  $handler->display->display_options['pane_description'] = 'Client logos NO';
  $handler->display->display_options['pane_category']['name'] = 'Peytz & Co.';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $translatables['client_logos'] = array(
    t('Master'),
    t('Test'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('kø'),
    t('Client Logos'),
    t('Besøg vores kunder'),
    t('Client logos'),
    t('Peytz & Co.'),
    t('Client Logos NO'),
    t('Client logos NO'),
  );
  $export['client_logos'] = $view;

  return $export;
}
