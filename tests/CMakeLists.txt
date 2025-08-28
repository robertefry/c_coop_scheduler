
cmake_minimum_required(VERSION 3.12)

file(GLOB_RECURSE GLOB_SOURCES CONFIGURE_DEPENDS "*.c" "*.cc" "*.cpp" "*.cxx" )
add_executable(c_coop_scheduler-tests ${GLOB_SOURCES})

target_include_directories(c_coop_scheduler-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(c_coop_scheduler-tests PUBLIC c_coop_scheduler)

add_test(
  NAME c_coop_scheduler-tests
  COMMAND $<TARGET_FILE:c_coop_scheduler-tests>)

add_custom_target(test-c_coop_scheduler
  COMMAND $<TARGET_FILE:c_coop_scheduler-tests>
  DEPENDS c_coop_scheduler-tests)

CPMAddPackage("gh:catchorg/Catch2@3.10.0")
target_link_libraries(c_coop_scheduler-tests PUBLIC Catch2::Catch2WithMain)
