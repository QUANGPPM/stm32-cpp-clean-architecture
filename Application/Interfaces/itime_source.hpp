#ifndef __ITIME_SOURCE_HPP
#define __ITIME_SOURCE_HPP

#include <cstdint>

class ITimeSource {
public:
    virtual ~ITimeSource() = default;
    
    // Returns the current tick count in milliseconds
    virtual uint32_t get_tick_ms() const = 0;            
};

#endif // __ITIME_SOURCE_HPP