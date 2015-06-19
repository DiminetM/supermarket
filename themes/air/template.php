<?php
/**
 * Auto-rebuild the theme registry during theme development.
 */
if (theme_get_setting('air_rebuild_registry')) {
  // Rebuild .info data.
  system_rebuild_theme_data();
  // Rebuild theme registry.
  drupal_theme_rebuild();
}

/**
 * Implementation of hook_theme().
 */
function air_theme(&$vars) {
  $items = array();
  if (isset($vars['fb_likebox_facebook'])) {
    $theme_path = drupal_get_path('theme', $GLOBALS['theme']);
    $vars['fb_likebox_facebook']['path'] = $theme_path . '/templates';
  }
  $items['node'] = array(
    'arguments' => array('node' => NULL, 'teaser' => FALSE, 'page' => FALSE),
    'template' => 'node',
    'path' => drupal_get_path('theme', 'air') .'/templates/nodes',
  );
  // Split out pager list into separate theme function.
  $items['pager_list'] = array('arguments' => array(
    'tags' => array(),
    'limit' => 10,
    'element' => 0,
    'parameters' => array(),
    'quantity' => 9,
  ));

  return $items;
}

/**
 * Override or insert variables into the html template.
 */
function air_preprocess_html(&$vars) {
  global $theme_path;
  global $language;

  $page_title = drupal_get_title();

  // Check if current page is frontpage
  if ($vars['is_front'] || empty($page_title)) {
    $vars['head_title'] = variable_get('site_name');
  } else {
    // Serve proper content title if is_front is false
    $vars['head_title'] = implode(' | ', array($page_title, variable_get('site_name', '')));
  }

  // Clean up the lang attributes
  $vars['html_attributes'] = 'version="HTML+RDFa 1.1" lang="' . $language->language . '" dir="' . $language->dir . '"';

  // Add conditional CSS for IE8 and below.
  drupal_add_css(path_to_theme() . '/styles/css/ie/ie.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lt IE 9', '!IE' => FALSE), 'preprocess' => FALSE));
  // Add conditional CSS for IE6.
  drupal_add_css(path_to_theme() . '/styles/css/ie/ie7.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
}

/**
 * theme_html_header_alter()
 *
 * Remove the generator meta tag for security reasons and add charset
 */
function air_html_head_alter(&$head_elements) {
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8',
  );
  unset($head_elements['system_meta_generator']);

  // Set og:image to first image, when multivalue image field.
  if (!empty($head_elements['metatag_og:image']['#value'])) {
    $images = explode(',', trim($head_elements['metatag_og:image']['#value']));
    $head_elements['metatag_og:image']['#value'] = !empty($images[0]) ? $images[0] : '';
  }
}

/**
 * Implementation of theme_preprocess_page().
 */
function air_preprocess_page(&$vars) {

  // Check if panels is present and serve different template if true.
  if (function_exists('panels_get_current_page_display')) {
    if (panels_get_current_page_display() && empty($_GET['popup'])) {
      $vars['theme_hook_suggestions'][] = 'page__panel';
    }
  }

  // Remove drupal_set_message() from "Tag" page.
  $current_path = current_path();
  if ($current_path == 'node/128' || $current_path == 'node/432' ) {
    $vars['show_messages'] = 0;
  }

}

/**
 * Implementation of theme_preprocess_node().
 */
function air_preprocess_node(&$vars) {
  // Date custom format
  $vars['date'] = format_date($vars['created'], 'custom', 'd. M Y');

  // Render images for field_image_gallery
  if ($vars['type'] == 'case' || $vars['type'] == 'blog' || $vars['type'] == 'product' || $vars['type'] == 'webform') {
    foreach($vars['field_image_gallery'] as $id => $result) {
      $vars['field_image_gallery'][$id]['rendered'] = theme('image_style', array('path' => $result['uri'], 'style_name' => 'image_10col'));
    }
  }

  // Create a switch on node type
  switch ($vars['type']) {
    case 'blog':
      // Build comma separated terms
      if (module_exists('taxonomy')) {
        $term_links = array();
        foreach ($vars['field_category'] as $term) {
          $term_links[] = l($term['taxonomy_term']->name, 'taxonomy/term/' . $term['tid']);
        }
        $vars['terms'] = implode(', ', $term_links);
      }
      $vars['submitted'] = t('by !username', array('!username' => $vars['name']));
      break;
  }
}

