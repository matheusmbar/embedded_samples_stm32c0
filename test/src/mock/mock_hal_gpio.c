#include "CppUTestExt/MockSupport_c.h"
#include "stm32c0xx_hal.h"
#include "stm32c0xx_hal_gpio.h"

GPIO_PinState HAL_GPIO_ReadPin(const GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
  return mock_c()
      ->actualCall("HAL_GPIO_ReadPin")
      ->withConstPointerParameters("GPIO_TypeDef", GPIOx)
      ->withUnsignedIntParameters("GPIO_Pin", GPIO_Pin)
      ->returnUnsignedIntValueOrDefault(GPIO_PIN_RESET);
}

void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) {
  mock_c()
      ->actualCall("HAL_GPIO_WritePin")
      ->withConstPointerParameters("GPIO_TypeDef", GPIOx)
      ->withUnsignedIntParameters("GPIO_Pin", GPIO_Pin)
      ->withUnsignedIntParameters("PinState", PinState);
}

void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
  mock_c()
      ->actualCall("HAL_GPIO_TogglePin")
      ->withConstPointerParameters("GPIO_TypeDef", GPIOx)
      ->withUnsignedIntParameters("GPIO_Pin", GPIO_Pin);
}
