#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_container.h"
#include "src/PSRInterface/PSRInterface.h"
zend_class_entry *PSRContainerInferfaceCE;

ZEND_BEGIN_ARG_INFO(getArgInfo, 0)
ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(hasArgInfo, 0)
ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

zend_function_entry PSRContainerInterfaceMethods[] = {
    ZEND_ABSTRACT_ME(PSRContainerInferface, get, getArgInfo)
    ZEND_ABSTRACT_ME(PSRContainerInferface, has, hasArgInfo)
    PHP_FE_END
};

PHP_CONTAINER_STARTUP_FUNCTION(PSRContainerInferface)
{
    zend_class_entry PSRContainerInferfaceTempCE;
    PSRContainerInferfaceCE = INIT_CLASS_ENTRY(PSRContainerInferfaceTempCE, "PSR\\ContainerInterface", PSRContainerInterfaceMethods);
    if (PSRContainerInferfaceCE == NULL) {
        return FAILURE;
    }
    PSRContainerInferfaceCE->ce_flags = ZEND_ACC_INTERFACE;
    return SUCCESS;
}