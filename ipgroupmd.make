; makefile for ipgroup.md site

; define core version and drush make compatibility

core = 7.x
api = 2

; Contribution modules

projects[admin_menu][version] = "3.0-rc5"
projects[admin_menu][subdir] = "contrib"

projects[addressfield][version] = "1.1"
projects[addressfield][subdir] = "contrib"

projects[ctools][version] = "1.7"
projects[ctools][subdir] = "contrib"

projects[date][version] = "2.8"
projects[date][subdir] = "contrib"

projects[devel][version] = "1.5"
projects[devel][subdir] = "contrib"

projects[diff][version] = "3.2"
projects[diff][subdir] = "contrib"

projects[entity_translation][version] = "1.0-beta4"
projects[entity_translation][subdir] = "contrib"

projects[features][version] = "2.5"
projects[features][subdir] = "contrib"

projects[features_extra][version] = "1.0-beta1"
projects[features_extra][subdir] = contrib

projects[field_group][version] = "1.4"
projects[field_group][subdir] = "contrib"

projects[panels][version] = "3.5"
projects[panels][subdir] = "contrib"

projects[pathauto][version] = "1.2"
projects[pathauto][subdir] = "contrib"

projects[references][version] = "2.1"
projects[references][subdir] = "contrib"

projects[strongarm][version] = "2.0"
projects[strongarm][subdir] = "contrib"

projects[token][version] = "1.6"
projects[token][subdir] = "contrib"

projects[variable][version] = "2.5"
projects[variable][subdir] = "contrib"

projects[taxonomy_menu][version] = "1.5"
projects[taxonomy_menu][subdir] = "contrib"

projects[submenutree][version] = "2.3"
projects[submenutree][subdir] = "contrib"

projects[tb_megamenu][version] = "1.0-beta5"
projects[tb_megamenu][subdir] = "contrib"

projects[view_profiles_perms][version] = "1.0"
projects[view_profiles_perms][subdir] = "contrib"

projects[views][version] = "3.11"
projects[views][subdir] = "contrib"

projects[colorbox][version] = "2.8"
projects[colorbox][subdir] = "contrib"

projects[better_exposed_filters][subdir] = contrib
projects[better_exposed_filters][download][type] = "git"
projects[better_exposed_filters][download][url] = "http://git.drupal.org/project/better_exposed_filters.git"
projects[better_exposed_filters][download][tag] = "7.x-3.0-beta4"

projects[views_block_filter_block][subdir] = contrib
projects[views_block_filter_block][download][type] = "git"
projects[views_block_filter_block][download][url] = "http://git.drupal.org/project/views_block_filter_block.git"
projects[views_block_filter_block][download][tag] = "7.x-1.0-beta1"
