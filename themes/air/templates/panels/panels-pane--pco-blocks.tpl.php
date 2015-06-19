<?php
/**
 * @file panels-pane.tpl.php
 * Main panel pane template
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 */
?>
<section class="<?php print $classes; ?> <?php print $pane->configuration['bgcolor']; ?> <?php if($pane->configuration['image'] == 1) { print 'image'; } else if ($pane->configuration['image'] == 2) { print 'image border'; } ?>" <?php print $id; ?>>
  <?php if ($admin_links): ?>
   <?php print $admin_links; ?>
  <?php endif; ?>

  <?php
  if ($pane->configuration['image']) {
    if (!empty($content['field_image'][0])) {
      print render($content['field_image'][0]);
    }
    else if (!empty($content['field_image_gallery'][0])) {
      print render($content['field_image_gallery'][0]);
    }
  }
  ?>
  <div class="pane-content">
    <?php if ($pane->configuration['category'] == '1'): ?>
      <div class="meta">
        <strong><?php print t($content['#bundle']) ?></strong>
        <span class="div">|</span>
        <div class="tags"><?php print render($content['field_category']); ?></div>
      </div>
    <?php endif; ?>

    <?php if ($title): ?>

      <?php if ($pane->configuration['titlesize'] == 'h2'): ?>
        <h2 class="pane-title"><?php print l($title, 'node/' . $content['body']['#object']->nid); ?></h2>
      <?php else: ?>
        <h1 class="pane-title"><?php print l($title, 'node/' . $content['body']['#object']->nid); ?></h1>
      <?php endif; ?>

    <?php endif; ?>

    <?php if ($feeds): ?>
      <div class="feed">
        <?php print $feeds; ?>
      </div>
    <?php endif; ?>

    <?php
      if ($pane->configuration['teaser'] == '1'):
        print render($content['body']);
      endif;
    ?>
  </div>

  <?php if ($links): ?>
  <div class="links">
    <?php print $links; ?>
  </div>
  <?php endif; ?>

  <?php if ($more): ?>
  <div class="more-link">
    <?php print $more; ?>
  </div>
  <?php endif; ?>
</section>
