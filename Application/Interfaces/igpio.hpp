#ifndef __IGPIOPIN_HPP
#define __IGPIOPIN_HPP

// This is a "Contract" (Interface) for GPIO pins
class IGpioPin {
public:
    virtual ~IGpioPin() = default;
    
    virtual void write(bool state) = 0;
    virtual bool read() const = 0;            
    virtual void toggle() = 0;         
};

#endif // __IGPIOPIN_HPP
