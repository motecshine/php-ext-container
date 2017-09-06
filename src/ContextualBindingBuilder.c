#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_container.h"
#include "src/ContextualBindingBuilder.h"

zend_class_entry *ContextualBindingBuilder;

ZEND_BEGIN_ARG_INFO(needsArgInfo,0)
ZEND_ARG_INFO(0, abstract)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(giveArgInfo,0)
ZEND_ARG_INFO(0, implemention)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(constructArgInfo,0)
ZEND_ARG_INFO(0, container)
ZEND_ARG_INFO(0, concrete)
ZEND_END_ARG_INFO()


PHP_METHOD(ContextualBindingBuilder, needs)
{

}

PHP_METHOD(ContextualBindingBuilder, give)
{

}

PHP_METHOD(ContextualBindingBuilder, __construct)
{

}


zend_function_entry ContextualBindingBuilderMethods[] = {
    PHP_ME(ContextualBindingBuilder, needs, needsArgInfo, ZEND_ACC_PUBLIC)
    PHP_ME(ContextualBindingBuilder, give, giveArgInfo, ZEND_ACC_PUBLIC)
    PHP_ME(ContextualBindingBuilder, __construct, constructArgInfo, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_FE_END
};


PHP_CONTAINER_STARTUP_FUNCTION(ContextualBindingBuilder)
{
    zend_class_entry ContextualBindingBuilderTmp, *ContextualBindingBuilderInterface;
    zend_string *ContextualBindingBuilderInterfaceName, *ContextualBindingBuilderInterfaceNameToLower;
    ContextualBindingBuilderInterfaceName = strpprintf(0, "MContainer\\MContract\\MContextualBindingBuilder");
    ContextualBindingBuilderInterfaceNameToLower = zend_string_tolower(ContextualBindingBuilderInterfaceName);
    INIT_CLASS_ENTRY(ContextualBindingBuilderTmp, "MContainer\\ContextualBindingBuilder", ContextualBindingBuilderMethods);
    if ((ContextualBindingBuilder = zend_register_internal_class(&ContextualBindingBuilderTmp TSRMLS_CC)) == NULL) {
        return FAILURE;
    }

    if ((ContextualBindingBuilderInterface = zend_hash_find_ptr(CG(class_table), ContextualBindingBuilderInterfaceNameToLower)) == NULL) {
        return FAILURE;
    }

    zend_class_implements(ContextualBindingBuilder TSRMLS_CC, 1 , ContextualBindingBuilderInterface);
    zend_string_release(ContextualBindingBuilderInterfaceName);
    zend_string_release(ContextualBindingBuilderInterfaceNameToLower);
    return SUCCESS;
}

