#include "Drivers/Peripherals/inc/gpio.hpp"

Stm32Gpio::Stm32Gpio(GPIO_TypeDef* port, uint16_t pin) 
    : port_(port), pin_(pin) {}

void Stm32Gpio::write(bool state) {
    HAL_GPIO_WritePin(port_, pin_, state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

bool Stm32Gpio::read() {
    return HAL_GPIO_ReadPin(port_, pin_) == GPIO_PIN_SET;
}

void Stm32Gpio::toggle() {
    HAL_GPIO_TogglePin(port_, pin_);
}
