#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_container.h"
#include "src/MContract/MContextualBindingBuilder.h"

zend_class_entry *MContextualBindingBuilder;

ZEND_BEGIN_ARG_INFO(needsArgInfo,0)
    ZEND_ARG_INFO(0, abstract)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(giveArgInfo,0)
    ZEND_ARG_INFO(0, implemention)
ZEND_END_ARG_INFO()

zend_function_entry MContextualBindingBuilderMethods[] = {
    ZEND_ABSTRACT_ME(MContextualBindingBuilder, needs, needsArgInfo)
    ZEND_ABSTRACT_ME(MContextualBindingBuilder, give, giveArgInfo)
    PHP_FE_END
};

PHP_CONTAINER_STARTUP_FUNCTION(MContextualBindingBuilder)
{
    zend_class_entry MContextualBindingBuilderTmp;
    INIT_CLASS_ENTRY(MContextualBindingBuilderTmp, "MContainer\\MContextualBindingBuilder", MContextualBindingBuilderMethods);
    MContextualBindingBuilder = zend_register_internal_class(&MContextualBindingBuilderTmp TSRMLS_CC);
    MContextualBindingBuilder->ce_flags = ZEND_ACC_INTERFACE;
    return SUCCESS;
}
