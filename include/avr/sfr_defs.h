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
#define _AVR_SFR_DEFS_H_1_

namespace Vavr {

#ifdef __ASSEMBLER__
#define _SFR_ASM_COMPAT 1
#elif !defined(_SFR_ASM_COMPAT)
#define _SFR_ASM_COMPAT 0
#endif

#ifndef __ASSEMBLER__
    /* These only work in C programs.  */
#include <inttypes.h>
    constexpr volatile uint8_t _MMIO_BYTE(auto mem_addr) {
        return (*(volatile uint8_t *)(mem_addr));
    }
    constexpr volatile uint16_t _MMIO_WORD(auto mem_addr) {
        return (*(volatile uint16_t *)(mem_addr));
    }
    constexpr volatile uint32_t _MMIO_DWORD(auto mem_addr) {
        return (*(volatile uint32_t *)(mem_addr));
    }
#endif

#if _SFR_ASM_COMPAT

#ifndef __SFR_OFFSET
/* Define as 0 before including this file for compatibility with old asm
   sources that don't subtract __SFR_OFFSET from symbolic I/O addresses.  */
#  if __AVR_ARCH__ >= 100
#    define __SFR_OFFSET 0x00
#  else
#    define __SFR_OFFSET 0x20
#  endif
#endif

#if (__SFR_OFFSET != 0) && (__SFR_OFFSET != 0x20)
#error "__SFR_OFFSET must be 0 or 0x20"
#endif

constexpr auto _SFR_MEM8(auto mem_addr) { return mem_addr;}
constexpr auto _SFR_MEM16(auto mem_addr) { return mem_addr;}
constexpr auto _SFR_MEM32(auto mem_addr) { return mem_addr;}
constexpr auto _SFR_IO8(auto io_addr) { return io_addr + __SFR_OFFSET;}
constexpr auto _SFR_IO16(auto io_addr) { return io_addr + __SFR_OFFSET;}

constexpr auto _SFR_IO_ADDR(auto sfr) { return sfr - __SFR_OFFSET;}
constexpr auto _SFR_MEM_ADDR(auto sfr) { return sfr;}
constexpr auto _SFR_IO_REG_P(auto sfr) { return sfr < 0x40 + __SFR_OFFSET;}

#if (__SFR_OFFSET == 0x20)
    /* No need to use ?: operator, so works in assembler too.  */
    constexpr auto _SFR_ADDR(auto sfr) {return _SFR_MEM_ADDR(sfr);}
#elif !defined(__ASSEMBLER__)
    constexpr auto _SFR_ADDR(auto sfr) { return (_SFR_IO_REG_P(sfr) ? (_SFR_IO_ADDR(sfr) + 0x20) : _SFR_MEM_ADDR(sfr)); }
#endif

#else  /* !_SFR_ASM_COMPAT */

#ifndef __SFR_OFFSET
#  if __AVR_ARCH__ >= 100
#    define __SFR_OFFSET 0x00
#  else
#    define __SFR_OFFSET 0x20
#  endif
#endif

constexpr auto _SFR_MEM8(auto mem_addr) { return _MMIO_BYTE(mem_addr);}
constexpr auto _SFR_MEM16(auto mem_addr) { return _MMIO_WORD(mem_addr);}
constexpr auto _SFR_MEM32(auto mem_addr) { return _MMIO_DWORD(mem_addr);}
constexpr auto _SFR_IO8(auto io_addr) { return _MMIO_BYTE(io_addr) + __SFR_OFFSET;}
constexpr auto _SFR_IO16(auto io_addr) { return _MMIO_WORD(io_addr) + __SFR_OFFSET;}

constexpr uint16_t _SFR_MEM_ADDR(auto sfr) { return (uint16_t) &sfr;}
constexpr auto _SFR_IO_ADDR(auto sfr) { return _SFR_MEM_ADDR(sfr) - __SFR_OFFSET;}
constexpr auto _SFR_IO_REG_P(auto sfr) { return _SFR_MEM_ADDR(sfr) < 0x40 + __SFR_OFFSET;}

constexpr auto _SFR_ADDR(auto sfr) { return _SFR_MEM_ADDR(sfr);}

#endif /* !_SFR_ASM_COMPAT */

constexpr auto _SFR_BYTE(auto sfr) { return _MMIO_BYTE(_SFR_ADDR(sfr));}
constexpr auto _SFR_WORD(auto sfr) { return _MMIO_WORD(_SFR_ADDR(sfr));}
constexpr auto _SFR_DWORD(auto sfr) { return _MMIO_DWORD(_SFR_ADDR(sfr));}

/** \name Bit manipulation */

/*@{*/
/** \def _BV
    \ingroup avr_sfr

    \code #include <avr/io.h>\endcode

    Converts a bit number into a byte value.

    \note The bit shift is performed by the compiler which then inserts the
    result into the code. Thus, there is no run-time overhead when using
    _BV(). */
    
constexpr auto _BV(auto bit) { return 1 << bit; } __attribute__((always_inline))

/*@}*/

#ifndef _VECTOR
#define _VECTOR(N) __vector_ ## N
#endif

#ifndef __ASSEMBLER__


/** \name IO register bit manipulation */

/*@{*/

/** \def bit_is_set
    \ingroup avr_sfr
    \code #include <avr/io.h>\endcode
    Test whether bit \c bit in IO register \c sfr is set. 
    This will return a 0 if the bit is clear, and non-zero
    if the bit is set. */

constexpr auto bit_is_set(auto sfr, auto bit){ return _SFR_BYTE(sfr) & _BV(bit);} __attribute__((always_inline))

/** \def bit_is_clear
    \ingroup avr_sfr
    \code #include <avr/io.h>\endcode
    Test whether bit \c bit in IO register \c sfr is clear. 
    This will return non-zero if the bit is clear, and a 0
    if the bit is set. */

constexpr auto bit_is_clear(auto sfr, auto bit) { return (!(_SFR_BYTE(sfr) & _BV(bit)));} __attribute__((always_inline))

/** \def loop_until_bit_is_set
    \ingroup avr_sfr
    \code #include <avr/io.h>\endcode
    Wait until bit \c bit in IO register \c sfr is set. */

inline __attribute__((always_inline))
void loop_until_bit_is_set(auto sfr, auto bit) { do{}while(bit_is_clear(sfr,bit));}

/** \def loop_until_bit_is_clear
    \ingroup avr_sfr
    \code #include <avr/io.h>\endcode
    Wait until bit \c bit in IO register \c sfr is clear. */

inline __attribute__((always_inline))
void loop_until_bit_is_clear(auto sfr, auto bit) { do{} while(bit_is_set(sfr,bit));} 

/*@}*/

#endif /* !__ASSEMBLER__ */

} /* namespace Vavr */

#endif  /* _SFR_DEFS_H_ */


