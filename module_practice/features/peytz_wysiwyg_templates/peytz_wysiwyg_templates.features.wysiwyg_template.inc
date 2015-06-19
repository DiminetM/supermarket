<?php
/**
 * @file
 * peytz_wysiwyg_templates.features.wysiwyg_template.inc
 */

/**
 * Implements hook_wysiwyg_template_default_templates().
 */
function peytz_wysiwyg_templates_wysiwyg_template_default_templates() {
  $templates = array();
  $templates['quote_dark_grey'] = array(
    'title' => 'Quote Dark grey',
    'description' => '',
    'weight' => 0,
    'fid' => 1193,
    'body' => '<blockquote class="darkgray"><p class="p1">lorem ipsum <strong>fed skrift er orange/fed</strong> - <a href="http://google.dk">links</a> er orange/normal<br />en linje mere til spændende nyheder</p></blockquote>',
    'name' => 'quote_dark_grey',
    'content_types' => array(),
  );
  $templates['quote_light_grey'] = array(
    'title' => 'Quote Light grey',
    'description' => '',
    'weight' => 0,
    'fid' => 1194,
    'body' => '<blockquote class="lightgray"><p class="p1">lorem ipsum <strong>fed skrift er sort/fed</strong> - <a href="http://google.dk">links</a> er orange/normal<br />en linje mere til spændende nyheder</p></blockquote>',
    'name' => 'quote_light_grey',
    'content_types' => array(),
  );
  $templates['quote_orange'] = array(
    'title' => 'Quote Orange',
    'description' => '',
    'weight' => 0,
    'fid' => 1195,
    'body' => '<blockquote class="orange"><p class="p1">lorem ipsum <strong>fed skrift er hvid/fed</strong> - <a href="http://google.dk">links</a> er sort/normal<br />en linje mere til spændende nyheder</p></blockquote>',
    'name' => 'quote_orange',
    'content_types' => array(),
  );
  return $templates;
}
