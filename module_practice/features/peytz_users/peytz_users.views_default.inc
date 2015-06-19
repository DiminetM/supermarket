<?php
/**
 * @file
 * peytz_users.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function peytz_users_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'employees';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Employees';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Medarbejdere';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Felt: Bruger: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Felt: Bruger: Billede */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Felt: Felt: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Felt: Felt: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Arbejde */
  $handler->display->display_options['fields']['field_work_number']['id'] = 'field_work_number';
  $handler->display->display_options['fields']['field_work_number']['table'] = 'field_data_field_work_number';
  $handler->display->display_options['fields']['field_work_number']['field'] = 'field_work_number';
  $handler->display->display_options['fields']['field_work_number']['label'] = '';
  $handler->display->display_options['fields']['field_work_number']['alter']['text'] = '[field_work_number] (arbejde)';
  $handler->display->display_options['fields']['field_work_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_work_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_work_number']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_work_number']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_work_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: Mobil */
  $handler->display->display_options['fields']['field_mobile_number']['id'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['table'] = 'field_data_field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['field'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['label'] = '';
  $handler->display->display_options['fields']['field_mobile_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number']['alter']['text'] = '[field_mobile_number] (mobil)';
  $handler->display->display_options['fields']['field_mobile_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mobile_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_mobile_number']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_mobile_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['mail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = 0;
  /* Sorteringskriterie: Felt: Name (field_name) */
  $handler->display->display_options['sorts']['field_name_value']['id'] = 'field_name_value';
  $handler->display->display_options['sorts']['field_name_value']['table'] = 'field_data_field_name';
  $handler->display->display_options['sorts']['field_name_value']['field'] = 'field_name_value';
  /* Kontekstuelt filter: Felt: Department (field_department) */
  $handler->display->display_options['arguments']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['arguments']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_department_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_department_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_department_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_department_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_department_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_department_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_department_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_department_tid']['validate_options']['vocabularies'] = array(
    'department' => 'department',
  );
  $handler->display->display_options['arguments']['field_department_tid']['validate_options']['type'] = 'convert';
  /* Kontekstuelt filter: Bruger: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['uid']['not'] = TRUE;
  /* Filterkriterie: Bruger: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Bruger: Show profile on site (field_show_profile_on_site) */
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['id'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['table'] = 'field_data_field_show_profile_on_site';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['field'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['group'] = '0';

  /* Display: Employees list */
  $handler = $view->new_display('panel_pane', 'Employees list', 'employees_list');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Bruger: Office */
  $handler->display->display_options['fields']['field_office']['id'] = 'field_office';
  $handler->display->display_options['fields']['field_office']['table'] = 'field_data_field_office';
  $handler->display->display_options['fields']['field_office']['field'] = 'field_office';
  $handler->display->display_options['fields']['field_office']['label'] = '';
  $handler->display->display_options['fields']['field_office']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Felt: Bruger: Billede */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Felt: Felt: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Felt: Felt: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Job title (Norwegian) */
  $handler->display->display_options['fields']['field_job_title_no']['id'] = 'field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['table'] = 'field_data_field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['field'] = 'field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['label'] = '';
  $handler->display->display_options['fields']['field_job_title_no']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_job_title_no']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Mobile number country code */
  $handler->display->display_options['fields']['field_mobile_number_country_code']['id'] = 'field_mobile_number_country_code';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['table'] = 'field_data_field_mobile_number_country_code';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['field'] = 'field_mobile_number_country_code';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number_country_code']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Work number country code */
  $handler->display->display_options['fields']['field_work_number_country_code']['id'] = 'field_work_number_country_code';
  $handler->display->display_options['fields']['field_work_number_country_code']['table'] = 'field_data_field_work_number_country_code';
  $handler->display->display_options['fields']['field_work_number_country_code']['field'] = 'field_work_number_country_code';
  $handler->display->display_options['fields']['field_work_number_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_work_number_country_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_work_number_country_code']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Arbejde */
  $handler->display->display_options['fields']['field_work_number']['id'] = 'field_work_number';
  $handler->display->display_options['fields']['field_work_number']['table'] = 'field_data_field_work_number';
  $handler->display->display_options['fields']['field_work_number']['field'] = 'field_work_number';
  $handler->display->display_options['fields']['field_work_number']['label'] = '';
  $handler->display->display_options['fields']['field_work_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_work_number']['alter']['text'] = '[field_work_number_country_code] [field_work_number]';
  $handler->display->display_options['fields']['field_work_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_work_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_work_number']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_work_number']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_work_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: Work number country code (Norwegian) */
  $handler->display->display_options['fields']['field_work_number_country_code_n']['id'] = 'field_work_number_country_code_n';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['table'] = 'field_data_field_work_number_country_code_n';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['field'] = 'field_work_number_country_code_n';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['label'] = '';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_work_number_country_code_n']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Work number (Norwegian) */
  $handler->display->display_options['fields']['field_work_number_no']['id'] = 'field_work_number_no';
  $handler->display->display_options['fields']['field_work_number_no']['table'] = 'field_data_field_work_number_no';
  $handler->display->display_options['fields']['field_work_number_no']['field'] = 'field_work_number_no';
  $handler->display->display_options['fields']['field_work_number_no']['label'] = '';
  $handler->display->display_options['fields']['field_work_number_no']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_work_number_no']['alter']['text'] = '[field_work_number_country_code_n] [field_work_number_no]';
  $handler->display->display_options['fields']['field_work_number_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_work_number_no']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_work_number_no']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: Mobil */
  $handler->display->display_options['fields']['field_mobile_number']['id'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['table'] = 'field_data_field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['field'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['label'] = '';
  $handler->display->display_options['fields']['field_mobile_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number']['alter']['text'] = '[field_mobile_number_country_code] [field_mobile_number]';
  $handler->display->display_options['fields']['field_mobile_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mobile_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_mobile_number']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_mobile_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['mail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sorteringskriterie: Felt: Name (field_name) */
  $handler->display->display_options['sorts']['field_name_value']['id'] = 'field_name_value';
  $handler->display->display_options['sorts']['field_name_value']['table'] = 'field_data_field_name';
  $handler->display->display_options['sorts']['field_name_value']['field'] = 'field_name_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Felt: Department (field_department) */
  $handler->display->display_options['arguments']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['arguments']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_department_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_department_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_department_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_department_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_department_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_department_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_department_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_department_tid']['validate_options']['vocabularies'] = array(
    'department' => 'department',
  );
  $handler->display->display_options['arguments']['field_department_tid']['validate_options']['type'] = 'convert';
  /* Kontekstuelt filter: Bruger: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['argument'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['uid']['not'] = TRUE;
  /* Kontekstuelt filter: Bruger: Office (field_office) */
  $handler->display->display_options['arguments']['field_office_value']['id'] = 'field_office_value';
  $handler->display->display_options['arguments']['field_office_value']['table'] = 'field_data_field_office';
  $handler->display->display_options['arguments']['field_office_value']['field'] = 'field_office_value';
  $handler->display->display_options['arguments']['field_office_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_office_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_office_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_office_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_office_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_office_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_office_value']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Bruger: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Bruger: Show profile on site (field_show_profile_on_site) */
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['id'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['table'] = 'field_data_field_show_profile_on_site';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['field'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['group'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_department_tid' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Fields: Department (field_department) - tid',
    ),
    'uid' => array(
      'type' => 'user',
      'context' => 'entity:user.picture',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Excluded users',
    ),
    'field_office_value' => array(
      'type' => 'user',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Bruker: Office (field_office)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Single employees */
  $handler = $view->new_display('panel_pane', 'Single employees', 'single_employees');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Bruger: Office */
  $handler->display->display_options['fields']['field_office']['id'] = 'field_office';
  $handler->display->display_options['fields']['field_office']['table'] = 'field_data_field_office';
  $handler->display->display_options['fields']['field_office']['field'] = 'field_office';
  $handler->display->display_options['fields']['field_office']['label'] = '';
  $handler->display->display_options['fields']['field_office']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Felt: Bruger: Billede */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Felt: Felt: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Felt: Felt: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Job title (Norwegian) */
  $handler->display->display_options['fields']['field_job_title_no']['id'] = 'field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['table'] = 'field_data_field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['field'] = 'field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['label'] = '';
  $handler->display->display_options['fields']['field_job_title_no']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_job_title_no']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Mobile number country code */
  $handler->display->display_options['fields']['field_mobile_number_country_code']['id'] = 'field_mobile_number_country_code';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['table'] = 'field_data_field_mobile_number_country_code';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['field'] = 'field_mobile_number_country_code';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number_country_code']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Work number country code */
  $handler->display->display_options['fields']['field_work_number_country_code']['id'] = 'field_work_number_country_code';
  $handler->display->display_options['fields']['field_work_number_country_code']['table'] = 'field_data_field_work_number_country_code';
  $handler->display->display_options['fields']['field_work_number_country_code']['field'] = 'field_work_number_country_code';
  $handler->display->display_options['fields']['field_work_number_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_work_number_country_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_work_number_country_code']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Arbejde */
  $handler->display->display_options['fields']['field_work_number']['id'] = 'field_work_number';
  $handler->display->display_options['fields']['field_work_number']['table'] = 'field_data_field_work_number';
  $handler->display->display_options['fields']['field_work_number']['field'] = 'field_work_number';
  $handler->display->display_options['fields']['field_work_number']['label'] = '';
  $handler->display->display_options['fields']['field_work_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_work_number']['alter']['text'] = '[field_work_number_country_code] [field_work_number]';
  $handler->display->display_options['fields']['field_work_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_work_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_work_number']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_work_number']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_work_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: Work number country code (Norwegian) */
  $handler->display->display_options['fields']['field_work_number_country_code_n']['id'] = 'field_work_number_country_code_n';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['table'] = 'field_data_field_work_number_country_code_n';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['field'] = 'field_work_number_country_code_n';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['label'] = '';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_work_number_country_code_n']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Work number (Norwegian) */
  $handler->display->display_options['fields']['field_work_number_no']['id'] = 'field_work_number_no';
  $handler->display->display_options['fields']['field_work_number_no']['table'] = 'field_data_field_work_number_no';
  $handler->display->display_options['fields']['field_work_number_no']['field'] = 'field_work_number_no';
  $handler->display->display_options['fields']['field_work_number_no']['label'] = '';
  $handler->display->display_options['fields']['field_work_number_no']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_work_number_no']['alter']['text'] = '[field_work_number_country_code_n] [field_work_number_no]';
  $handler->display->display_options['fields']['field_work_number_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_work_number_no']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_work_number_no']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_work_number_no']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_work_number_no']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: Mobil */
  $handler->display->display_options['fields']['field_mobile_number']['id'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['table'] = 'field_data_field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['field'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['label'] = '';
  $handler->display->display_options['fields']['field_mobile_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number']['alter']['text'] = '[field_mobile_number_country_code] [field_mobile_number]';
  $handler->display->display_options['fields']['field_mobile_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mobile_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_mobile_number']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_mobile_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['mail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sorteringskriterie: Parametre: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['sorts']['weight']['argument_number'] = '0';
  $handler->display->display_options['sorts']['weight']['field_type'] = 'users::uid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Bruger: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = TRUE;
  /* Kontekstuelt filter: Bruger: Office (field_office) */
  $handler->display->display_options['arguments']['field_office_value']['id'] = 'field_office_value';
  $handler->display->display_options['arguments']['field_office_value']['table'] = 'field_data_field_office';
  $handler->display->display_options['arguments']['field_office_value']['field'] = 'field_office_value';
  $handler->display->display_options['arguments']['field_office_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_office_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_office_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_office_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_office_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_office_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_office_value']['break_phrase'] = TRUE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'User: Uid',
    ),
    'field_office_value' => array(
      'type' => 'user',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Bruker: Office (field_office)',
    ),
  );

  /* Display: Employees A to Z */
  $handler = $view->new_display('panel_pane', 'Employees A to Z', 'employees_az');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Alfabetisk rækkefølge';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Felt: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[field_name]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sorteringskriterie: Felt: Name (field_name) */
  $handler->display->display_options['sorts']['field_name_value']['id'] = 'field_name_value';
  $handler->display->display_options['sorts']['field_name_value']['table'] = 'field_data_field_name';
  $handler->display->display_options['sorts']['field_name_value']['field'] = 'field_name_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Bruger: Office (field_office) */
  $handler->display->display_options['arguments']['field_office_value']['id'] = 'field_office_value';
  $handler->display->display_options['arguments']['field_office_value']['table'] = 'field_data_field_office';
  $handler->display->display_options['arguments']['field_office_value']['field'] = 'field_office_value';
  $handler->display->display_options['arguments']['field_office_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_office_value']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['field_office_value']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['field_office_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_office_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_office_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_office_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_office_value']['break_phrase'] = TRUE;
  $handler->display->display_options['argument_input'] = array(
    'field_office_value' => array(
      'type' => 'user',
      'context' => 'entity:user.field-office',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Bruker: Office (field_office)',
    ),
  );

  /* Display: Contact person */
  $handler = $view->new_display('panel_pane', 'Contact person', 'employee_contact_person');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2>Vil du vide mere?</h2>';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Bruger: Office */
  $handler->display->display_options['fields']['field_office']['id'] = 'field_office';
  $handler->display->display_options['fields']['field_office']['table'] = 'field_data_field_office';
  $handler->display->display_options['fields']['field_office']['field'] = 'field_office';
  $handler->display->display_options['fields']['field_office']['label'] = '';
  $handler->display->display_options['fields']['field_office']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Felt: Bruger: Billede */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Felt: Felt: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Felt: Felt: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Job title (Norwegian) */
  $handler->display->display_options['fields']['field_job_title_no']['id'] = 'field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['table'] = 'field_data_field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['field'] = 'field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['label'] = '';
  $handler->display->display_options['fields']['field_job_title_no']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_job_title_no']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Mobile number country code */
  $handler->display->display_options['fields']['field_mobile_number_country_code']['id'] = 'field_mobile_number_country_code';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['table'] = 'field_data_field_mobile_number_country_code';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['field'] = 'field_mobile_number_country_code';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number_country_code']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Work number country code */
  $handler->display->display_options['fields']['field_work_number_country_code']['id'] = 'field_work_number_country_code';
  $handler->display->display_options['fields']['field_work_number_country_code']['table'] = 'field_data_field_work_number_country_code';
  $handler->display->display_options['fields']['field_work_number_country_code']['field'] = 'field_work_number_country_code';
  $handler->display->display_options['fields']['field_work_number_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_work_number_country_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_work_number_country_code']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Arbejde */
  $handler->display->display_options['fields']['field_work_number']['id'] = 'field_work_number';
  $handler->display->display_options['fields']['field_work_number']['table'] = 'field_data_field_work_number';
  $handler->display->display_options['fields']['field_work_number']['field'] = 'field_work_number';
  $handler->display->display_options['fields']['field_work_number']['label'] = '';
  $handler->display->display_options['fields']['field_work_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_work_number']['alter']['text'] = '[field_work_number_country_code] [field_work_number]';
  $handler->display->display_options['fields']['field_work_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_work_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_work_number']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_work_number']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_work_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: Work number country code (Norwegian) */
  $handler->display->display_options['fields']['field_work_number_country_code_n']['id'] = 'field_work_number_country_code_n';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['table'] = 'field_data_field_work_number_country_code_n';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['field'] = 'field_work_number_country_code_n';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['label'] = '';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_work_number_country_code_n']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Work number (Norwegian) */
  $handler->display->display_options['fields']['field_work_number_no']['id'] = 'field_work_number_no';
  $handler->display->display_options['fields']['field_work_number_no']['table'] = 'field_data_field_work_number_no';
  $handler->display->display_options['fields']['field_work_number_no']['field'] = 'field_work_number_no';
  $handler->display->display_options['fields']['field_work_number_no']['label'] = '';
  $handler->display->display_options['fields']['field_work_number_no']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_work_number_no']['alter']['text'] = '[field_work_number_country_code_n] [field_work_number_no]';
  $handler->display->display_options['fields']['field_work_number_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_work_number_no']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_work_number_no']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: Mobil */
  $handler->display->display_options['fields']['field_mobile_number']['id'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['table'] = 'field_data_field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['field'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['label'] = '';
  $handler->display->display_options['fields']['field_mobile_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number']['alter']['text'] = '[field_mobile_number_country_code] [field_mobile_number]';
  $handler->display->display_options['fields']['field_mobile_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mobile_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_mobile_number']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_mobile_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['mail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Felt: Department (field_department) */
  $handler->display->display_options['arguments']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['arguments']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_department_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_options']['field'] = 'content_taxonomy::field_department';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_options']['settings'] = array(
    'content_taxonomy_format' => 'tid',
  );
  $handler->display->display_options['arguments']['field_department_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_department_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_department_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_department_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_department_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_department_tid']['validate_options']['vocabularies'] = array(
    'department' => 'department',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Bruger: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Bruger: Show profile on site (field_show_profile_on_site) */
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['id'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['table'] = 'field_data_field_show_profile_on_site';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['field'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['group'] = 1;
  /* Filterkriterie: Bruger: Contact person (field_contact_person) */
  $handler->display->display_options['filters']['field_contact_person_value']['id'] = 'field_contact_person_value';
  $handler->display->display_options['filters']['field_contact_person_value']['table'] = 'field_data_field_contact_person';
  $handler->display->display_options['filters']['field_contact_person_value']['field'] = 'field_contact_person_value';
  $handler->display->display_options['filters']['field_contact_person_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_contact_person_value']['group'] = 1;
  /* Filterkriterie: Bruger: Show contact person (field_show_contact_person) */
  $handler->display->display_options['filters']['field_show_contact_person_value']['id'] = 'field_show_contact_person_value';
  $handler->display->display_options['filters']['field_show_contact_person_value']['table'] = 'field_data_field_show_contact_person';
  $handler->display->display_options['filters']['field_show_contact_person_value']['field'] = 'field_show_contact_person_value';
  $handler->display->display_options['filters']['field_show_contact_person_value']['value'] = array(
    'da' => 'da',
    'nb' => 'nb',
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_department_tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Fields: Department (field_department) - tid',
    ),
  );

  /* Display: Contact person Node */
  $handler = $view->new_display('panel_pane', 'Contact person Node', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2>Vil du vide mere?</h2>';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Opførsel ved ingen resultater: Global: View-område */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['empty'] = TRUE;
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'employees:employee_contact_person';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Bruger: Office */
  $handler->display->display_options['fields']['field_office']['id'] = 'field_office';
  $handler->display->display_options['fields']['field_office']['table'] = 'field_data_field_office';
  $handler->display->display_options['fields']['field_office']['field'] = 'field_office';
  $handler->display->display_options['fields']['field_office']['label'] = '';
  $handler->display->display_options['fields']['field_office']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Felt: Bruger: Billede */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Felt: Felt: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Felt: Felt: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Job title (Norwegian) */
  $handler->display->display_options['fields']['field_job_title_no']['id'] = 'field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['table'] = 'field_data_field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['field'] = 'field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['label'] = '';
  $handler->display->display_options['fields']['field_job_title_no']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_job_title_no']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Mobile number country code */
  $handler->display->display_options['fields']['field_mobile_number_country_code']['id'] = 'field_mobile_number_country_code';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['table'] = 'field_data_field_mobile_number_country_code';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['field'] = 'field_mobile_number_country_code';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_mobile_number_country_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number_country_code']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Work number country code */
  $handler->display->display_options['fields']['field_work_number_country_code']['id'] = 'field_work_number_country_code';
  $handler->display->display_options['fields']['field_work_number_country_code']['table'] = 'field_data_field_work_number_country_code';
  $handler->display->display_options['fields']['field_work_number_country_code']['field'] = 'field_work_number_country_code';
  $handler->display->display_options['fields']['field_work_number_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_work_number_country_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_work_number_country_code']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Arbejde */
  $handler->display->display_options['fields']['field_work_number']['id'] = 'field_work_number';
  $handler->display->display_options['fields']['field_work_number']['table'] = 'field_data_field_work_number';
  $handler->display->display_options['fields']['field_work_number']['field'] = 'field_work_number';
  $handler->display->display_options['fields']['field_work_number']['label'] = '';
  $handler->display->display_options['fields']['field_work_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_work_number']['alter']['text'] = '[field_work_number_country_code] [field_work_number]';
  $handler->display->display_options['fields']['field_work_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_work_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_work_number']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_work_number']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_work_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: Work number country code (Norwegian) */
  $handler->display->display_options['fields']['field_work_number_country_code_n']['id'] = 'field_work_number_country_code_n';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['table'] = 'field_data_field_work_number_country_code_n';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['field'] = 'field_work_number_country_code_n';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['label'] = '';
  $handler->display->display_options['fields']['field_work_number_country_code_n']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_work_number_country_code_n']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Work number (Norwegian) */
  $handler->display->display_options['fields']['field_work_number_no']['id'] = 'field_work_number_no';
  $handler->display->display_options['fields']['field_work_number_no']['table'] = 'field_data_field_work_number_no';
  $handler->display->display_options['fields']['field_work_number_no']['field'] = 'field_work_number_no';
  $handler->display->display_options['fields']['field_work_number_no']['label'] = '';
  $handler->display->display_options['fields']['field_work_number_no']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_work_number_no']['alter']['text'] = '[field_work_number_country_code_n] [field_work_number_no]';
  $handler->display->display_options['fields']['field_work_number_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_work_number_no']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_work_number_no']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: Mobil */
  $handler->display->display_options['fields']['field_mobile_number']['id'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['table'] = 'field_data_field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['field'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['label'] = '';
  $handler->display->display_options['fields']['field_mobile_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number']['alter']['text'] = '[field_mobile_number_country_code] [field_mobile_number]';
  $handler->display->display_options['fields']['field_mobile_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mobile_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_number']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_mobile_number']['type'] = 'pco_site_phonenumber';
  $handler->display->display_options['fields']['field_mobile_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Felt: Bruger: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['mail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sorteringskriterie: Felt: Name (field_name) */
  $handler->display->display_options['sorts']['field_name_value']['id'] = 'field_name_value';
  $handler->display->display_options['sorts']['field_name_value']['table'] = 'field_data_field_name';
  $handler->display->display_options['sorts']['field_name_value']['field'] = 'field_name_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Bruger: Bruger ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '0';
  $handler->display->display_options['filters']['uid_raw']['group'] = 1;
  /* Filterkriterie: Bruger: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 2;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Bruger: Show profile on site (field_show_profile_on_site) */
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['id'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['table'] = 'field_data_field_show_profile_on_site';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['field'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['group'] = 2;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'user',
      'context' => 'entity:user.uid',
      'context_optional' => 1,
      'panel' => '1',
      'fixed' => '',
      'label' => 'User: Uid',
    ),
  );

  /* Display: Side */
  $handler = $view->new_display('page', 'Side', 'feed');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Bruger: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Felt: Bruger: Billede */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Felt: Felt: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Felt: Felt: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Employee description */
  $handler->display->display_options['fields']['field_employee_description']['id'] = 'field_employee_description';
  $handler->display->display_options['fields']['field_employee_description']['table'] = 'field_data_field_employee_description';
  $handler->display->display_options['fields']['field_employee_description']['field'] = 'field_employee_description';
  $handler->display->display_options['fields']['field_employee_description']['label'] = '';
  $handler->display->display_options['fields']['field_employee_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_employee_description']['type'] = 'text_plain';
  /* Felt: Bruger: Job title (Norwegian) */
  $handler->display->display_options['fields']['field_job_title_no']['id'] = 'field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['table'] = 'field_data_field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['field'] = 'field_job_title_no';
  $handler->display->display_options['fields']['field_job_title_no']['label'] = '';
  $handler->display->display_options['fields']['field_job_title_no']['element_label_colon'] = FALSE;
  /* Felt: Bruger: Employee description (Norwegian) */
  $handler->display->display_options['fields']['field_employee_description_no']['id'] = 'field_employee_description_no';
  $handler->display->display_options['fields']['field_employee_description_no']['table'] = 'field_data_field_employee_description_no';
  $handler->display->display_options['fields']['field_employee_description_no']['field'] = 'field_employee_description_no';
  $handler->display->display_options['fields']['field_employee_description_no']['label'] = '';
  $handler->display->display_options['fields']['field_employee_description_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_employee_description_no']['type'] = 'text_plain';
  $handler->display->display_options['path'] = 'employees/feed';

  /* Display: Contact person DK Node ProductPage */
  $handler = $view->new_display('panel_pane', 'Contact person DK Node ProductPage', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Tekstområde */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '[i can call you]';
  $handler->display->display_options['header']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Sidefod: Global: Tekstområde */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '72200199';
  $handler->display->display_options['footer']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Opførsel ved ingen resultater: Global: View-område */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['empty'] = TRUE;
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'employees:panel_pane_3';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Forbindelse: Bruger: Related contact persons (field_related_contact_persons) - reverse */
  $handler->display->display_options['relationships']['reverse_field_related_contact_persons_node']['id'] = 'reverse_field_related_contact_persons_node';
  $handler->display->display_options['relationships']['reverse_field_related_contact_persons_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_related_contact_persons_node']['field'] = 'reverse_field_related_contact_persons_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Bruger: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Felt: Bruger: Billede */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['text'] = '<div class="cta-title"><h2>Ta\' fat i mig!</h2></div>
[picture]';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Felt: Felt: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Felt: Felt: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Indhold: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_related_contact_persons_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Bruger: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 2;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Bruger: Show profile on site (field_show_profile_on_site) */
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['id'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['table'] = 'field_data_field_show_profile_on_site';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['field'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['group'] = 2;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'none',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => 'nothing',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Contact person DK ProductPage */
  $handler = $view->new_display('panel_pane', 'Contact person DK ProductPage', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Bruger: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Felt: Bruger: Billede */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['text'] = '<div class="cta-title"><h2>Ta\' fat i mig!</h2></div>
[picture]';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Felt: Felt: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Felt: Felt: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Felt: Department (field_department) */
  $handler->display->display_options['arguments']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['arguments']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_department_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_options']['field'] = 'content_taxonomy::field_department';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_options']['settings'] = array(
    'content_taxonomy_format' => 'tid',
  );
  $handler->display->display_options['arguments']['field_department_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_department_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_department_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_department_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_department_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_department_tid']['validate_options']['vocabularies'] = array(
    'department' => 'department',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Bruger: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Bruger: Show profile on site (field_show_profile_on_site) */
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['id'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['table'] = 'field_data_field_show_profile_on_site';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['field'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['group'] = 1;
  /* Filterkriterie: Bruger: Contact person (field_contact_person) */
  $handler->display->display_options['filters']['field_contact_person_value']['id'] = 'field_contact_person_value';
  $handler->display->display_options['filters']['field_contact_person_value']['table'] = 'field_data_field_contact_person';
  $handler->display->display_options['filters']['field_contact_person_value']['field'] = 'field_contact_person_value';
  $handler->display->display_options['filters']['field_contact_person_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_contact_person_value']['group'] = 1;
  /* Filterkriterie: Bruger: Show contact person (field_show_contact_person) */
  $handler->display->display_options['filters']['field_show_contact_person_value']['id'] = 'field_show_contact_person_value';
  $handler->display->display_options['filters']['field_show_contact_person_value']['table'] = 'field_data_field_show_contact_person';
  $handler->display->display_options['filters']['field_show_contact_person_value']['field'] = 'field_show_contact_person_value';
  $handler->display->display_options['filters']['field_show_contact_person_value']['value'] = array(
    'da' => 'da',
    'nb' => 'nb',
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_department_tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Fields: Department (field_department) - tid',
    ),
  );

  /* Display: Contact person NO Node ProductPage */
  $handler = $view->new_display('panel_pane', 'Contact person NO Node ProductPage', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Tekstområde */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '[i can call you]';
  $handler->display->display_options['header']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Sidefod: Global: Tekstområde */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '72200199';
  $handler->display->display_options['footer']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Opførsel ved ingen resultater: Global: View-område */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['empty'] = TRUE;
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'employees:panel_pane_5';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Forbindelse: Bruger: Related contact persons (field_related_contact_persons) - reverse */
  $handler->display->display_options['relationships']['reverse_field_related_contact_persons_node']['id'] = 'reverse_field_related_contact_persons_node';
  $handler->display->display_options['relationships']['reverse_field_related_contact_persons_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_related_contact_persons_node']['field'] = 'reverse_field_related_contact_persons_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Bruger: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Felt: Bruger: Billede */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['text'] = '<div class="cta-title"><h2>La oss snakke sammen</h2></div>
[picture] ';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Felt: Felt: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Felt: Felt: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Indhold: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_related_contact_persons_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Bruger: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 2;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Bruger: Show profile on site (field_show_profile_on_site) */
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['id'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['table'] = 'field_data_field_show_profile_on_site';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['field'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['group'] = 2;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'none',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => 'nothing',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Contact person NO ProductPage */
  $handler = $view->new_display('panel_pane', 'Contact person NO ProductPage', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Bruger: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Felt: Bruger: Billede */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['text'] = '<div class="cta-title"><h2>La oss snakke sammen</h2></div>
[picture] ';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Felt: Felt: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Felt: Felt: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Felt: Department (field_department) */
  $handler->display->display_options['arguments']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['arguments']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_department_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_options']['field'] = 'content_taxonomy::field_department';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_options']['settings'] = array(
    'content_taxonomy_format' => 'tid',
  );
  $handler->display->display_options['arguments']['field_department_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_department_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_department_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_department_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_department_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_department_tid']['validate_options']['vocabularies'] = array(
    'department' => 'department',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Bruger: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Bruger: Show profile on site (field_show_profile_on_site) */
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['id'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['table'] = 'field_data_field_show_profile_on_site';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['field'] = 'field_show_profile_on_site_value';
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_show_profile_on_site_value']['group'] = 1;
  /* Filterkriterie: Bruger: Contact person (field_contact_person) */
  $handler->display->display_options['filters']['field_contact_person_value']['id'] = 'field_contact_person_value';
  $handler->display->display_options['filters']['field_contact_person_value']['table'] = 'field_data_field_contact_person';
  $handler->display->display_options['filters']['field_contact_person_value']['field'] = 'field_contact_person_value';
  $handler->display->display_options['filters']['field_contact_person_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_contact_person_value']['group'] = 1;
  /* Filterkriterie: Bruger: Show contact person (field_show_contact_person) */
  $handler->display->display_options['filters']['field_show_contact_person_value']['id'] = 'field_show_contact_person_value';
  $handler->display->display_options['filters']['field_show_contact_person_value']['table'] = 'field_data_field_show_contact_person';
  $handler->display->display_options['filters']['field_show_contact_person_value']['field'] = 'field_show_contact_person_value';
  $handler->display->display_options['filters']['field_show_contact_person_value']['value'] = array(
    'da' => 'da',
    'nb' => 'nb',
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_department_tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Fields: Department (field_department) - tid',
    ),
  );
  $translatables['employees'] = array(
    t('Master'),
    t('Medarbejdere'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('[field_work_number] (arbejde)'),
    t('[field_mobile_number] (mobil)'),
    t('Alle'),
    t('%1'),
    t('Employees list'),
    t('[field_work_number_country_code] [field_work_number]'),
    t('[field_work_number_country_code_n] [field_work_number_no]'),
    t('[field_mobile_number_country_code] [field_mobile_number]'),
    t('View panes'),
    t('Single employees'),
    t('Employees A to Z'),
    t('Alfabetisk rækkefølge'),
    t('[field_name]'),
    t('Contact person'),
    t('<h2>Vil du vide mere?</h2>'),
    t('Contact person Node'),
    t('Side'),
    t('Contact person DK Node ProductPage'),
    t('[i can call you]'),
    t('72200199'),
    t('field_related_contact_persons'),
    t('<div class="cta-title"><h2>Ta\' fat i mig!</h2></div>
[picture]'),
    t('Contact person DK ProductPage'),
    t('Contact person NO Node ProductPage'),
    t('<div class="cta-title"><h2>La oss snakke sammen</h2></div>
[picture] '),
    t('Contact person NO ProductPage'),
  );
  $export['employees'] = $view;

  return $export;
}
