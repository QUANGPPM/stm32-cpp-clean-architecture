#ifndef __LED_HPP
#define __LED_HPP

#include "Application/Interfaces/gpio_interface.hpp"

class Led {
public:
    // Inject IGpioPin via reference in the constructor
    // Defined here, it becomes implicitly inline
    Led(IGpioPin& pin) : pin_(pin) {}

    void turn_on() {
        pin_.write(true); 
    }

    void turn_off() {
        pin_.write(false);
    }

    void toggle() {
        pin_.toggle();
    }

    bool is_on() const {
        return pin_.read(); // Read the current state of the LED
    }

private:
    IGpioPin& pin_;
};

#endif // __LED_HPP
