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
#include "Application/Interfaces/itime_source.hpp"

// Include C++ Implementation
#include "Drivers/Peripherals/inc/gpio.hpp"
#include "Drivers/Peripherals/inc/time_source.hpp"
// Declare functions that provide hardware objects (returns Interface only)
extern Gpio board_btn_pin;
extern Gpio board_led3_pin;
extern Gpio board_led4_pin;
extern TimeSource board_time_source;
#endif

#endif // __BOARD_H__
