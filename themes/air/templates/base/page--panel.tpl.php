<?php
/**
 * @file
 * Displays a single Drupal page.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 */
?>
    <header role="banner">
    	
      <?php if ($main_menu || $secondary_menu): ?>
      <div role="navigation">

        <div class="header">
          <div>
            <?php if ($site_slogan): ?>
            <small><?php print $site_slogan; ?></small>
            <?php endif; ?>
            
            <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => array('secondary')))); ?>
          </div>
        </div>

      	<div class="top">
      	  <div class="tophead">
  	      	<?php if ($logo): ?>
  	      	<div class="logo">
  	      	  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
  	      	    <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
  	      	  </a>
  	      	</div>
  	      	<?php endif; ?>
	      	</div>
	      	<div class="navhead">
	      	  <div>
  	      		<nav>
  	      		  <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('primary')), 'heading' => t('Main menu'))); ?>
  	      		</nav>
  	      		
  	      		<?php print render($page['header']); ?>
	      		</div>
	      	</div>	      	
      	</div>
      	
      	<?php print $messages; ?>
      	
      	<?php if ($page['highlighted']): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
      	
      </div> <!-- /div[role="navigation"] -->
      <?php endif; ?>
		</header> <!-- /header[role="banner"] -->

    <div id="main-content" role="main">
      <?php if ($action_links): ?><div class="action-links"><ul><?php print render($action_links); ?></ul></div><?php endif; ?>
      
      <?php print render($page['content']); ?>
    </div>

    <footer>
      <?php print render($page['footer']); ?>
    </footer> <!-- /.section, /#footer -->