/**
 * hook_views_pre_render()
 */
function air_views_pre_render(&$view) {
  switch ($view->name) {
    case 'slideshow_frontpage':
      foreach ($view->result as $id => $result) {
        // Remove <br> tag and apply span's instead
        $result->node_title = '<span>' . preg_replace('| *<br */?> *|', '</span> <span>', $result->node_title) . '</span>';
      }
      break;
    case 'blog':
      // We don't wat to show the attachment if we are one page two (page=1) or higher
      if ($view->current_display == 'attachment_1' && !empty($_GET['page'])) {
        foreach ($view->result as $key => $v) {
          unset($view->result[$key]);
        }
      }
      if ($view->current_display == 'panel_pane_1') {
        $user = user_load($view->args[0]);
        $new_title = $view->display['panel_pane_1']->handler->options['title'] . ' ' . $user->content['field_name'][0]['#markup'];
        $view->build_info['title'] = $new_title;
      }
      if ($view->current_display == 'feed_1') {
        // Change feeds title by user name if exist.
        if ($view->args[0] == 'all') {
          $new_title = t('All feeds');
        }
        else {
          $user = user_load($view->args[0]);
          if (isset($user->field_name)) {
            $new_title = $view->build_info['title'] . ' ' . $user->field_name['und'][0]['value'];
          }
          else {
            $new_title = t('No user');
          }
        }
        $view->build_info['title'] = $new_title;
      }
      break;
    case 'vocabularies':
      if (
        $view->current_display == 'vocabulary_departments'
      ||
        $view->current_display == 'vocabulary_categories'
      ) {
        foreach ($view->result as $res) {
          $res->taxonomy_term_data_name = t($res->taxonomy_term_data_name);
        }
      }
      break;
    case 'employees':
      if (
        $view->current_display == 'employees_list'
      ||
        $view->current_display == 'single_employees'
      ||
        $view->current_display == 'employee_contact_person'
      ||
        $view->current_display == 'panel_pane_1'
      ) {
        // Rewrite user blocks work/phone numbers adding "(work)/(mobile)"
        foreach ($view->result as $res) {
          global $language;
          $exist_nb_work = FALSE;
          if ($language->language == 'nb') {
            if (isset($res->field_field_work_number_no) && !empty($res->field_field_work_number_no)) {
              $res->field_field_work_number_no[0]['rendered']['#markup'] =
                $res->field_field_work_number_no[0]['rendered']['#markup'] . ' (' . t('Work') .')';
              $exist_nb_work = TRUE;
              unset($res->field_field_work_number[0]);
            }
          }
          if (!$exist_nb_work && !empty($res->field_field_work_number)) {
            $res->field_field_work_number[0]['rendered']['#markup'] =
              $res->field_field_work_number[0]['rendered']['#markup'] . ' (' . t('Work') .')';
            unset($res->field_field_work_number_no[0]);
          }

          if (!empty($res->field_field_mobile_number)) {
            $res->field_field_mobile_number[0]['rendered']['#markup'] =
              $res->field_field_mobile_number[0]['rendered']['#markup'] . ' (' . t('Mobile') .')';
          }
        }
      }
      break;
  }
}

/**
 * theme_preprocess_views_view_list().
 */
function air_preprocess_views_view_list(&$vars) {
  $view = $vars['view'];

  foreach ($view->result as $id => $result) {
    // Check if view is an attachment and have an image field.
    if ($view->is_attachment && empty($result->field_field_image_gallery[0])) {
      // If not, set appropriate status
      $vars['classes_array'][$id] .= ' no-image';
    }
  }
}

/**
 * theme_preprocess_views_view_unformatted().
 */
