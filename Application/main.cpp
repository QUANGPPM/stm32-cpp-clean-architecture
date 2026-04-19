#include "Board/v1/board.hpp"
#include "Application/LedControl/button.hpp"
#include "Application/LedControl/led.hpp"
#include "Application/Interfaces/itime_source.hpp"
typedef enum {
    BOTH_OFF = 0,
    LED3_ON,
    LED4_ON,
    BOTH_ON
} LedState;
LedState current_state = BOTH_OFF;

Button button(board_btn_pin);
Led led3(board_led3_pin);
Led led4(board_led4_pin);
TimeSource time_source;

void switch_state(LedState state, Led& led3, Led& led4) {
    switch (state) {
        case BOTH_OFF:
            led3.turn_off();
            led4.turn_off();
            break;
        case LED3_ON:
            led3.turn_on();
            led4.turn_off();
            break;
        case LED4_ON:
            led4.turn_on();
            led3.turn_off();
            break;
        case BOTH_ON:
            led3.turn_on();
            led4.turn_on();
            break;
    }

}

int main() {
    // 1. Initialize MCU
    board_init();

    // 2. Main loop
    uint8_t flag = 0;
    while (1) {
        switch_state(current_state, led3, led4);

        button.update(time_source.get_tick_ms());
        if (button.is_pressed() && !flag) {
            // Cycle through states on each button press
            flag = 1;
            current_state = static_cast<LedState>((current_state + 1) % 4);
        }
        if(!button.is_pressed()) {
            flag = 0;
        }

    }
}
