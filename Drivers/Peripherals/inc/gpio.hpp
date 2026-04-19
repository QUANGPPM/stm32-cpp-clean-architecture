#ifndef __STM32GPIO_HPP
#define __STM32GPIO_HPP

#include "stm32f0xx_hal.h"
#include "Application/Interfaces/igpio.hpp"

class Stm32Gpio : public IGpioPin {
public:
    // NOTE: Port and Pin are ONLY provided via the Constructor
    Stm32Gpio(GPIO_TypeDef* port, uint16_t pin) 
        : port_(port), pin_(pin) {}
    
    // Implementation of the Interface methods
    // Defined in the header to allow for inlining (zero-cost abstraction)
    void write(bool state) override {
        HAL_GPIO_WritePin(port_, pin_, state ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }

    bool read() const override {
        return HAL_GPIO_ReadPin(port_, pin_) == GPIO_PIN_SET;
    }

    void toggle() override {
        HAL_GPIO_TogglePin(port_, pin_);
    }

private:
    // STM32-specific hardware details are encapsulated here, hidden from the Application layer!
    GPIO_TypeDef* port_;
    uint16_t pin_;
};

#endif // __STM32GPIO_HPP
