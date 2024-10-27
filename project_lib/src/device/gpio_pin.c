#include "device/gpio_pin.h"

#include "stm32c0xx_hal.h"
#include "stm32c0xx_hal_gpio.h"

void GpioSetHigh(const Gpio *gpio) {
  if (!gpio || !(gpio->port)) {
    return;
  }
  HAL_GPIO_WritePin(gpio->port, gpio->pin, GPIO_PIN_SET);
}

void GpioSetLow(const Gpio *gpio) {
  if (!gpio || !(gpio->port)) {
    return;
  }
  HAL_GPIO_WritePin(gpio->port, gpio->pin, GPIO_PIN_RESET);
}

void GpioToggle(const Gpio *gpio) {
  if (!gpio || !(gpio->port)) {
    return;
  }
  HAL_GPIO_TogglePin(gpio->port, gpio->pin);
}

GpioLevel GpioGetLevel(const Gpio *gpio) {
  if (!gpio || !(gpio->port)) {
    return kGpioLevelUnknown;
  }
  if (HAL_GPIO_ReadPin(gpio->port, gpio->pin) == GPIO_PIN_RESET) {
    return kGpioLevelLow;
  }
  return kGpioLevelHigh;
}