function air_preprocess_views_view_unformatted(&$vars) {
  $view = $vars['view'];

  if ($view->name == 'morgeninspiration') {
    foreach ($view->result as $key => $result) {
      if (time() < strtotime($result->field_field_date_for_event[0]['raw']['value'])) {
        $vars['classes'][$key][] = 'orange';
        $vars['classes_array'][$key] = isset($vars['classes'][$key]) ? implode(' ', $vars['classes'][$key]) : '';
      } else {
        $vars['classes'][$key][] = 'gray';
        $vars['classes_array'][$key] = isset($vars['classes'][$key]) ? implode(' ', $vars['classes'][$key]) : '';
      }
    }
  }
}

/*
 * Implements hook_preprocess_views_view_fields
 */
function air_preprocess_views_view_fields(&$vars) {
  $row = $vars['row'];
  $view = $vars['view'];
  $fields = $vars['fields'];
  $is_blogs_feed = ($view->name == 'blog' && $view->current_display == 'blogsfeed');
  $is_cases_feed = ($view->name == 'cases_feed' && $view->current_display == 'feed');
  $is_employees_feed = ($view->name == 'employees' && $view->current_display == 'feed');

  if ($is_blogs_feed || $is_cases_feed) {
    $image = '';
    if (isset($row->field_field_image_gallery) && !empty($row->field_field_image_gallery)) {
      foreach ($row->field_field_image_gallery as $gallery_image) {
        $image .= '<image>' . file_create_url($gallery_image['raw']['uri']) . '</image>';
      }
    }
    $vars['image'] = $image;

    $node = node_load($fields['nid']->raw);
    $teaser = '';
    if (isset($node->body[$node->language][0]['safe_summary'])) {
      $teaser = $node->body[$node->language][0]['safe_summary'];
    }
    $vars['teaser'] = $teaser;
  }

  if ($is_blogs_feed) {
    $user = user_load($row->node_uid);
    $user_name = field_get_items('user', $user, 'field_name');
    $author = render(field_view_value('user', $user, 'field_name', $user_name[0], array()));
    $vars['author'] = $author;
  }

  if ($is_employees_feed) {
    global $language;

    $image = '';
    if (isset($row->users_picture) && ctype_digit($row->users_picture)) {
      $image = file_create_url(file_load($row->users_picture)->uri);
    }
    $vars['image'] = $image;

    $job_title = $fields['field_job_title']->content;
    $job_description = $fields['field_employee_description']->content;

    if ($language->language == 'nb') {
      if (!empty($fields['field_job_title_no']->content)) {
        $job_title = $fields['field_job_title_no']->content;
      }

      $job_description = $fields['field_employee_description_no']->content;
    }
    $vars['job_title'] = $job_title;
    $vars['job_description'] = $job_description;
  }
}

/**
 * Preprocess variables for panels-pane.tpl.php.
 *
 * @see panels-pane.tpl.php
 */
