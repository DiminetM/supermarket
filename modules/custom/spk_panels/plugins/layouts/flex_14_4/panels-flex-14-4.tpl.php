<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two or three column panel display layout, with
 * each column roughly equal in width.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following divs:
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 */
?>

<?php if (!empty($content['header'])): ?>
<header>
	<div class="deck deck-1">
		<div class="column full"><?php print $content['header']; ?></div>
	</div>
</header>
<?php endif; ?>

<div class="grid-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
	
	<?php if (!empty($content['full'])): ?>
	<div class="deck deck-2">
		<div class="column full"><?php print $content['full']; ?></div>
	</div>
	<?php endif; ?>
	
	<?php if (!empty($content['left']) || !empty($content['right'])): ?>
	<div class="deck deck-3">
	  <div class="column right four"><?php print $content['right']; ?></div>
		<div class="column left fourteen"><?php print $content['left']; ?></div>
	</div>
	<?php endif; ?>

	
</div>
