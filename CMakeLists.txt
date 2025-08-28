
cmake_minimum_required(VERSION 3.12)
include(cmake/get_cpm.cmake)

project("c_coop_scheduler" VERSION "0.1.0" LANGUAGES "C" "CXX"
  HOMEPAGE_URL "https://github.com/robertefry/c_coop_scheduler"
  DESCRIPTION "A lightweight cooperative scheduler for embedded applications.")

file(GLOB_RECURSE GLOB_SOURCES CONFIGURE_DEPENDS "src/*.c")
add_library(c_coop_scheduler STATIC ${GLOB_SOURCES})

target_include_directories(c_coop_scheduler
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(c_coop_scheduler
  PRIVATE
    -Werror
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wunused
    -Wconversion
    -Wsign-conversion
    -Wcast-align
    -Wdouble-promotion
    -Wnull-dereference
)

enable_testing()
add_subdirectory(tests)
