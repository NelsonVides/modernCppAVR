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

/* $Id: iomxx0_1.h 2235 2011-03-17 04:13:14Z arcanum $ */

/* avr/iomxx0_1.h - definitions for ATmega640, Atmega1280, ATmega1281,
   ATmega2560 and ATmega2561. */

#ifndef _AVR_IOMXX0_1_H_
#define _AVR_IOMXX0_1_H_ 1

/* This file should only be included from <avr/io.h>, never directly. */

namespace vAVR {

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iomxx0_1.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 

#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
# define __ATmegaxx0__
#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
# define __ATmegaxx1__
#endif

/* Registers and associated bit numbers */

#define PINA    _SFR_IO8(0X00)
constexpr auto PINA7 = 0x07;
constexpr auto PINA6 = 0x06;
constexpr auto PINA5 = 0x05;
constexpr auto PINA4 = 0x04;
constexpr auto PINA3 = 0x03;
constexpr auto PINA2 = 0x02;
constexpr auto PINA1 = 0x01;
constexpr auto PINA0 = 0x00;

#define DDRA    _SFR_IO8(0X01)
constexpr auto DDA7 = 0x07;
constexpr auto DDA6 = 0x06;
constexpr auto DDA5 = 0x05;
constexpr auto DDA4 = 0x04;
constexpr auto DDA3 = 0x03;
constexpr auto DDA2 = 0x02;
constexpr auto DDA1 = 0x01;
constexpr auto DDA0 = 0x00;

#define PORTA   _SFR_IO8(0X02)
constexpr auto PA7 = 0x07;
constexpr auto PA6 = 0x06;
constexpr auto PA5 = 0x05;
constexpr auto PA4 = 0x04;
constexpr auto PA3 = 0x03;
constexpr auto PA2 = 0x02;
constexpr auto PA1 = 0x01;
constexpr auto PA0 = 0x00;

#define PINB    _SFR_IO8(0X03)
constexpr auto PINB7 = 0x07;
constexpr auto PINB6 = 0x06;
constexpr auto PINB5 = 0x05;
constexpr auto PINB4 = 0x04;
constexpr auto PINB3 = 0x03;
constexpr auto PINB2 = 0x02;
constexpr auto PINB1 = 0x01;
constexpr auto PINB0 = 0x00;

#define DDRB    _SFR_IO8(0x04)
constexpr auto DDB7 = 0x07;
constexpr auto DDB6 = 0x06;
constexpr auto DDB5 = 0x05;
constexpr auto DDB4 = 0x04;
constexpr auto DDB3 = 0x03;
constexpr auto DDB2 = 0x02;
constexpr auto DDB1 = 0x01;
constexpr auto DDB0 = 0x00;

#define PORTB   _SFR_IO8(0x05)
constexpr auto PB7 = 0x07;
constexpr auto PB6 = 0x06;
constexpr auto PB5 = 0x05;
constexpr auto PB4 = 0x04;
constexpr auto PB3 = 0x03;
constexpr auto PB2 = 0x02;
constexpr auto PB1 = 0x01;
constexpr auto PB0 = 0x00;

#define PINC    _SFR_IO8(0x06)
constexpr auto PINC7 = 0x07;
constexpr auto PINC6 = 0x06;
constexpr auto PINC5 = 0x05;
constexpr auto PINC4 = 0x04;
constexpr auto PINC3 = 0x03;
constexpr auto PINC2 = 0x02;
constexpr auto PINC1 = 0x01;
constexpr auto PINC0 = 0x00;

#define DDRC    _SFR_IO8(0x07)
constexpr auto DDC7 = 0x07;
constexpr auto DDC6 = 0x06;
constexpr auto DDC5 = 0x05;
constexpr auto DDC4 = 0x04;
constexpr auto DDC3 = 0x03;
constexpr auto DDC2 = 0x02;
constexpr auto DDC1 = 0x01;
constexpr auto DDC0 = 0x00;

#define PORTC   _SFR_IO8(0x08)
constexpr auto PC7 = 0x07;
constexpr auto PC6 = 0x06;
constexpr auto PC5 = 0x05;
constexpr auto PC4 = 0x04;
constexpr auto PC3 = 0x03;
constexpr auto PC2 = 0x02;
constexpr auto PC1 = 0x01;
constexpr auto PC0 = 0x00;

#define PIND    _SFR_IO8(0x09)
constexpr auto PIND7 = 0x07;
constexpr auto PIND6 = 0x06;
constexpr auto PIND5 = 0x05;
constexpr auto PIND4 = 0x04;
constexpr auto PIND3 = 0x03;
constexpr auto PIND2 = 0x02;
constexpr auto PIND1 = 0x01;
constexpr auto PIND0 = 0x00;

#define DDRD    _SFR_IO8(0x0A)
constexpr auto DDD7 = 0x07;
constexpr auto DDD6 = 0x06;
constexpr auto DDD5 = 0x05;
constexpr auto DDD4 = 0x04;
constexpr auto DDD3 = 0x03;
constexpr auto DDD2 = 0x02;
constexpr auto DDD1 = 0x01;
constexpr auto DDD0 = 0x00;

#define PORTD   _SFR_IO8(0x0B)
constexpr auto PD7 = 0x07;
constexpr auto PD6 = 0x06;
constexpr auto PD5 = 0x05;
constexpr auto PD4 = 0x04;
constexpr auto PD3 = 0x03;
constexpr auto PD2 = 0x02;
constexpr auto PD1 = 0x01;
constexpr auto PD0 = 0x00;

#define PINE    _SFR_IO8(0x0C)
constexpr auto PINE7 = 0x07;
constexpr auto PINE6 = 0x06;
constexpr auto PINE5 = 0x05;
constexpr auto PINE4 = 0x04;
constexpr auto PINE3 = 0x03;
constexpr auto PINE2 = 0x02;
constexpr auto PINE1 = 0x01;
constexpr auto PINE0 = 0x00;

#define DDRE    _SFR_IO8(0x0D)
constexpr auto DDE7 = 0x07;
constexpr auto DDE6 = 0x06;
constexpr auto DDE5 = 0x05;
constexpr auto DDE4 = 0x04;
constexpr auto DDE3 = 0x03;
constexpr auto DDE2 = 0x02;
constexpr auto DDE1 = 0x01;
constexpr auto DDE0 = 0x00;

#define PORTE   _SFR_IO8(0x0E)
constexpr auto PE7 = 0x07;
constexpr auto PE6 = 0x06;
constexpr auto PE5 = 0x05;
constexpr auto PE4 = 0x04;
constexpr auto PE3 = 0x03;
constexpr auto PE2 = 0x02;
constexpr auto PE1 = 0x01;
constexpr auto PE0 = 0x00;

#define PINF    _SFR_IO8(0x0F)
constexpr auto PINF7 = 0x07;
constexpr auto PINF6 = 0x06;
constexpr auto PINF5 = 0x05;
constexpr auto PINF4 = 0x04;
constexpr auto PINF3 = 0x03;
constexpr auto PINF2 = 0x02;
constexpr auto PINF1 = 0x01;
constexpr auto PINF0 = 0x00;

#define DDRF    _SFR_IO8(0x10)
constexpr auto DDF7 = 0x07;
constexpr auto DDF6 = 0x06;
constexpr auto DDF5 = 0x05;
constexpr auto DDF4 = 0x04;
constexpr auto DDF3 = 0x03;
constexpr auto DDF2 = 0x02;
constexpr auto DDF1 = 0x01;
constexpr auto DDF0 = 0x00;

#define PORTF   _SFR_IO8(0x11)
constexpr auto PF7 = 0x07;
constexpr auto PF6 = 0x06;
constexpr auto PF5 = 0x05;
constexpr auto PF4 = 0x04;
constexpr auto PF3 = 0x03;
constexpr auto PF2 = 0x02;
constexpr auto PF1 = 0x01;
constexpr auto PF0 = 0x00;

#define PING    _SFR_IO8(0x12)
constexpr auto PING5 = 0x05;
constexpr auto PING4 = 0x04;
constexpr auto PING3 = 0x03;
constexpr auto PING2 = 0x02;
constexpr auto PING1 = 0x01;
constexpr auto PING0 = 0x00;

#define DDRG    _SFR_IO8(0x13)
constexpr auto DDG5 = 0x05;
constexpr auto DDG4 = 0x04;
constexpr auto DDG3 = 0x03;
constexpr auto DDG2 = 0x02;
constexpr auto DDG1 = 0x01;
constexpr auto DDG0 = 0x00;

#define PORTG   _SFR_IO8(0x14)
constexpr auto PG5 = 0x05;
constexpr auto PG4 = 0x04;
constexpr auto PG3 = 0x03;
constexpr auto PG2 = 0x02;
constexpr auto PG1 = 0x01;
constexpr auto PG0 = 0x00;

#define TIFR0   _SFR_IO8(0x15)
constexpr auto OCF0B = 0x02;
constexpr auto OCF0A = 0x01;
constexpr auto TOV0 = 0x00;

#define TIFR1   _SFR_IO8(0x16)
constexpr auto ICF1 = 0x05;
constexpr auto OCF1C = 0x03;
constexpr auto OCF1B = 0x02;
constexpr auto OCF1A = 0x01;
constexpr auto TOV1 = 0x00;

#define TIFR2   _SFR_IO8(0x17)
constexpr auto OCF2B = 0x02;
constexpr auto OCF2A = 0x01;
constexpr auto TOV2 = 0x00;

#define TIFR3   _SFR_IO8(0x18)
constexpr auto ICF3 = 0x05;
constexpr auto OCF3C = 0x03;
constexpr auto OCF3B = 0x02;
constexpr auto OCF3A = 0x01;
constexpr auto TOV3 = 0x00;

#define TIFR4   _SFR_IO8(0x19)
constexpr auto ICF4 = 0x05;
constexpr auto OCF4C = 0x03;
constexpr auto OCF4B = 0x02;
constexpr auto OCF4A = 0x01;
constexpr auto TOV4 = 0x00;

#define TIFR5   _SFR_IO8(0x1A)
constexpr auto ICF5 = 0x05;
constexpr auto OCF5C = 0x03;
constexpr auto OCF5B = 0x02;
constexpr auto OCF5A = 0x01;
constexpr auto TOV5 = 0x00;

#define PCIFR   _SFR_IO8(0x1B)
#if defined(__ATmegaxx0__) 
# define PCIF2  2
#endif /* __ATmegaxx0__ */
constexpr auto PCIF1 = 0x01;
constexpr auto PCIF0 = 0x00;

#define EIFR   _SFR_IO8(0x1C)
constexpr auto INTF7 = 0x07;
constexpr auto INTF6 = 0x06;
constexpr auto INTF5 = 0x05;
constexpr auto INTF4 = 0x04;
constexpr auto INTF3 = 0x03;
constexpr auto INTF2 = 0x02;
constexpr auto INTF1 = 0x01;
constexpr auto INTF0 = 0x00;

#define EIMSK   _SFR_IO8(0x1D)
constexpr auto INT7 = 0x07;
constexpr auto INT6 = 0x06;
constexpr auto INT5 = 0x05;
constexpr auto INT4 = 0x04;
constexpr auto INT3 = 0x03;
constexpr auto INT2 = 0x02;
constexpr auto INT1 = 1 ;
constexpr auto INT0 = 0x00;

#define GPIOR0  _SFR_IO8(0x1E)

#define EECR    _SFR_IO8(0x1F)
constexpr auto EEPM1 = 0x05;
constexpr auto EEPM0 = 0x04;
constexpr auto EERIE = 0x03;
constexpr auto EEMPE = 0x02;
constexpr auto EEPE = 0x01;
constexpr auto EERE = 0x00;

#define EEDR    _SFR_IO8(0X20)

/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x21)

