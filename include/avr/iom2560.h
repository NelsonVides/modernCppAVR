/* Copyright (c) 2005 Anatoly Sokolov 
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

/* $Id */

/* avr/iom2560.h - definitions for ATmega2560 */

#ifndef _AVR_IOM2560_H_
#define _AVR_IOM2560_H_ 1

#include <avr/iomxx0_1.h>

namespace vAVR {

/* Constants */
constexpr auto SPM_PAGESIZE = 256;
constexpr auto RAMSTART = 0x200;
constexpr auto RAMEND = 0x21FF;
constexpr auto XRAMEND = 0xFFFF;
constexpr auto E2END = 0xFFF;
constexpr auto E2PAGESIZE = 8;
constexpr auto FLASHEND = 0x3FFFF;


/* Fuses */

constexpr auto FUSE_MEMORY_SIZE = 3;

/* Low Fuse Byte */
constexpr auto FUSE_CKSEL0   = static_cast<unsigned char>(~_BV(0x00));
constexpr auto FUSE_CKSEL1   = static_cast<unsigned char>(~_BV(0x01));
constexpr auto FUSE_CKSEL2   = static_cast<unsigned char>(~_BV(0x02));
constexpr auto FUSE_CKSEL3   = static_cast<unsigned char>(~_BV(0x03));
constexpr auto FUSE_SUT0     = static_cast<unsigned char>(~_BV(0x04));
constexpr auto FUSE_SUT1     = static_cast<unsigned char>(~_BV(0x05));
constexpr auto FUSE_CKOUT    = static_cast<unsigned char>(~_BV(0x06));
constexpr auto FUSE_CKDIV8   = static_cast<unsigned char>(~_BV(0x07));
constexpr auto LFUSE_DEFAULT = static_cast<unsigned char>(FUSE_CKSEL0 & FUSE_CKSEL2 & FUSE_CKSEL3 & FUSE_SUT0 & FUSE_CKDIV8);

/* High Fuse Byte */
constexpr auto FUSE_BOOTRST  = static_cast<unsigned char>(~_BV(0x00));
constexpr auto FUSE_BOOTSZ0  = static_cast<unsigned char>(~_BV(0x01));
constexpr auto FUSE_BOOTSZ1  = static_cast<unsigned char>(~_BV(0x02));
constexpr auto FUSE_EESAVE   = static_cast<unsigned char>(~_BV(0x03));
constexpr auto FUSE_WDTON    = static_cast<unsigned char>(~_BV(0x04));
constexpr auto FUSE_SPIEN    = static_cast<unsigned char>(~_BV(0x05));
constexpr auto FUSE_JTAGEN   = static_cast<unsigned char>(~_BV(0x06));
constexpr auto FUSE_OCDEN    = static_cast<unsigned char>(~_BV(0x07));
constexpr auto HFUSE_DEFAULT = static_cast<unsigned char>(FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_SPIEN & FUSE_JTAGEN);

/* Extended Fuse Byte */
constexpr auto FUSE_BODLEVEL0 = static_cast<unsigned char>(~_BV(0x00));
constexpr auto FUSE_BODLEVEL1 = static_cast<unsigned char>(~_BV(0x01));
constexpr auto FUSE_BODLEVEL2 = static_cast<unsigned char>(~_BV(0x02));
constexpr auto EFUSE_DEFAULT  = static_cast<unsigned char>(0xFF);


/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST 


/* Signature */
constexpr auto SIGNATURE_0 = 0x1E;
constexpr auto SIGNATURE_1 = 0x98;
constexpr auto SIGNATURE_2 = 0x01;

constexpr auto SLEEP_MODE_IDLE        = static_cast<unsigned char>(0x00<<1);
constexpr auto SLEEP_MODE_ADC         = static_cast<unsigned char>(0x01<<1);
constexpr auto SLEEP_MODE_PWR_DOWN    = static_cast<unsigned char>(0x02<<1);
constexpr auto SLEEP_MODE_PWR_SAVE    = static_cast<unsigned char>(0x03<<1);
constexpr auto SLEEP_MODE_STANDBY     = static_cast<unsigned char>(0x06<<1);
constexpr auto SLEEP_MODE_EXT_STANDBY = static_cast<unsigned char>(0x07<<1);

} /* end of namespace vAVR */

#endif /* _AVR_IOM2560_H_ */

