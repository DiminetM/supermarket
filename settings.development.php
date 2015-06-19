<?php
// If PEYTZ_VIRT is set we can assume that we are on virtualbox
if (!empty($_SERVER['PEYTZ_VIRT'])) {
  $databases['default']['default']['username'] = 'drip';
  $databases['default']['default']['password'] = 'drip';
  $databases['default']['default']['host'] = 'localhost';

  // Unset memcache
  $conf['cache_backends'] = array();
  $conf['cache_default_class'] = 'DrupalDatabaseCache';
  $conf['memcache_servers'] = array();

  // Load images from dev site
  if (strpos($_GET['q'], 'files/ipgroup.md') !== FALSE && strpos($_GET['q'], 'admin') === FALSE) {
  if (!is_file($_GET['q'])) {
    // First try to redirect to live site.
    // This is much much faster than the very very slow placehold.it.
    if (preg_match('/ipgroup-md/', $_SERVER['HTTP_HOST'], $matches)) {
      $live_url = 'http://test.ipgroup-md.drupal7.dev.peytz.dk' . $_SERVER['REQUEST_URI'];
    }
    header('Location: ' .  $live_url);
    exit();
  }
}
}
elseif (isset($_SERVER['PEYTZ_DEV'])) {
  // Use database with developer initials prepended
  $databases['default']['default']['database'] = 'd7_ipgroup_md';
  $databases['default']['default']['username'] = 'drupal';
  $databases['default']['default']['password'] = 'mypal';
  $databases['default']['default']['host'] = 'mysql-write';

  // Unset memcache
  $conf['cache_backends'] = array();
  $conf['cache_default_class'] = 'DrupalDatabaseCache';
  $conf['memcache_servers'] = array();

  // TODO: Test memcache enabling on dev server
  /*
  $conf['cache_backends'][] = 'sites/ipgroup.md/modules/contrib/memcache/memcache.inc';
  $conf['cache_default_class'] = 'MemCacheDrupal';
  $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
  $conf['memcache_key_prefix'] = 'ipgroup';
  $conf['memcache_servers'] = array(
    '127.0.0.1:11211' => 'default',
  );
  $conf['memcache_bins'] = array(
    'cache' => 'default',
  );
   */
}

// For XDebug to work
$_SERVER['SCRIPT_NAME'] = '/';
error_reporting(E_ALL ^ E_NOTICE);