#define EEARL   _SFR_IO8(0x21)
#define EEARH   _SFR_IO8(0X22)

/* 6-char sequence denoting where to find the EEPROM registers in memory space.
   Adresses denoted in hex syntax with uppercase letters. Used by the EEPROM
   subroutines.
   First two letters:  EECR address.
   Second two letters: EEDR address.
   Last two letters:   EEAR address.  */
#define __EEPROM_REG_LOCATIONS__ 1F2021

#define GTCCR   _SFR_IO8(0x23)
constexpr auto TSM = 0x07;
constexpr auto PSRASY = 0x01;
constexpr auto PSRSYNC = 0x00;

#define TCCR0A  _SFR_IO8(0x24)
constexpr auto COM0A1 = 0x07;
constexpr auto COM0A0 = 0x06;
constexpr auto COM0B1 = 0x05;
constexpr auto COM0B0 = 0x04;
constexpr auto WGM01 = 0x01;
constexpr auto WGM00 = 0x00;

#define TCCR0B  _SFR_IO8(0x25)
constexpr auto FOC0A = 0x07;
constexpr auto FOC0B = 0x06;
constexpr auto WGM02 = 0x03;
constexpr auto CS02 = 0x02;
constexpr auto CS01 = 0x01;
constexpr auto CS00 = 0x00;

#define TCNT0   _SFR_IO8(0X26)

#define OCR0A   _SFR_IO8(0X27)

#define OCR0B   _SFR_IO8(0X28)

/* Reserved [0x29] */

#define GPIOR1  _SFR_IO8(0x2A)

#define GPIOR2  _SFR_IO8(0x2B)

#define SPCR    _SFR_IO8(0x2C)
constexpr auto SPIE = 0x07;
constexpr auto SPE = 0x06;
constexpr auto DORD = 0x05;
constexpr auto MSTR = 0x04;
constexpr auto CPOL = 0x03;
constexpr auto CPHA = 0x02;
constexpr auto SPR1 = 0x01;
constexpr auto SPR0 = 0x00;

#define SPSR    _SFR_IO8(0x2D)
constexpr auto SPIF = 0x07;
constexpr auto WCOL = 0x06;
constexpr auto SPI2X = 0x00;

#define SPDR    _SFR_IO8(0X2E)

/* Reserved [0x2F] */

#define ACSR    _SFR_IO8(0x30)
constexpr auto ACD = 0x07;
constexpr auto ACBG = 0x06;
constexpr auto ACO = 0x05;
constexpr auto ACI = 0x04;
constexpr auto ACIE = 0x03;
constexpr auto ACIC = 0x02;
constexpr auto ACIS1 = 0x01;
constexpr auto ACIS0 = 0x00;

#define MONDR   _SFR_IO8(0x31)
#define OCDR    _SFR_IO8(0x31)
constexpr auto IDRD = 0x07;
constexpr auto OCDR7 = 0x07;
constexpr auto OCDR6 = 0x06;
constexpr auto OCDR5 = 0x05;
constexpr auto OCDR4 = 0x04;
constexpr auto OCDR3 = 0x03;
constexpr auto OCDR2 = 0x02;
constexpr auto OCDR1 = 0x01;
constexpr auto OCDR0 = 0x00;

/* Reserved [0x32] */

#define SMCR    _SFR_IO8(0x33)
constexpr auto SM2 = 0x03;
constexpr auto SM1 = 0x02;
constexpr auto SM0 = 0x01;
constexpr auto SE = 0x00;

#define MCUSR   _SFR_IO8(0x34)
constexpr auto JTRF = 0x04;
constexpr auto WDRF = 0x03;
constexpr auto BORF = 0x02;
constexpr auto EXTRF = 0x01;
constexpr auto PORF = 0x00;

