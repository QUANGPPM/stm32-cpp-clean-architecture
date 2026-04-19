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
#include "Application/Interfaces/gpio_interface.hpp"

// Declare functions that provide hardware objects (returns Interface only)
IGpioPin* board_get_button_pin();
IGpioPin* board_get_led_pin();

#endif

#endif // __BOARD_H__
