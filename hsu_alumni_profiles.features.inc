<?php

/**
 * @file
 * hsu_alumni_profiles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hsu_alumni_profiles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hsu_alumni_profiles_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hsu_alumni_profiles_node_info() {
  $items = array(
    'alumni_profile' => array(
      'name' => t('Alumni Profile'),
      'base' => 'node_content',
      'description' => t('This content will show up in the large feature on the home page and also on the careers and alumni page. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