#define MCUCR   _SFR_IO8(0X35)
constexpr auto JTD = 0x07;
constexpr auto PUD = 0x04;
constexpr auto IVSEL = 0x01;
constexpr auto IVCE = 0x00;

/* Reserved [0x36] */

#define SPMCSR  _SFR_IO8(0x37)
constexpr auto SPMIE = 0x07;
constexpr auto RWWSB = 0x06;
constexpr auto SIGRD = 0x05;
constexpr auto RWWSRE = 0x04;
constexpr auto BLBSET = 0x03;
constexpr auto PGWRT = 0x02;
constexpr auto PGERS = 0x01;
constexpr auto SPMEN = 0x00;

/* Reserved [0x38..0x3A] */

#define RAMPZ   _SFR_IO8(0X3B)
constexpr auto RAMPZ0 = 0x00;

#define EIND    _SFR_IO8(0X3C)
constexpr auto EIND0 = 0x00;

/* SP [0x3D..0x3E] */
/* SREG [0x3F] */

#define WDTCSR  _SFR_MEM8(0x60)
constexpr auto WDIF = 0x07;
constexpr auto WDIE = 0x06;
constexpr auto WDP3 = 0x05;
constexpr auto WDCE = 0x04;
constexpr auto WDE = 0x03;
constexpr auto WDP2 = 0x02;
constexpr auto WDP1 = 0x01;
constexpr auto WDP0 = 0x00;

#define CLKPR   _SFR_MEM8(0x61)
constexpr auto CLKPCE = 0x07;
constexpr auto CLKPS3 = 0x03;
constexpr auto CLKPS2 = 0x02;
constexpr auto CLKPS1 = 0x01;
constexpr auto CLKPS0 = 0x00;

/* Reserved [0x62..0x63] */

#define PRR0    _SFR_MEM8(0x64)
constexpr auto PRTWI = 0x07;
constexpr auto PRTIM2 = 0x06;
constexpr auto PRTIM0 = 0x05;
constexpr auto PRTIM1 = 0x03;
constexpr auto PRSPI = 0x02;
constexpr auto PRUSART0 = 0x01;
constexpr auto PRADC = 0x00;

#define __AVR_HAVE_PRR0	((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI))
#define __AVR_HAVE_PRR0_PRADC
#define __AVR_HAVE_PRR0_PRUSART0
#define __AVR_HAVE_PRR0_PRSPI
#define __AVR_HAVE_PRR0_PRTIM1
#define __AVR_HAVE_PRR0_PRTIM0
#define __AVR_HAVE_PRR0_PRTIM2
#define __AVR_HAVE_PRR0_PRTWI

#define PRR1    _SFR_MEM8(0x65)
#define PRTIM5      5
constexpr auto PRTIM4 = 0x04;
constexpr auto PRTIM3 = 0x03;
constexpr auto PRUSART3 = 0x02;
constexpr auto PRUSART2 = 0x01;
constexpr auto PRUSART1 = 0x00;

#define __AVR_HAVE_PRR1	((1<<PRUSART1)|(1<<PRUSART2)|(1<<PRUSART3)|(1<<PRTIM3)|(1<<PRTIM4)|(1<<PRTIM5))
#define __AVR_HAVE_PRR1_PRUSART1
#define __AVR_HAVE_PRR1_PRUSART2
#define __AVR_HAVE_PRR1_PRUSART3
#define __AVR_HAVE_PRR1_PRTIM3
#define __AVR_HAVE_PRR1_PRTIM4
#define __AVR_HAVE_PRR1_PRTIM5

#define OSCCAL  _SFR_MEM8(0x66)

/* Reserved [0x67] */

#define PCICR   _SFR_MEM8(0x68)
#if defined(__ATmegaxx0__)
# define PCIE2  2
#endif /* __ATmegaxx0__ */
constexpr auto PCIE1 = 0x01;
constexpr auto PCIE0 = 0x00;

#define EICRA   _SFR_MEM8(0x69)
constexpr auto ISC31 = 0x07;
constexpr auto ISC30 = 0x06;
constexpr auto ISC21 = 0x05;
constexpr auto ISC20 = 0x04;
constexpr auto ISC11 = 0x03;
constexpr auto ISC10 = 0x02;
constexpr auto ISC01 = 0x01;
constexpr auto ISC00 = 0x00;

#define EICRB   _SFR_MEM8(0x6A)
constexpr auto ISC71 = 0x07;
constexpr auto ISC70 = 0x06;
constexpr auto ISC61 = 0x05;
constexpr auto ISC60 = 0x04;
constexpr auto ISC51 = 0x03;
constexpr auto ISC50 = 0x02;
constexpr auto ISC41 = 0x01;
constexpr auto ISC40 = 0x00;

#define PCMSK0  _SFR_MEM8(0x6B)
constexpr auto PCINT7 = 0x07;
constexpr auto PCINT6 = 0x06;
constexpr auto PCINT5 = 0x05;
constexpr auto PCINT4 = 0x04;
constexpr auto PCINT3 = 0x03;
constexpr auto PCINT2 = 0x02;
constexpr auto PCINT1 = 0x01;
constexpr auto PCINT0 = 0x00;

#define PCMSK1  _SFR_MEM8(0x6C)
constexpr auto PCINT15 = 0x07;
constexpr auto PCINT14 = 0x06;
constexpr auto PCINT13 = 0x05;
constexpr auto PCINT12 = 0x04;
constexpr auto PCINT11 = 0x03;
constexpr auto PCINT10 = 0x02;
constexpr auto PCINT9 = 0x01;
constexpr auto PCINT8 = 0x00;

#if defined(__ATmegaxx0__) 
# define PCMSK2 _SFR_MEM8(0x6D)
# define PCINT23 7
# define PCINT22 6
# define PCINT21 5
# define PCINT20 4
# define PCINT19 3
# define PCINT18 2
# define PCINT17 1
# define PCINT16 0
#endif /* __ATmegaxx0__ */

#define TIMSK0  _SFR_MEM8(0x6E)
constexpr auto OCIE0B = 0x02;
constexpr auto OCIE0A = 0x01;
constexpr auto TOIE0 = 0x00;

#define TIMSK1  _SFR_MEM8(0x6F)
constexpr auto ICIE1 = 0x05;
constexpr auto OCIE1C = 0x03;
constexpr auto OCIE1B = 0x02;
constexpr auto OCIE1A = 0x01;
constexpr auto TOIE1 = 0x00;

#define TIMSK2  _SFR_MEM8(0x70)
constexpr auto OCIE2B = 0x02;
constexpr auto OCIE2A = 0x01;
constexpr auto TOIE2 = 0x00;

#define TIMSK3  _SFR_MEM8(0x71)
constexpr auto ICIE3 = 0x05;
constexpr auto OCIE3C = 0x03;
constexpr auto OCIE3B = 0x02;
constexpr auto OCIE3A = 0x01;
constexpr auto TOIE3 = 0x00;

#define TIMSK4  _SFR_MEM8(0x72)
constexpr auto ICIE4 = 0x05;
constexpr auto OCIE4C = 0x03;
constexpr auto OCIE4B = 0x02;
constexpr auto OCIE4A = 0x01;
constexpr auto TOIE4 = 0x00;

#define TIMSK5  _SFR_MEM8(0x73)
constexpr auto ICIE5 = 0x05;
constexpr auto OCIE5C = 0x03;
constexpr auto OCIE5B = 0x02;
constexpr auto OCIE5A = 0x01;
constexpr auto TOIE5 = 0x00;

#define XMCRA   _SFR_MEM8(0x74)
constexpr auto SRE = 0x07;
constexpr auto SRL2 = 0x06;
constexpr auto SRL1 = 0x05;
constexpr auto SRL0 = 0x04;
constexpr auto SRW11 = 0x03;
constexpr auto SRW10 = 0x02;
constexpr auto SRW01 = 0x01;
constexpr auto SRW00 = 0x00;

