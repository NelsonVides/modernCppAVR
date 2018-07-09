/* Copyright (c) 2002, Marek Michalkiewicz <marekm@amelek.gda.pl>
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
   POSSIBILITY OF SUCH DAMAGE.  */

/* avr/sfr_defs.h - macros for accessing AVR special function registers */

#ifndef _AVR_SFR_DEFS_H_
#define _AVR_SFR_DEFS_H_

#ifdef __GNUC__
#define __COMPILER__INLINE__ __attribute__( ( always_inline ) ) inline
#else
#define __COMPILER__INLINE__ inline
#endif

namespace vAVR {

#define _SFR_ASM_COMPAT 0

#include <inttypes.h>
    __COMPILER__INLINE__ static uint8_t _MMIO_BYTE(uint8_t mem_addr) {
        return (*(volatile uint8_t *)(mem_addr));
    }
    __COMPILER__INLINE__ static uint16_t _MMIO_WORD(uint16_t mem_addr) {
        return (*(volatile uint16_t *)(mem_addr));
    }
    __COMPILER__INLINE__ static uint32_t _MMIO_DWORD(uint32_t mem_addr) {
        return (*(volatile uint32_t *)(mem_addr));
    }

    constexpr auto __SFR_OFFSET = 0x20;

__COMPILER__INLINE__ static auto _SFR_MEM8(uint8_t mem_addr) { return _MMIO_BYTE(mem_addr);}
__COMPILER__INLINE__ static auto _SFR_MEM16(uint16_t mem_addr) { return _MMIO_WORD(mem_addr);}
__COMPILER__INLINE__ static auto _SFR_MEM32(uint32_t mem_addr) { return _MMIO_DWORD(mem_addr);}
__COMPILER__INLINE__ static auto _SFR_IO8(uint8_t io_addr) { return _MMIO_BYTE(io_addr) + __SFR_OFFSET;}
__COMPILER__INLINE__ static auto _SFR_IO16(uint16_t io_addr) { return _MMIO_WORD(io_addr) + __SFR_OFFSET;}

__COMPILER__INLINE__ static uint16_t _SFR_MEM_ADDR(auto sfr) { return (uint16_t)&sfr;}
__COMPILER__INLINE__ static auto _SFR_IO_ADDR(auto sfr) { return _SFR_MEM_ADDR(sfr) - __SFR_OFFSET;}
__COMPILER__INLINE__ static auto _SFR_IO_REG_P(auto sfr) { return _SFR_MEM_ADDR(sfr) < 0x40 + __SFR_OFFSET;}

__COMPILER__INLINE__ static auto _SFR_ADDR(auto sfr) { return _SFR_MEM_ADDR(sfr);}

__COMPILER__INLINE__ static auto _SFR_BYTE(auto sfr) { return _MMIO_BYTE(_SFR_ADDR(sfr));}
__COMPILER__INLINE__ static auto _SFR_WORD(auto sfr) { return _MMIO_WORD(_SFR_ADDR(sfr));}
__COMPILER__INLINE__ static auto _SFR_DWORD(auto sfr) { return _MMIO_DWORD(_SFR_ADDR(sfr));}

/** \name Bit manipulation */

/*@{*/
/** \def _BV
    \ingroup avr_sfr

    \code #include <avr/io.h>\endcode

    Converts a bit number into a byte value.

    \note The bit shift is performed by the compiler which then inserts the
    result into the code. Thus, there is no run-time overhead when using
    _BV(). */

//uint8_t operator~(uint8_t bit) { return reinterpret_cast<uint8_t>~bit; }
constexpr uint8_t _BV(uint8_t bit) { return 1 << bit; }
//constexpr auto _BV(auto bit) { return 1 << bit; }

/*@}*/

#ifndef _VECTOR
#define _VECTOR(N) __vector_ ## N
#endif


/** \name IO register bit manipulation */

/*@{*/

/** \def bit_is_set
    \ingroup avr_sfr
    \code #include <avr/io.h>\endcode
    Test whether bit \c bit in IO register \c sfr is set. 
    This will return a 0 if the bit is clear, and non-zero
    if the bit is set. */

constexpr auto bit_is_set(auto sfr, auto bit){ return _SFR_BYTE(sfr) & _BV(bit);}

/** \def bit_is_clear
    \ingroup avr_sfr
    \code #include <avr/io.h>\endcode
    Test whether bit \c bit in IO register \c sfr is clear. 
    This will return non-zero if the bit is clear, and a 0
    if the bit is set. */

constexpr auto bit_is_clear(auto sfr, auto bit) { return (!(_SFR_BYTE(sfr) & _BV(bit)));}

/** \def loop_until_bit_is_set
    \ingroup avr_sfr
    \code #include <avr/io.h>\endcode
    Wait until bit \c bit in IO register \c sfr is set. */

inline
void loop_until_bit_is_set(auto sfr, auto bit) { do{}while(bit_is_clear(sfr,bit));}

/** \def loop_until_bit_is_clear
    \ingroup avr_sfr
    \code #include <avr/io.h>\endcode
    Wait until bit \c bit in IO register \c sfr is clear. */

inline
void loop_until_bit_is_clear(auto sfr, auto bit) { do{} while(bit_is_set(sfr,bit));} 

/*@}*/


} /* namespace Vavr */

#endif  /* _SFR_DEFS_H_ */


