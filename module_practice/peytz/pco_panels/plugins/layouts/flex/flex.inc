<?php

// Plugin definition
$plugin = array(
  'title' => t('Flexible'),
  'category' => t('Air'),
  'icon' => 'flex.png',
  'theme' => 'panels_flex',
  'css' => 'flex.css',
  'regions' => array(
  	'header' => t('Header'),
  	'full' => t('Full width: 18col'),
    'left' => t('Left 12col'),
    'right' => t('Right 6col'),
    'left-1' => t('Left 6col'),
    'right-1' => t('Right 12col'),
    'left-2' => t('Left 6col'),
    'middle-2' => t('Middle 6col'),
    'right-2' => t('Right 6col'),
    'full-1' => t('Full width: 18col'),
    'left-3' => t('Left 12col'),
    'left-3-2' => t('Left 12col &rarr; 6col'),
    'left-3-3' => t('Left 12col &rarr; 6col'),
    'right-3' => t('Right 6col'),
    'left-4' => t('Left 6col'),
    'right-4' => t('Right 12col'),
    'left-5' => t('Left 6col'),
    'middle-5' => t('Middle 6col'),
    'right-5' => t('Right 6col')   
  ),
);