#define XMCRB   _SFR_MEM8(0x75)
constexpr auto XMBK = 0x07;
constexpr auto XMM2 = 0x02;
constexpr auto XMM1 = 0x01;
constexpr auto XMM0 = 0x00;

/* Reserved [0x76..0x77] */

/* Combine ADCL and ADCH */
#ifndef __ASSEMBLER__
#define ADC     _SFR_MEM16(0x78)
#endif
#define ADCW    _SFR_MEM16(0x78)
#define ADCL    _SFR_MEM8(0x78)
#define ADCH    _SFR_MEM8(0x79)

#define ADCSRA  _SFR_MEM8(0x7A)
constexpr auto ADEN = 0x07;
constexpr auto ADSC = 0x06;
constexpr auto ADATE = 0x05;
constexpr auto ADIF = 0x04;
constexpr auto ADIE = 0x03;
constexpr auto ADPS2 = 0x02;
constexpr auto ADPS1 = 0x01;
constexpr auto ADPS0 = 0x00;

#define ADCSRB  _SFR_MEM8(0x7B)
constexpr auto ACME = 0x06;
#if defined(__ATmegaxx0__)
# define MUX5    3
#endif /* __ATmegaxx0__ */
constexpr auto ADTS2 = 0x02;
constexpr auto ADTS1 = 0x01;
constexpr auto ADTS0 = 0x00;

#define ADMUX   _SFR_MEM8(0x7C)
constexpr auto REFS1 = 0x07;
constexpr auto REFS0 = 0x06;
constexpr auto ADLAR = 0x05;
constexpr auto MUX4 = 0x04;
constexpr auto MUX3 = 0x03;
constexpr auto MUX2 = 0x02;
constexpr auto MUX1 = 0x01;
constexpr auto MUX0 = 0x00;

#define DIDR2   _SFR_MEM8(0x7D)
constexpr auto ADC15D = 0x07;
constexpr auto ADC14D = 0x06;
constexpr auto ADC13D = 0x05;
constexpr auto ADC12D = 0x04;
constexpr auto ADC11D = 0x03;
constexpr auto ADC10D = 0x02;
constexpr auto ADC9D = 0x01;
constexpr auto ADC8D = 0x00;

#define DIDR0   _SFR_MEM8(0x7E)
constexpr auto ADC7D = 0x07;
constexpr auto ADC6D = 0x06;
constexpr auto ADC5D = 0x05;
constexpr auto ADC4D = 0x04;
constexpr auto ADC3D = 0x03;
constexpr auto ADC2D = 0x02;
constexpr auto ADC1D = 0x01;
constexpr auto ADC0D = 0x00;

#define DIDR1   _SFR_MEM8(0x7F)
constexpr auto AIN1D = 0x01;
constexpr auto AIN0D = 0x00;

#define TCCR1A  _SFR_MEM8(0x80)
constexpr auto COM1A1 = 0x07;
constexpr auto COM1A0 = 0x06;
constexpr auto COM1B1 = 0x05;
constexpr auto COM1B0 = 0x04;
constexpr auto COM1C1 = 0x03;
constexpr auto COM1C0 = 0x02;
constexpr auto WGM11 = 0x01;
constexpr auto WGM10 = 0x00;

#define TCCR1B  _SFR_MEM8(0x81)
constexpr auto ICNC1 = 0x07;
constexpr auto ICES1 = 0x06;
constexpr auto WGM13 = 0x04;
constexpr auto WGM12 = 0x03;
constexpr auto CS12 = 0x02;
constexpr auto CS11 = 0x01;
constexpr auto CS10 = 0x00;

#define TCCR1C  _SFR_MEM8(0x82)
constexpr auto FOC1A = 0x07;
constexpr auto FOC1B = 0x06;
constexpr auto FOC1C = 0x05;

/* Reserved [0x83] */

/* Combine TCNT1L and TCNT1H */
#define TCNT1   _SFR_MEM16(0x84)

#define TCNT1L  _SFR_MEM8(0x84)
#define TCNT1H  _SFR_MEM8(0x85)

/* Combine ICR1L and ICR1H */
#define ICR1    _SFR_MEM16(0x86)

#define ICR1L   _SFR_MEM8(0x86)
#define ICR1H   _SFR_MEM8(0x87)

/* Combine OCR1AL and OCR1AH */
#define OCR1A   _SFR_MEM16(0x88)

#define OCR1AL  _SFR_MEM8(0x88)
#define OCR1AH  _SFR_MEM8(0x89)

/* Combine OCR1BL and OCR1BH */
#define OCR1B   _SFR_MEM16(0x8A)

#define OCR1BL  _SFR_MEM8(0x8A)
#define OCR1BH  _SFR_MEM8(0x8B)

/* Combine OCR1CL and OCR1CH */
#define OCR1C   _SFR_MEM16(0x8C)

#define OCR1CL  _SFR_MEM8(0x8C)
#define OCR1CH  _SFR_MEM8(0x8D)

/* Reserved [0x8E..0x8F] */

#define TCCR3A  _SFR_MEM8(0x90)
constexpr auto COM3A1 = 0x07;
constexpr auto COM3A0 = 0x06;
constexpr auto COM3B1 = 0x05;
constexpr auto COM3B0 = 0x04;
constexpr auto COM3C1 = 0x03;
constexpr auto COM3C0 = 0x02;
constexpr auto WGM31 = 0x01;
constexpr auto WGM30 = 0x00;

#define TCCR3B  _SFR_MEM8(0x91)
constexpr auto ICNC3 = 0x07;
constexpr auto ICES3 = 0x06;
constexpr auto WGM33 = 0x04;
constexpr auto WGM32 = 0x03;
constexpr auto CS32 = 0x02;
constexpr auto CS31 = 0x01;
constexpr auto CS30 = 0x00;

#define TCCR3C  _SFR_MEM8(0x92)
constexpr auto FOC3A = 0x07;
constexpr auto FOC3B = 0x06;
constexpr auto FOC3C = 0x05;

/* Reserved [0x93] */

/* Combine TCNT3L and TCNT3H */
#define TCNT3   _SFR_MEM16(0x94)

#define TCNT3L  _SFR_MEM8(0x94)
#define TCNT3H  _SFR_MEM8(0x95)

/* Combine ICR3L and ICR3H */
#define ICR3    _SFR_MEM16(0x96)

#define ICR3L   _SFR_MEM8(0x96)
#define ICR3H   _SFR_MEM8(0x97)

/* Combine OCR3AL and OCR3AH */
#define OCR3A   _SFR_MEM16(0x98)

#define OCR3AL  _SFR_MEM8(0x98)
#define OCR3AH  _SFR_MEM8(0x99)

/* Combine OCR3BL and OCR3BH */
#define OCR3B   _SFR_MEM16(0x9A)

#define OCR3BL  _SFR_MEM8(0x9A)
#define OCR3BH  _SFR_MEM8(0x9B)

/* Combine OCR3CL and OCR3CH */
#define OCR3C   _SFR_MEM16(0x9C)

#define OCR3CL  _SFR_MEM8(0x9C)
#define OCR3CH  _SFR_MEM8(0x9D)

/* Reserved [0x9E..0x9F] */

#define TCCR4A  _SFR_MEM8(0xA0)
constexpr auto COM4A1 = 0x07;
constexpr auto COM4A0 = 0x06;
constexpr auto COM4B1 = 0x05;
constexpr auto COM4B0 = 0x04;
constexpr auto COM4C1 = 0x03;
constexpr auto COM4C0 = 0x02;
constexpr auto WGM41 = 0x01;
constexpr auto WGM40 = 0x00;

#define TCCR4B  _SFR_MEM8(0xA1)
constexpr auto ICNC4 = 0x07;
constexpr auto ICES4 = 0x06;
constexpr auto WGM43 = 0x04;
constexpr auto WGM42 = 0x03;
constexpr auto CS42 = 0x02;
constexpr auto CS41 = 0x01;
constexpr auto CS40 = 0x00;

