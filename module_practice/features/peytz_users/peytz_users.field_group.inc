<?php
/**
 * @file
 * peytz_users.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function peytz_users_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_account|user|user|form';
  $field_group->group_name = 'group_account';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vertical_tabs';
  $field_group->data = array(
    'label' => 'Account settings',
    'weight' => '36',
    'children' => array(
      0 => 'redirect',
      1 => 'account',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-account field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_account|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal|user|user|form';
  $field_group->group_name = 'group_personal';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vertical_tabs';
  $field_group->data = array(
    'label' => 'Personal information',
    'weight' => '33',
    'children' => array(
      0 => 'field_name',
      1 => 'field_mobile_number',
      2 => 'field_work_number',
      3 => 'field_job_title',
      4 => 'field_employee_description',
      5 => 'field_department',
      6 => 'field_show_profile_on_site',
      7 => 'field_contact_person',
      8 => 'field_image',
      9 => 'field_files',
      10 => 'field_employee_description_no',
      11 => 'field_job_title_no',
      12 => 'field_mobile_number_country_code',
      13 => 'field_office',
      14 => 'field_work_number_country_code',
      15 => 'field_show_contact_person',
      16 => 'field_work_number_country_code_n',
      17 => 'field_work_number_no',
      18 => 'picture',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-personal field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_personal|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_settings|user|user|form';
  $field_group->group_name = 'group_settings';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vertical_tabs';
  $field_group->data = array(
    'label' => 'Settings',
    'weight' => '35',
    'children' => array(
      0 => 'admin_select',
      1 => 'timezone',
      2 => 'overlay_control',
      3 => 'locale',
      4 => 'wysiwyg',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_settings|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social|user|user|form';
  $field_group->group_name = 'group_social';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vertical_tabs';
  $field_group->data = array(
    'label' => 'Social network',
    'weight' => '34',
    'children' => array(
      0 => 'field_linkedin',
      1 => 'field_drupal_org',
      2 => 'field_twitter',
      3 => 'field_github',
      4 => 'googleanalytics',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-social field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_social|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vertical_tabs|user|user|form';
  $field_group->group_name = 'group_vertical_tabs';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vertical tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_account',
      1 => 'group_settings',
      2 => 'group_personal',
      3 => 'group_social',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-vertical-tabs field-group-tabs',
      ),
    ),
  );
  $export['group_vertical_tabs|user|user|form'] = $field_group;

  return $export;
}
