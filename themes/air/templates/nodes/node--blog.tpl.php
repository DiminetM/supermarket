<?php
/**
 * @file
 * Default theme implementation to display a blog.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if (!$page && $node->nid != 127): // Hal: We don't want title with link on Webform newsletter signup block, nid=127 ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php else: ?>
  	<h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div class="content"<?php print $content_attributes; ?>>
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
  	<div class="meta">
  		<?php print $user_picture; ?>
  		<div class="submitted">
  		  <p><?php print $submitted; ?></p>
  		  <p><?php print $date; ?></p>
  		</div>
		<?php if (!empty($content['field_category'])) : ?>
  		<div class="tags">
  		  <span><?php print t('categories:'); ?></span> <?php print $terms; ?>
  		</div>
		<?php endif; ?>
  	</div>
  	
	  <div class="prose">
	  	<?php print render($content['body']); ?>
	  </div>
  </div>
</article>
