#include "board.hpp"
#include "Drivers/Peripherals/inc/gpio.hpp"

extern "C" void SystemClock_Config(void);

// Initialize specific hardware objects
// Static allocation ensures these objects persist throughout the application's lifetime
static Stm32Gpio stm32_btn_pin(B1_GPIO_Port, B1_Pin);
static Stm32Gpio stm32_led_pin(LD3_GPIO_Port, LD3_Pin);

void board_init(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART1_UART_Init();
}

// Implement functions that provide Interfaces to the Application
IGpioPin* board_get_button_pin() {
    // Automatic upcasting from Stm32Gpio* to IGpioPin*
    return &stm32_btn_pin; 
}

IGpioPin* board_get_led_pin() {
    return &stm32_led_pin;
}
