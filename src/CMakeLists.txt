include(GNUInstallDirs)
include(GenerateExportHeader)

set(TARGET MyCalculatorLib)

add_library(${TARGET} SHARED)
add_library(My::Calculator ALIAS ${TARGET})

set_target_properties(${TARGET}
    PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        OUTPUT_NAME calculator
        EXPORT_NAME Calculator
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN YES
)

target_compile_features(${TARGET} PUBLIC cxx_std_20)

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

generate_export_header(${TARGET}
    BASE_NAME CALC
    EXPORT_FILE_NAME calculator/CalculatorExport.hpp
)

target_sources(${TARGET}
    INTERFACE
        FILE_SET HEADERS
        BASE_DIRS "${PROJECT_SOURCE_DIR}/include"
                  "${CMAKE_CURRENT_BINARY_DIR}"
        FILES "${PROJECT_SOURCE_DIR}/include/calculator/Calculator.hpp"
              ${CMAKE_CURRENT_BINARY_DIR}/calculator/CalculatorExport.hpp
)

install(TARGETS ${TARGET}
    EXPORT MyCalculator
    LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT MyCalculatorRuntime
        NAMELINK_COMPONENT MyCalculatorDevelopment
    ARCHIVE
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT MyCalculatorDevelopment
    FILE_SET HEADERS
        COMPONENT MyCalculatorDevelopment
    INCLUDES
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT MyCalculator
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyCalculator
    NAMESPACE My::
    COMPONENT MyCalculatorDevelopment
)
