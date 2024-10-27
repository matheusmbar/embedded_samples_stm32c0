cmake_minimum_required(VERSION 3.22)

## Set C and C++ standards
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS -m32)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS -m32)

# Perform compiler test with static library
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

project(stm32c0_sample LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON )

set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)

add_compile_definitions(USE_HAL_DRIVER STM32C011xx)

add_subdirectory(project_lib)

enable_testing()
add_subdirectory(test)
