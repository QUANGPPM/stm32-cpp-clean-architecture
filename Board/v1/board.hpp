#ifndef __BOARD_H__
#define __BOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "gpio.h"
#include "usart.h"

void board_init(void);

#ifdef __cplusplus
}

// Include C++ Interfaces
#include "Application/Interfaces/igpio.hpp"

#include "Drivers/Peripherals/inc/gpio.hpp"
// Declare functions that provide hardware objects (returns Interface only)
extern Stm32Gpio board_btn_pin;
extern Stm32Gpio board_led3_pin;
extern Stm32Gpio board_led4_pin;
#endif

#endif // __BOARD_H__
