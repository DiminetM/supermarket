<?php

// Plugin definition
$plugin = array(
  'title' => t('Flexible: 14/4 column'),
  'category' => t('Air'),
  'icon' => 'flex_14_4.png',
  'theme' => 'panels_flex_14_4',
  'css' => 'flex_14_4.css',
  'regions' => array(
  	'header' => t('Header'),
  	'full' => t('Full width: 18col'),
		'left' => t('Left: 14col'),
		'right' => t('Right: 4col')
  ),
);