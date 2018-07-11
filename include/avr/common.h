/* Copyright (c) 2007 Eric B. Weddington
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

  /* $Id$ */


#ifndef _AVR_COMMON_H
#define _AVR_COMMON_H

#include "../avr/sfr_defs.h"
#include "../avr/registers.h"

namespace vAVR {
    namespace internal {
        namespace common {

            /*
            This purpose of this header is to define registers that have not been
            previously defined in the individual device IO header files, and to define
            other symbols that are common across AVR device families.

            This file is designed to be included in <avr/io.h> after the individual
            device IO header files, and after <avr/sfr_defs.h>
            */

            /*------------ Registers Not Previously Defined ------------*/

            /*
            These are registers that are not previously defined in the individual
            IO header files, OR they are defined here because they are used in parts of
            avr-libc even if a device is not selected but a general architecture has
            been selected.
            */

            struct commonChip {
                ~commonChip() = delete;

                using SP  = registers::rw_io_register<0x5D, 16, 0b1111111111111111>;
                using SPL = registers::rw_io_register<0x5D, 8, 0b11111111>;
                using SPH = registers::rw_io_register<0x5E, 8, 0b00000111>;

                using SREG = registers::rw_io_register<0x5F, 8, 0b11111111>;
                using SREG_C = registers::rw_bit<SREG, 0>;
                using SREG_Z = registers::rw_bit<SREG, 1>;
                using SREG_N = registers::rw_bit<SREG, 2>;
                using SREG_V = registers::rw_bit<SREG, 3>;
                using SREG_S = registers::rw_bit<SREG, 4>;
                using SREG_H = registers::rw_bit<SREG, 5>;
                using SREG_T = registers::rw_bit<SREG, 6>;
                using SREG_I = registers::rw_bit<SREG, 7>;

                using XL = registers::rw_io_register<0x5F, 8, 0b11111111>;
                using XH = registers::rw_io_register<0x5F, 8, 0b11111111>;
                using YL = registers::rw_io_register<0x5F, 8, 0b11111111>;
                using YH = registers::rw_io_register<0x5F, 8, 0b11111111>;
                using ZL = registers::rw_io_register<0x5F, 8, 0b11111111>;
                using ZH = registers::rw_io_register<0x5F, 8, 0b11111111>;
            };

        }
    }
} /* end of all three nested namespaces vAVR::internal::common */

#endif /* _AVR_COMMON_H */
