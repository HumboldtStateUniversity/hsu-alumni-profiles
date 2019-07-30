<?php

/**
 * @file
 * hsu_alumni_profiles.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hsu_alumni_profiles_user_default_permissions() {
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
