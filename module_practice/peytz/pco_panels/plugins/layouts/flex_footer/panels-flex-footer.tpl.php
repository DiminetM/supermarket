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
	
	<?php if (!empty($content['right']) || !empty($content['middle']) || !empty($content['left'])): ?>
	<div class="deck deck-2">
		<div class="column left six"><?php print $content['left']; ?></div>
		<div class="column middle six"><?php print $content['middle']; ?></div>
		<div class="column right six"><?php print $content['right']; ?></div>
	</div>
	<?php endif; ?>
	
</div>

<?php if (!empty($content['footer'])): ?>
<footer>
	<div class="deck deck-3">
		<div class="column full"><?php print $content['footer']; ?></div>
	</div>
</footer>
<?php endif; ?>
