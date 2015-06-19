<?php

// Plugin definition
$plugin = array(
  'title' => t('Flexible: Whitespace'),
  'category' => t('Air'),
  'icon' => 'flex_ws.png',
  'theme' => 'panels_flex_ws',
  'css' => 'flex_ws.css',
  'regions' => array(
  	'header' => t('Header'),
  	'full' => t('Full width: 18col'),
		'left' => t('Left'),
		'right' => t('Right'),
    'full-1' => t('Full width: 18col'),
    'left-3' => t('Left 12col'),
    'right-3' => t('Right 6col'),
    'left-4' => t('Left 6col'),
    'right-4' => t('Right 12col'),
    'left-5' => t('Left 6col'),
    'middle-5' => t('Middle 6col'),
    'right-5' => t('Right 6col')   
  ),
);