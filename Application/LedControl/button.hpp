#ifndef __BUTTON_H
#define __BUTTON_H

#include "Application/Interfaces/igpio.hpp"
#include <cstdint>

class Button {
public:
    Button(IGpioPin& pin);
    void update(uint32_t current_time_ms);
    bool is_pressed() const;

private:
    IGpioPin& pin_; 

    uint8_t btn_current_ = 0;
    uint8_t btn_last_ = 0;
    bool is_debouncing_ = false;
    uint32_t time_debounce_ = 0;
};


#endif // __BUTTON_H