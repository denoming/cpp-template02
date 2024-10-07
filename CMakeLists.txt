cmake_minimum_required(VERSION 3.18)

project(Template02
    VERSION 1.0.0
    DESCRIPTION "Plain library application"
)

include(cmake/ProjectOptions.cmake)
include(cmake/ProjectConfigs.cmake)
include(cmake/ProjectInstall.cmake)

add_subdirectory(config)
add_subdirectory(src)
if (TEMPLATE02_ENABLE_TESTS)
    add_subdirectory(test)
endif()
