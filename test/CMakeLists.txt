cmake_minimum_required(VERSION 3.22)

include(CTest)

# CppUTest
include(FetchContent)
FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        master
    SOURCE_DIR     "${CMAKE_SOURCE_DIR}/thirdy-party/cpputest"
)
# Set this to ON if you want to have the CppUTests in your project as well.
set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")
FetchContent_MakeAvailable(CppUTest)

set(TEST_NAME run_tests)

add_executable(${TEST_NAME}
  src/main.cpp
  src/ut_basic.cpp
  src/ut_dummy.cpp
  src/mock/mock_hal_gpio.c
  src/mock/ut_mock_hal_gpio.cpp
  src/device/ut_gpio_pin.cpp
)

target_include_directories(${TEST_NAME}
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${TEST_NAME} PRIVATE
  CppUTest::CppUTest
  CppUTest::CppUTestExt
  project_lib
)

# Auto discover tests for CTest unless disabled
if(CPPUTEST_TEST_DISCOVERY OR NOT DEFINED CPPUTEST_TEST_DISCOVERY)
  include(CppUTest)
  cpputest_discover_tests(${TEST_NAME})
endif()