function air_preprocess_panels_pane(&$variables) {
  global $language;
  // Filter blocks in panel display.
  if ($variables['pane']->type == 'block') {
    // Check if isset facet api block ex. on search result page.
    if (
      isset($variables['content']['bundle'])
    &&
      isset($variables['content']['bundle']['#items'])
    ) {
      $andet = NULL;
      // Loop facet's items for get Andet item, unset it and put at the end of list.
      foreach ($variables['content']['bundle']['#items'] as $key => $item) {
        if (preg_match('/' . t('Andet') . '/', $item['data'])) {
          $andet = $item;
          // Put bundle:page item array into new variable.
          unset($variables['content']['bundle']['#items'][$key]);
        }
      }
      // Put Andet at the end of facet content types list.
      if (isset($andet)) {
        $variables['content']['bundle']['#items'][] = $andet;
      }
    }
  }

  if ($variables['pane']->type == 'pco_blocks') {
    // Put taxonomy category name in t() function for PCO Blocks.
    if (
      is_array($variables['content'])
    &&
      isset($variables['content']['field_category'])
    &&
      !empty($variables['content']['field_category'])
    ) {
      $variables['content']['field_category'][0]['#title'] = t($variables['content']['field_category'][0]['#title']);
    }

    $exploded_layout = explode(':', $variables['display']->layout);
    $layout = array_pop($exploded_layout);
    $layout_pane = $layout . '__' . $variables['pane']->panel;

    switch ($layout_pane) {
      //layout: flex
      case 'flex__left':
        $image_style = 'image_12col';
        break;
      case 'flex__right':
        $image_style = 'image_09col';
        break;
      case 'flex__left-1':
        $image_style = 'image_09col';
        break;
      case 'flex__right-1':
        $image_style = 'image_12col';
        break;
      case 'flex__left-2':
        $image_style = 'image_09col';
        break;
      case 'flex__middle-2':
        $image_style = 'image_09col';
        break;
      case 'flex__right-2':
        $image_style = 'image_09col';
        break;
      case 'flex__left-3':
        $image_style = 'image_12col';
        break;
      case 'flex__left-3-2':
        $image_style = 'image_09col';
        break;
      case 'flex__left-3-3':
        $image_style = 'image_09col';
        break;
      case 'flex__right-3':
        $image_style = 'image_09col';
        break;
      case 'flex__left-4':
        $image_style = 'image_09col';
        break;
      case 'flex__right-4':
        $image_style = 'image_12col';
        break;
      case 'flex__left-5':
        $image_style = 'image_09col';
        break;
      case 'flex__middle-5':
        $image_style = 'image_09col';
        break;
      case 'flex__right-5':
        $image_style = 'image_09col';
        break;
      //layout: flex ws
      case 'flex_ws__full':
        $image_style = 'image_07col';
        break;
      case 'flex_ws__left':
        $image_style = 'image_07col';
        break;
      case 'flex_ws__right':
        $image_style = 'image_07col';
        break;
      case 'flex_ws__full-1':
        $image_style = 'image_07col';
        break;
      case 'flex_ws__left-3':
        $image_style = 'image_12col';
        break;
      case 'flex_ws__right-3':
        $image_style = 'image_07col';
        break;
      case 'flex_ws__left-4':
        $image_style = 'image_07col';
        break;
      case 'flex_ws__right-4':
        $image_style = 'image_07col';
        break;
      case 'flex_ws__left-5':
        $image_style = 'image_07col';
        break;
      case 'flex_ws__middle-5':
        $image_style = 'image_07col';
        break;
      case 'flex_ws__right-5':
        $image_style = 'image_07col';
        break;
    }

    // Add image style.
    if (!empty($variables['content']['field_image'][0])) {
      $variables['content']['field_image'][0]['#image_style'] = $image_style;
    }
    if (!empty($variables['content']['field_image_gallery'][0])) {
      $variables['content']['field_image_gallery'][0]['#image_style'] = $image_style;
    }

    $variables['theme_hook_suggestions'][] = 'panels_pane__pco_blocks';
  }
  // Check if current pane is (field related content).
  elseif (
    $variables['pane']->type == 'entity_field'
  &&
    $variables['pane']->subtype == 'node:field_related'
  ) {
    global $language;

    if ($language->language == 'nb') {
      foreach ($variables['content'] as $key => &$content) {
        // Add (på dansk) to the title of DK related nodes in case NO node was opened.
        if (
          is_array($content)
        &&
          isset($content['#title'])
        &&
          $content['#options']['entity']->language == 'da'
        ) {
          $content['#title'] .= ' (' . t('på dansk') . ')';
        }
      }
    }
  }
  // Check if current pane is field related webform.
  elseif (
    $variables['pane']->type == 'entity_field'
  &&
    $variables['pane']->subtype == 'node:field_related_webform'
  &&
    !empty($variables['content'])
  ) {
    $webform_description = '';
    $webform_title = '';

    // Get custom description text for current webform related to the node.
    if (
      isset($variables['content']['#object']->field_webform_description)
    &&
      !empty($variables['content']['#object']->field_webform_description)
    ) {
      $webform_description = $variables['content']['#object']->field_webform_description['und'][0]['value'];
      // Set custom webform description for current node.
      $variables['content'][0]['body'][0]['#markup'] = $webform_description;
    }

    // Get custom title text for current webform related to the node.
    if (
      isset($variables['content']['#object']->field_webform_title)
    &&
      !empty($variables['content']['#object']->field_webform_title)
    ) {
      $webform_title = $variables['content']['#object']->field_webform_title['und'][0]['value'];
      // Set custom webform title for current node.
      $variables['content'][0]['#node']->title = $webform_title;
    }
  }
}

