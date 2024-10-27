cmake_minimum_required(VERSION 3.22)

set(LIB_NAME project_lib)

add_library(${LIB_NAME} "")

target_include_directories(${LIB_NAME}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include

    ${CMAKE_SOURCE_DIR}/Core/Inc
    ${CMAKE_SOURCE_DIR}/Drivers/STM32C0xx_HAL_Driver/Inc
    ${CMAKE_SOURCE_DIR}/Drivers/STM32C0xx_HAL_Driver/Inc/Legacy
    ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/Device/ST/STM32C0xx/Include
    ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/Include
)

target_sources(${LIB_NAME}
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/dummy.c
    ${CMAKE_CURRENT_LIST_DIR}/src/device/gpio_pin.c
)
