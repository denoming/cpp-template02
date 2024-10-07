include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Generate package config
set(cmakeModulesDir "${CMAKE_INSTALL_LIBDIR}/cmake/MyCalculator")
configure_package_config_file(
        ${CMAKE_CURRENT_LIST_DIR}/MyCalculatorConfig.cmake.in
        MyCalculatorConfig.cmake
    INSTALL_DESTINATION
        ${cmakeModulesDir}
    PATH_VARS
        cmakeModulesDir
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

# Generate version file
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/MyCalculatorConfigVersion.cmake
    COMPATIBILITY SameMajorVersion
)

# Install package config
install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/MyCalculatorConfig.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyCalculator
    COMPONENT MyCalculatorDevelopment
)

# Install version file
install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/MyCalculatorConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyCalculator
    COMPONENT MyCalculatorDevelopment
)