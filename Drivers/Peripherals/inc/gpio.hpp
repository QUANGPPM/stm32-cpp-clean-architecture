#ifndef __STM32GPIO_HPP
#define __STM32GPIO_HPP

#include "stm32f0xx_hal.h"
#include "Application/Interfaces/gpio_interface.hpp"

class Stm32Gpio : public IGpioPin {
public:
    // NOTE: Port and Pin are ONLY provided via the Constructor
    Stm32Gpio(GPIO_TypeDef* port, uint16_t pin);
    
    // Implementation of the Interface methods
    void write(bool state) override;
    bool read() override;
    void toggle() override;

private:
    // STM32-specific hardware details are encapsulated here, hidden from the Application layer!
    GPIO_TypeDef* port_;
    uint16_t pin_;
};

#endif // __STM32GPIO_HPP
