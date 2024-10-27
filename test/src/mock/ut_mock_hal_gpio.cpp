#include <stm32c0xx_hal.h>
#include <stm32c0xx_hal_gpio.h>

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport_c.h"

TEST_GROUP(MockHalGpio) {
  GPIO_TypeDef port_1;
  GPIO_TypeDef port_2;
  uint16_t pin = 1;
  uint16_t pin_2 = 2;

  void teardown() {
    mock_c()->checkExpectations();
    mock_c()->clear();
  }
};

TEST(MockHalGpio, WritePin) {
  mock_c()
      ->expectOneCall("HAL_GPIO_WritePin")
      ->withConstPointerParameters("GPIO_TypeDef", &port_1)
      ->withUnsignedIntParameters("GPIO_Pin", pin)
      ->withUnsignedIntParameters("PinState", GPIO_PIN_SET);
  HAL_GPIO_WritePin(&port_1, pin, GPIO_PIN_SET);

  mock_c()
      ->expectOneCall("HAL_GPIO_WritePin")
      ->withConstPointerParameters("GPIO_TypeDef", &port_2)
      ->withUnsignedIntParameters("GPIO_Pin", pin_2)
      ->withUnsignedIntParameters("PinState", GPIO_PIN_RESET);
  HAL_GPIO_WritePin(&port_2, pin_2, GPIO_PIN_RESET);
}

TEST(MockHalGpio, Toggle) {
  mock_c()
      ->expectOneCall("HAL_GPIO_TogglePin")
      ->withConstPointerParameters("GPIO_TypeDef", &port_1)
      ->withUnsignedIntParameters("GPIO_Pin", pin);
  HAL_GPIO_TogglePin(&port_1, pin);
}

TEST(MockHalGpio, GetLevel) {
  mock_c()
      ->expectOneCall("HAL_GPIO_ReadPin")
      ->withConstPointerParameters("GPIO_TypeDef", &port_1)
      ->withUnsignedIntParameters("GPIO_Pin", pin)
      ->andReturnUnsignedIntValue(GPIO_PIN_RESET);
  CHECK_EQUAL(GPIO_PIN_RESET, HAL_GPIO_ReadPin(&port_1, pin));

  mock_c()
      ->expectOneCall("HAL_GPIO_ReadPin")
      ->withConstPointerParameters("GPIO_TypeDef", &port_1)
      ->withUnsignedIntParameters("GPIO_Pin", pin)
      ->andReturnUnsignedIntValue(GPIO_PIN_SET);
  CHECK_EQUAL(GPIO_PIN_SET, HAL_GPIO_ReadPin(&port_1, pin));
}
