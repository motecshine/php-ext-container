#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_container.h"
#include "src/PSRInterface/PSRContainerExceptionInterface.h"

zend_class_entry *PSRContainerExceptionInferface;

zend_function_entry PSRContainerExceptionInterfaceMethods[] = {
    PHP_FE_END
};

PHP_CONTAINER_STARTUP_FUNCTION(PSRContainerExceptionInferface)
{
    zend_class_entry PSRContainerExceptionInferfaceTempCE;
    INIT_CLASS_ENTRY(PSRContainerExceptionInferfaceTempCE, "MContainer\\ContainerExceptionInterface", PSRContainerExceptionInterfaceMethods);
    PSRContainerExceptionInferface = zend_register_internal_class(&PSRContainerExceptionInferfaceTempCE TSRMLS_CC);
    PSRContainerExceptionInferface->ce_flags = ZEND_ACC_INTERFACE;
    ZEND_ASSERT(PSRContainerExceptionInferface);
    return SUCCESS;
}