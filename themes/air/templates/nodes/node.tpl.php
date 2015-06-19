<?php
/**
 * @file
 * Default theme implementation to display a node.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if (!$page && !empty($title)): // Hal: We don't want title with link on Webform newsletter signup block, nid=127 ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php else: ?>
    <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
  ?>
  <?php if (!empty($content['field_image_gallery']) && !empty($content['field_image_gallery'][1])): ?>
    <div class="image slideshow">
      <div class="item-list">
        <ul>
        <?php foreach($field_image_gallery as $id => $result): ?>
          <li><?php print $result['rendered']; ?></li>
        <?php endforeach; ?>
        </ul>
      </div>
    </div>
  <?php elseif (!empty($content['field_image_gallery'])): ?>
    <div class="image">
     <?php print render($content['field_image_gallery'][0]); ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['field_deck'])): ?>
    <div class="lead">
      <?php print render($content['field_deck']); ?>
    </div>
  <?php endif; ?>
  <?php if ($node->type != 'page' && $node->type != 'webform' && $node->type != 'job') : ?>
    <div class="meta">
      <strong><?php print t($node->type); ?></strong><?php
      if (!empty($content['field_category'])) {
        print '<span class="div">|</span><div class="tags">' . render($content['field_category']) . '</div>';
      } ?>
    </div>
  <?php endif; ?>
    <div class="prose">
      <?php print render($content['body']); ?>
      <?php if (!empty($content['webform'])): ?>
        <?php print render($content['webform']); ?>
      <?php endif; ?>
    </div>
  <?php print render($content['links']); ?>
</article>
