<?php
$plugin = array(
  'single' => TRUE,
  'title' => t('SPK Block'),
  'icon' => 'icon_node.png',
  'description' => t('Teaser blocks for Supermarket.'),
  'category' => t('Supermarket.'),
  'edit form' => 'spk_blocks_content_type_edit_form',
  'render callback' => 'spk_blocks_content_type_render',
  'admin title' => 'spk_blocks_content_type_admin_title',
  'top level' => TRUE,
  'js' => array('misc/autocomplete.js'),
);

/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function spk_blocks_content_type_render($subtype, $conf, $panel_args) {
  $nid = $conf['nid'];
  $block = new stdClass();

  foreach (explode('/', $_GET['q']) as $id => $arg) {
    $nid = str_replace("%$id", $arg, $nid);
  }

  foreach ($panel_args as $id => $arg) {
    if (is_string($arg)) {
      $nid = str_replace("@$id", $arg, $nid);
    }
  }

  // Support node translation
  if (module_exists('translation')) {
    if ($translations = module_invoke('translation', 'node_get_translations', $nid)) {
      if (isset($translations[$GLOBALS['language']->language]))  {
        $nid = $translations[$GLOBALS['language']->language]->nid;
      }
    }
  }

  if (!is_numeric($nid)) {
    return;
  }

  // Look for translations of selected node.
  //global $language;
  //$lang = $language->language;
  //$base_node = node_load($nid);
  //$translations = translation_node_get_translations($base_node->tnid);
  //$translated_node = isset($translations[$lang]) ? node_load($translations[$lang]->nid) : $base_node;
  //$node = $translated_node;

  $node = node_load($nid);
  if (!node_access('view', $node)) {
    return;
  }

  // Don't store viewed node data on the node, this can mess up other
  // views of the node.
  $node = clone($node);

  $block->module = 'spk_blocks';
  $block->delta = $node->nid;
  $block->title = check_plain($node->title);

  if (!empty($conf['identifier'])) {
    $node->ctools_template_identifier = $conf['identifier'];
  }

  $block->content = node_view($node, 'teaser');

  return $block;
}

/**
 * 'Edit form' callback for the content type.
 */
function spk_blocks_content_type_edit_form($form, &$form_state) {
  
// The current configuration
  $conf = $form_state['conf'];
  // This and the next one are normal FAPI form making.
  if ($form_state['op'] == 'add') {
    $form['nid'] = array(
      '#prefix' => '<div class="no-float">',
      '#title' => t('Enter the title or NID of a node'),
      '#description' => t('To use a NID from the URL, you may use %0, %1, ..., %N to get URL arguments. Or use @0, @1, @2, ..., @N to use arguments passed into the panel.'),
      '#type' => 'textfield',
      '#maxlength' => 512,
      '#size' => 100,
      '#autocomplete_path' => 'pcoblocks/autocomplete/node_title',
      '#weight' => -10,
      '#suffix' => '</div>',
    );
  }
  else {
    $form['nid'] = array(
      '#type' => 'value',
      '#value' => $conf['nid'],
    );
  }
  
  $form['bgcolor'] = array(
    '#type' => 'select',
    '#title' => t('Select background color of block'),
    '#options' => array(
      'strict' => t('No color'),
      'grey' => t('Light grey'),
      'dark' => t('Dark grey'),
      'orange' => t('Orange'),
    ),
    '#default_value' => $conf['bgcolor'],
    '#description' => t('Choose a background color for the block.'),
  );
  
  $form['titlesize'] = array(
    '#type' => 'select',
    '#title' => t('Select fontsize for headline'),
    '#options' => array(
      'h1' => t('H1'),
      'h2' => t('H2'),
    ),
    '#default_value' => $conf['titlesize'],
    '#description' => t('Choose a fontsize for the headline of the block.'),
  );
  
  $form['image'] = array(
    '#type' => 'radios',
    '#title' => t('Use image?'),
    '#default_value' => $conf['image'],
    '#options' => array(
      0 => t('No image'),
      1 => t('Without border'),
      2 => t('With border'),
    ),
  );
  
  $form['category'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use category'),
    '#default_value' => $conf['category'],
  );
  
  $form['teaser'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use teaser text'),
    '#default_value' => $conf['teaser'],
  );
  return $form;
}

/**
 * Validate the node selection.
 */
function spk_blocks_content_type_edit_form_validate(&$form, &$form_state) {
  if ($form_state['op'] != 'add') {
    return;
  }

  $nid = $form_state['values']['nid'];
  $preg_matches = array();
  $match = preg_match('/\[id: (\d+)\]/', $nid, $preg_matches);
  if (!$match) {
    $match = preg_match('/^id: (\d+)/', $nid, $preg_matches);
  }

  if ($match) {
    $nid = $preg_matches[1];
  }
  if (is_numeric($nid)) {
    $node = db_query('SELECT nid, status FROM {node} WHERE nid = :nid', array(':nid' => $nid))->fetchObject();
  }
  else {
    $node = db_query('SELECT nid, status FROM {node} WHERE title = :title', array(':title' => $nid))->fetchObject();
  }
  if ($node) {
    $form_state['values']['nid'] = $node->nid;
  }

  if (!($node || preg_match('/^[@%]\d+$/', $nid)) ||
      // Do not allow unpublished nodes to be selected by unprivileged users
      (empty($node->status) && !user_access('administer nodes'))) {
    form_error($form['nid'], t('Invalid node'));
  }
}
  

/**
* Submit function, note anything in the formstate[conf] automatically gets saved
*/
function spk_blocks_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array('nid', 'bgcolor', 'titlesize', 'image', 'category', 'teaser') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Returns the administrative title for a node.
 */
function spk_blocks_content_type_admin_title($subtype, $conf) {
  if (!is_numeric($conf['nid'])) {
    return t('Node loaded from @var', array('@var' => $conf['nid']));
  }

  $node = node_load($conf['nid']);
  if ($node) {
    if (!empty($node->status) || user_access('administer nodes')) {
      return check_plain($node->title);
    }
    else {
      return t('Unpublished node @nid', array('@nid' => $conf['nid']));
    }
  }
  else {
    return t('Deleted/missing node @nid', array('@nid' => $conf['nid']));
  }
}
