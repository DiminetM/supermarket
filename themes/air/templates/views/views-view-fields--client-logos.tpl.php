<?php
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * @ingroup views_templates
 */
?>
<li>
	<?php if(isset($variables['fields']['field_client_link']->content)) : ?>
		<a href="<?php print $variables['fields']['field_client_link']->content; ?>" title="Gå til kundens hjemmeside.">
	<?php endif; ?>
			<img typeof="foaf:Image" src="<?php print $variables['fields']['field_client_logo']->content; ?>" data-hover="<?php print $variables['fields']['field_client_logo_mouse_over']->content; ?>" alt="Thumbnail">
	<?php if(isset($variables['fields']['field_client_link']->content)) : ?>
		</a>
	<?php endif; ?>
</li>
