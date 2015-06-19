<?php
/**
 * @file
 * peytz_multilingual.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function peytz_multilingual_locale_default_languages() {
  $languages = array();

  // Exported language: da.
  $languages['da'] = array(
    'language' => 'da',
    'name' => 'Danish',
    'native' => 'Dansk',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '2',
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => '',
    'weight' => '0',
  );
  // Exported language: en.
  $languages['en'] = array(
    'language' => 'en',
    'name' => 'English',
    'native' => 'English',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '0',
    'formula' => '',
    'domain' => '',
    'prefix' => 'en',
    'weight' => '0',
  );
  // Exported language: nb.
  $languages['nb'] = array(
    'language' => 'nb',
    'name' => 'Norwegian Bokmål',
    'native' => 'Bokmål',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '2',
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => '',
    'weight' => '0',
  );
  return $languages;
}
