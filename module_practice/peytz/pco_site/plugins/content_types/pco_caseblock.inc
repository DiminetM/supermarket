<?php
/**
* This plugin array is more or less self documenting
*/
$plugin = array(
  'single' => TRUE,    
  'title' => t('PCo caseblock'),
  'icon' => 'icon_node.png',
  'description' => t('Block that show selected cases'),    
  'category' => t('Peytz & Co.'),
  'render callback' => 'pco_site_content_type_render'
);

/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function pco_site_content_type_render($subtype, $conf, $context = NULL) {
  $block->content = '
    <h2>' . t('We worked with') . '</h2>
    <ul>
      <li class="left top"><a href="#case"><img src="/'. drupal_get_path('theme', 'air') .'/images/cases/bonnierpublications.png" alt="Bonnier publications" /></a></li>
      <li class="right top"><a href="#case"><img src="/'. drupal_get_path('theme', 'air') .'/images/cases/tv2.png" alt="TV2" /></a></li>
      <li class="right"><a href="#case"><img src="/'. drupal_get_path('theme', 'air') .'/images/cases/metro.png" alt="Metro International" /></a></li>
      <li class="left"><a href="#case"><img src="/'. drupal_get_path('theme', 'air') .'/images/cases/sundbaelt.png" alt="Storebælt A/S" /></a></li>
      <li class="right"><a href="#case"><img src="/'. drupal_get_path('theme', 'air') .'/images/cases/dr.png" alt="DR" /></a></li>
      <li class="left bottom"><a href="#case"><img src="/'. drupal_get_path('theme', 'air') .'/images/cases/tv2sport.png" alt="TV2 Sport" /></a></li>
      <li class="right bottom"><a href="#case"><img src="/'. drupal_get_path('theme', 'air') .'/images/cases/3f.png" alt="3F" /></a></li>
    </ul>';
  return $block;
}


?>