/**
 * Prepare for theming of the webform form.
 */
function air_preprocess_webform_confirmation(&$variables, $hook) {
  global $base_url;
  // Get path of node where current webform was related.
  $prev_url = str_replace($base_url . '/', '', $_SERVER['HTTP_REFERER']);
  $original_url = drupal_get_normal_path($prev_url);
  $original_url_arr = explode('/', $original_url);
  if ((int) $original_url_arr[1]) {
    // Get the node object where current webform was related.
    $webform_related_node = node_load($original_url_arr[1]);

    // Check if node where current webform was related contains the field
    // "field_webform_confirmation_messa" - the confirmation message webform field.
    if (
      isset($webform_related_node->field_webform_confirmation_messa)
    &&
      !empty($webform_related_node->field_webform_confirmation_messa)
    ) {
      $confirmation_message = $webform_related_node->field_webform_confirmation_messa['und'][0]['value'];
      // Override confirmation message variable.
      $variables['confirmation_message'] = $confirmation_message;
    }
  }
}

/**
 * theme_preprocess_user_picture();
 */
function air_preprocess_user_picture(&$variables) {
  $variables['user_picture'] = '';
  if (variable_get('user_pictures', 0)) {
    $account = user_load($variables['account']->uid);
    if (!empty($account->picture)) {
      // @TODO: Ideally this function would only be passed file objects, but
      // since there's a lot of legacy code that JOINs the {users} table to
      // {node} or {comments} and passes the results into this function if we
      // a numeric value in the picture field we'll assume it's a file id
      // and load it for them. Once we've got user_load_multiple() and
      // comment_load_multiple() functions the user module will be able to load
      // the picture files in mass during the object's load process.
      if (is_numeric($account->picture)) {
        $account->picture = file_load($account->picture);
      }
      if (!empty($account->picture->uri)) {
        $filepath = $account->picture->uri;
      }
      // Add alternative picture for mouseover
      $alternative_picture = field_get_items('user', $account, 'field_image');
      if (!empty($alternative_picture[0]['uri'])) {
        $filepath_alternative = $alternative_picture[0]['uri'];
      }
    }
    elseif (variable_get('user_picture_default', '')) {
      $filepath = variable_get('user_picture_default', '');
    }
    if (isset($filepath)) {
      if (empty($filepath_alternative)) {
        $filepath_alternative = FALSE;
      }
      $alt = t("@user's picture", array('@user' => format_username($account)));
      // If the image does not have a valid Drupal scheme (for eg. HTTP),
      // don't load image styles.
      if (module_exists('image') && file_valid_uri($filepath) && $style = variable_get('user_picture_style', '')) {
        $variables['user_picture'] = theme('image_style', array('style_name' => $style, 'path' => $filepath, 'path_alternative' => $filepath_alternative, 'alt' => $alt, 'title' => $alt));
      }
      else {
        $variables['user_picture'] = theme('image', array('path' => $filepath, 'path_alternative' => $filepath_alternative, 'alt' => $alt, 'title' => $alt));
      }
      if (!empty($account->uid) && user_access('access user profiles')) {
        $attributes = array(
          'attributes' => array('title' => t('View user profile.')),
          'html' => TRUE,
        );
        $variables['user_picture'] = l($variables['user_picture'], "user/$account->uid", $attributes);
      }
    }
  }
}

/**
 * Implementation of theme_apachesolr_sort_link()
 */
function air_apachesolr_sort_link($vars) {
  $icon = '';

  if ($vars['active']) {
    if (isset($vars['options']['attributes']['class'])) {
      $vars['options']['attributes']['class'] .= ' active';
    }
    else {
      $vars['options']['attributes']['class'] = 'active';
    }
  }
  return apachesolr_l($vars['text'], $vars['path'], $vars['options']);
}