#define TCCR4C  _SFR_MEM8(0xA2)
constexpr auto FOC4A = 0x07;
constexpr auto FOC4B = 0x06;
constexpr auto FOC4C = 0x05;

/* Reserved [0xA3] */

/* Combine TCNT4L and TCNT4H */
#define TCNT4   _SFR_MEM16(0xA4)

#define TCNT4L  _SFR_MEM8(0xA4)
#define TCNT4H  _SFR_MEM8(0xA5)

/* Combine ICR4L and ICR4H */
#define ICR4    _SFR_MEM16(0xA6)

#define ICR4L   _SFR_MEM8(0xA6)
#define ICR4H   _SFR_MEM8(0xA7)

/* Combine OCR4AL and OCR4AH */
#define OCR4A   _SFR_MEM16(0xA8)

#define OCR4AL  _SFR_MEM8(0xA8)
#define OCR4AH  _SFR_MEM8(0xA9)

/* Combine OCR4BL and OCR4BH */
#define OCR4B   _SFR_MEM16(0xAA)

#define OCR4BL  _SFR_MEM8(0xAA)
#define OCR4BH  _SFR_MEM8(0xAB)

/* Combine OCR4CL and OCR4CH */
#define OCR4C   _SFR_MEM16(0xAC)

#define OCR4CL  _SFR_MEM8(0xAC)
#define OCR4CH  _SFR_MEM8(0xAD)

/* Reserved [0xAE..0xAF] */

#define TCCR2A  _SFR_MEM8(0xB0)
constexpr auto COM2A1 = 0x07;
constexpr auto COM2A0 = 0x06;
constexpr auto COM2B1 = 0x05;
constexpr auto COM2B0 = 0x04;
constexpr auto WGM21 = 0x01;
constexpr auto WGM20 = 0x00;

#define TCCR2B  _SFR_MEM8(0xB1)
constexpr auto FOC2A = 0x07;
constexpr auto FOC2B = 0x06;
constexpr auto WGM22 = 0x03;
constexpr auto CS22 = 0x02;
constexpr auto CS21 = 0x01;
constexpr auto CS20 = 0x00;

#define TCNT2   _SFR_MEM8(0xB2)

#define OCR2A   _SFR_MEM8(0xB3)

#define OCR2B   _SFR_MEM8(0xB4)

/* Reserved [0xB5] */

#define ASSR    _SFR_MEM8(0xB6)
constexpr auto EXCLK = 0x06;
constexpr auto AS2 = 0x05;
constexpr auto TCN2UB = 0x04;
constexpr auto OCR2AUB = 0x03;
constexpr auto OCR2BUB = 0x02;
constexpr auto TCR2AUB = 0x01;
constexpr auto TCR2BUB = 0x00;

/* Reserved [0xB7] */

#define TWBR    _SFR_MEM8(0xB8)

#define TWSR    _SFR_MEM8(0xB9)
constexpr auto TWS7 = 0x07;
constexpr auto TWS6 = 0x06;
constexpr auto TWS5 = 0x05;
constexpr auto TWS4 = 0x04;
constexpr auto TWS3 = 0x03;
constexpr auto TWPS1 = 0x01;
constexpr auto TWPS0 = 0x00;

#define TWAR    _SFR_MEM8(0xBA)
constexpr auto TWA6 = 0x07;
constexpr auto TWA5 = 0x06;
constexpr auto TWA4 = 0x05;
constexpr auto TWA3 = 0x04;
constexpr auto TWA2 = 0x03;
constexpr auto TWA1 = 0x02;
constexpr auto TWA0 = 0x01;
constexpr auto TWGCE = 0x00;

#define TWDR    _SFR_MEM8(0xBB)

#define TWCR    _SFR_MEM8(0xBC)
constexpr auto TWINT = 0x07;
constexpr auto TWEA = 0x06;
constexpr auto TWSTA = 0x05;
constexpr auto TWSTO = 0x04;
constexpr auto TWWC = 0x03;
constexpr auto TWEN = 0x02;
constexpr auto TWIE = 0x00;

#define TWAMR   _SFR_MEM8(0xBD)
constexpr auto TWAM6 = 0x07;
constexpr auto TWAM5 = 0x06;
constexpr auto TWAM4 = 0x05;
constexpr auto TWAM3 = 0x04;
constexpr auto TWAM2 = 0x03;
constexpr auto TWAM1 = 0x02;
constexpr auto TWAM0 = 0x01;

/* Reserved [0xBE..0xBF] */

#define UCSR0A  _SFR_MEM8(0xC0)
constexpr auto RXC0 = 0x07;
constexpr auto TXC0 = 0x06;
constexpr auto UDRE0 = 0x05;
constexpr auto FE0 = 0x04;
constexpr auto DOR0 = 0x03;
constexpr auto UPE0 = 0x02;
constexpr auto U2X0 = 0x01;
constexpr auto MPCM0 = 0x00;

#define UCSR0B  _SFR_MEM8(0XC1)
constexpr auto RXCIE0 = 0x07;
constexpr auto TXCIE0 = 0x06;
constexpr auto UDRIE0 = 0x05;
constexpr auto RXEN0 = 0x04;
constexpr auto TXEN0 = 0x03;
constexpr auto UCSZ02 = 0x02;
constexpr auto RXB80 = 0x01;
constexpr auto TXB80 = 0x00;

#define UCSR0C  _SFR_MEM8(0xC2)
constexpr auto UMSEL01 = 0x07;
constexpr auto UMSEL00 = 0x06;
constexpr auto UPM01 = 0x05;
constexpr auto UPM00 = 0x04;
constexpr auto USBS0 = 0x03;
constexpr auto UCSZ01 = 0x02;
constexpr auto UCSZ00 = 0x01;
constexpr auto UCPOL0 = 0x00;

/* Reserved [0xC3] */

/* Combine UBRR0L and UBRR0H */
#define UBRR0   _SFR_MEM16(0xC4)

#define UBRR0L  _SFR_MEM8(0xC4)
#define UBRR0H  _SFR_MEM8(0xC5)

#define UDR0    _SFR_MEM8(0XC6)

/* Reserved [0xC7] */

#define UCSR1A  _SFR_MEM8(0xC8)
constexpr auto RXC1 = 0x07;
constexpr auto TXC1 = 0x06;
constexpr auto UDRE1 = 0x05;
constexpr auto FE1 = 0x04;
constexpr auto DOR1 = 0x03;
constexpr auto UPE1 = 0x02;
constexpr auto U2X1 = 0x01;
constexpr auto MPCM1 = 0x00;

#define UCSR1B  _SFR_MEM8(0XC9)
constexpr auto RXCIE1 = 0x07;
constexpr auto TXCIE1 = 0x06;
constexpr auto UDRIE1 = 0x05;
constexpr auto RXEN1 = 0x04;
constexpr auto TXEN1 = 0x03;
constexpr auto UCSZ12 = 0x02;
constexpr auto RXB81 = 0x01;
constexpr auto TXB81 = 0x00;

#define UCSR1C  _SFR_MEM8(0xCA)
constexpr auto UMSEL11 = 0x07;
constexpr auto UMSEL10 = 0x06;
constexpr auto UPM11 = 0x05;
constexpr auto UPM10 = 0x04;
constexpr auto USBS1 = 0x03;
constexpr auto UCSZ11 = 0x02;
constexpr auto UCSZ10 = 0x01;
constexpr auto UCPOL1 = 0x00;

/* Reserved [0xCB] */

/* Combine UBRR1L and UBRR1H */
#define UBRR1   _SFR_MEM16(0xCC)

#define UBRR1L  _SFR_MEM8(0xCC)
#define UBRR1H  _SFR_MEM8(0xCD)

