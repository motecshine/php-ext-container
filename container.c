/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_container.h"
#include "src/PSRInterface/PSRContainerInterface.h"
#include "src/ContainerContract.h"
/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(container)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	PHP_CONTAINER_STARTUP(PSRContainerInferface);
	PHP_CONTAINER_STARTUP(ContainerContract);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(container)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(container)
{
#if defined(COMPILE_DL_CONTAINER) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(container)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(container)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "container support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ container_functions[]
 *
 * Every user visible function must have an entry in container_functions[].
 */
const zend_function_entry container_functions[] = {
	PHP_FE_END	/* Must be the last line in container_functions[] */
};
/* }}} */

/* {{{ container_module_entry
 */
zend_module_entry container_module_entry = {
	STANDARD_MODULE_HEADER,
	"container",
	container_functions,
	PHP_MINIT(container),
	PHP_MSHUTDOWN(container),
	PHP_RINIT(container),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(container),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(container),
	PHP_CONTAINER_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_CONTAINER
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(container)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
