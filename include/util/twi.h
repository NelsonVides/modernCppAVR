/* Copyright (c) 2002, Marek Michalkiewicz
   Copyright (c) 2005, 2007 Joerg Wunsch
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
/* copied from: Id: avr/twi.h,v 1.4 2004/11/01 21:19:54 arcanum Exp */

#ifndef _UTIL_TWI_H_
#define _UTIL_TWI_H_ 1

#include <avr/io.h>

namespace vAVR {
    namespace TWI {
        /** \file */
        /** \defgroup util_twi <util/twi.h>: TWI bit mask definitions
          \code #include <util/twi.h> \endcode

          This header file contains bit mask definitions for use with
          the AVR TWI interface.
          */
        /** \name TWSR values

Mnemonics:
<br>TW_MT_xxx - master transmitter
<br>TW_MR_xxx - master receiver
<br>TW_ST_xxx - slave transmitter
<br>TW_SR_xxx - slave receiver
*/

        enum class TWI : stl::uint8_t {
            TW_START                 = 0x08,
            TW_REP_START             = 0x10,
            TW_MT_SLA_ACK            = 0x18,
            TW_MT_SLA_NACK           = 0x20,
            TW_MT_DATA_ACK           = 0x28,
            TW_MT_DATA_NACK          = 0x30,
            TW_MT_ARB_LOST           = 0x38,
            TW_MR_ARB_LOST           = 0x38,
            TW_MR_SLA_ACK            = 0x40,
            TW_MR_SLA_NACK           = 0x48,
            TW_MR_DATA_ACK           = 0x50,
            TW_MR_DATA_NACK          = 0x58,
            TW_ST_SLA_ACK            = 0xA8,
            TW_ST_ARB_LOST_SLA_ACK   = 0xB0,
            TW_ST_DATA_ACK           = 0xB8,
            TW_ST_DATA_NACK          = 0xC0,
            TW_ST_LAST_DATA          = 0xC8,
            TW_SR_SLA_ACK            = 0x60,
            TW_SR_ARB_LOST_SLA_ACK   = 0x68,
            TW_SR_GCALL_ACK          = 0x70,
            TW_SR_ARB_LOST_GCALL_ACK = 0x78,
            TW_SR_DATA_ACK           = 0x80,
            TW_SR_DATA_NACK          = 0x88,
            TW_SR_GCALL_DATA_ACK     = 0x90,
            TW_SR_GCALL_DATA_NACK    = 0x98,
            TW_SR_STOP               = 0xA0,
            TW_NO_INFO               = 0xF8,
            TW_BUS_ERROR             = 0x00,
            TW_READ                  = 0x01,
            TW_WRITE                 = 0x00
        };

        __attribute__((always_inline)) static inline auto constexpr TW_STATUS_MASK()
        { 
            return (  _BV( mcu::TWS7::get())
                    | _BV( mcu::TWS6::get())
                    | _BV( mcu::TWS5::get())
                    | _BV( mcu::TWS4::get())
                    | _BV( mcu::TWS3::get())
                    );
        }
        
        __attribute__((always_inline)) inline auto TW_STATUS()
        { 
            return (mcu::TWSR::get() & TW_STATUS_MASK()); 
        }

    }
} /* end of namespace vAVR */

#endif  /* _UTIL_TWI_H_ */
