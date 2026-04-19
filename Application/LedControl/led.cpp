#include "led.hpp"

Led::Led(IGpioPin* pin) : pin_(pin), current_state_(false) {
    // Initialize state to OFF
    turn_off();
}

void Led::turn_on() {
    if (pin_ != nullptr) {
        // Note: Logic level (true/false) depends on hardware (Active High or Active Low)
        // If your board pulls LED to GND to light it up (Active Low), change this to false
        pin_->write(true); 
        current_state_ = true;
    }
}

void Led::turn_off() {
    if (pin_ != nullptr) {
        pin_->write(false);
        current_state_ = false;
    }
}

void Led::toggle() {
    if (pin_ != nullptr) {
        pin_->toggle();
        current_state_ = !current_state_;
    }
}

bool Led::is_on() {
    return current_state_;
}
