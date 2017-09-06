cmake_minimum_required(VERSION 3.8)
project(container)

add_custom_target(makefile COMMAND sudo phpize && ./configure -enable-debug  && make && make install
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES
        src/PSRInterface/PSRContainerInterface.c
        src/PSRInterface/PSRContainerInterface.h
        src/ContainerContract.c
        src/ContainerContract.h
        src/MContainer.c
        src/MContainer.h
        src/MContextualBindingBuilder.c
        src/MContextualBindingBuilder.h
        container.c
        php_container.h)

set(PHP_SOURCE /usr/local/Cellar/php71/7.1.8_20/include/php)
include_directories(${PHP_SOURCE}/main)
include_directories(${PHP_SOURCE}/Zend)
include_directories(${PHP_SOURCE}/sapi)
include_directories(${PHP_SOURCE}/pear)
include_directories(${PHP_SOURCE}/TSRM)
include_directories(${PHP_SOURCE})
include_directories(${PROJECT_SOURCE_DIR})

add_executable(container ${SOURCE_FILES})