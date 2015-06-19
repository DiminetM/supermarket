<?php

// Plugin definition
$plugin = array(
  'title' => t('Flexible: Footer'),
  'category' => t('Air'),
  'icon' => 'flex_footer.png',
  'theme' => 'panels_flex_footer',
  'css' => 'flex_footer.css',
  'regions' => array(
  	'header' => t('Header'),
    'left' => t('Left 6col'),
    'middle' => t('Middle 6col'),
    'right' => t('Right 6col'),
    'footer' => t('Footer'),
  ),
);
