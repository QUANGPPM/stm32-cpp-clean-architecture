#ifndef __LED_HPP
#define __LED_HPP

#include "Application/Interfaces/gpio_interface.hpp"

class Led {
public:
    // Inject IGpioPin vào qua constructor
    Led(IGpioPin* pin);

    void turn_on();
    void turn_off();
    void toggle();
    bool is_on();

private:
    IGpioPin* pin_;
    bool current_state_;
};

#endif // __LED_HPP
