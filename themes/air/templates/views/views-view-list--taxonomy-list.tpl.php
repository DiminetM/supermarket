<?php
/**
 * @file views-view--taxonomy-list.tpl.php
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  
  <?php print $list_type_prefix; ?>
  
    <?php foreach ($view->style_plugin->rendered_fields as $id => $result): ?>
      <li class="<?php print $classes_array[$id]; ?>">
      <?php if (!empty($result['field_image_gallery'])): ?>
        <div class="image"><?php print $result['field_image_gallery']; ?></div>
      <?php endif; ?>
        <div class="content">
          <div class="meta"><strong><?php print $result['type']; ?></strong><span class="div">|</span><div class="tags"><?php print $result['field_category']; ?></div><?php if(!empty($result['created'])): ?><span class="div">|</span><strong><?php print $result['created']; ?></strong><?php endif; ?></div>
          <h2><?php print $result['title']; ?></h2>
          <?php print $result['body']; ?>
        </div>
      </li>
    <?php endforeach; ?>
    
  <?php print $list_type_suffix; ?>
  
<?php print $wrapper_suffix; ?>
