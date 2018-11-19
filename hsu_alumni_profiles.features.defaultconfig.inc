<?php
/**
 * @file
 * hsu_alumni_profiles.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function hsu_alumni_profiles_defaultconfig_features() {
  return array(
    'hsu_alumni_profiles' => array(
      'feeds_importer_default' => 'feeds_importer_default',
      'field_default_fields' => 'field_default_fields',
      'field_group_info' => 'field_group_info',
      'panelizer_defaults' => 'panelizer_defaults',
      'strongarm' => 'strongarm',
      'user_default_permissions' => 'user_default_permissions',
      'views_default_views' => 'views_default_views',
    ),
  );
}

/**
 * Implements hook_defaultconfig_feeds_importer_default().
 */
function hsu_alumni_profiles_defaultconfig_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'profile_alumni';
  $feeds_importer->config = array(
    'name' => 'Alumni profile',
    'description' => 'Pulling alumni profiles from humboldt.edu',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 1,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => 'http',
        'accept_invalid_cert' => 0,
        'cache_http_result' => 1,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExJsonPath',
      'config' => array(
        'context' => array(
          'value' => '$.[*].profile.',
        ),
        'sources' => array(
          'guid' => array(
            'name' => 'GUID',
            'value' => 'nid',
            'debug' => 0,
            'weight' => '0',
          ),
          'first_name' => array(
            'name' => 'First name',
            'value' => 'field_first_name',
            'debug' => 0,
            'weight' => '1',
          ),
          'last_name' => array(
            'name' => 'Last name',
            'value' => 'field_last_name',
            'debug' => 0,
            'weight' => '2',
          ),
          'grad_year' => array(
            'name' => 'Grad year',
            'value' => 'field_year',
            'debug' => 0,
            'weight' => '3',
          ),
          'major_program' => array(
            'name' => 'Major/Program',
            'value' => 'field_major_program',
            'debug' => 0,
            'weight' => '4',
          ),
          'major_program_other' => array(
            'name' => 'Alternative Major/Program',
            'value' => 'field_alumni_program_other',
            'debug' => 0,
            'weight' => '5',
          ),
          'concentration_option' => array(
            'name' => 'Concentration/option',
            'value' => 'fieldfield_alumni_concentration_opt',
            'debug' => 0,
            'weight' => '6',
          ),
          'degree_or_credential' => array(
            'name' => 'Degree or credential',
            'value' => 'field_program_type_single_select',
            'debug' => 0,
            'weight' => '7',
          ),
          'photo' => array(
            'name' => 'Photo src',
            'value' => 'field_photo_private.src',
            'debug' => 0,
            'weight' => '8',
          ),
          'photo_alt' => array(
            'name' => 'Photo alt',
            'value' => 'field_photo_private.alt',
            'debug' => 0,
            'weight' => '9',
          ),
          'job_title' => array(
            'name' => 'Job title',
            'value' => 'field_job_title',
            'debug' => 0,
            'weight' => '10',
          ),
          'job_description' => array(
            'name' => 'Job description',
            'value' => 'field_description',
            'debug' => 0,
            'weight' => '11',
          ),
          'employer' => array(
            'name' => 'Employer',
            'value' => 'field_employer',
            'debug' => 0,
            'weight' => '12',
          ),
          'employer_url' => array(
            'name' => 'Employer URL',
            'value' => 'field_employer_website',
            'debug' => 0,
            'weight' => '13',
          ),
          'why_program_chosen' => array(
            'name' => 'Why program chosen',
            'value' => 'field_alumni_program_choose',
            'debug' => 0,
            'weight' => '14',
          ),
          'how_program_prepared' => array(
            'name' => 'How program prepared',
            'value' => 'field_alumni_program_prepare',
            'debug' => 0,
            'weight' => '15',
          ),
          'what_enjoyed' => array(
            'name' => 'What enjoyed',
            'value' => 'field_alumni_program_enjoy',
            'debug' => 0,
            'weight' => '16',
          ),
          'student_advice' => array(
            'name' => 'Student advice',
            'value' => 'field_alumni_program_recommend',
            'debug' => 0,
            'weight' => '17',
          ),
          'comments' => array(
            'name' => 'Comments',
            'value' => 'field_comments',
            'debug' => 0,
            'weight' => '18',
          ),
          'submitted_date' => array(
            'name' => 'Submitted Date',
            'value' => 'created',
            'debug' => 0,
            'weight' => '19',
          ),
        ),
        'display_errors' => 0,
        'debug_mode' => 0,
        'source_encoding' => array(
          0 => 'auto',
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'first_name',
            'target' => 'field_profile_fname',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'last_name',
            'target' => 'field_profile_lname',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'grad_year',
            'target' => 'field_profile_year_graduated:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'degree_or_credential',
            'target' => 'field_profile_degree',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'major_program_other',
            'target' => 'field_profile_alternative_degree',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'concentration_option',
            'target' => 'field_profile_concentration',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'job_title',
            'target' => 'field_profile_job_title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'employer',
            'target' => 'field_profile_employer:title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'employer_url',
            'target' => 'field_profile_employer:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'job_description',
            'target' => 'field_profile_job_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'student_advice',
            'target' => 'field_profile_student_advice',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'photo',
            'target' => 'field_profile_photo:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'photo_alt',
            'target' => 'field_profile_photo:alt',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'submitted_date',
            'target' => 'field_profile_submitted_date',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'alumni_profile',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '10800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['profile_alumni'] = $feeds_importer;

  return $export;
}

/**
 * Implements hook_defaultconfig_field_default_fields().
 */
function hsu_alumni_profiles_defaultconfig_field_default_fields() {
  $fields = array();

  // Exported field: 'node-alumni_profile-field_profile_alternative_degree'.
  $fields['node-alumni_profile-field_profile_alternative_degree'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_alternative_degree',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 15,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_alternative_degree',
      'label' => 'Alternative Degree',
      'required' => 0,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 9,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_comments'.
  $fields['node-alumni_profile-field_profile_comments'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_comments',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 14,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_comments',
      'label' => 'Other comments?',
      'required' => 0,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 19,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_concentration'.
  $fields['node-alumni_profile-field_profile_concentration'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_concentration',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 3,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_concentration',
      'label' => 'Concentration',
      'required' => 0,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 10,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_degree'.
  $fields['node-alumni_profile-field_profile_degree'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_degree',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => 'Keep it short. Please expand on minors and concentrations in the main job descriptions field if necessary.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 4,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_degree',
      'label' => 'Degree or credential',
      'required' => 1,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 8,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_employer'.
  $fields['node-alumni_profile-field_profile_employer'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_employer',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => 0,
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => 0,
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => 5,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_employer',
      'label' => 'Employer',
      'required' => 1,
      'settings' => array(
        'absolute_url' => 1,
        'attributes' => array(
          'class' => '',
          'configurable_class' => 0,
          'configurable_title' => 0,
          'rel' => 'nofollow',
          'target' => 'default',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'rel_remove' => 'default',
        'title' => 'required',
        'title_label_use_field_label' => 0,
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 'optional',
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => 7,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_fname'.
  $fields['node-alumni_profile-field_profile_fname'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_fname',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 6,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_fname',
      'label' => 'First name',
      'required' => 1,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 4,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_job_description'.
  $fields['node-alumni_profile-field_profile_job_description'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_job_description',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 8,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_job_description',
      'label' => 'Job description',
      'required' => 0,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 6,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_job_title'.
  $fields['node-alumni_profile-field_profile_job_title'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_job_title',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => 'List your current job title. Keep it short. You can expand on the title in the Job Description field if necessary. ',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_job_title',
      'label' => 'Job Title',
      'required' => 0,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 5,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_lname'.
  $fields['node-alumni_profile-field_profile_lname'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_lname',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 7,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_lname',
      'label' => 'Last name',
      'required' => 1,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 5,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_photo'.
  $fields['node-alumni_profile-field_profile_photo'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_photo',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => 0,
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => 0,
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'deleted' => 0,
      'description' => 'Minimum height or width is 300px and max is 900px',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'file_entity',
          'settings' => array(
            'file_view_mode' => 'default',
          ),
          'type' => 'file_rendered',
          'weight' => 0,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_photo',
      'label' => 'Photo',
      'required' => 1,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 217,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'filefield_paths' => array(
          'active_updating' => 0,
          'file_name' => array(
            'options' => array(
              'pathauto' => 0,
              'slashes' => 0,
              'transliterate' => 0,
            ),
            'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
          ),
          'file_path' => array(
            'options' => array(
              'pathauto' => 0,
              'slashes' => 0,
              'transliterate' => 0,
            ),
            'value' => '',
          ),
          'redirect' => 0,
          'retroactive_update' => 0,
        ),
        'filefield_paths_enabled' => 1,
        'max_filesize' => '1 MB',
        'max_resolution' => '900x900',
        'min_resolution' => '300x300',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'private' => 0,
            'public' => 'public',
            'vimeo' => 0,
            'youtube' => 0,
          ),
          'allowed_types' => array(
            'audio' => 0,
            'document' => 0,
            'image' => 'image',
            'video' => 0,
          ),
          'browser_plugins' => array(
            'media_default--media_browser_1' => 0,
            'media_default--media_browser_my_files' => 0,
            'media_internet' => 'media_internet',
            'upload' => 'upload',
          ),
          'manualcrop_crop_info' => 1,
          'manualcrop_default_crop_area' => 1,
          'manualcrop_enable' => 0,
          'manualcrop_inline_crop' => 0,
          'manualcrop_instant_crop' => FALSE,
          'manualcrop_instant_preview' => 1,
          'manualcrop_keyboard' => 1,
          'manualcrop_maximize_default_crop_area' => 0,
          'manualcrop_require_cropping' => array(),
          'manualcrop_styles_list' => array(),
          'manualcrop_styles_mode' => 'include',
          'manualcrop_thumblist' => 0,
        ),
        'type' => 'media_generic',
        'weight' => 6,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_program_choose'.
  $fields['node-alumni_profile-field_profile_program_choose'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_program_choose',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 10,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_program_choose',
      'label' => 'Why did you choose this program?',
      'required' => 0,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 14,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_program_enjoy'.
  $fields['node-alumni_profile-field_profile_program_enjoy'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_program_enjoy',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 12,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_program_enjoy',
      'label' => 'What did you enjoy most about the program?',
      'required' => 0,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 16,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_program_prepare'.
  $fields['node-alumni_profile-field_profile_program_prepare'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_program_prepare',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 11,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_program_prepare',
      'label' => 'How did this program prepare you for your job?',
      'required' => 0,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 15,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_program_recommend'.
  $fields['node-alumni_profile-field_profile_program_recommend'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_program_recommend',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 13,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_program_recommend',
      'label' => 'What would you say to prospective students who are thinking about applying to this program?',
      'required' => 0,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 17,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_student_advice'.
  $fields['node-alumni_profile-field_profile_student_advice'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_student_advice',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 9,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_student_advice',
      'label' => 'Advice for students',
      'required' => 0,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 18,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_submitted_date'.
  $fields['node-alumni_profile-field_profile_submitted_date'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_submitted_date',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 16,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_submitted_date',
      'label' => 'Submitted',
      'required' => 0,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 20,
      ),
    ),
  );

  // Exported field: 'node-alumni_profile-field_profile_year_graduated'.
  $fields['node-alumni_profile-field_profile_year_graduated'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_profile_year_graduated',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => 0,
      'module' => 'date',
      'settings' => array(
        'cache_count' => 4,
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 0,
          'hour' => 0,
          'minute' => 0,
          'month' => 0,
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => 0,
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'alumni_profile',
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_remaining_days' => FALSE,
          ),
          'type' => 'date_default',
          'weight' => 1,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_year_graduated',
      'label' => 'Year Graduated',
      'required' => 0,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'same',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'increment' => 15,
          'input_format' => 'M j Y - g:i:sa',
          'input_format_custom' => '',
          'label_position' => 'above',
          'no_fieldset' => 0,
          'text_parts' => array(),
          'year_range' => '-10:+10',
        ),
        'type' => 'date_select',
        'weight' => 7,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Advice for students');
  t('Alternative Degree');
  t('Concentration');
  t('Degree or credential');
  t('Employer');
  t('First name');
  t('How did this program prepare you for your job?');
  t('Job Title');
  t('Job description');
  t('Keep it short. Please expand on minors and concentrations in the main job descriptions field if necessary.');
  t('Last name');
  t('List your current job title. Keep it short. You can expand on the title in the Job Description field if necessary. ');
  t('Minimum height or width is 300px and max is 900px');
  t('Other comments?');
  t('Photo');
  t('Submitted');
  t('What did you enjoy most about the program?');
  t('What would you say to prospective students who are thinking about applying to this program?');
  t('Why did you choose this program?');
  t('Year Graduated');

  return $fields;
}

/**
 * Implements hook_defaultconfig_field_group_info().
 */
function openhsu_alumni_profiles_defaultconfig_field_group_info() {
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

/**
 * Implements hook_defaultconfig_panelizer_defaults().
 */
function openhsu_alumni_profiles_defaultconfig_panelizer_defaults() {
  $export = array();

  return $export;
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function openhsu_alumni_profiles_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_alumni_profile';
  $strongarm->value = '1';
  $export['ant_alumni_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_alumni_profile';
  $strongarm->value = '[node:field_profile_fname] [node:field_profile_lname]';
  $export['ant_pattern_alumni_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_alumni_profile';
  $strongarm->value = 0;
  $export['ant_php_alumni_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_alumni_profile';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_alumni_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_alumni_profile';
  $strongarm->value = '0';
  $export['node_preview_alumni_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_alumni_profile';
  $strongarm->value = 0;
  $export['node_submitted_alumni_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_alumni_profile';
  $strongarm->value = array(
    'status' => 1,
    'help' => '',
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'substitute' => '',
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'featured' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_alumni_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_alumni_profile_pattern';
  $strongarm->value = 'alumni-profile/[node:title]';
  $export['pathauto_node_alumni_profile_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_alumni_profile';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_alumni_profile'] = $strongarm;

  return $export;
}

/**
 * Implements hook_defaultconfig_user_default_permissions().
 */
function openhsu_alumni_profiles_defaultconfig_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer panelizer node alumni_profile breadcrumbs'.
  $permissions['administer panelizer node alumni_profile breadcrumbs'] = array(
    'name' => 'administer panelizer node alumni_profile breadcrumbs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node alumni_profile content'.
  $permissions['administer panelizer node alumni_profile content'] = array(
    'name' => 'administer panelizer node alumni_profile content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node alumni_profile context'.
  $permissions['administer panelizer node alumni_profile context'] = array(
    'name' => 'administer panelizer node alumni_profile context',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node alumni_profile defaults'.
  $permissions['administer panelizer node alumni_profile defaults'] = array(
    'name' => 'administer panelizer node alumni_profile defaults',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node alumni_profile layout'.
  $permissions['administer panelizer node alumni_profile layout'] = array(
    'name' => 'administer panelizer node alumni_profile layout',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node alumni_profile overview'.
  $permissions['administer panelizer node alumni_profile overview'] = array(
    'name' => 'administer panelizer node alumni_profile overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node alumni_profile settings'.
  $permissions['administer panelizer node alumni_profile settings'] = array(
    'name' => 'administer panelizer node alumni_profile settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'clear profile_alumni feeds'.
  $permissions['clear profile_alumni feeds'] = array(
    'name' => 'clear profile_alumni feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'create alumni_profile content'.
  $permissions['create alumni_profile content'] = array(
    'name' => 'create alumni_profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'import profile_alumni feeds'.
  $permissions['import profile_alumni feeds'] = array(
    'name' => 'import profile_alumni feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock profile_alumni feeds'.
  $permissions['unlock profile_alumni feeds'] = array(
    'name' => 'unlock profile_alumni feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  return $permissions;
}

/**
 * Implements hook_defaultconfig_views_default_views().
 */
function openhsu_alumni_profiles_defaultconfig_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'alumni_profiles';
  $view->description = 'Homepage and internal page views';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Alumni Profiles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Degree or credential */
  $handler->display->display_options['fields']['field_profile_degree']['id'] = 'field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['table'] = 'field_data_field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['field'] = 'field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['label'] = '';
  $handler->display->display_options['fields']['field_profile_degree']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_degree']['delta_offset'] = '0';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description_alumni_updates']['id'] = 'field_description_alumni_updates';
  $handler->display->display_options['fields']['field_description_alumni_updates']['table'] = 'field_data_field_description_alumni_updates';
  $handler->display->display_options['fields']['field_description_alumni_updates']['field'] = 'field_description_alumni_updates';
  $handler->display->display_options['fields']['field_description_alumni_updates']['label'] = '';
  $handler->display->display_options['fields']['field_description_alumni_updates']['element_label_colon'] = FALSE;
  /* Field: Content: Employer */
  $handler->display->display_options['fields']['field_profile_employer']['id'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['table'] = 'field_data_field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['field'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['label'] = '';
  $handler->display->display_options['fields']['field_profile_employer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_employer']['click_sort_column'] = 'url';
  /* Field: Content: Job Title */
  $handler->display->display_options['fields']['field_profile_job_title']['id'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['table'] = 'field_data_field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['field'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_job_title']['element_label_colon'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Profile Image */
  $handler->display->display_options['fields']['field_hsu_people_profile_image']['id'] = 'field_hsu_people_profile_image';
  $handler->display->display_options['fields']['field_hsu_people_profile_image']['table'] = 'field_data_field_hsu_people_profile_image';
  $handler->display->display_options['fields']['field_hsu_people_profile_image']['field'] = 'field_hsu_people_profile_image';
  $handler->display->display_options['fields']['field_hsu_people_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_hsu_people_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hsu_people_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_hsu_people_profile_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Year Graduated */
  $handler->display->display_options['fields']['field_profile_year_graduated']['id'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['table'] = 'field_data_field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['field'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['label'] = '';
  $handler->display->display_options['fields']['field_profile_year_graduated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_year_graduated']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Full-width dark */
  $handler = $view->new_display('panel_pane', 'Full-width dark', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'alumni-view-full-width dark';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="alumni-full-width-title"><h4 class="title-text">Featured Alumni Profile</h4></div>';
  $handler->display->display_options['header']['area']['format'] = 'panopoly_wysiwyg_text';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['format'] = 'panopoly_wysiwyg_text';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_profile_fname']['id'] = 'field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['table'] = 'field_data_field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['field'] = 'field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['label'] = '';
  $handler->display->display_options['fields']['field_profile_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_fname']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Year Graduated */
  $handler->display->display_options['fields']['field_profile_year_graduated']['id'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['table'] = 'field_data_field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['field'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['label'] = '';
  $handler->display->display_options['fields']['field_profile_year_graduated']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_year_graduated']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_year_graduated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_year_graduated']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Degree or credential */
  $handler->display->display_options['fields']['field_profile_degree']['id'] = 'field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['table'] = 'field_data_field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['field'] = 'field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['label'] = '';
  $handler->display->display_options['fields']['field_profile_degree']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_degree']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_degree']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_degree']['delta_offset'] = '0';
  /* Field: Content: Job Title */
  $handler->display->display_options['fields']['field_profile_job_title']['id'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['table'] = 'field_data_field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['field'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_job_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_job_title']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_job_title']['element_label_colon'] = FALSE;
  /* Field: Content: Job description */
  $handler->display->display_options['fields']['field_profile_job_description']['id'] = 'field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['table'] = 'field_data_field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['field'] = 'field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['label'] = '';
  $handler->display->display_options['fields']['field_profile_job_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_job_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_job_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_job_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_profile_job_description']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Content: Employer */
  $handler->display->display_options['fields']['field_profile_employer']['id'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['table'] = 'field_data_field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['field'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['label'] = '';
  $handler->display->display_options['fields']['field_profile_employer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_employer']['alter']['text'] = '<a href="[field_profile_employer-url]">[field_profile_employer-title] &nbsp;<i class="fa fa-external-link" aria-hidden="true"></i></a>';
  $handler->display->display_options['fields']['field_profile_employer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_employer']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_profile_employer']['type'] = 'link_title_plain';
  /* Field: Content: Title (Rewritten for button) */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['ui_name'] = 'Content: Title (Rewritten for button)';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[field_profile_fname]\'s Profile &raquo;';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '[title]';
  $handler->display->display_options['fields']['title_1']['alter']['link_class'] = 'btn btn-primary btn-block';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="row">
  <div class="col-xs-4">
    <a href="/node/[nid]">[field_profile_photo]</a>
  </div>
  <div class="col-xs-8">
    <h3 style="text-align:center"><a href="/node/[nid]">[title], [field_profile_year_graduated]</a></h3>
    <h5>[field_profile_job_title], [field_profile_employer]</h5>
    <p>[field_profile_job_description]</p>
    <div class="row"><div class="col-lg-4 col-md-5"><p>[title_1]</p></div></div>
   <div><p><a href="/alumni-profiles" >Other Alumni Profiles &raquo;</a></p></div>
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'alumni_profile' => 'alumni_profile',
  );

  /* Display: Full-width light */
  $handler = $view->new_display('panel_pane', 'Full-width light', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'alumni-view-full-width light';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="alumni-full-width-title"><h4 class="title-text">Featured Alumni Profile</h4></div>';
  $handler->display->display_options['header']['area']['format'] = 'panopoly_wysiwyg_text';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['format'] = 'panopoly_wysiwyg_text';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_profile_fname']['id'] = 'field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['table'] = 'field_data_field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['field'] = 'field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['label'] = '';
  $handler->display->display_options['fields']['field_profile_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_fname']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Year Graduated */
  $handler->display->display_options['fields']['field_profile_year_graduated']['id'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['table'] = 'field_data_field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['field'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['label'] = '';
  $handler->display->display_options['fields']['field_profile_year_graduated']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_year_graduated']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_year_graduated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_year_graduated']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Degree or credential */
  $handler->display->display_options['fields']['field_profile_degree']['id'] = 'field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['table'] = 'field_data_field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['field'] = 'field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['label'] = '';
  $handler->display->display_options['fields']['field_profile_degree']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_degree']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_degree']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_degree']['delta_offset'] = '0';
  /* Field: Content: Job Title */
  $handler->display->display_options['fields']['field_profile_job_title']['id'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['table'] = 'field_data_field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['field'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_job_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_job_title']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_job_title']['element_label_colon'] = FALSE;
  /* Field: Content: Job description */
  $handler->display->display_options['fields']['field_profile_job_description']['id'] = 'field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['table'] = 'field_data_field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['field'] = 'field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['label'] = '';
  $handler->display->display_options['fields']['field_profile_job_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_job_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_job_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_job_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_profile_job_description']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Content: Employer */
  $handler->display->display_options['fields']['field_profile_employer']['id'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['table'] = 'field_data_field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['field'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['label'] = '';
  $handler->display->display_options['fields']['field_profile_employer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_employer']['alter']['text'] = '<a href="[field_profile_employer-url]">[field_profile_employer-title] &nbsp;<i class="fa fa-external-link" aria-hidden="true"></i></a>';
  $handler->display->display_options['fields']['field_profile_employer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_employer']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_profile_employer']['type'] = 'link_title_plain';
  /* Field: Content: Title (Rewritten for button) */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['ui_name'] = 'Content: Title (Rewritten for button)';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[field_profile_fname]\'s Profile &raquo;';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '[title]';
  $handler->display->display_options['fields']['title_1']['alter']['link_class'] = 'btn btn-primary btn-block';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="row">
  <div class="col-xs-4">
    <a href="/node/[nid]">[field_profile_photo]</a>
  </div>
  <div class="col-xs-8">
    <h3 style="text-align:center"><a href="/node/[nid]">[title], [field_profile_year_graduated]</a></h3>
    <h5>[field_profile_job_title], [field_profile_employer]</h5>
    <p>[field_profile_job_description]</p>
    <div class="row"><div class="col-lg-4 col-md-5"><p>[title_1]</p></div></div>
   <div><p><a href="/alumni-profiles" >Other Alumni Profiles &raquo;</a></p></div>
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'alumni_profile' => 'alumni_profile',
  );

  /* Display: two-up / half pane  */
  $handler = $view->new_display('panel_pane', 'two-up / half pane ', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'alumni-profile-view-cards clearfix row two-up';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-sm-6 col-lg-6';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_profile_fname']['id'] = 'field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['table'] = 'field_data_field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['field'] = 'field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['label'] = '';
  $handler->display->display_options['fields']['field_profile_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_fname']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '[field_profile_fname]\'s Profile &raquo;';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['link_class'] = 'btn btn-primary btn-block';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Year Graduated */
  $handler->display->display_options['fields']['field_profile_year_graduated']['id'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['table'] = 'field_data_field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['field'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['label'] = '';
  $handler->display->display_options['fields']['field_profile_year_graduated']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_year_graduated']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_year_graduated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_year_graduated']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Alternative Degree */
  $handler->display->display_options['fields']['field_profile_alternative_degree']['id'] = 'field_profile_alternative_degree';
  $handler->display->display_options['fields']['field_profile_alternative_degree']['table'] = 'field_data_field_profile_alternative_degree';
  $handler->display->display_options['fields']['field_profile_alternative_degree']['field'] = 'field_profile_alternative_degree';
  $handler->display->display_options['fields']['field_profile_alternative_degree']['label'] = '';
  $handler->display->display_options['fields']['field_profile_alternative_degree']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_alternative_degree']['element_label_colon'] = FALSE;
  /* Field: Content: Degree or credential */
  $handler->display->display_options['fields']['field_profile_degree']['id'] = 'field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['table'] = 'field_data_field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['field'] = 'field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['label'] = '';
  $handler->display->display_options['fields']['field_profile_degree']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_degree']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_degree']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_degree']['empty'] = '[field_profile_alternative_degree]';
  $handler->display->display_options['fields']['field_profile_degree']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_profile_degree']['delta_offset'] = '0';
  /* Field: Content: Concentration */
  $handler->display->display_options['fields']['field_profile_concentration']['id'] = 'field_profile_concentration';
  $handler->display->display_options['fields']['field_profile_concentration']['table'] = 'field_data_field_profile_concentration';
  $handler->display->display_options['fields']['field_profile_concentration']['field'] = 'field_profile_concentration';
  $handler->display->display_options['fields']['field_profile_concentration']['label'] = '';
  $handler->display->display_options['fields']['field_profile_concentration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_concentration']['element_label_colon'] = FALSE;
  /* Field: Content: Job Title */
  $handler->display->display_options['fields']['field_profile_job_title']['id'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['table'] = 'field_data_field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['field'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_job_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_job_title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_profile_job_title']['element_label_colon'] = FALSE;
  /* Field: Content: Employer */
  $handler->display->display_options['fields']['field_profile_employer']['id'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['table'] = 'field_data_field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['field'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['label'] = '';
  $handler->display->display_options['fields']['field_profile_employer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_employer']['alter']['text'] = '<a href="[field_profile_employer-url]">[field_profile_employer-title] &nbsp;<i class="fa fa-external-link" aria-hidden="true"></i></a>';
  $handler->display->display_options['fields']['field_profile_employer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_employer']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_profile_employer']['type'] = 'link_title_plain';
  /* Field: Content: Job description */
  $handler->display->display_options['fields']['field_profile_job_description']['id'] = 'field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['table'] = 'field_data_field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['field'] = 'field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['label'] = '';
  $handler->display->display_options['fields']['field_profile_job_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_job_description']['element_label_colon'] = FALSE;
  /* Field: Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="alumni-card">
<div class="alumni-card-photo">[field_profile_photo]</div>
<div class="alumni-card-info"><p>Class of [field_profile_year_graduated]</p>
    <h4><srong>[title]</strong></h4>
    <p><strong>[field_profile_job_title],</strong><br>
    [field_profile_employer]</p>
</div>
<div>[view_node]</div>

</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'alumni_profile' => 'alumni_profile',
  );

  /* Display: four-up / full width */
  $handler = $view->new_display('panel_pane', 'four-up / full width', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'alumni-profile-view-cards clearfix row four-up';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-sm-6 col-md-3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_profile_fname']['id'] = 'field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['table'] = 'field_data_field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['field'] = 'field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['label'] = '';
  $handler->display->display_options['fields']['field_profile_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_fname']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '[field_profile_fname]\'s Profile &raquo;';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['link_class'] = 'btn btn-primary btn-block';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Year Graduated */
  $handler->display->display_options['fields']['field_profile_year_graduated']['id'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['table'] = 'field_data_field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['field'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['label'] = '';
  $handler->display->display_options['fields']['field_profile_year_graduated']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_year_graduated']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_year_graduated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_year_graduated']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Alternative Degree */
  $handler->display->display_options['fields']['field_profile_alternative_degree']['id'] = 'field_profile_alternative_degree';
  $handler->display->display_options['fields']['field_profile_alternative_degree']['table'] = 'field_data_field_profile_alternative_degree';
  $handler->display->display_options['fields']['field_profile_alternative_degree']['field'] = 'field_profile_alternative_degree';
  $handler->display->display_options['fields']['field_profile_alternative_degree']['label'] = '';
  $handler->display->display_options['fields']['field_profile_alternative_degree']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_alternative_degree']['element_label_colon'] = FALSE;
  /* Field: Content: Degree or credential */
  $handler->display->display_options['fields']['field_profile_degree']['id'] = 'field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['table'] = 'field_data_field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['field'] = 'field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['label'] = '';
  $handler->display->display_options['fields']['field_profile_degree']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_degree']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_degree']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_degree']['empty'] = '[field_profile_alternative_degree]';
  $handler->display->display_options['fields']['field_profile_degree']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_profile_degree']['delta_offset'] = '0';
  /* Field: Content: Concentration */
  $handler->display->display_options['fields']['field_profile_concentration']['id'] = 'field_profile_concentration';
  $handler->display->display_options['fields']['field_profile_concentration']['table'] = 'field_data_field_profile_concentration';
  $handler->display->display_options['fields']['field_profile_concentration']['field'] = 'field_profile_concentration';
  $handler->display->display_options['fields']['field_profile_concentration']['label'] = '';
  $handler->display->display_options['fields']['field_profile_concentration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_concentration']['element_label_colon'] = FALSE;
  /* Field: Content: Job Title */
  $handler->display->display_options['fields']['field_profile_job_title']['id'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['table'] = 'field_data_field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['field'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_job_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_job_title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_profile_job_title']['element_label_colon'] = FALSE;
  /* Field: Content: Employer */
  $handler->display->display_options['fields']['field_profile_employer']['id'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['table'] = 'field_data_field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['field'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['label'] = '';
  $handler->display->display_options['fields']['field_profile_employer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_employer']['alter']['text'] = '<a href="[field_profile_employer-url]">[field_profile_employer-title] &nbsp;<i class="fa fa-external-link" aria-hidden="true"></i></a>';
  $handler->display->display_options['fields']['field_profile_employer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_employer']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_profile_employer']['type'] = 'link_title_plain';
  /* Field: Content: Job description */
  $handler->display->display_options['fields']['field_profile_job_description']['id'] = 'field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['table'] = 'field_data_field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['field'] = 'field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['label'] = '';
  $handler->display->display_options['fields']['field_profile_job_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_job_description']['element_label_colon'] = FALSE;
  /* Field: Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="alumni-card">
<div class="alumni-card-photo">[field_profile_photo]</div>
<div class="alumni-card-info"><p>Class of [field_profile_year_graduated]</p>
    <h4><srong>[title]</strong></h4>
    <p><strong>[field_profile_job_title]</strong>,<br>[field_profile_employer]</p>
</div>
<div>[view_node]</div>

</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'alumni_profile' => 'alumni_profile',
  );

  /* Display: Sidebar List for panelized page */
  $handler = $view->new_display('panel_pane', 'Sidebar List for panelized page', 'panel_pane_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'alumni-profile-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<br><a href="/alumni-profiles" class="btn btn-primary btn-block">View all Profiles &raquo;</a>';
  $handler->display->display_options['footer']['area']['format'] = 'panopoly_wysiwyg_text';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Job Title */
  $handler->display->display_options['fields']['field_profile_job_title']['id'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['table'] = 'field_data_field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['field'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_job_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_job_title']['element_label_colon'] = FALSE;
  /* Field: Content: Year Graduated */
  $handler->display->display_options['fields']['field_profile_year_graduated']['id'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['table'] = 'field_data_field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['field'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['label'] = '';
  $handler->display->display_options['fields']['field_profile_year_graduated']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_year_graduated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_year_graduated']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'Y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Employer */
  $handler->display->display_options['fields']['field_profile_employer']['id'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['table'] = 'field_data_field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['field'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['label'] = '';
  $handler->display->display_options['fields']['field_profile_employer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_employer']['alter']['text'] = '<a href="[field_profile_employer-url]">[field_profile_employer-title] &nbsp;<i class="fa fa-external-link" aria-hidden="true"></i></a>';
  $handler->display->display_options['fields']['field_profile_employer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_employer']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_profile_employer']['type'] = 'link_title_plain';
  /* Field: Content: Title (Rewrite) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Content: Title (Rewrite)';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<p><a href="[path]#content"><strong>[title], [field_profile_year_graduated]&nbsp;&raquo;</strong><br>
[field_profile_job_title]<br>[field_profile_employer]</a></p>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'alumni_profile' => 'alumni_profile',
  );

  /* Display: Overview Page */
  $handler = $view->new_display('page', 'Overview Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Meet our Alumni';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'alumni-profile-view-cards clearfix row four-up';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-sm-6 col-md-4 col-lg-3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_profile_fname']['id'] = 'field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['table'] = 'field_data_field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['field'] = 'field_profile_fname';
  $handler->display->display_options['fields']['field_profile_fname']['label'] = '';
  $handler->display->display_options['fields']['field_profile_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_fname']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '[field_profile_fname]\'s Profile &raquo;';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['link_class'] = 'btn btn-primary btn-block';
  $handler->display->display_options['fields']['view_node']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more &raquo;';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Year Graduated */
  $handler->display->display_options['fields']['field_profile_year_graduated']['id'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['table'] = 'field_data_field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['field'] = 'field_profile_year_graduated';
  $handler->display->display_options['fields']['field_profile_year_graduated']['label'] = '';
  $handler->display->display_options['fields']['field_profile_year_graduated']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_year_graduated']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_year_graduated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_year_graduated']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Degree or credential */
  $handler->display->display_options['fields']['field_profile_degree']['id'] = 'field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['table'] = 'field_data_field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['field'] = 'field_profile_degree';
  $handler->display->display_options['fields']['field_profile_degree']['label'] = '';
  $handler->display->display_options['fields']['field_profile_degree']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_degree']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_degree']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_degree']['delta_offset'] = '0';
  /* Field: Content: Job Title */
  $handler->display->display_options['fields']['field_profile_job_title']['id'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['table'] = 'field_data_field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['field'] = 'field_profile_job_title';
  $handler->display->display_options['fields']['field_profile_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_job_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_job_title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_profile_job_title']['element_label_colon'] = FALSE;
  /* Field: Content: Employer */
  $handler->display->display_options['fields']['field_profile_employer']['id'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['table'] = 'field_data_field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['field'] = 'field_profile_employer';
  $handler->display->display_options['fields']['field_profile_employer']['label'] = '';
  $handler->display->display_options['fields']['field_profile_employer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_employer']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_employer']['alter']['text'] = '<a href="[field_profile_employer-url]">[field_profile_employer-title] &nbsp;<i class="fa fa-external-link" aria-hidden="true"></i></a>';
  $handler->display->display_options['fields']['field_profile_employer']['alter']['path'] = '[field_profile_employer-url]';
  $handler->display->display_options['fields']['field_profile_employer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_employer']['click_sort_column'] = 'url';
  /* Field: Content: Job description */
  $handler->display->display_options['fields']['field_profile_job_description']['id'] = 'field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['table'] = 'field_data_field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['field'] = 'field_profile_job_description';
  $handler->display->display_options['fields']['field_profile_job_description']['label'] = '';
  $handler->display->display_options['fields']['field_profile_job_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_job_description']['element_label_colon'] = FALSE;
  /* Field: Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="alumni-card">
<div class="alumni-card-photo">[field_profile_photo]</div>
<div class="alumni-card-info"><p>Class of [field_profile_year_graduated]</p>
    <h4><srong>[title]</strong></h4>
    <p><strong>[field_profile_job_title]</strong></p><p>[field_profile_employer]</p>
</div>
<div>[view_node]</div>

</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'alumni_profile' => 'alumni_profile',
  );
  $handler->display->display_options['path'] = 'alumni-profiles';
  $export['alumni_profiles'] = $view;

  return $export;
}
