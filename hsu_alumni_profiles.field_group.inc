<?php
/**
 * @file
 * hsu_alumni_profiles.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function hsu_alumni_profiles_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about_you|node|alumni_profile|form';
  $field_group->group_name = 'group_about_you';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alumni_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About You',
    'weight' => '2',
    'children' => array(
      0 => 'field_profile_photo',
      1 => 'field_profile_fname',
      2 => 'field_profile_lname',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-about-you field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_about_you|node|alumni_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hsu_experience|node|alumni_profile|form';
  $field_group->group_name = 'group_hsu_experience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alumni_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Your HSU Experience',
    'weight' => '5',
    'children' => array(
      0 => 'field_profile_student_advice',
      1 => 'field_profile_program_choose',
      2 => 'field_profile_program_prepare',
      3 => 'field_profile_program_enjoy',
      4 => 'field_profile_program_recommend',
      5 => 'field_profile_comments',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-hsu-experience field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_hsu_experience|node|alumni_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_job_info|node|alumni_profile|form';
  $field_group->group_name = 'group_profile_job_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alumni_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About Your Job',
    'weight' => '4',
    'children' => array(
      0 => 'field_profile_job_title',
      1 => 'field_profile_employer',
      2 => 'field_profile_job_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-profile-job-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_profile_job_info|node|alumni_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_you_degree|node|alumni_profile|form';
  $field_group->group_name = 'group_you_degree';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alumni_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Your Degree',
    'weight' => '3',
    'children' => array(
      0 => 'field_profile_year_graduated',
      1 => 'field_profile_degree',
      2 => 'field_profile_concentration',
      3 => 'field_profile_alternative_degree',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-you-degree field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_you_degree|node|alumni_profile|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('About You');
  t('About Your Job');
  t('Your Degree');
  t('Your HSU Experience');

  return $field_groups;
}