#define UDR1    _SFR_MEM8(0XCE)

/* Reserved [0xCF] */

#if defined(__ATmegaxx0__)

# define UCSR2A _SFR_MEM8(0xD0)
# define RXC2   7
# define TXC2   6
# define UDRE2  5
# define FE2    4
# define DOR2   3
# define UPE2   2
# define U2X2   1
# define MPCM2  0

# define UCSR2B _SFR_MEM8(0XD1)
# define RXCIE2 7
# define TXCIE2 6
# define UDRIE2 5
# define RXEN2  4
# define TXEN2  3
# define UCSZ22 2
# define RXB82  1
# define TXB82  0

# define UCSR2C _SFR_MEM8(0xD2)
# define UMSEL21 7
# define UMSEL20 6
# define UPM21  5
# define UPM20  4
# define USBS2  3
# define UCSZ21 2
# define UCSZ20 1
# define UCPOL2 0

/* Reserved [0xD3] */

/* Combine UBRR2L and UBRR2H */
# define UBRR2  _SFR_MEM16(0xD4)

# define UBRR2L _SFR_MEM8(0xD4)
# define UBRR2H _SFR_MEM8(0xD5)

# define UDR2   _SFR_MEM8(0XD6)

#endif /* __ATmegaxx0__ */

/* Reserved [0xD7..0xFF] */

#if defined(__ATmegaxx0__)

# define PINH   _SFR_MEM8(0x100)
# define PINH7  7
# define PINH6  6
# define PINH5  5
# define PINH4  4
# define PINH3  3
# define PINH2  2
# define PINH1  1
# define PINH0  0

# define DDRH   _SFR_MEM8(0x101)
# define DDH7   7
# define DDH6   6
# define DDH5   5
# define DDH4   4
# define DDH3   3
# define DDH2   2
# define DDH1   1
# define DDH0   0

# define PORTH  _SFR_MEM8(0x102)
# define PH7    7
# define PH6    6
# define PH5    5
# define PH4    4
# define PH3    3
# define PH2    2
# define PH1    1
# define PH0    0

# define PINJ   _SFR_MEM8(0x103)
# define PINJ7  7
# define PINJ6  6
# define PINJ5  5
# define PINJ4  4
# define PINJ3  3
# define PINJ2  2
# define PINJ1  1
# define PINJ0  0

# define DDRJ   _SFR_MEM8(0x104)
# define DDJ7   7
# define DDJ6   6
# define DDJ5   5
# define DDJ4   4
# define DDJ3   3
# define DDJ2   2
# define DDJ1   1
# define DDJ0   0

# define PORTJ  _SFR_MEM8(0x105)
# define PJ7 7
# define PJ6 6
# define PJ5 5
# define PJ4 4
# define PJ3 3
# define PJ2 2
# define PJ1 1
# define PJ0 0

# define PINK   _SFR_MEM8(0x106)
# define PINK7  7
# define PINK6  6
# define PINK5  5
# define PINK4  4
# define PINK3  3
# define PINK2  2
# define PINK1  1
# define PINK0  0

# define DDRK   _SFR_MEM8(0x107)
# define DDK7   7
# define DDK6   6
# define DDK5   5
# define DDK4   4
# define DDK3   3
# define DDK2   2
# define DDK1   1
# define DDK0   0

# define PORTK  _SFR_MEM8(0x108)
# define PK7 7
# define PK6 6
# define PK5 5
# define PK4 4
# define PK3 3
# define PK2 2
# define PK1 1
# define PK0 0

# define PINL   _SFR_MEM8(0x109)
# define PINL7  7
# define PINL6  6
# define PINL5  5
# define PINL4  4
# define PINL3  3
# define PINL2  2
# define PINL1  1
# define PINL0  0

# define DDRL   _SFR_MEM8(0x10A)
# define DDL7   7
# define DDL6   6
# define DDL5   5
# define DDL4   4
# define DDL3   3
# define DDL2   2
# define DDL1   1
# define DDL0   0

# define PORTL  _SFR_MEM8(0x10B)
# define PL7 7
# define PL6 6
# define PL5 5
# define PL4 4
# define PL3 3
# define PL2 2
# define PL1 1
# define PL0 0

#endif /* __ATmegaxx0__ */

/* Reserved [0x10C..0x11F] */

#define TCCR5A  _SFR_MEM8(0x120)
constexpr auto COM5A1 = 0x07;
constexpr auto COM5A0 = 0x06;
constexpr auto COM5B1 = 0x05;
constexpr auto COM5B0 = 0x04;
constexpr auto COM5C1 = 0x03;
constexpr auto COM5C0 = 0x02;
constexpr auto WGM51 = 0x01;
constexpr auto WGM50 = 0x00;

#define TCCR5B  _SFR_MEM8(0x121)
constexpr auto ICNC5 = 0x07;
constexpr auto ICES5 = 0x06;
constexpr auto WGM53 = 0x04;
constexpr auto WGM52 = 0x03;
constexpr auto CS52 = 0x02;
constexpr auto CS51 = 0x01;
constexpr auto CS50 = 0x00;

#define TCCR5C  _SFR_MEM8(0x122)
constexpr auto FOC5A = 0x07;
constexpr auto FOC5B = 0x06;
constexpr auto FOC5C = 0x05;

/* Reserved [0x123] */

/* Combine TCNT5L and TCNT5H */
#define TCNT5   _SFR_MEM16(0x124)

#define TCNT5L  _SFR_MEM8(0x124)
#define TCNT5H  _SFR_MEM8(0x125)

/* Combine ICR5L and ICR5H */
#define ICR5    _SFR_MEM16(0x126)

#define ICR5L   _SFR_MEM8(0x126)
#define ICR5H   _SFR_MEM8(0x127)

/* Combine OCR5AL and OCR5AH */
#define OCR5A   _SFR_MEM16(0x128)

#define OCR5AL  _SFR_MEM8(0x128)
#define OCR5AH  _SFR_MEM8(0x129)

/* Combine OCR5BL and OCR5BH */
#define OCR5B   _SFR_MEM16(0x12A)

#define OCR5BL  _SFR_MEM8(0x12A)
#define OCR5BH  _SFR_MEM8(0x12B)

/* Combine OCR5CL and OCR5CH */
#define OCR5C   _SFR_MEM16(0x12C)

#define OCR5CL  _SFR_MEM8(0x12C)
#define OCR5CH  _SFR_MEM8(0x12D)

/* Reserved [0x12E..0x12F] */

#if defined(__ATmegaxx0__) 

# define UCSR3A _SFR_MEM8(0x130)
# define RXC3   7
# define TXC3   6
# define UDRE3  5
# define FE3    4
# define DOR3   3
# define UPE3   2
# define U2X3   1
# define MPCM3  0

# define UCSR3B _SFR_MEM8(0X131)
# define RXCIE3 7
# define TXCIE3 6
# define UDRIE3 5
# define RXEN3  4
# define TXEN3  3
# define UCSZ32 2
# define RXB83  1
# define TXB83  0

# define UCSR3C _SFR_MEM8(0x132)
# define UMSEL31 7
# define UMSEL30 6
# define UPM31  5
# define UPM30  4
# define USBS3  3
# define UCSZ31 2
# define UCSZ30 1
# define UCPOL3 0

/* Reserved [0x133] */

/* Combine UBRR3L and UBRR3H */
# define UBRR3  _SFR_MEM16(0x134)

# define UBRR3L _SFR_MEM8(0x134)
# define UBRR3H _SFR_MEM8(0x135)

# define UDR3   _SFR_MEM8(0X136)

#endif /* __ATmegaxx0__ */

/* Reserved [0x137..1FF] */

