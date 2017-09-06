<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('container')) {
	dl('container.' . PHP_SHLIB_SUFFIX);
}
use MContainer\ContextualBindingBuilder;

var_dump((new ContextualBindingBuilder)->needs());


