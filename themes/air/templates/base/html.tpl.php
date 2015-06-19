<?php

/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * Old content for google site verification: <meta name="google-site-verification"
 * content="DpflHKhMblYDnm1_3foRIwC8pBat4T3SuEeUQnkbmRE" />.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 */
?><!DOCTYPE html>
<html xmlns:og="http://opengraphprotocol.org/schema/" <?php print $html_attributes . $rdf_namespaces; ?>>

<head>
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
  <!-- Mobile viewport -->
  <meta name="viewport" content="width=device-width, initial-scale=1, minimum-scale=1, maximum-scale=1">
  <meta name="google-site-verification" content="RDuHd4YvK1dGe373ttcSV6Km9VDX2SgRYeN828-R-nI" />
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>

  <!--[if lt IE 9]>
  <script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
  <![endif]-->

</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>

  <?php
    $arg_1 = arg(1);
    if (is_numeric($arg_1)) {
      $node = node_load($arg_1);
      if (isset($node->type) && !empty($node->type) && $node->type == 'product') {
        echo '<script type="text/javascript" src="//web.telemetric.dk/t/422/tm.js" async="async"></script>';
        //echo '<script type="text/javascript" src="themes/air/scripts/tm.js" async="async"></script>';
      }
    }
  ?>

  <script type="text/javascript">
    // --- Set GA tracking ---
    /*var url = window.location;
    var Regex = /peytz\.no/gi;
    var curr_path_arr = window.location.pathname.split('/');

    if (Regex.test(url)) {
      (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
      (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
      m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
      })(window,document,'script','//www.google-analytics.com/analytics.js','ga');
      ga('create', 'UA-109799-7', 'peytz.no');
      // Check if current page is search result page. Add custom param "s" (search param) for GA tracking.
      if (curr_path_arr.length > 2 && curr_path_arr[1] == 'search' && curr_path_arr[2] == 'site') {
        ga('set', 'page', '?q=' + curr_path_arr[3]);
      }
      ga('send', 'pageview');
    }
    else {
      var _gaq = _gaq || [];

      _gaq.push(['_setAccount', 'UA-109799-1']);
      // Check if current page is search result page. Add custom param "s" (search param) for GA tracking.
      if (curr_path_arr.length > 2 && curr_path_arr[1] == 'search' && curr_path_arr[2] == 'site') {
        _gaq.push(['_set', 'page', '?q=' + curr_path_arr[3]]);
      }
      _gaq.push(['_trackPageview']);

      (function() {
        var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
        ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
        var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
      })();
    }*/
    // --- End setting GA tracking ---
  </script>

</body>
</html>
