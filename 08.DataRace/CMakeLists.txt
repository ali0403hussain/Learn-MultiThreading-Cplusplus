cmake_minimum_required(VERSION 3.22)

#Project Parameters- define
set(PROJECT_NAME "DataRace")
set(PROJECT_VERSION 1.0.0)

#Project Parameters Config
project(
    ${PROJECT_NAME}
    VERSION ${PROJECT_VERSION}
    LANGUAGES CXX
)

#Project CMake Config
set(CMAKE_CXX_STANDARD            17)
set(CMAKE_CXX_STANDARD_REQUIRED   ON)
set(CMAKE_CXX_EXTENSIONS          OFF)
set(CMAKE_BUILD_TYPE              Debug)

#Project Files Varibale
set(EXE ${PROJECT_NAME})

#%%%%%%%%%%%%%%%%% Enable CMake Features %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#Defining Path for cmake features
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

#Enable warnings and treat warnings as error
option(ENABLE_WARNINGS "Enable Warnings" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable Warnings as Errors" ON)

#Enable Sanitizers
option(ENABLE_SANITIZE_ADDR "Enable Sanitizer address" ON)
option(ENABLE_SANITIZE_UNDEF "Enable Sanitizer Undefined" ON)

#%%%%%%%%%%%%%%%%% Enable CMake Features Ends %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if(${ENABLE_WARNINGS})
    include(warnings)
    message(STATUS "Warnings Enabled for:${CMAKE_CXX_COMPILER_ID}")
endif()

if((${NABLE_SANITIZE_ADDR}) OR (${ENABLE_SANITIZE_UNDEF}))
    include(Sanitizers)
    add_sanitizers_flags()
endif()

add_subdirectory(src)