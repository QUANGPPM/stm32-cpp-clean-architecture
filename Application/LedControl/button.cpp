#include "button.hpp"

Button::Button(IGpioPin& pin) : pin_(pin) {}

void Button::update(uint32_t current_time_ms) {
        // Read hardware via Interface (no direct HAL_GPIO_ReadPin call)
        bool current_state = pin_.read(); 

        // --- Debounce Logic ---
        if (current_state != btn_last_) {
            is_debouncing_ = true;
            time_debounce_ = current_time_ms;
        }
        
        if (is_debouncing_ && (current_time_ms - time_debounce_ > 20)) {
            btn_current_ = current_state;
            is_debouncing_ = false;
        }
        btn_last_ = current_state;
    }

bool Button::is_pressed() const {
    return btn_current_ == 1;
}