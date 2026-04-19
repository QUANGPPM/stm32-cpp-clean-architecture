#include "board.hpp"
#include "Drivers/Peripherals/inc/gpio.hpp"

extern "C" void SystemClock_Config(void);

// Initialize specific hardware objects
// Static allocation ensures these objects persist throughout the application's lifetime
Stm32Gpio board_btn_pin(B1_GPIO_Port, B1_Pin);
Stm32Gpio board_led3_pin(LD3_GPIO_Port, LD3_Pin);
Stm32Gpio board_led4_pin(LD4_GPIO_Port, LD4_Pin);
void board_init(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART1_UART_Init();
}
