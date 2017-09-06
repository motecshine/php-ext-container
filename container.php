<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('container')) {
	dl('container.' . PHP_SHLIB_SUFFIX);
}
use MContainer\ContainerInterface;
use MContainer\ContainerContract;
use MContainer\MContextualBindingBuilder;

class Container implements ContainerInterface {
	public function get($id)
	{
		return $id;
	}

	public function has($id)
	{
		return $id;
	}
}

var_dump(new Container);

var_dump(new MContextualBindingBuilder);
?>
