/*
 * main, to test compilation.
 */

#include <stl/type_traits.h>
#include <stl/utility.h>
#include <avr/io.h>
//#include <avr/boot.h>
//#include <avr/builtins.h>
//#include <avr/cpufunc.h>
//#include <avr/crc16.h>
//#include <avr/delay.h>
//#include <avr/eeprom.h>
//#include <avr/fuse.h>
#include <avr/interrupt.h>
//#include <avr/lock.h>
//#include <avr/parity.h>
//#include <avr/pgmspace.h>
#include <avr/power.h>
//#include <avr/signal.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
//#define BAUD 76800
//#include <util/setbaud.h>
//#include <util/twi.h>
#include <util/atomic.h>
#include <stl/cstdint.h>

short factorial(short val) {
    return (val == 1 ? 1 : val* factorial(val-1));
}

volatile stl::uint16_t ctr;

ISR(TIMER1_OVF_vect)
{
    ctr--;
}

int main(void)
{
    ctr = 0x200;
    sei();
    stl::uint16_t ctr_copy;
    do
    {
        ATOMIC_BLOCK(ATOMIC_FORCEON)
        {
            ctr_copy = ctr;
        }
    }
    while (ctr_copy != 0);
}