/* Interrupt vectors */
/* Vector 0 is the reset vector */
/* External Interrupt Request 0 */
constexpr auto INT0_vect_num = 0x01;
#define INT0_vect			_VECTOR(1)
#define SIG_INTERRUPT0			_VECTOR(1)

/* External Interrupt Request 1 */
constexpr auto INT1_vect_num = 0x02;
#define INT1_vect			_VECTOR(2)
#define SIG_INTERRUPT1			_VECTOR(2)

/* External Interrupt Request 2 */
constexpr auto INT2_vect_num = 0x03;
#define INT2_vect			_VECTOR(3)
#define SIG_INTERRUPT2			_VECTOR(3)

/* External Interrupt Request 3 */
constexpr auto INT3_vect_num = 0x04;
#define INT3_vect			_VECTOR(4)
#define SIG_INTERRUPT3			_VECTOR(4)

/* External Interrupt Request 4 */
constexpr auto INT4_vect_num = 0x05;
#define INT4_vect			_VECTOR(5)
#define SIG_INTERRUPT4			_VECTOR(5)

/* External Interrupt Request 5 */
constexpr auto INT5_vect_num = 0x06;
#define INT5_vect			_VECTOR(6)
#define SIG_INTERRUPT5			_VECTOR(6)

/* External Interrupt Request 6 */
constexpr auto INT6_vect_num = 0x07;
#define INT6_vect			_VECTOR(7)
#define SIG_INTERRUPT6			_VECTOR(7)

/* External Interrupt Request 7 */
constexpr auto INT7_vect_num = 0x08;
#define INT7_vect			_VECTOR(8)
#define SIG_INTERRUPT7			_VECTOR(8)

/* Pin Change Interrupt Request 0 */
constexpr auto PCINT0_vect_num = 0x09;
#define PCINT0_vect			_VECTOR(9)
#define SIG_PIN_CHANGE0			_VECTOR(9)

/* Pin Change Interrupt Request 1 */
#define PCINT1_vect_num		10
#define PCINT1_vect			_VECTOR(10)
#define SIG_PIN_CHANGE1			_VECTOR(10)

#if defined(__ATmegaxx0__)
/* Pin Change Interrupt Request 2 */
#define PCINT2_vect_num		11
#define PCINT2_vect			_VECTOR(11)
#define SIG_PIN_CHANGE2			_VECTOR(11)

#endif /* __ATmegaxx0__ */

/* Watchdog Time-out Interrupt */
#define WDT_vect_num		12
#define WDT_vect			_VECTOR(12)
#define SIG_WATCHDOG_TIMEOUT		_VECTOR(12)

/* Timer/Counter2 Compare Match A */
#define TIMER2_COMPA_vect_num	13
#define TIMER2_COMPA_vect		_VECTOR(13)
#define SIG_OUTPUT_COMPARE2A		_VECTOR(13)

/* Timer/Counter2 Compare Match B */
#define TIMER2_COMPB_vect_num	14
#define TIMER2_COMPB_vect		_VECTOR(14)
#define SIG_OUTPUT_COMPARE2B		_VECTOR(14)

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect_num		15
#define TIMER2_OVF_vect			_VECTOR(15)
#define SIG_OVERFLOW2			_VECTOR(15)

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect_num	16
#define TIMER1_CAPT_vect		_VECTOR(16)
#define SIG_INPUT_CAPTURE1		_VECTOR(16)

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect_num	17
#define TIMER1_COMPA_vect		_VECTOR(17)
#define SIG_OUTPUT_COMPARE1A		_VECTOR(17)

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect_num	18
#define TIMER1_COMPB_vect		_VECTOR(18)
#define SIG_OUTPUT_COMPARE1B		_VECTOR(18)

/* Timer/Counter1 Compare Match C */
#define TIMER1_COMPC_vect_num	19
#define TIMER1_COMPC_vect		_VECTOR(19)
#define SIG_OUTPUT_COMPARE1C		_VECTOR(19)

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect_num		20
#define TIMER1_OVF_vect			_VECTOR(20)
#define SIG_OVERFLOW1			_VECTOR(20)

/* Timer/Counter0 Compare Match A */
#define TIMER0_COMPA_vect_num	21
#define TIMER0_COMPA_vect		_VECTOR(21)
#define SIG_OUTPUT_COMPARE0A		_VECTOR(21)

/* Timer/Counter0 Compare Match B */
#define TIMER0_COMPB_vect_num	22
#define TIMER0_COMPB_vect		_VECTOR(22)
#define SIG_OUTPUT_COMPARE0B		_VECTOR(22)

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect_num		23
#define TIMER0_OVF_vect			_VECTOR(23)
#define SIG_OVERFLOW0			_VECTOR(23)

/* SPI Serial Transfer Complete */
#define SPI_STC_vect_num		24
#define SPI_STC_vect			_VECTOR(24)
#define SIG_SPI				_VECTOR(24)

/* USART0, Rx Complete */
#define USART0_RX_vect_num		25
#define USART0_RX_vect			_VECTOR(25)
#define SIG_USART0_RECV			_VECTOR(25)

/* USART0 Data register Empty */
#define USART0_UDRE_vect_num	26
#define USART0_UDRE_vect		_VECTOR(26)
#define SIG_USART0_DATA			_VECTOR(26)

/* USART0, Tx Complete */
#define USART0_TX_vect_num		27
#define USART0_TX_vect			_VECTOR(27)
#define SIG_USART0_TRANS		_VECTOR(27)

/* Analog Comparator */
#define ANALOG_COMP_vect_num	28
#define ANALOG_COMP_vect		_VECTOR(28)
#define SIG_COMPARATOR			_VECTOR(28)

/* ADC Conversion Complete */
#define ADC_vect_num		29
#define ADC_vect			_VECTOR(29)
#define SIG_ADC				_VECTOR(29)

/* EEPROM Ready */
#define EE_READY_vect_num		30
#define EE_READY_vect			_VECTOR(30)
#define SIG_EEPROM_READY		_VECTOR(30)

/* Timer/Counter3 Capture Event */
#define TIMER3_CAPT_vect_num	31
#define TIMER3_CAPT_vect		_VECTOR(31)
#define SIG_INPUT_CAPTURE3		_VECTOR(31)

/* Timer/Counter3 Compare Match A */
#define TIMER3_COMPA_vect_num	32
#define TIMER3_COMPA_vect		_VECTOR(32)
#define SIG_OUTPUT_COMPARE3A		_VECTOR(32)

/* Timer/Counter3 Compare Match B */
#define TIMER3_COMPB_vect_num	33
#define TIMER3_COMPB_vect		_VECTOR(33)
#define SIG_OUTPUT_COMPARE3B		_VECTOR(33)

/* Timer/Counter3 Compare Match C */
#define TIMER3_COMPC_vect_num	34
#define TIMER3_COMPC_vect		_VECTOR(34)
#define SIG_OUTPUT_COMPARE3C		_VECTOR(34)

/* Timer/Counter3 Overflow */
#define TIMER3_OVF_vect_num		35
#define TIMER3_OVF_vect			_VECTOR(35)
#define SIG_OVERFLOW3			_VECTOR(35)

/* USART1, Rx Complete */
#define USART1_RX_vect_num		36
#define USART1_RX_vect			_VECTOR(36)
#define SIG_USART1_RECV			_VECTOR(36)

/* USART1 Data register Empty */
#define USART1_UDRE_vect_num	37
#define USART1_UDRE_vect		_VECTOR(37)
#define SIG_USART1_DATA			_VECTOR(37)

/* USART1, Tx Complete */
#define USART1_TX_vect_num		38
#define USART1_TX_vect			_VECTOR(38)
#define SIG_USART1_TRANS		_VECTOR(38)

/* 2-wire Serial Interface */
#define TWI_vect_num		39
#define TWI_vect			_VECTOR(39)
#define SIG_2WIRE_SERIAL		_VECTOR(39)

