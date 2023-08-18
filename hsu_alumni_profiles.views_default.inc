<?php

/**
 * @file
 * hsu_alumni_profiles.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hsu_alumni_profiles_views_default_views() {
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
    'image_style' => 'panopoly_image_square',
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
    <h3><a href="/node/[nid]">[title], [field_profile_year_graduated]</a></h3>
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
    'image_style' => 'panopoly_image_square',
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
    <h3><a href="/node/[nid]">[title], [field_profile_year_graduated]</a></h3>
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
    'image_style' => 'panopoly_image_square',
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
    'image_style' => 'panopoly_image_square',
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
    'image_style' => 'panopoly_image_square',
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
