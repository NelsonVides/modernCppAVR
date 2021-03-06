#ifndef AVR_INTERNAL_CONTROLLERS_MEGA328P_H
#define AVR_INTERNAL_CONTROLLERS_MEGA328P_H

#include <avr/registers.h>

namespace vAVR {
    namespace internal {
        namespace controllers {

    struct mega328p
    {
        ~mega328p() = delete;
        
        /* I/O registers are being given memory addresses instead of I/O addresses.
         * This is how the C/C++ compiler will interpret the addresses, mapping the range
         * [0x20-0xff] to in/out instructions in [0x00-0xdf] */

        using pinb = registers::pin_register<0x23, 0b11111111>;
        using ddrb = registers::ddr_register<0x24, 0b11111111>;
        using portb = registers::port_register<0x25, 0b11111111>;

        using pinc = registers::pin_register<0x26, 0b01111111>;
        using ddrc = registers::ddr_register<0x27, 0b01111111>;
        using portc = registers::port_register<0x28, 0b01111111>;

        using pind = registers::pin_register<0x29, 0b11111111>;
        using ddrd = registers::ddr_register<0x2a, 0b11111111>;
        using portd = registers::port_register<0x2b, 0b11111111>;
    };
}}}

namespace vAVR { using mcu = vAVR::internal::controllers::mega328p; }

#endif

