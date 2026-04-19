#include "Board/v1/board.hpp"
// No need to include "Drivers/Peripherals/gpio.hpp" anymore!
#include "Application/LedControl/button.hpp"
#include "Application/LedControl/led.hpp"

int main() {
    // 1. Initialize MCU
    board_init();

    // 2. Retrieve hardware instances from Board (Interfaces only)
    IGpioPin* btn_pin = board_get_button_pin();
    IGpioPin* led_pin = board_get_led_pin();

    // 3. Inject into Application Logic
    Button my_button(btn_pin);
    Led my_led(led_pin);

    // 4. Main loop
    uint32_t current_time = 0;
    while (1) {
        current_time = HAL_GetTick(); // Hint: You can create an ITime interface for this as well
        my_button.update(current_time);

        if (my_button.is_pressed()) {
            my_led.turn_on();
        } else {
            my_led.turn_off();
        }
    }
}