/**
 * Returns HTML for an active facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', 'options', and
 *   'count'. See the l() and theme_facetapi_count() functions for information
 *   about these variables.
 *
 * @ingroup themeable
 */
function air_facetapi_link_inactive($variables) {
  if (!empty($variables['count'])) {
    // Set custom titles for specific content types names.
    $bundle = $variables['options']['query']['f'][0];
    if (preg_match('/product/', $bundle)) {
      $variables['text'] = t('Produkt');
    }
    if (preg_match('/case/', $bundle)) {
      $variables['text'] = t('Cases');
    }
    if (preg_match('/page/', $bundle)) {
      $variables['text'] = t('Andet');
    }
    if (preg_match('/user/', $bundle)) {
      $variables['text'] = t('Employees');
    }

    $variables['text'] .= ' ' . theme('facetapi_count', $variables);
  }
  return theme_link($variables);
}

/**
 * Returns HTML for an inactive facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @ingroup themeable
 */
function air_facetapi_link_active($variables) {
  if (isset($variables['text'])) {
    // Set custom titles for specific content types names.
    $bundle = $_GET['f'][0];
    if (preg_match('/product/', $bundle)) {
      $variables['text'] = t('Produkt');
    }
    if (preg_match('/case/', $bundle)) {
      $variables['text'] = t('Cases');
    }
    if (preg_match('/page/', $bundle)) {
      $variables['text'] = t('Andet');
    }
    if (preg_match('/user/', $bundle)) {
      $variables['text'] = t('Employees');
    }

    if (empty($variables['options']['html'])) {
      $prefix = ' ' . check_plain(t($variables['text']));
    }
    else {
      $prefix  = ' ' . t($variables['text']);
    }
  }
  $variables['options']['html'] = TRUE;
  $variables['text'] = ' <span>(x)</span>';

  return '<em>' . $prefix . '</em>' . theme_link($variables);
}

/**
 * Implementation of theme_image_style()
 */
function air_image_style($variables) {
  /* Aggreed with Kalms to remove width and height from all images
  // Determine the dimensions of the styled image.
  $dimensions = array(
    'width' => $variables['width'],
    'height' => $variables['height'],
  );

  image_style_transform_dimensions($variables['style_name'], $dimensions);

  $variables['width'] = $dimensions['width'];
  $variables['height'] = $dimensions['height'];
  */

  // Determine the url for the styled image.
  $variables['path'] = image_style_url($variables['style_name'], $variables['path']);
  if (!empty($variables['path_alternative'])) {
    $variables['path_alternative'] = image_style_url($variables['style_name'], $variables['path_alternative']);
  }
  return theme('image', $variables);
}

/**
 * Implementation of theme_image()
 */
function air_image($variables) {
  $attributes = $variables['attributes'];
  $attributes['src'] = file_create_url($variables['path']);
  if (!empty($variables['path_alternative'])) {
    $attributes['data-hover'] = file_create_url($variables['path_alternative']);
  }

  // Aggreed with Kalms to remove width and height from all images
  unset($variables['width']);
  unset($variables['height']);

  foreach (array('width', 'height', 'alt', 'title', 'data-hover') as $key) {

    if (isset($variables[$key])) {
      $attributes[$key] = $variables[$key];
    }
  }

  return '<img' . drupal_attributes($attributes) . ' />';
}

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function air_panels_default_style_render_region($vars) {
  $output = '';

  $output .= implode('', $vars['panes']);

  return $output;
}

/**
 * theme_username().
 *
 */
function air_username($variables) {
  // Load author
  $account = user_load($variables['uid']);
  // Load fields
  $name = field_get_items('user', $account, 'field_name');

  // Set full name
  $variables['full_name'] = $name[0]['safe_value'];

  if (isset($variables['link_path'])) {
    // We have a link path, so we should generate a link using l().
    // Additional classes may be added as array elements like
    // $variables['link_options']['attributes']['class'][] = 'myclass';
    $output = l($variables['full_name'] . $variables['extra'], $variables['link_path'], $variables['link_options']);
  }
  else {
    // Modules may have added important attributes so they must be included
    // in the output. Additional classes may be added as array elements like
    // $variables['attributes_array']['class'][] = 'myclass';
    $output = '<span' . drupal_attributes($variables['attributes_array']) . '>' . $variables['name'] . $variables['extra'] . '</span>';
  }

  return $output;
}


