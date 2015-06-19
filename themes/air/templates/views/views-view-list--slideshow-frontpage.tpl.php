<?php
/**
 * @file views-view-list--slideshow-frontpage.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php print $list_type_prefix; ?>
    <?php foreach ($view->result as $id => $result): ?>
      <li class="<?php print $classes_array[$id]; ?>">
        <?php if (!empty($result->field_field_link[0]['raw']['url'])): ?>
          <h1><?php print l($result->node_title, $result->field_field_link[0]['raw']['url'], array('html' => TRUE)); ?></h1>
        <?php else: ?>
          <h1><?php print $result->node_title; ?></h1>
        <?php endif; ?>
        <div class="image">
          <?php print l(render($result->field_field_image[0]['rendered']), $result->field_field_link[0]['raw']['url'], array('html' => TRUE)); ?>
        </div>
        <div class="actions">
        <?php if (!empty($result->field_field_link[0]['raw']['title'])) : ?>
          <?php print l($result->field_field_link[0]['raw']['title'], $result->field_field_link[0]['raw']['url'], array('attributes' => array('class' => 'button'))); ?>
        <?php endif; ?>
        </div>
      </li>
    <?php endforeach; ?>
  <?php print $list_type_suffix; ?>
<?php print $wrapper_suffix; ?>
