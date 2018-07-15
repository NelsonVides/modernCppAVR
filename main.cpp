/*
 * main, to test compilation.
 */

//#include <stl/type_traits.h>
//#include <stl/utility.h>
#include "avr/io.h"
//#include "avr/sfr_defs.h"
//#include "avr/boot.h"
//#include "avr/builtins.h"
//#include "avr/cpufunc.h"
//#include "avr/crc16.h"
//#include "avr/delay.h"
//#include "avr/eeprom.h"
//#include "avr/fuse.h"
#include "avr/interrupt.h"
//#include "avr/lock.h"
//#include "avr/parity.h"
//#include "avr/pgmspace.h"
//#include "avr/power.h"
//#include "avr/signal.h"
//#include "avr/sleep.h"
//#include "avr/wdt.h"
//#define BAUD 76800
//#include "util/setbaud.h"
//#include "util/twi.h"
#include "util/atomic.h"
//#include "stl/cstdint.h"
#include "RTOS/queue.h"
#include "RTOS/AtomicBlock.h"
//#include "RTOS/Mutex.h"
#include "include\RTOS\vTask.h"
#include "include\RTOS\Scheduler.h"

namespace vAVR
{
    using mcu = vAVR::internal::controllers::mega2560;
}

short factorial(short val) {
    return (val == 1 ? 1 : val* factorial(val-1));
}

void mainLoop(long a) {
    while(1) {
        //vAVR::Sync::Mutex<> m((vAVR::Sync::vTask*)42);
        //m.Lock(nullptr);
        long long t = 0;
        ++t;
        vAVR::mcu::PORTA::port<1>::toggle();
        vAVR::mcu::PORTC::set(factorial(t++));
        t *= a;
        //m.Unlock(nullptr);
    }
}

int main(void)
{
    stl::uint16_t ctr = 0;
    do
    {
        //mainLoop(ctr);
    } while (ctr != 0);
}