/* Store Program Memory Read */
#define SPM_READY_vect_num		40
#define SPM_READY_vect			_VECTOR(40)
#define SIG_SPM_READY			_VECTOR(40)

#if defined(__ATmegaxx0__)
/* Timer/Counter4 Capture Event */
#define TIMER4_CAPT_vect_num	41
#define TIMER4_CAPT_vect		_VECTOR(41)
#define SIG_INPUT_CAPTURE4		_VECTOR(41)

#endif /* __ATmegaxx0__ */

/* Timer/Counter4 Compare Match A */
#define TIMER4_COMPA_vect_num	42
#define TIMER4_COMPA_vect		_VECTOR(42)
#define SIG_OUTPUT_COMPARE4A		_VECTOR(42)

/* Timer/Counter4 Compare Match B */
#define TIMER4_COMPB_vect_num	43
#define TIMER4_COMPB_vect		_VECTOR(43)
#define SIG_OUTPUT_COMPARE4B		_VECTOR(43)

/* Timer/Counter4 Compare Match C */
#define TIMER4_COMPC_vect_num	44
#define TIMER4_COMPC_vect		_VECTOR(44)
#define SIG_OUTPUT_COMPARE4C		_VECTOR(44)

/* Timer/Counter4 Overflow */
#define TIMER4_OVF_vect_num		45
#define TIMER4_OVF_vect			_VECTOR(45)
#define SIG_OVERFLOW4			_VECTOR(45)

#if defined(__ATmegaxx0__)
/* Timer/Counter5 Capture Event */
#define TIMER5_CAPT_vect_num	46
#define TIMER5_CAPT_vect		_VECTOR(46)
#define SIG_INPUT_CAPTURE5		_VECTOR(46)

#endif /* __ATmegaxx0__ */

/* Timer/Counter5 Compare Match A */
#define TIMER5_COMPA_vect_num	47
#define TIMER5_COMPA_vect		_VECTOR(47)
#define SIG_OUTPUT_COMPARE5A		_VECTOR(47)

/* Timer/Counter5 Compare Match B */
#define TIMER5_COMPB_vect_num	48
#define TIMER5_COMPB_vect		_VECTOR(48)
#define SIG_OUTPUT_COMPARE5B		_VECTOR(48)

/* Timer/Counter5 Compare Match C */
#define TIMER5_COMPC_vect_num	49
#define TIMER5_COMPC_vect		_VECTOR(49)
#define SIG_OUTPUT_COMPARE5C		_VECTOR(49)

/* Timer/Counter5 Overflow */
#define TIMER5_OVF_vect_num		50
#define TIMER5_OVF_vect			_VECTOR(50)
#define SIG_OVERFLOW5			_VECTOR(50)

#if defined(__ATmegaxx1__)

# define _VECTORS_SIZE 204

#else

/* USART2, Rx Complete */
#define USART2_RX_vect_num		51
#define USART2_RX_vect			_VECTOR(51)
#define SIG_USART2_RECV			_VECTOR(51)

/* USART2 Data register Empty */
#define USART2_UDRE_vect_num		52
#define USART2_UDRE_vect		_VECTOR(52)
#define SIG_USART2_DATA			_VECTOR(52)

/* USART2, Tx Complete */
#define USART2_TX_vect_num		53
#define USART2_TX_vect			_VECTOR(53)
#define SIG_USART2_TRANS		_VECTOR(53)

/* USART3, Rx Complete */
#define USART3_RX_vect_num		54
#define USART3_RX_vect			_VECTOR(54)
#define SIG_USART3_RECV			_VECTOR(54)

/* USART3 Data register Empty */
#define USART3_UDRE_vect_num		55
#define USART3_UDRE_vect		_VECTOR(55)
#define SIG_USART3_DATA			_VECTOR(55)

/* USART3, Tx Complete */
#define USART3_TX_vect_num		56
#define USART3_TX_vect			_VECTOR(56)
#define SIG_USART3_TRANS		_VECTOR(56)

# define _VECTORS_SIZE 228

#endif /* __ATmegaxx1__ */

#if defined(__ATmegaxx0__)
# undef __ATmegaxx0__
#endif

#if defined(__ATmegaxx1__)
# undef __ATmegaxx1__
#endif


/* Deprecated items */
#if !defined(__AVR_LIBC_DEPRECATED_ENABLE__)

#pragma GCC system_header

#pragma GCC poison SIG_INTERRUPT0
#pragma GCC poison SIG_INTERRUPT1
#pragma GCC poison SIG_INTERRUPT2
#pragma GCC poison SIG_INTERRUPT3
#pragma GCC poison SIG_INTERRUPT4
#pragma GCC poison SIG_INTERRUPT5
#pragma GCC poison SIG_INTERRUPT6
#pragma GCC poison SIG_INTERRUPT7
#pragma GCC poison SIG_PIN_CHANGE0
#pragma GCC poison SIG_PIN_CHANGE1
#pragma GCC poison SIG_PIN_CHANGE2
#pragma GCC poison SIG_WATCHDOG_TIMEOUT
#pragma GCC poison SIG_OUTPUT_COMPARE2A
#pragma GCC poison SIG_OUTPUT_COMPARE2B
#pragma GCC poison SIG_OVERFLOW2
#pragma GCC poison SIG_INPUT_CAPTURE1
#pragma GCC poison SIG_OUTPUT_COMPARE1A
#pragma GCC poison SIG_OUTPUT_COMPARE1B
#pragma GCC poison SIG_OUTPUT_COMPARE1C
#pragma GCC poison SIG_OVERFLOW1
#pragma GCC poison SIG_OUTPUT_COMPARE0A
#pragma GCC poison SIG_OUTPUT_COMPARE0B
#pragma GCC poison SIG_OVERFLOW0
#pragma GCC poison SIG_SPI
#pragma GCC poison SIG_USART0_RECV
#pragma GCC poison SIG_USART0_DATA
#pragma GCC poison SIG_USART0_TRANS
#pragma GCC poison SIG_COMPARATOR
#pragma GCC poison SIG_ADC
#pragma GCC poison SIG_EEPROM_READY
#pragma GCC poison SIG_INPUT_CAPTURE3
#pragma GCC poison SIG_OUTPUT_COMPARE3A
#pragma GCC poison SIG_OUTPUT_COMPARE3B
#pragma GCC poison SIG_OUTPUT_COMPARE3C
#pragma GCC poison SIG_OVERFLOW3
#pragma GCC poison SIG_USART1_RECV
#pragma GCC poison SIG_USART1_DATA
#pragma GCC poison SIG_USART1_TRANS
#pragma GCC poison SIG_2WIRE_SERIAL
#pragma GCC poison SIG_SPM_READY
#pragma GCC poison SIG_INPUT_CAPTURE4
#pragma GCC poison SIG_OUTPUT_COMPARE4A
#pragma GCC poison SIG_OUTPUT_COMPARE4B
#pragma GCC poison SIG_OUTPUT_COMPARE4C
#pragma GCC poison SIG_OVERFLOW4
#pragma GCC poison SIG_INPUT_CAPTURE5
#pragma GCC poison SIG_OUTPUT_COMPARE5A
#pragma GCC poison SIG_OUTPUT_COMPARE5B
#pragma GCC poison SIG_OUTPUT_COMPARE5C
#pragma GCC poison SIG_OVERFLOW5
#pragma GCC poison SIG_USART2_RECV
#pragma GCC poison SIG_USART2_DATA
#pragma GCC poison SIG_USART2_TRANS
#pragma GCC poison SIG_USART3_RECV
#pragma GCC poison SIG_USART3_DATA
#pragma GCC poison SIG_USART3_TRANS

#endif  /* !defined(__AVR_LIBC_DEPRECATED_ENABLE__) */

} /* end of namespace vAVR */

#endif /* _AVR_IOMXX0_1_H_ */
