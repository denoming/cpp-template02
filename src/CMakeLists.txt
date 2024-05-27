include(GNUInstallDirs)
include(GenerateExportHeader)
include(CMakePackageConfigHelpers)

set(TARGET MyCalculatorLib)

add_library(${TARGET} SHARED)
add_library(My::Calculator ALIAS ${TARGET})

set_target_properties(${TARGET}
    PROPERTIES
        OUTPUT_NAME calculator
        EXPORT_NAME Calculator
)

set_target_properties(${TARGET}
    PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN YES
        COMPATIBLE_INTERFACE_BOOL FLOAT_SUPPORT
        INTERFACE_FLOAT_SUPPORT YES
)

target_include_directories(${TARGET}
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
           $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

target_sources(${TARGET}
    PRIVATE
        Calculator.cpp
        CalculatorImpl.hpp
        CalculatorImpl.cpp
)

target_compile_features(${TARGET} PUBLIC cxx_std_17)

# Generate export header file with export macros
generate_export_header(${TARGET}
    BASE_NAME CALC
    EXPORT_FILE_NAME CalculatorExport.hpp
)

# Install target files except namelink file
install(TARGETS ${TARGET}
    EXPORT MyCalculatorRuntime
    LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT MyCalculatorRuntime
        NAMELINK_SKIP
    INCLUDES
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install target namelink file
install(TARGETS ${TARGET}
    EXPORT MyCalculatorDevelopment
    LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT MyCalculatorDevelopment
        NAMELINK_ONLY
    ARCHIVE
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT MyCalculatorDevelopment
    INCLUDES
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install package config file
install(EXPORT MyCalculatorRuntime
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyCalculator
    NAMESPACE My::
    COMPONENT MyCalculatorRuntime
    FILE MyCalculatorRuntime.cmake
)

# Install package config file
install(EXPORT MyCalculatorDevelopment
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyCalculator
    NAMESPACE My::
    COMPONENT MyCalculatorDevelopment
    FILE MyCalculatorDevelopment.cmake
)

# Install library header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    TYPE INCLUDE
    COMPONENT MyCalculatorDevelopment
    FILES_MATCHING
        PATTERN *.hpp
)

# Install export header file
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/CalculatorExport.hpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/calculator
    COMPONENT MyCalculatorDevelopment
)

# Generate package config and version file
configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/config/MyCalculatorConfig.cmake.in
    MyCalculatorConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyCalculator
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/MyCalculatorConfigVersion.cmake
    COMPATIBILITY SameMajorVersion
)

# Install package config and version file
install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/MyCalculatorConfig.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyCalculator
    COMPONENT MyCalculatorDevelopment
)
install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/MyCalculatorConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyCalculator
    COMPONENT MyCalculatorDevelopment
)
