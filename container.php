<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('container')) {
	dl('container.' . PHP_SHLIB_SUFFIX);
}
use PSR\ContainerInterface;

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

?>
