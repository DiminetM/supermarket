<?php

$template_prefix = <<<XML
<?xml version="1.0" encoding="utf-8" ?>
<subscriberlist action="replace" xmlns="http://xsd.peytz.dk/oprop/subscriberImport.xsd">
XML;

$template = <<<XML
  <subscriber id="%d" action="subscribe">
    <email>%s</email>
  </subscriber>
XML;

$template_suffix = '</subscriberlist>';