/**
 * theme_field($variables);
 */
function air_field($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }

  // Render the items.
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= drupal_render($item);
  }

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

/**
 * Implementation of preprocess_comment().
 */
function air_preprocess_comment(&$vars) {
  $vars['hook'] = 'comment';

  $vars['created'] = format_date($vars['elements']['#comment']->created, 'custom', 'd. M Y');
  $vars['title'] = check_plain($vars['elements']['#comment']->subject);

  $vars['title_attributes_array']['class'][] = 'comment-title';
  $vars['title_attributes_array']['class'][] = 'clearfix';

  $vars['content_attributes_array']['class'][] = 'comment-content';
  $vars['content_attributes_array']['class'][] = 'clearfix';

  $vars['submitted'] = t('by !username, !datetime', array(
    '!username' => $vars['author'],
    '!datetime' => $vars['created'],
  ));

  if (isset($vars['content']['links'])) {
    $vars['links'] = $vars['content']['links'];
    unset($vars['content']['links']);
  }
}

/**
 * Override of theme_pager().
 */
function air_pager($vars) {
  $tags = $vars['tags'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];
  $quantity = $vars['quantity'];
  $pager_list = theme('pager_list', $vars);

  $links = array();
  $links['pager-previous'] = theme('pager_previous', array(
    'text' => (isset($tags[1]) ? $tags[1] : t('Prev')),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters
  ));
  $links['pager-next'] = theme('pager_next', array(
    'text' => (isset($tags[3]) ? $tags[3] : t('Next')),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters
  ));
  $links = array_filter($links);
  $pager_links = theme('links', array(
    'links' => $links,
    'attributes' => array('class' => 'links pager pager-links')
  ));
  if ($pager_list) {
    return "<div class='pager clearfix'>$pager_list $pager_links</div>";
  }
}

/**
 * Split out page list generation into its own function.
 */
function air_pager_list($vars) {
  $tags = $vars['tags'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];
  $quantity = $vars['quantity'];

  global $pager_page_array, $pager_total;
  if ($pager_total[$element] > 1) {
    // Calculate various markers within this pager piece:
    // Middle is used to "center" pages around the current page.
    $pager_middle = ceil($quantity / 2);
    // current is the page we are currently paged to
    $pager_current = $pager_page_array[$element] + 1;
    // first is the first page listed by this pager piece (re quantity)
    $pager_first = $pager_current - $pager_middle + 1;
    // last is the last page listed by this pager piece (re quantity)
    $pager_last = $pager_current + $quantity - $pager_middle;
    // max is the maximum page number
    $pager_max = $pager_total[$element];
    // End of marker calculations.

    // Prepare for generation loop.
    $i = $pager_first;
    if ($pager_last > $pager_max) {
      // Adjust "center" if at end of query.
      $i = $i + ($pager_max - $pager_last);
      $pager_last = $pager_max;
    }
    if ($i <= 0) {
      // Adjust "center" if at start of query.
      $pager_last = $pager_last + (1 - $i);
      $i = 1;
    }
    // End of generation loop preparation.

    $links = array();

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      // Now generate the actual pager piece.
      for ($i; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $links["$i pager-item"] = theme('pager_previous', array(
            'text' => $i,
            'element' => $element,
            'interval' => ($pager_current - $i),
            'parameters' => $parameters
          ));
        }
        if ($i == $pager_current) {
          $links["$i pager-current"] = array('title' => $i);
        }
        if ($i > $pager_current) {
          $links["$i pager-item"] = theme('pager_next', array(
            'text' => $i,
            'element' => $element,
            'interval' => ($i - $pager_current),
            'parameters' => $parameters
          ));
        }
      }
      return theme('links', array(
        'links' => $links,
        'attributes' => array('class' => 'links pager pager-list')
      ));
    }
  }
  return '';
}

/**
 * Return an array suitable for theme_links() rather than marked up HTML link.
 */
