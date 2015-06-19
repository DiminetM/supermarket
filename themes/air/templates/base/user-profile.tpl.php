<?php
/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($content['field_example']). Always call render($user_profile)
 * at the end in order to print all remaining items. If the item is a category,
 * it will contain all its profile items. By default, $user_profile['summary']
 * is provided which contains data on the user's history. Other data can be
 * included by modules. $user_profile['user_picture'] is available
 * for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $user->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $user->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 */
?>
<article class="profile"<?php print $attributes; ?>>
  <header>
    <?php print render($user_profile['user_picture']); ?>
    <div class="content">
      <h1><?php print render($user_profile['field_name']); ?></h1>
      <?php print render($user_profile['field_job_title']); ?>
      <?php print render($user_profile['field_work_number']); ?>
      <?php print render($user_profile['field_mobile_number']); ?>
      <div class="field field-label-inline clearfix">
        <div class="field-label"><?php print t('E-mail'); ?>:&nbsp;</div>
        <?php print l($variables['elements']['#account']->mail, 'mailto:' . $variables['elements']['#account']->mail, array('absolute' => TRUE)); ?>
      </div>
    </div>
  </header>
  <div class="link-to-description">
    <?php print $user_profile['need_dk_description'] ? t('Vi har dessverre ikke noen norsk versjon, klikk her for å se') . ' ' . l(t('den danske versjonen.'), '#', array('external' => TRUE)) : ''; ?>
  </div>
  <div class="prose">
    <?php print render($user_profile['field_employee_description']); ?>
  </div>
</article>
