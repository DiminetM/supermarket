<?php
/**
 * @file
 * peytz_multilang_panels.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function peytz_multilang_panels_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'cp_productpage_graybox';
  $mini->category = '';
  $mini->admin_title = 'CP ProductPage graybox';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0493403c-5672-4605-9898-0659d199c0bf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-591f11de-53cb-4cfc-8c73-f63087e381ec';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'i-can-call-you pane',
      'title' => '',
      'body' => 'i can call you',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '591f11de-53cb-4cfc-8c73-f63087e381ec';
    $display->content['new-591f11de-53cb-4cfc-8c73-f63087e381ec'] = $pane;
    $display->panels['middle'][0] = 'new-591f11de-53cb-4cfc-8c73-f63087e381ec';
    $pane = new stdClass();
    $pane->pid = 'new-6e8e8736-3f58-49e0-a869-5d93764b20b6';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'employees-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6e8e8736-3f58-49e0-a869-5d93764b20b6';
    $display->content['new-6e8e8736-3f58-49e0-a869-5d93764b20b6'] = $pane;
    $display->panels['middle'][1] = 'new-6e8e8736-3f58-49e0-a869-5d93764b20b6';
    $pane = new stdClass();
    $pane->pid = 'new-95c82ccd-aeb6-4cc5-831b-6e36a362d858';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'hardcoded-phone-number pane',
      'title' => '',
      'body' => '[hardcoded phone number]',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '95c82ccd-aeb6-4cc5-831b-6e36a362d858';
    $display->content['new-95c82ccd-aeb6-4cc5-831b-6e36a362d858'] = $pane;
    $display->panels['middle'][2] = 'new-95c82ccd-aeb6-4cc5-831b-6e36a362d858';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['cp_productpage_graybox'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'cta_contact_person';
  $mini->category = '';
  $mini->admin_title = 'CTA Contact person';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fa957017-a12c-4ed2-b6a7-fa8e5f428ba3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4211aca3-fb57-42bf-b7e1-2cd3e3a82a2f';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'i-can-call-you pane',
      'title' => '',
      'body' => 'i can call you',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4211aca3-fb57-42bf-b7e1-2cd3e3a82a2f';
    $display->content['new-4211aca3-fb57-42bf-b7e1-2cd3e3a82a2f'] = $pane;
    $display->panels['left'][0] = 'new-4211aca3-fb57-42bf-b7e1-2cd3e3a82a2f';
    $pane = new stdClass();
    $pane->pid = 'new-f1120d73-8d5e-4251-b898-5daedafd2b69';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'employees-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'contact-person',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f1120d73-8d5e-4251-b898-5daedafd2b69';
    $display->content['new-f1120d73-8d5e-4251-b898-5daedafd2b69'] = $pane;
    $display->panels['left'][1] = 'new-f1120d73-8d5e-4251-b898-5daedafd2b69';
    $pane = new stdClass();
    $pane->pid = 'new-cddfd529-eb60-41a9-96d7-8b2b026f324e';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'hardcoded-phone pane',
      'title' => '',
      'body' => '[hardcoded phone number]',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'cddfd529-eb60-41a9-96d7-8b2b026f324e';
    $display->content['new-cddfd529-eb60-41a9-96d7-8b2b026f324e'] = $pane;
    $display->panels['left'][2] = 'new-cddfd529-eb60-41a9-96d7-8b2b026f324e';
    $pane = new stdClass();
    $pane->pid = 'new-55e6c01e-eb65-4172-9ac8-96547bf5b584';
    $pane->panel = 'right';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '482',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'cta-form',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '55e6c01e-eb65-4172-9ac8-96547bf5b584';
    $display->content['new-55e6c01e-eb65-4172-9ac8-96547bf5b584'] = $pane;
    $display->panels['right'][0] = 'new-55e6c01e-eb65-4172-9ac8-96547bf5b584';
    $pane = new stdClass();
    $pane->pid = 'new-fddf7952-0f35-46b5-8241-ed992652c071';
    $pane->panel = 'right';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '556',
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'cta-form',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'fddf7952-0f35-46b5-8241-ed992652c071';
    $display->content['new-fddf7952-0f35-46b5-8241-ed992652c071'] = $pane;
    $display->panels['right'][1] = 'new-fddf7952-0f35-46b5-8241-ed992652c071';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['cta_contact_person'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'cta_contact_person_no';
  $mini->category = '';
  $mini->admin_title = 'CTA Contact person NO';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fa957017-a12c-4ed2-b6a7-fa8e5f428ba3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4211aca3-fb57-42bf-b7e1-2cd3e3a82a2f';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'i-can-call-you pane',
      'title' => '',
      'body' => 'i can call you',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4211aca3-fb57-42bf-b7e1-2cd3e3a82a2f';
    $display->content['new-4211aca3-fb57-42bf-b7e1-2cd3e3a82a2f'] = $pane;
    $display->panels['left'][0] = 'new-4211aca3-fb57-42bf-b7e1-2cd3e3a82a2f';
    $pane = new stdClass();
    $pane->pid = 'new-50e55170-d280-4d3b-8f0d-95c6f0996f9b';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'employees-panel_pane_4';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'contact-person',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '50e55170-d280-4d3b-8f0d-95c6f0996f9b';
    $display->content['new-50e55170-d280-4d3b-8f0d-95c6f0996f9b'] = $pane;
    $display->panels['left'][1] = 'new-50e55170-d280-4d3b-8f0d-95c6f0996f9b';
    $pane = new stdClass();
    $pane->pid = 'new-cddfd529-eb60-41a9-96d7-8b2b026f324e';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'hardcoded-phone pane',
      'title' => '',
      'body' => '[hardcoded phone number]',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'cddfd529-eb60-41a9-96d7-8b2b026f324e';
    $display->content['new-cddfd529-eb60-41a9-96d7-8b2b026f324e'] = $pane;
    $display->panels['left'][2] = 'new-cddfd529-eb60-41a9-96d7-8b2b026f324e';
    $pane = new stdClass();
    $pane->pid = 'new-9926d392-c508-4342-b1d4-a3f74eb9b3e8';
    $pane->panel = 'right';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '557',
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'cta-form',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9926d392-c508-4342-b1d4-a3f74eb9b3e8';
    $display->content['new-9926d392-c508-4342-b1d4-a3f74eb9b3e8'] = $pane;
    $display->panels['right'][0] = 'new-9926d392-c508-4342-b1d4-a3f74eb9b3e8';
    $pane = new stdClass();
    $pane->pid = 'new-42cdf911-528b-4188-a58b-b63f4f5ca3a5';
    $pane->panel = 'right';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '558',
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'cta-form',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '42cdf911-528b-4188-a58b-b63f4f5ca3a5';
    $display->content['new-42cdf911-528b-4188-a58b-b63f4f5ca3a5'] = $pane;
    $display->panels['right'][1] = 'new-42cdf911-528b-4188-a58b-b63f4f5ca3a5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['cta_contact_person_no'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'footer';
  $mini->category = '';
  $mini->admin_title = 'Footer';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array(
    0 => array(
      'identifier' => 'Language',
      'keyword' => 'language',
      'name' => 'language',
      'language' => 'current',
      'id' => 1,
    ),
  );
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'flex_footer';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'header' => NULL,
      'full' => NULL,
      'left-1' => NULL,
      'right-1' => NULL,
      'left-2' => NULL,
      'middle-2' => NULL,
      'right-2' => NULL,
      'full-1' => NULL,
      'left-3' => NULL,
      'right-3' => NULL,
      'left-4' => NULL,
      'right-4' => NULL,
      'left-5' => NULL,
      'middle-5' => NULL,
      'right-5' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '93fb1f7d-d881-438f-8a97-5dbd5f623d9f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-71388793-d1c9-4491-bf99-6c78f114e653';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'block-4';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '71388793-d1c9-4491-bf99-6c78f114e653';
    $display->content['new-71388793-d1c9-4491-bf99-6c78f114e653'] = $pane;
    $display->panels['footer'][0] = 'new-71388793-d1c9-4491-bf99-6c78f114e653';
    $pane = new stdClass();
    $pane->pid = 'new-0be6ee8b-733c-4523-b378-4dd170bb52ff';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'site_language',
          'settings' => array(
            'language' => array(
              'da' => 'da',
              'default' => 0,
              'en' => 0,
              'nb' => 0,
            ),
          ),
          'context' => 'context_language_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Department footer DK',
      'title' => 'Afdelinger',
      'body' => '<div class="view view-departments view-id-departments view-display-id-panel_pane_1">
  <div class="view-content" style="clear:both">
    <div class="views-row views-row-1 views-row-odd views-row-first">
      <div class="views-field views-field-name">
        <h3 class="field-content"><a href="/afdeling/analyse">Analyse</a></h3>
      </div>

      <div class="views-field views-field-description">
        <div class="field-content">
          <p>Vi skaber den viden om dine l&aelig;sere, brugere og kunder, du skal bruge, n&aring;r du vil udvikle din kommunikation.</p>
        </div>
      </div>
    </div>

    <div class="views-row views-row-2 views-row-even">
      <div class="views-field views-field-name">
        <h3 class="field-content"><a href="/afdeling/design">Design</a></h3>
      </div>

      <div class="views-field views-field-description">
        <div class="field-content">
          <p>Enkelt, sk&oslash;nt og unikt design - udviklet med kraftfuld webteknologi.</p>
        </div>
      </div>
    </div>

    <div class="views-row views-row-3 views-row-odd">
      <div class="views-field views-field-name">
        <h3 class="field-content"><a href="/afdeling/udvikling">Udvikling</a></h3>
      </div>

      <div class="views-field views-field-description">
        <div class="field-content">
          <p>Drupal, Wordpress, PHP og projektledelse. Samarbejde på tv&aelig;rs af kompetencer.</p>
        </div>
      </div>
    </div>
  </div>
  <div class="view-content" style="clear:both">
    <div class="views-row views-row-4 views-row-even">
      <div class="views-field views-field-name">
        <h3 class="field-content"><a href="/afdeling/flex">Flex</a></h3>
      </div>

      <div class="views-field views-field-description">
        <div class="field-content">
          <p>Specialudviklede l&oslash;sninger til b&aring;de virksomhed og brugere. St&aelig;rke koncepter og elegante gr&aelig;nseflader.</p>
        </div>
      </div>
    </div>

    <div class="views-row views-row-5 views-row-odd">
      <div class="views-field views-field-name">
        <h3 class="field-content"><a href="/afdeling/nyhedsbreve">Nyhedsbreve</a></h3>
      </div>

      <div class="views-field views-field-description">
        <div class="field-content">
          <p>Markedsledende indenfor e-mail nyhedsbreve til danske medier. Og godt p&aring; vej til at opn&aring; samme status i andre brancher.</p>
        </div>
      </div>
    </div>

    <div class="views-row views-row-6 views-row-even views-row-last">
      <div class="views-field views-field-name">
        <h3 class="field-content"><a href="/afdeling/strategi">Strategi</a></h3>
      </div>

      <div class="views-field views-field-description">
        <div class="field-content">
          <p>Medier og foreninger skaber sunde samfund. Vi bidrager ved at udvikle nye, b&aelig;redygtige digitale strategier.</p>
        </div>
      </div>
    </div>
  </div>
</div>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-departments-panel-pane-1',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0be6ee8b-733c-4523-b378-4dd170bb52ff';
    $display->content['new-0be6ee8b-733c-4523-b378-4dd170bb52ff'] = $pane;
    $display->panels['header'][0] = 'new-0be6ee8b-733c-4523-b378-4dd170bb52ff';
    $pane = new stdClass();
    $pane->pid = 'new-be3735f9-b5be-4544-a4dd-58fcbf4c2d7e';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'site_language',
          'settings' => array(
            'language' => array(
              'nb' => 'nb',
              'default' => 0,
              'da' => 0,
              'en' => 0,
            ),
          ),
          'context' => 'context_language_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Product footer NO',
      'title' => 'Produkter',
      'body' => '<div class="view view-departments view-id-departments view-display-id-panel_pane_1">
  <div class="view-content" style="clear:both">
    <div class="views-row views-row-1 views-row-odd views-row-first">
      <div class="views-field views-field-name">
        <h3 class="field-content"><a href="/produkt/har-du-behov-for-en-profesjonell-nettside">Nettside</a></h3>
      </div>

      <div class="views-field views-field-description">
        <div class="field-content">
          <p>Digitale kanaler og digital kommunikasjon blir stadig viktigere for forretningen din. Vi tilbyr verdens to mest utbredte open source CMS’er.</p>
        </div>
      </div>
    </div>

    <div class="views-row views-row-2 views-row-even">
      <div class="views-field views-field-name">
        <h3 class="field-content"><a href="/produkt/derfor-skal-du-velge-peytz-nyhetsbrev">Nyhetsbrev</a></h3>
      </div>

      <div class="views-field views-field-description">
        <div class="field-content">
          <p>Vi yter kompetent r&aring;dgivning på både strategi, teknikk og forretning. Og systemet v&aring;rt funker bare.</p>
        </div>
      </div>
    </div>

    <div class="views-row views-row-3 views-row-odd">
      <div class="views-field views-field-name">
        <h3 class="field-content"><a href="/produkt/hvem-bruker-nettstedet-ditt">Analyse</a></h3>
      </div>

      <div class="views-field views-field-description">
        <div class="field-content">
          <p>Vi hjelper deg med &aring; prioritere SEO- strategien din, m&aring;ler på innsatsen din og gir deg konkrete anbefalinger.</p>
        </div>
      </div>
    </div>
  </div>
',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-departments-panel-pane-1',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'be3735f9-b5be-4544-a4dd-58fcbf4c2d7e';
    $display->content['new-be3735f9-b5be-4544-a4dd-58fcbf4c2d7e'] = $pane;
    $display->panels['header'][1] = 'new-be3735f9-b5be-4544-a4dd-58fcbf4c2d7e';
    $pane = new stdClass();
    $pane->pid = 'new-28e8a48a-078d-48de-bf05-64831153c263';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'site_language',
          'settings' => array(
            'language' => array(
              'da' => 'da',
              'default' => 0,
              'en' => 0,
              'nb' => 0,
            ),
          ),
          'context' => 'context_language_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Kontakt os DA',
      'title' => 'Kontakt os',
      'body' => '<p>Rentemestervej 80<br />2400 København NV<br />CVR 2692 3549<br /><br />Telefon +45 7220 0101<br />Telefax +45 7220 0102<br /><br /><a href="mailto:info@peytz.dk">Skriv til os</a><br /><a href="http://twitter.com/#!/peytz" target="_blank">Følg os på Twitter</a><br /><a href="http://findvej.dk/Rentemestervej80,2400" target="_blank">Find os på et kort</a></p>',
      'format' => 'wysiwyg_',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '28e8a48a-078d-48de-bf05-64831153c263';
    $display->content['new-28e8a48a-078d-48de-bf05-64831153c263'] = $pane;
    $display->panels['left'][0] = 'new-28e8a48a-078d-48de-bf05-64831153c263';
    $pane = new stdClass();
    $pane->pid = 'new-ec660a59-59d7-4abb-bee5-6fbe8fdeae70';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'site_language',
          'settings' => array(
            'language' => array(
              'nb' => 'nb',
              'default' => 0,
              'da' => 0,
              'en' => 0,
            ),
          ),
          'context' => 'context_language_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Kontakt os NO',
      'title' => 'Kontakt oss',
      'body' => '<p>Skippergata 26<br />260154 Oslo</p><p>Org nr 912 863 093</p><p>Telefon +47 21 999 113</p><p><a href="mailto:info@peytz.no" style="line-height: 1.538em;">Skriv til oss</a></p><p><a href="https://twitter.com/peytz">Følg oss på twitter</a><br />&nbsp;</p>',
      'format' => 'wysiwyg_',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ec660a59-59d7-4abb-bee5-6fbe8fdeae70';
    $display->content['new-ec660a59-59d7-4abb-bee5-6fbe8fdeae70'] = $pane;
    $display->panels['left'][1] = 'new-ec660a59-59d7-4abb-bee5-6fbe8fdeae70';
    $pane = new stdClass();
    $pane->pid = 'new-1e6de3a7-1dfd-4038-b7df-0ec7fcb08ca5';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'testimonials-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1e6de3a7-1dfd-4038-b7df-0ec7fcb08ca5';
    $display->content['new-1e6de3a7-1dfd-4038-b7df-0ec7fcb08ca5'] = $pane;
    $display->panels['middle'][0] = 'new-1e6de3a7-1dfd-4038-b7df-0ec7fcb08ca5';
    $pane = new stdClass();
    $pane->pid = 'new-7e517570-55c8-49aa-8222-1e52984bccc6';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'webform-client-block-127';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7e517570-55c8-49aa-8222-1e52984bccc6';
    $display->content['new-7e517570-55c8-49aa-8222-1e52984bccc6'] = $pane;
    $display->panels['right'][0] = 'new-7e517570-55c8-49aa-8222-1e52984bccc6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['footer'] = $mini;

  return $export;
}