function air_pager_link($vars) {
  $text = $vars['text'];
  $page_new = $vars['page_new'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];
  $attributes = $vars['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    else if (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  return array(
    'title' => $text,
    'href' => $_GET['q'],
    'attributes' => $attributes,
    'query' => count($query) ? $query : NULL,
  );
}



/**
 * Implementation of hook template_preprocess_field()
 */
function air_preprocess_field(&$variables, $hook) {
  if ($variables['element']['#field_name'] == 'field_related') {
    foreach ($variables['items'] as $item) {
      $links[] = drupal_render($item);
    }
    $variables['item_list'] = array(
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#items' => $links
    );
  }
}

/**
 * Implementation of hook template_preprocess_search_result()
 */
function air_preprocess_search_result(&$variables) {
  $result = $variables['result'];
  if ($result['entity_type'] == 'user') {
    $entity = entity_load('user', array($result['fields']['entity_id']));
    $user = $entity[$result['fields']['entity_id']];

    $field = field_get_items('user', $user, 'field_name', $user->language);
    $name = $field[0]['value'];
    $field = field_get_items('user', $user, 'field_job_title', $user->language);
    $job = $field[0]['value'];

    $variables['title'] = $name;
    $variables['info'] = l(t('Employees'), 'employees') . ' - ' . $job;
  }
}

/**
 * Implementation of template_preprocess_user_profile().
 */
function air_preprocess_user_profile(&$variables) {
  global $language;
  $variables['user_profile']['need_dk_description'] = FALSE;
  if ($language->language == 'nb') {
    $variables['user_profile']['need_dk_description'] = TRUE;
    if (isset($variables['user_profile']['field_employee_description_no'])) {
      $variables['user_profile']['need_dk_description'] = FALSE;
      $variables['user_profile']['field_employee_description'] = $variables['user_profile']['field_employee_description_no'];
    }
    if (isset($variables['user_profile']['field_job_title_no'])) {
      $variables['user_profile']['field_job_title'] = $variables['user_profile']['field_job_title_no'];
    }
  }

  $exist_work_phone_no = FALSE;
  if ($language->language == 'nb' && isset($variables['user_profile']['field_work_number_country_code_n'])) {
    if (isset($variables['user_profile']['field_work_number_country_code_n'][0]['#markup'])) {
      $work_number_country_code_n = $variables['user_profile']['field_work_number_country_code_n'][0]['#markup'];

      if (isset($variables['user_profile']['field_work_number_no'][0]['#markup'])) {
        $work_number_no = $variables['user_profile']['field_work_number_no'][0]['#markup'];
        $variables['user_profile']['field_work_number'][0]['#markup'] = $work_number_country_code_n . ' ' . $work_number_no . ' (' . t('Work') .')';
        $exist_work_phone_no = TRUE;
      }
    }
  }

  if (!$exist_work_phone_no && isset($variables['user_profile']['field_work_number_country_code'])) {
    if (isset($variables['user_profile']['field_work_number_country_code'][0]['#markup'])) {
      $work_number_country_code = $variables['user_profile']['field_work_number_country_code'][0]['#markup'];

      if (isset($variables['user_profile']['field_work_number'][0]['#markup'])) {
        $work_number = $variables['user_profile']['field_work_number'][0]['#markup'];
        $variables['user_profile']['field_work_number'][0]['#markup'] = $work_number_country_code . ' ' . $work_number . ' (' . t('Work') .')';
      }
    }
  }

  if (isset($variables['user_profile']['field_mobile_number_country_code'])) {
    if (isset($variables['user_profile']['field_mobile_number_country_code'][0]['#markup'])) {
      $mobile_number_country_code = $variables['user_profile']['field_mobile_number_country_code'][0]['#markup'];

      if (isset($variables['user_profile']['field_mobile_number'][0]['#markup'])) {
        $mobile_number = $variables['user_profile']['field_mobile_number'][0]['#markup'];
        $variables['user_profile']['field_mobile_number'][0]['#markup'] = $mobile_number_country_code . ' ' . $mobile_number . ' (' . t('Mobile') .')';
      }
    }
  }
}
