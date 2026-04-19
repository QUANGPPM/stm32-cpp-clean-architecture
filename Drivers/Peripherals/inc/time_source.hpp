#ifndef __TIME_SOURCE_HPP
#define __TIME_SOURCE_HPP

#include "Application/Interfaces/itime_source.hpp"
#include "stm32f0xx_hal.h"
#include <cstdint>

class TimeSource : public ITimeSource {
public:
    uint32_t get_tick_ms() const override {
        return HAL_GetTick();
    }
};

#endif // __TIME_SOURCE_HPP