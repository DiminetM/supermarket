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
	
	<?php if (!empty($content['right']) || !empty($content['left'])): ?>
	<div class="deck deck-3">
		<div class="column left twelve"><?php print $content['left']; ?></div>
		<div class="column right six"><?php print $content['right']; ?></div>
	</div>
	<?php endif; ?>
	
	<?php if (!empty($content['left-1']) || !empty($content['right-1'])): ?>
	<div class="deck deck-4">
		<div class="column left six"><?php print $content['left-1']; ?></div>
		<div class="column right twelve"><?php print $content['right-1']; ?></div>
	</div>
	<?php endif; ?>
	
	<?php if (!empty($content['left-2']) || !empty($content['middle-2']) || !empty($content['right-2'])): ?>
	<div class="deck deck-5">
		<div class="column left six"><?php print $content['left-2']; ?></div>
		<div class="column middle six"><?php print $content['middle-2']; ?></div>
		<div class="column right six"><?php print $content['right-2']; ?></div>
	</div>
	<?php endif; ?>
	
	<?php if (!empty($content['full-1'])): ?>
	<div class="deck deck-6">
		<div class="column full"><?php print $content['full-1']; ?></div>
	</div>
	<?php endif; ?>
	
	<?php if (!empty($content['left-3']) || !empty($content['left-3-2']) || !empty($content['left-3-3']) || !empty($content['right-3'])): ?>
	<div class="deck deck-8">
		<div class="column left twelve">
		  <div class="column left twelve clearfix">
		    <?php print $content['left-3']; ?>
		  </div>
		  <div class="column left six">
		    <?php print $content['left-3-2']; ?>
		  </div>
		  <div class="column right six">
		    <?php print $content['left-3-3']; ?>
		  </div>
		</div>
		<div class="column right six"><?php print $content['right-3']; ?></div>
	</div>
	<?php endif; ?>
	
	<?php if (!empty($content['left-4']) || !empty($content['right-4'])): ?>
	<div class="deck deck-9">
		<div class="column left six"><?php print $content['left-4']; ?></div>
		<div class="column right twelve"><?php print $content['right-4']; ?></div>
	</div>
	<?php endif; ?>
	
	<?php if (!empty($content['left-5']) || !empty($content['middle-5']) || !empty($content['right-5'])): ?>
	<div class="deck deck-10">
		<div class="column left six"><?php print $content['left-5']; ?></div>
		<div class="column middle six"><?php print $content['middle-5']; ?></div>
		<div class="column right six"><?php print $content['right-5']; ?></div>
	</div>
	<?php endif; ?>
	
</div>
