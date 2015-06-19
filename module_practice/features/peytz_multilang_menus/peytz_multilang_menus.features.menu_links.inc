<?php
/**
 * @file
 * peytz_multilang_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function peytz_multilang_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Forside',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: main-menu:about
  $menu_links['main-menu:about'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'about',
    'router_path' => 'about',
    'link_title' => 'Om',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: main-menu:blog
  $menu_links['main-menu:blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: main-menu:cases
  $menu_links['main-menu:cases'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'cases',
    'router_path' => 'cases',
    'link_title' => 'Cases',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: main-menu:employees
  $menu_links['main-menu:employees'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'employees',
    'router_path' => 'employees',
    'link_title' => 'Medarbejdere',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: main-menu:products
  $menu_links['main-menu:products'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'products',
    'router_path' => 'products',
    'link_title' => 'Produkter',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-main-menu-no:<front>
  $menu_links['menu-main-menu-no:<front>'] = array(
    'menu_name' => 'menu-main-menu-no',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Forside',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-main-menu-no:about
  $menu_links['menu-main-menu-no:about'] = array(
    'menu_name' => 'menu-main-menu-no',
    'link_path' => 'about',
    'router_path' => 'about',
    'link_title' => 'Om',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: menu-main-menu-no:blog
  $menu_links['menu-main-menu-no:blog'] = array(
    'menu_name' => 'menu-main-menu-no',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blogg',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-main-menu-no:cases
  $menu_links['menu-main-menu-no:cases'] = array(
    'menu_name' => 'menu-main-menu-no',
    'link_path' => 'cases',
    'router_path' => 'cases',
    'link_title' => 'Cases',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-main-menu-no:employees
  $menu_links['menu-main-menu-no:employees'] = array(
    'menu_name' => 'menu-main-menu-no',
    'link_path' => 'employees',
    'router_path' => 'employees',
    'link_title' => 'Medarbeidere',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-main-menu-no:products
  $menu_links['menu-main-menu-no:products'] = array(
    'menu_name' => 'menu-main-menu-no',
    'link_path' => 'products',
    'router_path' => 'products',
    'link_title' => 'Produkter',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-secondary-menu-no:node/115
  $menu_links['menu-secondary-menu-no:node/115'] = array(
    'menu_name' => 'menu-secondary-menu-no',
    'link_path' => 'node/115',
    'router_path' => 'node/%',
    'link_title' => 'In English',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-secondary-menu:node/115
  $menu_links['menu-secondary-menu:node/115'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => 'node/115',
    'router_path' => 'node/%',
    'link_title' => 'In English',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-secondary-menu:node/127
  $menu_links['menu-secondary-menu:node/127'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => 'node/127',
    'router_path' => 'node/%',
    'link_title' => 'Få vores nyhedsbrev',
    'options' => array(
      'attributes' => array(
        'title' => 'Få vores nyhedsbrev',
        'rel' => 'modal[newsletter]',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-secondary-menu:node/262
  $menu_links['menu-secondary-menu:node/262'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => 'node/262',
    'router_path' => 'node/%',
    'link_title' => 'Cookiepolitik',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'is-cookie',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-secondary-menu:user/logout
  $menu_links['menu-secondary-menu:user/logout'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log ud',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  t('Blogg');
  t('Cases');
  t('Cookiepolitik');
  t('Forside');
  t('Få vores nyhedsbrev');
  t('In English');
  t('Log ud');
  t('Medarbeidere');
  t('Medarbejdere');
  t('Om');
  t('Produkter');


  return $menu_links;
}
