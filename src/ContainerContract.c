#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_container.h"
#include "src/ContainerContract.h"
#include "src/PSRInterface/PSRContainerInterface.h"

ZEND_BEGIN_ARG_INFO(boundArgInfo, 0)
ZEND_ARG_INFO(0, abstract)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(aliasArgInfo, 0)
ZEND_ARG_INFO(0, abstract)
ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(tagArgInfo, 0)
ZEND_ARG_INFO(0, abstracts)
ZEND_ARG_INFO(0, tags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(taggedArgInfo, 0)
ZEND_ARG_INFO(0, tag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(bindArgInfo, 0)
ZEND_ARG_INFO(0, abstract)
ZEND_ARG_INFO(0, concrete)
ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(bindIfArgInfo, 0)
ZEND_ARG_INFO(0, abstract)
ZEND_ARG_INFO(0, concrete)
ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()


ZEND_BEGIN_ARG_INFO(singletonArgInfo, 0)
ZEND_ARG_INFO(0, abstract)
ZEND_ARG_INFO(0, concrete)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(extendArgInfo, 0)
ZEND_ARG_INFO(0, abstract)
ZEND_ARG_INFO(0, closure)
ZEND_END_ARG_INFO()


ZEND_BEGIN_ARG_INFO(instanceArgInfo, 0)
ZEND_ARG_INFO(0, abstract)
ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(whenArgInfo, 0)
ZEND_ARG_INFO(0, concrete)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(factoryArgInfo, 0)
ZEND_ARG_INFO(0, abstract)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(makeArgInfo, 0)
ZEND_ARG_INFO(0, abstract)
ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()
 

ZEND_BEGIN_ARG_INFO(callArgInfo, 0)
ZEND_ARG_INFO(0, abstract)
ZEND_ARG_INFO(0, parameters)
ZEND_ARG_INFO(0, defaultMethod)
ZEND_END_ARG_INFO()
 
ZEND_BEGIN_ARG_INFO(resolvedArgInfo, 0)
ZEND_ARG_INFO(0, abstract)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(resolvingArgInfo, 0)
ZEND_ARG_INFO(0, abstract)
ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()


ZEND_BEGIN_ARG_INFO(afterResolvingArgInfo, 0)
ZEND_ARG_INFO(0, abstract)
ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

zend_function_entry ContainerContractMethods[] = {

    /**
     * Determine if the given abstract type has been bound.
     *
     * @param  string  $abstract
     * @return bool
     */
    ZEND_ABSTRACT_ME(ContainerContract, bound, boundArgInfo)

    /**
     * Alias a type to a different name.
     *
     * @param  string  $abstract
     * @param  string  $alias
     * @return void
     */
    ZEND_ABSTRACT_ME(ContainerContract, alias, aliasArgInfo)

    /**
     * Assign a set of tags to a given binding.
     *
     * @param  array|string  $abstracts
     * @param  array|mixed   ...$tags
     * @return void
     */
    ZEND_ABSTRACT_ME(ContainerContract, tag, tagArgInfo)

    /**
     * Resolve all of the bindings for a given tag.
     *
     * @param  array  $tag
     * @return array
     */
    ZEND_ABSTRACT_ME(ContainerContract, tagged, taggedArgInfo)


    /**
     * Register a binding with the container.
     *
     * @param  string|array  $abstract
     * @param  \Closure|string|null  $concrete
     * @param  bool  $shared
     * @return void
     */
    ZEND_ABSTRACT_ME(ContainerContract, bind, bindArgInfo)

    /**
     * Register a binding if it hasn't already been registered.
     *
     * @param  string  $abstract
     * @param  \Closure|string|null  $concrete
     * @param  bool  $shared
     * @return void
     */
    ZEND_ABSTRACT_ME(ContainerContract, bindIf, bindIfArgInfo)


    /**
     * Register a shared binding in the container.
     *
     * @param  string|array  $abstract
     * @param  \Closure|string|null  $concrete
     * @return void
     */
    ZEND_ABSTRACT_ME(ContainerContract, singleton, singletonArgInfo)

    /**
     * "Extend" an abstract type in the container.
     *
     * @param  string    $abstract
     * @param  \Closure  $closure
     * @return void
     *
     * @throws \InvalidArgumentException
     */
    ZEND_ABSTRACT_ME(ContainerContract, extend, extendArgInfo)

    /**
     * Register an existing instance as shared in the container.
     *
     * @param  string  $abstract
     * @param  mixed   $instance
     * @return mixed
     */
    ZEND_ABSTRACT_ME(ContainerContract, instance, instanceArgInfo)

    /**
     * Define a contextual binding.
     *
     * @param  string  $concrete
     * @return \Illuminate\Contracts\Container\ContextualBindingBuilder
     */
    ZEND_ABSTRACT_ME(ContainerContract, when, whenArgInfo)

    /**
     * Get a closure to resolve the given type from the container.
     *
     * @param  string  $abstract
     * @return \Closure
     */
    ZEND_ABSTRACT_ME(ContainerContract, factory, factoryArgInfo)

    /**
     * Resolve the given type from the container.
     *
     * @param  string  $abstract
     * @param  array  $parameters
     * @return mixed
     */
    ZEND_ABSTRACT_ME(ContainerContract, make, makeArgInfo)

    /**
     * Call the given Closure / class@method and inject its dependencies.
     *
     * @param  callable|string  $callback
     * @param  array  $parameters
     * @param  string|null  $defaultMethod
     * @return mixed
     */
    ZEND_ABSTRACT_ME(ContainerContract, call, callArgInfo)

    /**
     * Determine if the given abstract type has been resolved.
     *
     * @param  string $abstract
     * @return bool
     */
    ZEND_ABSTRACT_ME(ContainerContract, resolved, resolvedArgInfo)

    /**
     * Register a new resolving callback.
     *
     * @param  string    $abstract
     * @param  \Closure|null  $callback
     * @return void
     */
    ZEND_ABSTRACT_ME(ContainerContract, resolving, resolvingArgInfo)

    /**
     * Register a new after resolving callback.
     *
     * @param  string    $abstract
     * @param  \Closure|null  $callback
     * @return void
     */
    ZEND_ABSTRACT_ME(ContainerContract, afterResolving, afterResolvingArgInfo)
    PHP_FE_END
};

PHP_CONTAINER_STARTUP_FUNCTION(ContainerContract)
{
    return SUCCESS;
}