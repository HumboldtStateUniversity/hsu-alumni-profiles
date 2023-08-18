<?php

/**
 * @file
 * hsu_alumni_profiles.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hsu_alumni_profiles_feeds_importer_default() {
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
                    'value' => '$.[*].',
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
                        'value' => 'field_photo_private',
                        'debug' => 0,
                        'weight' => '8',
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
                        'source' => 'photo',
                        'target' => 'field_profile_photo:uri',
                        'unique' => FALSE,
                        'language' => 'und',
                    ),
                    12 => array(
                        'source' => 'photo_alt',
                        'target' => 'field_profile_photo:alt',
                        'unique' => FALSE,
                        'language' => 'und',
                    ),
                    13 => array(
                        'source' => 'submitted_date',
                        'target' => 'field_profile_submitted_date',
                        'unique' => FALSE,
                        'language' => 'und',
                    ),
                    14 => array(
                        'source' => 'why_program_chosen',
                        'target' => 'field_profile_program_choose',
                        'unique' => FALSE,
                        'language' => 'und',
                    ),
                    15 => array(
                        'source' => 'how_program_prepared',
                        'target' => 'field_profile_program_prepare',
                        'unique' => FALSE,
                        'language' => 'und',
                    ),
                    16 => array(
                        'source' => 'what_enjoyed',
                        'target' => 'field_profile_program_enjoy',
                        'unique' => FALSE,
                        'language' => 'und',
                    ),
                    17 => array(
                        'source' => 'comments',
                        'target' => 'field_profile_comments',
                        'unique' => FALSE,
                        'language' => 'und',
                    ),
                    18 => array(
                        'source' => 'student_advice',
                        'target' => 'field_profile_program_recommend',
                        'unique' => FALSE,
                        'language' => 'und',
                    ),
                ),
                'insert_new' => '1',
                'update_existing' => '2',
                'update_non_existent' => 'delete',
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
