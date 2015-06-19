<?php
/**
 * @file
 * content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function content_types_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blog_related_webform|node|blog|form';
  $field_group->group_name = 'group_blog_related_webform';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Blog Related Webform',
    'weight' => '11',
    'children' => array(
      0 => 'field_related_webform',
      1 => 'field_webform_user_copy_email',
      2 => 'field_webform_title',
      3 => 'field_webform_description',
      4 => 'field_webform_confirmation_messa',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Blog Related Webform',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-blog-related-webform field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_blog_related_webform|node|blog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_morgeninspiration|node|blog|form';
  $field_group->group_name = 'group_morgeninspiration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Morgeninspiration Indstillinger',
    'weight' => '20',
    'children' => array(
      0 => 'field_morgeninspiration',
      1 => 'field_date_for_event',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-morgeninspiration field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_morgeninspiration|node|blog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_webform|node|product|form';
  $field_group->group_name = 'group_related_webform';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Webform',
    'weight' => '12',
    'children' => array(
      0 => 'field_related_webform',
      1 => 'field_webform_confirmation_messa',
      2 => 'field_webform_description',
      3 => 'field_webform_title',
      4 => 'field_webform_user_copy_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Related Webform',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-related-webform field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_related_webform|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_terms|node|blog|form';
  $field_group->group_name = 'group_taxonomy_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Category/Department',
    'weight' => '2',
    'children' => array(
      0 => 'field_category',
      1 => 'field_department',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-taxonomy-terms field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_taxonomy_terms|node|blog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_terms|node|case|form';
  $field_group->group_name = 'group_taxonomy_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'case';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Category/Department',
    'weight' => '2',
    'children' => array(
      0 => 'field_department',
      1 => 'field_category',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-taxonomy-terms field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_taxonomy_terms|node|case|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_terms|node|product|form';
  $field_group->group_name = 'group_taxonomy_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Category/Department',
    'weight' => '2',
    'children' => array(
      0 => 'field_department',
      1 => 'field_category',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-taxonomy-terms field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_taxonomy_terms|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_terms|node|webform|form';
  $field_group->group_name = 'group_taxonomy_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Category/Department',
    'weight' => '2',
    'children' => array(
      0 => 'field_category',
      1 => 'field_department',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-taxonomy-terms field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_taxonomy_terms|node|webform|form'] = $field_group;

  return $export;
}
