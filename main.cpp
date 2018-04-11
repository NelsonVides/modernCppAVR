/*
 * main, to test compilation.
 */

#include <stl/type_traits.h>
#include <stl/utility.h>
#include <avr/io.h>
#include "mega328p.h"

int main()
{
    //if(vAVR::mcu::portb::port<3>::get())
    //{
        vAVR::mcu::portb::port<7>::set();
    //}
    //else
    //{
        vAVR::mcu::portb::port<7>::get();
    //}
}

