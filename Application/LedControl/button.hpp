#ifndef __BUTTON_H
#define __BUTTON_H

#include "gpio_interface.hpp"
#include <cstdint>

class Button {
public:
    Button(IGpioPin* pin) : pin_(pin) {}
    void update(uint32_t current_time_ms);
    bool is_pressed();

private:
    IGpioPin* pin_; 

    uint8_t btn_current_ = 0;
    uint8_t btn_last_ = 0;
    bool is_debouncing_ = false;
    uint32_t time_debounce_ = 0;
};


#endif // __BUTTON_H