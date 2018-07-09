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

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iomxx0_1.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 

# define __ATmegaxx0__

#include "registers.h"

namespace vAVR {
    namespace internal {
        namespace controllers {

            /* Registers and associated bit numbers */
            struct megaxx01 : common::commonChip {
                ~megaxx01() = delete;

                using PINA = registers::pin_register<0x20, 0b11111111>;
                using PINA0 = registers::rw_bit<PINA, 0>;
                using PINA1 = registers::rw_bit<PINA, 1>;
                using PINA2 = registers::rw_bit<PINA, 2>;
                using PINA3 = registers::rw_bit<PINA, 3>;
                using PINA4 = registers::rw_bit<PINA, 4>;
                using PINA5 = registers::rw_bit<PINA, 5>;
                using PINA6 = registers::rw_bit<PINA, 6>;
                using PINA7 = registers::rw_bit<PINA, 7>;
                using DDRA = registers::ddr_register<0x21, 0b11111111>;
                using DDRA0 = registers::rw_bit<DDRA, 0>;
                using DDRA1 = registers::rw_bit<DDRA, 1>;
                using DDRA2 = registers::rw_bit<DDRA, 2>;
                using DDRA3 = registers::rw_bit<DDRA, 3>;
                using DDRA4 = registers::rw_bit<DDRA, 4>;
                using DDRA5 = registers::rw_bit<DDRA, 5>;
                using DDRA6 = registers::rw_bit<DDRA, 6>;
                using DDRA7 = registers::rw_bit<DDRA, 7>;
                using PORTA = registers::port_register<0x22, 0b11111111>;
                using PORTA0 = registers::rw_bit<PORTA, 0>;
                using PORTA1 = registers::rw_bit<PORTA, 1>;
                using PORTA2 = registers::rw_bit<PORTA, 2>;
                using PORTA3 = registers::rw_bit<PORTA, 3>;
                using PORTA4 = registers::rw_bit<PORTA, 4>;
                using PORTA5 = registers::rw_bit<PORTA, 5>;
                using PORTA6 = registers::rw_bit<PORTA, 6>;
                using PORTA7 = registers::rw_bit<PORTA, 7>;

                using PINB = registers::pin_register<0x23, 0b11111111>;
                using PINB0 = registers::rw_bit<PINB, 0>;
                using PINB1 = registers::rw_bit<PINB, 1>;
                using PINB2 = registers::rw_bit<PINB, 2>;
                using PINB3 = registers::rw_bit<PINB, 3>;
                using PINB4 = registers::rw_bit<PINB, 4>;
                using PINB5 = registers::rw_bit<PINB, 5>;
                using PINB6 = registers::rw_bit<PINB, 6>;
                using PINB7 = registers::rw_bit<PINB, 7>;
                using DDRB = registers::ddr_register<0x24, 0b11111111>;
                using DDRB0 = registers::rw_bit<DDRB, 0>;
                using DDRB1 = registers::rw_bit<DDRB, 1>;
                using DDRB2 = registers::rw_bit<DDRB, 2>;
                using DDRB3 = registers::rw_bit<DDRB, 3>;
                using DDRB4 = registers::rw_bit<DDRB, 4>;
                using DDRB5 = registers::rw_bit<DDRB, 5>;
                using DDRB6 = registers::rw_bit<DDRB, 6>;
                using DDRB7 = registers::rw_bit<DDRB, 7>;
                using PORTB = registers::port_register<0x25, 0b11111111>;
                using PORTB0 = registers::rw_bit<PORTB, 0>;
                using PORTB1 = registers::rw_bit<PORTB, 1>;
                using PORTB2 = registers::rw_bit<PORTB, 2>;
                using PORTB3 = registers::rw_bit<PORTB, 3>;
                using PORTB4 = registers::rw_bit<PORTB, 4>;
                using PORTB5 = registers::rw_bit<PORTB, 5>;
                using PORTB6 = registers::rw_bit<PORTB, 6>;
                using PORTB7 = registers::rw_bit<PORTB, 7>;

                using PINC = registers::pin_register<0x26, 0b01111111>;
                using PINC0 = registers::rw_bit<PINC, 0>;
                using PINC1 = registers::rw_bit<PINC, 1>;
                using PINC2 = registers::rw_bit<PINC, 2>;
                using PINC3 = registers::rw_bit<PINC, 3>;
                using PINC4 = registers::rw_bit<PINC, 4>;
                using PINC5 = registers::rw_bit<PINC, 5>;
                using PINC6 = registers::rw_bit<PINC, 6>;
                using PINC7 = registers::rw_bit<PINC, 7>;
                using DDRC = registers::ddr_register<0x27, 0b01111111>;
                using DDRC0 = registers::rw_bit<DDRC, 0>;
                using DDRC1 = registers::rw_bit<DDRC, 1>;
                using DDRC2 = registers::rw_bit<DDRC, 2>;
                using DDRC3 = registers::rw_bit<DDRC, 3>;
                using DDRC4 = registers::rw_bit<DDRC, 4>;
                using DDRC5 = registers::rw_bit<DDRC, 5>;
                using DDRC6 = registers::rw_bit<DDRC, 6>;
                using DDRC7 = registers::rw_bit<DDRC, 7>;
                using PORTC = registers::port_register<0x28, 0b01111111>;
                using PORTC0 = registers::rw_bit<PORTC, 0>;
                using PORTC1 = registers::rw_bit<PORTC, 1>;
                using PORTC2 = registers::rw_bit<PORTC, 2>;
                using PORTC3 = registers::rw_bit<PORTC, 3>;
                using PORTC4 = registers::rw_bit<PORTC, 4>;
                using PORTC5 = registers::rw_bit<PORTC, 5>;
                using PORTC6 = registers::rw_bit<PORTC, 6>;
                using PORTC7 = registers::rw_bit<PORTC, 7>;

                using PIND = registers::pin_register<0x29, 0b11111111>;
                using PIND0 = registers::rw_bit<PIND, 0>;
                using PIND1 = registers::rw_bit<PIND, 1>;
                using PIND2 = registers::rw_bit<PIND, 2>;
                using PIND3 = registers::rw_bit<PIND, 3>;
                using PIND4 = registers::rw_bit<PIND, 4>;
                using PIND5 = registers::rw_bit<PIND, 5>;
                using PIND6 = registers::rw_bit<PIND, 6>;
                using PIND7 = registers::rw_bit<PIND, 7>;
                using DDRD = registers::ddr_register<0x2a, 0b11111111>;
                using DDRD0 = registers::rw_bit<DDRD, 0>;
                using DDRD1 = registers::rw_bit<DDRD, 1>;
                using DDRD2 = registers::rw_bit<DDRD, 2>;
                using DDRD3 = registers::rw_bit<DDRD, 3>;
                using DDRD4 = registers::rw_bit<DDRD, 4>;
                using DDRD5 = registers::rw_bit<DDRD, 5>;
                using DDRD6 = registers::rw_bit<DDRD, 6>;
                using DDRD7 = registers::rw_bit<DDRD, 7>;
                using PORTD = registers::port_register<0x2b, 0b11111111>;
                using PORTD0 = registers::rw_bit<PORTD, 0>;
                using PORTD1 = registers::rw_bit<PORTD, 1>;
                using PORTD2 = registers::rw_bit<PORTD, 2>;
                using PORTD3 = registers::rw_bit<PORTD, 3>;
                using PORTD4 = registers::rw_bit<PORTD, 4>;
                using PORTD5 = registers::rw_bit<PORTD, 5>;
                using PORTD6 = registers::rw_bit<PORTD, 6>;
                using PORTD7 = registers::rw_bit<PORTD, 7>;

                using PINE = registers::pin_register<0x2c, 0b11111111>;
                using PINE0 = registers::rw_bit<PINE, 0>;
                using PINE1 = registers::rw_bit<PINE, 1>;
                using PINE2 = registers::rw_bit<PINE, 2>;
                using PINE3 = registers::rw_bit<PINE, 3>;
                using PINE4 = registers::rw_bit<PINE, 4>;
                using PINE5 = registers::rw_bit<PINE, 5>;
                using PINE6 = registers::rw_bit<PINE, 6>;
                using PINE7 = registers::rw_bit<PINE, 7>;
                using DDRE = registers::ddr_register<0x2d, 0b11111111>;
                using DDRE0 = registers::rw_bit<DDRE, 0>;
                using DDRE1 = registers::rw_bit<DDRE, 1>;
                using DDRE2 = registers::rw_bit<DDRE, 2>;
                using DDRE3 = registers::rw_bit<DDRE, 3>;
                using DDRE4 = registers::rw_bit<DDRE, 4>;
                using DDRE5 = registers::rw_bit<DDRE, 5>;
                using DDRE6 = registers::rw_bit<DDRE, 6>;
                using DDRE7 = registers::rw_bit<DDRE, 7>;
                using PORTE = registers::port_register<0x2e, 0b11111111>;
                using PORTE0 = registers::rw_bit<PORTE, 0>;
                using PORTE1 = registers::rw_bit<PORTE, 1>;
                using PORTE2 = registers::rw_bit<PORTE, 2>;
                using PORTE3 = registers::rw_bit<PORTE, 3>;
                using PORTE4 = registers::rw_bit<PORTE, 4>;
                using PORTE5 = registers::rw_bit<PORTE, 5>;
                using PORTE6 = registers::rw_bit<PORTE, 6>;
                using PORTE7 = registers::rw_bit<PORTE, 7>;

                using PINF = registers::pin_register<0x2f, 0b11111111>;
                using PINF0 = registers::rw_bit<PINF, 0>;
                using PINF1 = registers::rw_bit<PINF, 1>;
                using PINF2 = registers::rw_bit<PINF, 2>;
                using PINF3 = registers::rw_bit<PINF, 3>;
                using PINF4 = registers::rw_bit<PINF, 4>;
                using PINF5 = registers::rw_bit<PINF, 5>;
                using PINF6 = registers::rw_bit<PINF, 6>;
                using PINF7 = registers::rw_bit<PINF, 7>;
                using DDRF = registers::ddr_register<0x30, 0b11111111>;
                using DDRF0 = registers::rw_bit<DDRF, 0>;
                using DDRF1 = registers::rw_bit<DDRF, 1>;
                using DDRF2 = registers::rw_bit<DDRF, 2>;
                using DDRF3 = registers::rw_bit<DDRF, 3>;
                using DDRF4 = registers::rw_bit<DDRF, 4>;
                using DDRF5 = registers::rw_bit<DDRF, 5>;
                using DDRF6 = registers::rw_bit<DDRF, 6>;
                using DDRF7 = registers::rw_bit<DDRF, 7>;
                using PORTF = registers::port_register<0x31, 0b11111111>;
                using PORTF0 = registers::rw_bit<PORTF, 0>;
                using PORTF1 = registers::rw_bit<PORTF, 1>;
                using PORTF2 = registers::rw_bit<PORTF, 2>;
                using PORTF3 = registers::rw_bit<PORTF, 3>;
                using PORTF4 = registers::rw_bit<PORTF, 4>;
                using PORTF5 = registers::rw_bit<PORTF, 5>;
                using PORTF6 = registers::rw_bit<PORTF, 6>;
                using PORTF7 = registers::rw_bit<PORTF, 7>;

                using PING = registers::pin_register<0x32, 0b00111111>;
                using PING0 = registers::rw_bit<PING, 0>;
                using PING1 = registers::rw_bit<PING, 1>;
                using PING2 = registers::rw_bit<PING, 2>;
                using PING3 = registers::rw_bit<PING, 3>;
                using PING4 = registers::rw_bit<PING, 4>;
                using PING5 = registers::rw_bit<PING, 5>;
                using DDRG = registers::ddr_register<0x33, 0b00111111>;
                using DDRG0 = registers::rw_bit<DDRG, 0>;
                using DDRG1 = registers::rw_bit<DDRG, 1>;
                using DDRG2 = registers::rw_bit<DDRG, 2>;
                using DDRG3 = registers::rw_bit<DDRG, 3>;
                using DDRG4 = registers::rw_bit<DDRG, 4>;
                using DDRG5 = registers::rw_bit<DDRG, 5>;
                using PORTG = registers::port_register<0x34, 0b00111111>;
                using PORTG0 = registers::rw_bit<PORTG, 0>;
                using PORTG1 = registers::rw_bit<PORTG, 1>;
                using PORTG2 = registers::rw_bit<PORTG, 2>;
                using PORTG3 = registers::rw_bit<PORTG, 3>;
                using PORTG4 = registers::rw_bit<PORTG, 4>;
                using PORTG5 = registers::rw_bit<PORTG, 5>;


                using TIFR0 = registers::rw_io_register<0x35, 8, 0b00000111>;
                using OCF0B = registers::rw_bit<TIFR0, 0x02>;
                using OCF0A = registers::rw_bit<TIFR0, 0x01>;
                using TOV0  = registers::rw_bit<TIFR0, 0x00>;

                using TIFR1 = registers::rw_io_register<0x36, 8, 0b00101111>;
                using ICF1  = registers::rw_bit<TIFR1, 0x05>;
                using OCF1C = registers::rw_bit<TIFR1, 0x03>;
                using OCF1B = registers::rw_bit<TIFR1, 0x02>;
                using OCF1A = registers::rw_bit<TIFR1, 0x01>;
                using TOV1  = registers::rw_bit<TIFR1, 0x00>;

                using TIFR2 = registers::rw_io_register<0x37, 8, 0b00000111>;
                using OCF2B = registers::rw_bit<TIFR2, 0x02>;
                using OCF2A = registers::rw_bit<TIFR2, 0x01>;
                using TOV2  = registers::rw_bit<TIFR2, 0x00>;

                using TIFR3 = registers::rw_io_register<0x38, 8, 0b00101111>;
                using ICF3  = registers::rw_bit<TIFR3, 0x05>;
                using OCF3C = registers::rw_bit<TIFR3, 0x03>;
                using OCF3B = registers::rw_bit<TIFR3, 0x02>;
                using OCF3A = registers::rw_bit<TIFR3, 0x01>;
                using TOV3  = registers::rw_bit<TIFR3, 0x00>;

                using TIFR4 = registers::rw_io_register<0x39, 8, 0b00101111>;
                using ICF4  = registers::rw_bit<TIFR4, 0x05>;
                using OCF4C = registers::rw_bit<TIFR4, 0x03>;
                using OCF4B = registers::rw_bit<TIFR4, 0x02>;
                using OCF4A = registers::rw_bit<TIFR4, 0x01>;
                using TOV4  = registers::rw_bit<TIFR4, 0x00>;

                using TIFR5 = registers::rw_io_register<0x3A, 8, 0b00101111>;
                using ICF5  = registers::rw_bit<TIFR5, 0x05>;
                using OCF5C = registers::rw_bit<TIFR5, 0x03>;
                using OCF5B = registers::rw_bit<TIFR5, 0x02>;
                using OCF5A = registers::rw_bit<TIFR5, 0x01>;
                using TOV5  = registers::rw_bit<TIFR5, 0x00>;

                using PCIFR = registers::rw_io_register<0x3B, 8, 0b00000111>;
                using PCIF2 = registers::rw_bit<PCIFR, 0x02>;
                using PCIF1 = registers::rw_bit<PCIFR, 0x01>;
                using PCIF0 = registers::rw_bit<PCIFR, 0x00>;

                using EIFR  = registers::rw_io_register<0x3C, 8, 0b11111111>;
                using INTF7 = registers::rw_bit<EIFR, 0x07>;
                using INTF6 = registers::rw_bit<EIFR, 0x06>;
                using INTF5 = registers::rw_bit<EIFR, 0x05>;
                using INTF4 = registers::rw_bit<EIFR, 0x04>;
                using INTF3 = registers::rw_bit<EIFR, 0x03>;
                using INTF2 = registers::rw_bit<EIFR, 0x02>;
                using INTF1 = registers::rw_bit<EIFR, 0x01>;
                using INTF0 = registers::rw_bit<EIFR, 0x00>;

                using EIMSK = registers::rw_io_register<0x3D, 8, 0b11111111>;
                using INT7 = registers::rw_bit<EIMSK, 0x07>;
                using INT6 = registers::rw_bit<EIMSK, 0x06>;
                using INT5 = registers::rw_bit<EIMSK, 0x05>;
                using INT4 = registers::rw_bit<EIMSK, 0x04>;
                using INT3 = registers::rw_bit<EIMSK, 0x03>;
                using INT2 = registers::rw_bit<EIMSK, 0x02>;
                using INT1 = registers::rw_bit<EIMSK, 0X01>;
                using INT0 = registers::rw_bit<EIMSK, 0x00>;

                using GPIOR0  = registers::rw_io_register<0x3E, 8, 0b11111111>;

                using EECR  = registers::rw_io_register<0x3F, 8, 0b00111111>;
                using EEPM1 = registers::rw_bit<EECR, 0x05>;
                using EEPM0 = registers::rw_bit<EECR, 0x04>;
                using EERIE = registers::rw_bit<EECR, 0x03>;
                using EEMPE = registers::rw_bit<EECR, 0x02>;
                using EEPE  = registers::rw_bit<EECR, 0x01>;
                using EERE  = registers::rw_bit<EECR, 0x00>;

                using EEDR    = registers::rw_io_register<0X40, 8, 0b11111111>;

                /* Combine EEARL and EEARH */
                using EEAR    = registers::rw_io_register<0x41, 16, 0b1111111111111111>;

                using EEARL   = registers::rw_io_register<0x41, 8, 0b11111111>;
                using EEARH   = registers::rw_io_register<0X42, 8, 0b00001111>;

                /* 6-char sequence denoting where to find the EEPROM registers in memory space.
                   Adresses denoted in hex syntax with uppercase letters. Used by the EEPROM
                   subroutines.
                   First two letters:  EECR address.
                   Second two letters: EEDR address.
                   Last two letters:   EEAR address.  */
#define __EEPROM_REG_LOCATIONS__ 1F2021

                using GTCCR   = registers::rw_io_register<0x43, 8, 0b10000011>;
                using TSM     = registers::rw_bit<GTCCR, 0x07>;
                using PSRASY  = registers::rw_bit<GTCCR, 0x01>;
                using PSRSYNC = registers::rw_bit<GTCCR, 0x00>;

                using TCCR0A = registers::rw_io_register<0x44, 8, 0b11110011>;
                using COM0A1 = registers::rw_bit<TCCR0A, 0x07>;
                using COM0A0 = registers::rw_bit<TCCR0A, 0x06>;
                using COM0B1 = registers::rw_bit<TCCR0A, 0x05>;
                using COM0B0 = registers::rw_bit<TCCR0A, 0x04>;
                using WGM01  = registers::rw_bit<TCCR0A, 0x01>;
                using WGM00  = registers::rw_bit<TCCR0A, 0x00>;

                using TCCR0B = registers::rw_io_register<0x45, 8, 0b11001111>;
                using FOC0A = registers::rw_bit<TCCR0B, 0x07>;
                using FOC0B = registers::rw_bit<TCCR0B, 0x06>;
                using WGM02 = registers::rw_bit<TCCR0B, 0x03>;
                using CS02  = registers::rw_bit<TCCR0B, 0x02>;
                using CS01  = registers::rw_bit<TCCR0B, 0x01>;
                using CS00  = registers::rw_bit<TCCR0B, 0x00>;

                using TCNT0   = registers::rw_io_register<0X46, 8, 0b11111111>;
                using OCR0A   = registers::rw_io_register<0X47, 8, 0b11111111>;
                using OCR0B   = registers::rw_io_register<0X48, 8, 0b11111111>;

                /* Reserved [0x49] */

                using GPIOR1  = registers::rw_io_register<0x4A, 8, 0b11111111>;
                using GPIOR2  = registers::rw_io_register<0x4B, 8, 0b11111111>;

                using SPCR = registers::rw_io_register<0x4C, 8, 0b11111111>;
                using SPIE = registers::rw_bit<SPCR, 0x07>;
                using SPE  = registers::rw_bit<SPCR, 0x06>;
                using DORD = registers::rw_bit<SPCR, 0x05>;
                using MSTR = registers::rw_bit<SPCR, 0x04>;
                using CPOL = registers::rw_bit<SPCR, 0x03>;
                using CPHA = registers::rw_bit<SPCR, 0x02>;
                using SPR1 = registers::rw_bit<SPCR, 0x01>;
                using SPR0 = registers::rw_bit<SPCR, 0x00>;

                using SPSR      = registers::rw_io_register<0x4D, 8, 0b11000001>;
                using SPIF  = registers::ro_bit<SPSR, 0x07>;
                using WCOL  = registers::ro_bit<SPSR, 0x06>;
                using SPI2X = registers::rw_bit<SPSR, 0x00>;

                using SPDR    = registers::rw_io_register<0X4E, 8, 0b11111111>;

                /* Reserved [0x4F] */

                using ACSR  = registers::rw_io_register<0x50, 8, 0b11111111>;
                using ACD   = registers::rw_bit<ACSR, 0x07>;
                using ACBG  = registers::rw_bit<ACSR, 0x06>;
                using ACO   = registers::ro_bit<ACSR, 0x05>;
                using ACI   = registers::rw_bit<ACSR, 0x04>;
                using ACIE  = registers::rw_bit<ACSR, 0x03>;
                using ACIC  = registers::rw_bit<ACSR, 0x02>;
                using ACIS1 = registers::rw_bit<ACSR, 0x01>;
                using ACIS0 = registers::rw_bit<ACSR, 0x00>;

                using MONDR = registers::rw_io_register<0x51, 8, 0b00000000>;
                using OCDR  = registers::rw_io_register<0x51, 8, 0b11111111>;
                using IDRD  = registers::rw_bit<OCDR, 0x07>;
                using OCDR7 = registers::rw_bit<OCDR, 0x07>;
                using OCDR6 = registers::rw_bit<OCDR, 0x06>;
                using OCDR5 = registers::rw_bit<OCDR, 0x05>;
                using OCDR4 = registers::rw_bit<OCDR, 0x04>;
                using OCDR3 = registers::rw_bit<OCDR, 0x03>;
                using OCDR2 = registers::rw_bit<OCDR, 0x02>;
                using OCDR1 = registers::rw_bit<OCDR, 0x01>;
                using OCDR0 = registers::rw_bit<OCDR, 0x00>;

                /* Reserved [0x52] */

                using SMCR = registers::rw_io_register<0x53, 8, 0b00001111>;
                using SM2 = registers::rw_bit<SMCR, 0x03>;
                using SM1 = registers::rw_bit<SMCR, 0x02>;
                using SM0 = registers::rw_bit<SMCR, 0x01>;
                using SE  = registers::rw_bit<SMCR, 0x00>;

                using MCUSR = registers::rw_io_register<0x54, 8, 0b00011111>;
                using JTRF  = registers::rw_bit<MCUSR, 0x04>;
                using WDRF  = registers::rw_bit<MCUSR, 0x03>;
                using BORF  = registers::rw_bit<MCUSR, 0x02>;
                using EXTRF = registers::rw_bit<MCUSR, 0x01>;
                using PORF  = registers::rw_bit<MCUSR, 0x00>;

                using MCUCR = registers::rw_io_register<0X55, 8, 0b10010011>;
                using JTD   = registers::rw_bit<MCUCR, 0x07>;
                using PUD   = registers::rw_bit<MCUCR, 0x04>;
                using IVSEL = registers::rw_bit<MCUCR, 0x01>;
                using IVCE  = registers::rw_bit<MCUCR, 0x00>;

                /* Reserved [0x56] */

                using SPMCSR = registers::rw_io_register<0x57, 8, 0b11111111>;
                using SPMIE  = registers::rw_bit<SPMCSR, 0x07>;
                using RWWSB  = registers::rw_bit<SPMCSR, 0x06>;
                using SIGRD  = registers::rw_bit<SPMCSR, 0x05>;
                using RWWSRE = registers::rw_bit<SPMCSR, 0x04>;
                using BLBSET = registers::rw_bit<SPMCSR, 0x03>;
                using PGWRT  = registers::rw_bit<SPMCSR, 0x02>;
                using PGERS  = registers::rw_bit<SPMCSR, 0x01>;
                using SPMEN  = registers::rw_bit<SPMCSR, 0x00>;

                /* Reserved [0x58..0x5A] */

                using RAMPZ  = registers::rw_io_register<0X5B, 8, 0b00000011>;
                using RAMPZ1 = registers::rw_bit<RAMPZ, 0x01>;
                using RAMPZ0 = registers::rw_bit<RAMPZ, 0x00>;

                using EIND  = registers::rw_io_register<0X5C, 8, 0b00000001>;
                using EIND0 = registers::rw_bit<EIND, 0x00>;

                /* SP [0x5D..0x5E] */
                /* SREG [0x5F] */


                using WDTCSR = registers::rw_extended_io_register<0x60, 8, 0b11111111>;
                using WDIF = registers::rw_bit<WDTCSR, 0x07>;
                using WDIE = registers::rw_bit<WDTCSR, 0x06>;
                using WDP3 = registers::rw_bit<WDTCSR, 0x05>;
                using WDCE = registers::rw_bit<WDTCSR, 0x04>;
                using WDE  = registers::rw_bit<WDTCSR, 0x03>;
                using WDP2 = registers::rw_bit<WDTCSR, 0x02>;
                using WDP1 = registers::rw_bit<WDTCSR, 0x01>;
                using WDP0 = registers::rw_bit<WDTCSR, 0x00>;

                using CLKPR  = registers::rw_extended_io_register<0x61, 8, 0b10001111>;
                using CLKPCE = registers::rw_bit<CLKPR, 0x07>;
                using CLKPS3 = registers::rw_bit<CLKPR, 0x03>;
                using CLKPS2 = registers::rw_bit<CLKPR, 0x02>;
                using CLKPS1 = registers::rw_bit<CLKPR, 0x01>;
                using CLKPS0 = registers::rw_bit<CLKPR, 0x00>;

                /* Reserved [0x62..0x63] */

                using PRR0   = registers::rw_extended_io_register<0x64, 8, 0b11101111>;
                using PRTWI  = registers::rw_bit<PRR0, 0x07>;
                using PRTIM2 = registers::rw_bit<PRR0, 0x06>;
                using PRTIM0 = registers::rw_bit<PRR0, 0x05>;
                using PRTIM1 = registers::rw_bit<PRR0, 0x03>;
                using PRSPI  = registers::rw_bit<PRR0, 0x02>;
                using PRUSART0 = registers::rw_bit<PRR0, 0x01>;
                using PRADC  = registers::rw_bit<PRR0, 0x00>;

#define __AVR_HAVE_PRR0	((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI))

                using PRR1          = registers::rw_extended_io_register<0x65, 8, 0b00111111>;
                using PRTIM5   = registers::rw_bit<PRR1, 0x05>;
                using PRTIM4   = registers::rw_bit<PRR1, 0x04>;
                using PRTIM3   = registers::rw_bit<PRR1, 0x03>;
                using PRUSART3 = registers::rw_bit<PRR1, 0x02>;
                using PRUSART2 = registers::rw_bit<PRR1, 0x01>;
                using PRUSART1 = registers::rw_bit<PRR1, 0x00>;

#define __AVR_HAVE_PRR1	((1<<PRUSART1)|(1<<PRUSART2)|(1<<PRUSART3)|(1<<PRTIM3)|(1<<PRTIM4)|(1<<PRTIM5))

                using OSCCAL  = registers::rw_extended_io_register<0x66, 8, 0b11111111>;

                /* Reserved [0x67] */

                using PCICR     = registers::rw_extended_io_register<0x68, 8, 0b00000111>;
                using PCIE2 = registers::rw_bit<PCICR, 0x02>;
                using PCIE1 = registers::rw_bit<PCICR, 0x01>;
                using PCIE0 = registers::rw_bit<PCICR, 0x00>;

                using EICRA     = registers::rw_extended_io_register<0x69, 8, 0b11111111>;
                using ISC31 = registers::rw_bit<EICRA, 0x07>;
                using ISC30 = registers::rw_bit<EICRA, 0x06>;
                using ISC21 = registers::rw_bit<EICRA, 0x05>;
                using ISC20 = registers::rw_bit<EICRA, 0x04>;
                using ISC11 = registers::rw_bit<EICRA, 0x03>;
                using ISC10 = registers::rw_bit<EICRA, 0x02>;
                using ISC01 = registers::rw_bit<EICRA, 0x01>;
                using ISC00 = registers::rw_bit<EICRA, 0x00>;

                using EICRB     = registers::rw_extended_io_register<0x6A, 8, 0b11111111>;
                using ISC71 = registers::rw_bit<EICRB, 0x07>;
                using ISC70 = registers::rw_bit<EICRB, 0x06>;
                using ISC61 = registers::rw_bit<EICRB, 0x05>;
                using ISC60 = registers::rw_bit<EICRB, 0x04>;
                using ISC51 = registers::rw_bit<EICRB, 0x03>;
                using ISC50 = registers::rw_bit<EICRB, 0x02>;
                using ISC41 = registers::rw_bit<EICRB, 0x01>;
                using ISC40 = registers::rw_bit<EICRB, 0x00>;

                using PCMSK0     = registers::rw_extended_io_register<0x6B, 8, 0b11111111>;
                using PCINT7 = registers::rw_bit<PCMSK0, 0x07>;
                using PCINT6 = registers::rw_bit<PCMSK0, 0x06>;
                using PCINT5 = registers::rw_bit<PCMSK0, 0x05>;
                using PCINT4 = registers::rw_bit<PCMSK0, 0x04>;
                using PCINT3 = registers::rw_bit<PCMSK0, 0x03>;
                using PCINT2 = registers::rw_bit<PCMSK0, 0x02>;
                using PCINT1 = registers::rw_bit<PCMSK0, 0x01>;
                using PCINT0 = registers::rw_bit<PCMSK0, 0x00>;

                using PCMSK1      = registers::rw_extended_io_register<0x6C, 8, 0b11111111>;
                using PCINT15 = registers::rw_bit<PCMSK1, 0x07>;
                using PCINT14 = registers::rw_bit<PCMSK1, 0x06>;
                using PCINT13 = registers::rw_bit<PCMSK1, 0x05>;
                using PCINT12 = registers::rw_bit<PCMSK1, 0x04>;
                using PCINT11 = registers::rw_bit<PCMSK1, 0x03>;
                using PCINT10 = registers::rw_bit<PCMSK1, 0x02>;
                using PCINT9  = registers::rw_bit<PCMSK1, 0x01>;
                using PCINT8  = registers::rw_bit<PCMSK1, 0x00>;

                using PCMSK2      = registers::rw_extended_io_register<0x6C, 8, 0b11111111>;
                using PCINT23 = registers::rw_bit<PCMSK2, 0x07>;
                using PCINT22 = registers::rw_bit<PCMSK2, 0x06>;
                using PCINT21 = registers::rw_bit<PCMSK2, 0x05>;
                using PCINT20 = registers::rw_bit<PCMSK2, 0x04>;
                using PCINT19 = registers::rw_bit<PCMSK2, 0x03>;
                using PCINT18 = registers::rw_bit<PCMSK2, 0x02>;
                using PCINT17 = registers::rw_bit<PCMSK2, 0x01>;
                using PCINT16 = registers::rw_bit<PCMSK2, 0x00>;

                using TIMSK0     = registers::rw_extended_io_register<0x6E, 8, 0b00000111>;
                using OCIE0B = registers::rw_bit<TIMSK0, 0x02>;
                using OCIE0A = registers::rw_bit<TIMSK0, 0x01>;
                using TOIE0  = registers::rw_bit<TIMSK0, 0x00>;

                using TIMSK1     = registers::rw_extended_io_register<0x6F, 8, 0b00101111>;
                using ICIE1  = registers::rw_bit<TIMSK1, 0x05>;
                using OCIE1C = registers::rw_bit<TIMSK1, 0x03>;
                using OCIE1B = registers::rw_bit<TIMSK1, 0x02>;
                using OCIE1A = registers::rw_bit<TIMSK1, 0x01>;
                using TOIE1  = registers::rw_bit<TIMSK1, 0x00>;

                using TIMSK2     = registers::rw_extended_io_register<0x70, 8, 0b00000111>;
                using OCIE2B = registers::rw_bit<TIMSK2, 0x02>;
                using OCIE2A = registers::rw_bit<TIMSK2, 0x01>;
                using TOIE2  = registers::rw_bit<TIMSK2, 0x00>;

                using TIMSK3     = registers::rw_extended_io_register<0x71, 8, 0b00101111>;
                using ICIE3  = registers::rw_bit<TIMSK3, 0x05>;
                using OCIE3C = registers::rw_bit<TIMSK3, 0x03>;
                using OCIE3B = registers::rw_bit<TIMSK3, 0x02>;
                using OCIE3A = registers::rw_bit<TIMSK3, 0x01>;
                using TOIE3  = registers::rw_bit<TIMSK3, 0x00>;

                using TIMSK4     = registers::rw_extended_io_register<0x72, 8, 0b00101111>;
                using ICIE4  = registers::rw_bit<TIMSK4, 0x05>;
                using OCIE4C = registers::rw_bit<TIMSK4, 0x03>;
                using OCIE4B = registers::rw_bit<TIMSK4, 0x02>;
                using OCIE4A = registers::rw_bit<TIMSK4, 0x01>;
                using TOIE4  = registers::rw_bit<TIMSK4, 0x00>;

                using TIMSK5     = registers::rw_extended_io_register<0x73, 8, 0b00101111>;
                using ICIE5  = registers::rw_bit<TIMSK5, 0x05>;
                using OCIE5C = registers::rw_bit<TIMSK5, 0x03>;
                using OCIE5B = registers::rw_bit<TIMSK5, 0x02>;
                using OCIE5A = registers::rw_bit<TIMSK5, 0x01>;
                using TOIE5  = registers::rw_bit<TIMSK5, 0x00>;

                using XMCRA     = registers::rw_extended_io_register<0x74, 8, 0b11111111>;
                using SRE   = registers::rw_bit<XMCRA, 0x07>;
                using SRL2  = registers::rw_bit<XMCRA, 0x06>;
                using SRL1  = registers::rw_bit<XMCRA, 0x05>;
                using SRL0  = registers::rw_bit<XMCRA, 0x04>;
                using SRW11 = registers::rw_bit<XMCRA, 0x03>;
                using SRW10 = registers::rw_bit<XMCRA, 0x02>;
                using SRW01 = registers::rw_bit<XMCRA, 0x01>;
                using SRW00 = registers::rw_bit<XMCRA, 0x00>;

                using XMCRB    = registers::rw_extended_io_register<0x75, 8, 0b10000111>;
                using XMBK = registers::rw_bit<XMCRB, 0x07>;
                using XMM2 = registers::rw_bit<XMCRB, 0x02>;
                using XMM1 = registers::rw_bit<XMCRB, 0x01>;
                using XMM0 = registers::rw_bit<XMCRB, 0x00>;

                /* Reserved [0x76..0x77] */

                /* Combine ADCL and ADCH */
                using ADCW = registers::ro_extended_io_register<0x78, 16, 0b1111111111111111>;
                using ADCL = registers::ro_extended_io_register<0x78, 8, 0b11111111>;
                using ADCH = registers::ro_extended_io_register<0x79, 8, 0b11111111>;

                using ADCSRA    = registers::rw_extended_io_register<0x7A, 8, 0b11111111>;
                using ADEN  = registers::rw_bit<ADCSRA, 0x07>;
                using ADSC  = registers::rw_bit<ADCSRA, 0x06>;
                using ADATE = registers::rw_bit<ADCSRA, 0x05>;
                using ADIF  = registers::rw_bit<ADCSRA, 0x04>;
                using ADIE  = registers::rw_bit<ADCSRA, 0x03>;
                using ADPS2 = registers::rw_bit<ADCSRA, 0x02>;
                using ADPS1 = registers::rw_bit<ADCSRA, 0x01>;
                using ADPS0 = registers::rw_bit<ADCSRA, 0x00>;

                using ADCSRB    = registers::rw_extended_io_register<0x7B, 8, 0b10001111>;
                using ACME  = registers::rw_bit<ADCSRB, 0x06>;
                using MUX5  = registers::rw_bit<ADCSRB, 0x03>;
                using ADTS2 = registers::rw_bit<ADCSRB, 0x02>;
                using ADTS1 = registers::rw_bit<ADCSRB, 0x01>;
                using ADTS0 = registers::rw_bit<ADCSRB, 0x00>;

                using ADMUX     = registers::rw_extended_io_register<0x7C, 8, 0b11111111>;
                using REFS1 = registers::rw_bit<ADMUX, 0x07>;
                using REFS0 = registers::rw_bit<ADMUX, 0x06>;
                using ADLAR = registers::rw_bit<ADMUX, 0x05>;
                using MUX4  = registers::rw_bit<ADMUX, 0x04>;
                using MUX3  = registers::rw_bit<ADMUX, 0x03>;
                using MUX2  = registers::rw_bit<ADMUX, 0x02>;
                using MUX1  = registers::rw_bit<ADMUX, 0x01>;
                using MUX0  = registers::rw_bit<ADMUX, 0x00>;

                using DIDR2      = registers::rw_extended_io_register<0x7D, 8, 0b11111111>;
                using ADC15D = registers::rw_bit<DIDR2, 0x07>;
                using ADC14D = registers::rw_bit<DIDR2, 0x06>;
                using ADC13D = registers::rw_bit<DIDR2, 0x05>;
                using ADC12D = registers::rw_bit<DIDR2, 0x04>;
                using ADC11D = registers::rw_bit<DIDR2, 0x03>;
                using ADC10D = registers::rw_bit<DIDR2, 0x02>;
                using ADC9D  = registers::rw_bit<DIDR2, 0x01>;
                using ADC8D  = registers::rw_bit<DIDR2, 0x00>;

                using DIDR0   = registers::rw_extended_io_register<0x7E, 8, 0b11111111>;
                using ADC7D = registers::rw_bit<DIDR0, 0x07>;
                using ADC6D = registers::rw_bit<DIDR0, 0x06>;
                using ADC5D = registers::rw_bit<DIDR0, 0x05>;
                using ADC4D = registers::rw_bit<DIDR0, 0x04>;
                using ADC3D = registers::rw_bit<DIDR0, 0x03>;
                using ADC2D = registers::rw_bit<DIDR0, 0x02>;
                using ADC1D = registers::rw_bit<DIDR0, 0x01>;
                using ADC0D = registers::rw_bit<DIDR0, 0x00>;

                using DIDR1   = registers::rw_extended_io_register<0x7F, 8, 0b00000011>;
                using AIN1D = registers::rw_bit<DIDR1, 0x01>;
                using AIN0D = registers::rw_bit<DIDR1, 0x00>;

                using TCCR1A  = registers::rw_extended_io_register<0x80, 8, 0b11111111>;
                using COM1A1 = registers::rw_bit<TCCR1A, 0x07>;
                using COM1A0 = registers::rw_bit<TCCR1A, 0x06>;
                using COM1B1 = registers::rw_bit<TCCR1A, 0x05>;
                using COM1B0 = registers::rw_bit<TCCR1A, 0x04>;
                using COM1C1 = registers::rw_bit<TCCR1A, 0x03>;
                using COM1C0 = registers::rw_bit<TCCR1A, 0x02>;
                using WGM11 = registers::rw_bit<TCCR1A, 0x01>;
                using WGM10 = registers::rw_bit<TCCR1A, 0x00>;

                using TCCR1B  = registers::rw_extended_io_register<0x81, 8, 0b11011111>;
                using ICNC1 = registers::rw_bit<TCCR1B, 0x07>;
                using ICES1 = registers::rw_bit<TCCR1B, 0x06>;
                using WGM13 = registers::rw_bit<TCCR1B, 0x04>;
                using WGM12 = registers::rw_bit<TCCR1B, 0x03>;
                using CS12 = registers::rw_bit<TCCR1B, 0x02>;
                using CS11 = registers::rw_bit<TCCR1B, 0x01>;
                using CS10 = registers::rw_bit<TCCR1B, 0x00>;

                using TCCR1C  = registers::rw_extended_io_register<0x82, 8, 0b11100000>;
                using FOC1A = registers::rw_bit<TCCR1C, 0x07>;
                using FOC1B = registers::rw_bit<TCCR1C, 0x06>;
                using FOC1C = registers::rw_bit<TCCR1C, 0x05>;

                /* Reserved [0x83] */

                /* Combine TCNT1L and TCNT1H */
                using TCNT1   = registers::rw_extended_io_register<0x84, 16, 0b1111111111111111>;

                using TCNT1L  = registers::rw_extended_io_register<0x84, 8, 0b11111111>;
                using TCNT1H  = registers::rw_extended_io_register<0x85, 8, 0b11111111>;

                /* Combine ICR1L and ICR1H */
                using ICR1    = registers::rw_extended_io_register<0x86, 16, 0b1111111111111111>;

                using ICR1L   = registers::rw_extended_io_register<0x86, 8, 0b11111111>;
                using ICR1H   = registers::rw_extended_io_register<0x87, 8, 0b11111111>;

                /* Combine OCR1AL and OCR1AH */
                using OCR1A   = registers::rw_extended_io_register<0x88, 16, 0b1111111111111111>;

                using OCR1AL  = registers::rw_extended_io_register<0x88, 8, 0b11111111>;
                using OCR1AH  = registers::rw_extended_io_register<0x89, 8, 0b11111111>;

                /* Combine OCR1BL and OCR1BH */
                using OCR1B   = registers::rw_extended_io_register<0x8A, 16, 0b1111111111111111>;

                using OCR1BL  = registers::rw_extended_io_register<0x8A, 8, 0b11111111>;
                using OCR1BH  = registers::rw_extended_io_register<0x8B, 8, 0b11111111>;

                /* Combine OCR1CL and OCR1CH */
                using OCR1C   = registers::rw_extended_io_register<0x8C, 16, 0b1111111111111111>;

                using OCR1CL  = registers::rw_extended_io_register<0x8C, 8, 0b11111111>;
                using OCR1CH  = registers::rw_extended_io_register<0x8D, 8, 0b11111111>;

                /* Reserved [0x8E..0x8F] */

                using TCCR3A  = registers::rw_extended_io_register<0x90, 8, 0b11111111>;
                using COM3A1 = registers::rw_bit<TCCR3A, 0x07>;
                using COM3A0 = registers::rw_bit<TCCR3A, 0x06>;
                using COM3B1 = registers::rw_bit<TCCR3A, 0x05>;
                using COM3B0 = registers::rw_bit<TCCR3A, 0x04>;
                using COM3C1 = registers::rw_bit<TCCR3A, 0x03>;
                using COM3C0 = registers::rw_bit<TCCR3A, 0x02>;
                using WGM31 = registers::rw_bit<TCCR3A, 0x01>;
                using WGM30 = registers::rw_bit<TCCR3A, 0x00>;

                using TCCR3B  = registers::rw_extended_io_register<0x91, 8, 0b11011111>;
                using ICNC3 = registers::rw_bit<TCCR3B, 0x07>;
                using ICES3 = registers::rw_bit<TCCR3B, 0x06>;
                using WGM33 = registers::rw_bit<TCCR3B, 0x04>;
                using WGM32 = registers::rw_bit<TCCR3B, 0x03>;
                using CS32 = registers::rw_bit<TCCR3B, 0x02>;
                using CS31 = registers::rw_bit<TCCR3B, 0x01>;
                using CS30 = registers::rw_bit<TCCR3B, 0x00>;

                using TCCR3C  = registers::rw_extended_io_register<0x92, 8, 0b11100000>;
                using FOC3A = registers::rw_bit<TCCR3C, 0x07>;
                using FOC3B = registers::rw_bit<TCCR3C, 0x06>;
                using FOC3C = registers::rw_bit<TCCR3C, 0x05>;

                /* Reserved [0x93] */

                /* Combine TCNT3L and TCNT3H */
                using TCNT3   = registers::rw_extended_io_register<0x94, 16, 0b1111111111111111>;

                using TCNT3L  = registers::rw_extended_io_register<0x94, 8, 0b11111111>;
                using TCNT3H  = registers::rw_extended_io_register<0x95, 8, 0b11111111>;

                /* Combine ICR3L and ICR3H */
                using ICR3    = registers::rw_extended_io_register<0x96, 16, 0b1111111111111111>;

                using ICR3L   = registers::rw_extended_io_register<0x96, 8, 0b11111111>;
                using ICR3H   = registers::rw_extended_io_register<0x97, 8, 0b11111111>;

                /* Combine OCR3AL and OCR3AH */
                using OCR3A   = registers::rw_extended_io_register<0x98, 16, 0b1111111111111111>;

                using OCR3AL  = registers::rw_extended_io_register<0x98, 8, 0b11111111>;
                using OCR3AH  = registers::rw_extended_io_register<0x99, 8, 0b11111111>;

                /* Combine OCR3BL and OCR3BH */
                using OCR3B   = registers::rw_extended_io_register<0x9A, 16, 0b1111111111111111>;

                using OCR3BL  = registers::rw_extended_io_register<0x9A, 8, 0b11111111>;
                using OCR3BH  = registers::rw_extended_io_register<0x9B, 8, 0b11111111>;

                /* Combine OCR3CL and OCR3CH */
                using OCR3C   = registers::rw_extended_io_register<0x9C, 16, 0b1111111111111111>;

                using OCR3CL  = registers::rw_extended_io_register<0x9C, 8, 0b11111111>;
                using OCR3CH  = registers::rw_extended_io_register<0x9D, 8, 0b11111111>;

                /* Reserved [0x9E..0x9F] */

                using TCCR4A  = registers::rw_extended_io_register<0xA0, 8, 0b11111111>;
                using COM4A1 = registers::rw_bit<TCCR4A, 0x07>;
                using COM4A0 = registers::rw_bit<TCCR4A, 0x06>;
                using COM4B1 = registers::rw_bit<TCCR4A, 0x05>;
                using COM4B0 = registers::rw_bit<TCCR4A, 0x04>;
                using COM4C1 = registers::rw_bit<TCCR4A, 0x03>;
                using COM4C0 = registers::rw_bit<TCCR4A, 0x02>;
                using WGM41 = registers::rw_bit<TCCR4A, 0x01>;
                using WGM40 = registers::rw_bit<TCCR4A, 0x00>;

                using TCCR4B  = registers::rw_extended_io_register<0xA1, 8, 0b00000000>;
                using ICNC4 = registers::rw_bit<TCCR4B, 0x07>;
                using ICES4 = registers::rw_bit<TCCR4B, 0x06>;
                using WGM43 = registers::rw_bit<TCCR4B, 0x04>;
                using WGM42 = registers::rw_bit<TCCR4B, 0x03>;
                using CS42 = registers::rw_bit<TCCR4B, 0x02>;
                using CS41 = registers::rw_bit<TCCR4B, 0x01>;
                using CS40 = registers::rw_bit<TCCR4B, 0x00>;

                using TCCR4C  = registers::rw_extended_io_register<0xA2, 8, 0b00000000>;
                using FOC4A = registers::rw_bit<TCCR4C, 0x07>;
                using FOC4B = registers::rw_bit<TCCR4C, 0x06>;
                using FOC4C = registers::rw_bit<TCCR4C, 0x05>;

                /* Reserved [0xA3] */

                /* Combine TCNT4L and TCNT4H */
                using TCNT4   = registers::rw_extended_io_register<0xA4, 16, 0b1111111111111111>;

                using TCNT4L  = registers::rw_extended_io_register<0xA4, 8, 0b11111111>;
                using TCNT4H  = registers::rw_extended_io_register<0xA5, 8, 0b11111111>;

                /* Combine ICR4L and ICR4H */
                using ICR4    = registers::rw_extended_io_register<0xA6, 16, 0b1111111111111111>;

                using ICR4L   = registers::rw_extended_io_register<0xA6, 8, 0b11111111>;
                using ICR4H   = registers::rw_extended_io_register<0xA7, 8, 0b11111111>;

                /* Combine OCR4AL and OCR4AH */
                using OCR4A   = registers::rw_extended_io_register<0xA8, 16, 0b1111111111111111>;

                using OCR4AL  = registers::rw_extended_io_register<0xA8, 8, 0b11111111>;
                using OCR4AH  = registers::rw_extended_io_register<0xA9, 8, 0b11111111>;

                /* Combine OCR4BL and OCR4BH */
                using OCR4B   = registers::rw_extended_io_register<0xAA, 16, 0b1111111111111111>;

                using OCR4BL  = registers::rw_extended_io_register<0xAA, 8, 0b11111111>;
                using OCR4BH  = registers::rw_extended_io_register<0xAB, 8, 0b11111111>;

                /* Combine OCR4CL and OCR4CH */
                using OCR4C   = registers::rw_extended_io_register<0xAC, 16, 0b1111111111111111>;

                using OCR4CL  = registers::rw_extended_io_register<0xAC, 8, 0b11111111>;
                using OCR4CH  = registers::rw_extended_io_register<0xAD, 8, 0b11111111>;

                /* Reserved [0xAE..0xAF] */

                using TCCR2A  = registers::rw_extended_io_register<0xB0, 8, 0b00000000>;
                using COM2A1 = registers::rw_bit<TCCR2A, 0x07>;
                using COM2A0 = registers::rw_bit<TCCR2A, 0x06>;
                using COM2B1 = registers::rw_bit<TCCR2A, 0x05>;
                using COM2B0 = registers::rw_bit<TCCR2A, 0x04>;
                using WGM21 = registers::rw_bit<TCCR2A, 0x01>;
                using WGM20 = registers::rw_bit<TCCR2A, 0x00>;

                using TCCR2B  = registers::rw_extended_io_register<0xB1, 8, 0b00000000>;
                using FOC2A = registers::rw_bit<TCCR2B, 0x07>;
                using FOC2B = registers::rw_bit<TCCR2B, 0x06>;
                using WGM22 = registers::rw_bit<TCCR2B, 0x03>;
                using CS22 = registers::rw_bit<TCCR2B, 0x02>;
                using CS21 = registers::rw_bit<TCCR2B, 0x01>;
                using CS20 = registers::rw_bit<TCCR2B, 0x00>;

                using TCNT2   = registers::rw_extended_io_register<0xB2, 8, 0b11111111>;

                using OCR2A   = registers::rw_extended_io_register<0xB3, 8, 0b11111111>;

                using OCR2B   = registers::rw_extended_io_register<0xB4, 8, 0b11111111>;

                /* Reserved [0xB5] */

                using ASSR    = registers::rw_extended_io_register<0xB6, 8, 0b00000000>;
                using EXCLK = registers::rw_bit<ASSR, 0x06>;
                using AS2 = registers::rw_bit<ASSR, 0x05>;
                using TCN2UB = registers::rw_bit<ASSR, 0x04>;
                using OCR2AUB = registers::rw_bit<ASSR, 0x03>;
                using OCR2BUB = registers::rw_bit<ASSR, 0x02>;
                using TCR2AUB = registers::rw_bit<ASSR, 0x01>;
                using TCR2BUB = registers::rw_bit<ASSR, 0x00>;

                /* Reserved [0xB7] */

                using TWBR    = registers::rw_extended_io_register<0xB8, 8, 0b11111111>;

                using TWSR    = registers::rw_extended_io_register<0xB9, 8, 0b11111011>;
                using TWS7 = registers::rw_bit<TWSR, 0x07>;
                using TWS6 = registers::rw_bit<TWSR, 0x06>;
                using TWS5 = registers::rw_bit<TWSR, 0x05>;
                using TWS4 = registers::rw_bit<TWSR, 0x04>;
                using TWS3 = registers::rw_bit<TWSR, 0x03>;
                using TWPS1 = registers::rw_bit<TWSR, 0x01>;
                using TWPS0 = registers::rw_bit<TWSR, 0x00>;

                using TWAR    = registers::rw_extended_io_register<0xBA, 8, 0b11111111>;
                using TWA6 = registers::rw_bit<TWAR, 0x07>;
                using TWA5 = registers::rw_bit<TWAR, 0x06>;
                using TWA4 = registers::rw_bit<TWAR, 0x05>;
                using TWA3 = registers::rw_bit<TWAR, 0x04>;
                using TWA2 = registers::rw_bit<TWAR, 0x03>;
                using TWA1 = registers::rw_bit<TWAR, 0x02>;
                using TWA0 = registers::rw_bit<TWAR, 0x01>;
                using TWGCE = registers::rw_bit<TWAR, 0x00>;

                using TWDR    = registers::rw_extended_io_register<0xBB, 8, 0b11111111>;

                using TWCR    = registers::rw_extended_io_register<0xBC, 8, 0b11111101>;
                using TWINT = registers::rw_bit<TWCR, 0x07>;
                using TWEA = registers::rw_bit<TWCR, 0x06>;
                using TWSTA = registers::rw_bit<TWCR, 0x05>;
                using TWSTO = registers::rw_bit<TWCR, 0x04>;
                using TWWC = registers::rw_bit<TWCR, 0x03>;
                using TWEN = registers::rw_bit<TWCR, 0x02>;
                using TWIE = registers::rw_bit<TWCR, 0x00>;

                using TWAMR   = registers::rw_extended_io_register<0xBD, 8, 0b11111111>;
                using TWAM6 = registers::rw_bit<TWAMR, 0x07>;
                using TWAM5 = registers::rw_bit<TWAMR, 0x06>;
                using TWAM4 = registers::rw_bit<TWAMR, 0x05>;
                using TWAM3 = registers::rw_bit<TWAMR, 0x04>;
                using TWAM2 = registers::rw_bit<TWAMR, 0x03>;
                using TWAM1 = registers::rw_bit<TWAMR, 0x02>;
                using TWAM0 = registers::rw_bit<TWAMR, 0x01>;

                /* Reserved [0xBE..0xBF] */

                using UCSR0A  = registers::rw_extended_io_register<0xC0, 8, 0b11111111>;
                using RXC0 = registers::rw_bit<UCSR0A, 0x07>;
                using TXC0 = registers::rw_bit<UCSR0A, 0x06>;
                using UDRE0 = registers::rw_bit<UCSR0A, 0x05>;
                using FE0 = registers::rw_bit<UCSR0A, 0x04>;
                using DOR0 = registers::rw_bit<UCSR0A, 0x03>;
                using UPE0 = registers::rw_bit<UCSR0A, 0x02>;
                using U2X0 = registers::rw_bit<UCSR0A, 0x01>;
                using MPCM0 = registers::rw_bit<UCSR0A, 0x00>;

                using UCSR0B  = registers::rw_extended_io_register<0XC1, 8, 0b11111111>;
                using RXCIE0 = registers::rw_bit<UCSR0B, 0x07>;
                using TXCIE0 = registers::rw_bit<UCSR0B, 0x06>;
                using UDRIE0 = registers::rw_bit<UCSR0B, 0x05>;
                using RXEN0 = registers::rw_bit<UCSR0B, 0x04>;
                using TXEN0 = registers::rw_bit<UCSR0B, 0x03>;
                using UCSZ02 = registers::rw_bit<UCSR0B, 0x02>;
                using RXB80 = registers::rw_bit<UCSR0B, 0x01>;
                using TXB80 = registers::rw_bit<UCSR0B, 0x00>;

                using UCSR0C  = registers::rw_extended_io_register<0xC2, 8, 0b11111111>;
                using UMSEL01 = registers::rw_bit<UCSR0C, 0x07>;
                using UMSEL00 = registers::rw_bit<UCSR0C, 0x06>;
                using UPM01 = registers::rw_bit<UCSR0C, 0x05>;
                using UPM00 = registers::rw_bit<UCSR0C, 0x04>;
                using USBS0 = registers::rw_bit<UCSR0C, 0x03>;
                using UCSZ01 = registers::rw_bit<UCSR0C, 0x02>;
                using UCSZ00 = registers::rw_bit<UCSR0C, 0x01>;
                using UCPOL0 = registers::rw_bit<UCSR0C, 0x00>;

                /* Reserved [0xC3] */

                /* Combine UBRR0L and UBRR0H */
                using UBRR0   = registers::rw_extended_io_register<0xC4, 16, 0b1111111111111111>;

                using UBRR0L  = registers::rw_extended_io_register<0xC4, 8, 0b11111111>;
                using UBRR0H  = registers::rw_extended_io_register<0xC5, 8, 0b00001111>;

                using UDR0    = registers::rw_extended_io_register<0XC6, 8, 0b11111111>;

                /* Reserved [0xC7] */

                using UCSR1A  = registers::rw_extended_io_register<0xC8, 8, 0b11111111>;
                using RXC1 = registers::rw_bit<UCSR1A, 0x07>;
                using TXC1 = registers::rw_bit<UCSR1A, 0x06>;
                using UDRE1 = registers::rw_bit<UCSR1A, 0x05>;
                using FE1 = registers::rw_bit<UCSR1A, 0x04>;
                using DOR1 = registers::rw_bit<UCSR1A, 0x03>;
                using UPE1 = registers::rw_bit<UCSR1A, 0x02>;
                using U2X1 = registers::rw_bit<UCSR1A, 0x01>;
                using MPCM1 = registers::rw_bit<UCSR1A, 0x00>;

                using UCSR1B  = registers::rw_extended_io_register<0XC9, 8, 0b11111111>;
                using RXCIE1 = registers::rw_bit<UCSR1B, 0x07>;
                using TXCIE1 = registers::rw_bit<UCSR1B, 0x06>;
                using UDRIE1 = registers::rw_bit<UCSR1B, 0x05>;
                using RXEN1 = registers::rw_bit<UCSR1B, 0x04>;
                using TXEN1 = registers::rw_bit<UCSR1B, 0x03>;
                using UCSZ12 = registers::rw_bit<UCSR1B, 0x02>;
                using RXB81 = registers::rw_bit<UCSR1B, 0x01>;
                using TXB81 = registers::rw_bit<UCSR1B, 0x00>;

                using UCSR1C  = registers::rw_extended_io_register<0xCA, 8, 0b11111111>;
                using UMSEL11 = registers::rw_bit<UCSR1C, 0x07>;
                using UMSEL10 = registers::rw_bit<UCSR1C, 0x06>;
                using UPM11 = registers::rw_bit<UCSR1C, 0x05>;
                using UPM10 = registers::rw_bit<UCSR1C, 0x04>;
                using USBS1 = registers::rw_bit<UCSR1C, 0x03>;
                using UCSZ11 = registers::rw_bit<UCSR1C, 0x02>;
                using UCSZ10 = registers::rw_bit<UCSR1C, 0x01>;
                using UCPOL1 = registers::rw_bit<UCSR1C, 0x00>;

                /* Reserved [0xCB] */

                /* Combine UBRR1L and UBRR1H */
                using UBRR1   = registers::rw_extended_io_register<0xCC, 16, 0b1111111111111111>;
                using UBRR1L  = registers::rw_extended_io_register<0xCC, 8, 0b11111111>;
                using UBRR1H  = registers::rw_extended_io_register<0xCD, 8, 0b00001111>;

                using UDR1    = registers::rw_extended_io_register<0XCE, 8, 0b11111111>;

                /* Reserved [0xCF] */


                using UCSR2A = registers::rw_extended_io_register<0xD0, 8, 0b11111111>;
                using RXC2   = registers::rw_bit<UCSR2A, 0x07>;
                using TXC2   = registers::rw_bit<UCSR2A, 0x06>;
                using UDRE2  = registers::rw_bit<UCSR2A, 0x05>;
                using FE2    = registers::rw_bit<UCSR2A, 0x04>;
                using DOR2   = registers::rw_bit<UCSR2A, 0x03>;
                using UPE2   = registers::rw_bit<UCSR2A, 0x02>;
                using U2X2   = registers::rw_bit<UCSR2A, 0x01>;
                using MPCM2  = registers::rw_bit<UCSR2A, 0x00>;

                using UCSR2B = registers::rw_extended_io_register<0XD1, 8, 0b11111111>;
                using RXCIE2 = registers::rw_bit<UCSR2B, 0x07>;
                using TXCIE2 = registers::rw_bit<UCSR2B, 0x06>;
                using UDRIE2 = registers::rw_bit<UCSR2B, 0x05>;
                using RXEN2  = registers::rw_bit<UCSR2B, 0x04>;
                using TXEN2  = registers::rw_bit<UCSR2B, 0x03>;
                using UCSZ22 = registers::rw_bit<UCSR2B, 0x02>;
                using RXB82  = registers::rw_bit<UCSR2B, 0x01>;
                using TXB82  = registers::rw_bit<UCSR2B, 0x00>;

                using UCSR2C = registers::rw_extended_io_register<0xD2, 8, 0b11111111>;
                using UMSEL21 = registers::rw_bit<UCSR2C, 0x07>;
                using UMSEL20 = registers::rw_bit<UCSR2C, 0x06>;
                using UPM21  = registers::rw_bit<UCSR2C, 0x05>;
                using UPM20  = registers::rw_bit<UCSR2C, 0x04>;
                using USBS2  = registers::rw_bit<UCSR2C, 0x03>;
                using UCSZ21 = registers::rw_bit<UCSR2C, 0x02>;
                using UCSZ20 = registers::rw_bit<UCSR2C, 0x01>;
                using UCPOL2 = registers::rw_bit<UCSR2C, 0x00>;

                /* Reserved [0xD3] */

                /* Combine UBRR2L and UBRR2H */
                using UBRR2  = registers::rw_extended_io_register<0xD4, 16, 0b1111111111111111>;

                using UBRR2L = registers::rw_extended_io_register<0xD4, 8, 0b11111111>;
                using UBRR2H = registers::rw_extended_io_register<0xD5, 8, 0b00001111>;

                using UDR2   = registers::rw_extended_io_register<0XD6, 8, 0b11111111>;


                /* Reserved [0xD7..0xFF] */


                using PINH   = registers::rw_extended_io_register<0x100, 8, 0b11111111>;
                using PINH7  = registers::rw_bit<PINH, 0x07>;
                using PINH6  = registers::rw_bit<PINH, 0x06>;
                using PINH5  = registers::rw_bit<PINH, 0x05>;
                using PINH4  = registers::rw_bit<PINH, 0x04>;
                using PINH3  = registers::rw_bit<PINH, 0x03>;
                using PINH2  = registers::rw_bit<PINH, 0x02>;
                using PINH1  = registers::rw_bit<PINH, 0x01>;
                using PINH0  = registers::rw_bit<PINH, 0x00>;

                using DDRH   = registers::rw_extended_io_register<0x101, 8, 0b11111111>;
                using DDH7   = registers::rw_bit<DDRH, 0x07>;
                using DDH6   = registers::rw_bit<DDRH, 0x06>;
                using DDH5   = registers::rw_bit<DDRH, 0x05>;
                using DDH4   = registers::rw_bit<DDRH, 0x04>;
                using DDH3   = registers::rw_bit<DDRH, 0x03>;
                using DDH2   = registers::rw_bit<DDRH, 0x02>;
                using DDH1   = registers::rw_bit<DDRH, 0x01>;
                using DDH0   = registers::rw_bit<DDRH, 0x00>;

                using PORTH  = registers::rw_extended_io_register<0x102, 8, 0b11111111>;
                using PH7    = registers::rw_bit<PORTH, 0x07>;
                using PH6    = registers::rw_bit<PORTH, 0x06>;
                using PH5    = registers::rw_bit<PORTH, 0x05>;
                using PH4    = registers::rw_bit<PORTH, 0x04>;
                using PH3    = registers::rw_bit<PORTH, 0x03>;
                using PH2    = registers::rw_bit<PORTH, 0x02>;
                using PH1    = registers::rw_bit<PORTH, 0x01>;
                using PH0    = registers::rw_bit<PORTH, 0x00>;

                using PINJ   = registers::rw_extended_io_register<0x103, 8, 0b11111111>;
                using PINJ7  = registers::rw_bit<PINJ, 0x07>;
                using PINJ6  = registers::rw_bit<PINJ, 0x06>;
                using PINJ5  = registers::rw_bit<PINJ, 0x05>;
                using PINJ4  = registers::rw_bit<PINJ, 0x04>;
                using PINJ3  = registers::rw_bit<PINJ, 0x03>;
                using PINJ2  = registers::rw_bit<PINJ, 0x02>;
                using PINJ1  = registers::rw_bit<PINJ, 0x01>;
                using PINJ0  = registers::rw_bit<PINJ, 0x00>;

                using DDRJ   = registers::rw_extended_io_register<0x104, 8, 0b11111111>;
                using DDJ7   = registers::rw_bit<DDRJ, 0x07>;
                using DDJ6   = registers::rw_bit<DDRJ, 0x06>;
                using DDJ5   = registers::rw_bit<DDRJ, 0x05>;
                using DDJ4   = registers::rw_bit<DDRJ, 0x04>;
                using DDJ3   = registers::rw_bit<DDRJ, 0x03>;
                using DDJ2   = registers::rw_bit<DDRJ, 0x02>;
                using DDJ1   = registers::rw_bit<DDRJ, 0x01>;
                using DDJ0   = registers::rw_bit<DDRJ, 0x00>;

                using PORTJ  = registers::rw_extended_io_register<0x105, 8, 0b11111111>;
                using PJ7 = registers::rw_bit<PORTJ, 0x07>;
                using PJ6 = registers::rw_bit<PORTJ, 0x06>;
                using PJ5 = registers::rw_bit<PORTJ, 0x05>;
                using PJ4 = registers::rw_bit<PORTJ, 0x04>;
                using PJ3 = registers::rw_bit<PORTJ, 0x03>;
                using PJ2 = registers::rw_bit<PORTJ, 0x02>;
                using PJ1 = registers::rw_bit<PORTJ, 0x01>;
                using PJ0 = registers::rw_bit<PORTJ, 0x00>;

                using PINK   = registers::rw_extended_io_register<0x106, 8, 0b11111111>;
                using PINK7  = registers::rw_bit<PINK, 0x07>;
                using PINK6  = registers::rw_bit<PINK, 0x06>;
                using PINK5  = registers::rw_bit<PINK, 0x05>;
                using PINK4  = registers::rw_bit<PINK, 0x04>;
                using PINK3  = registers::rw_bit<PINK, 0x03>;
                using PINK2  = registers::rw_bit<PINK, 0x02>;
                using PINK1  = registers::rw_bit<PINK, 0x01>;
                using PINK0  = registers::rw_bit<PINK, 0x00>;

                using DDRK   = registers::rw_extended_io_register<0x107, 8, 0b11111111>;
                using DDK7   = registers::rw_bit<DDRK, 0x07>;
                using DDK6   = registers::rw_bit<DDRK, 0x06>;
                using DDK5   = registers::rw_bit<DDRK, 0x05>;
                using DDK4   = registers::rw_bit<DDRK, 0x04>;
                using DDK3   = registers::rw_bit<DDRK, 0x03>;
                using DDK2   = registers::rw_bit<DDRK, 0x02>;
                using DDK1   = registers::rw_bit<DDRK, 0x01>;
                using DDK0   = registers::rw_bit<DDRK, 0x00>;

                using PORTK  = registers::rw_extended_io_register<0x108, 8, 0b11111111>;
                using PK7 = registers::rw_bit<PORTK, 0x07>;
                using PK6 = registers::rw_bit<PORTK, 0x06>;
                using PK5 = registers::rw_bit<PORTK, 0x05>;
                using PK4 = registers::rw_bit<PORTK, 0x04>;
                using PK3 = registers::rw_bit<PORTK, 0x03>;
                using PK2 = registers::rw_bit<PORTK, 0x02>;
                using PK1 = registers::rw_bit<PORTK, 0x01>;
                using PK0 = registers::rw_bit<PORTK, 0x00>;

                using PINL   = registers::rw_extended_io_register<0x109, 8, 0b11111111>;
                using PINL7  = registers::rw_bit<PINL, 0x07>;
                using PINL6  = registers::rw_bit<PINL, 0x06>;
                using PINL5  = registers::rw_bit<PINL, 0x05>;
                using PINL4  = registers::rw_bit<PINL, 0x04>;
                using PINL3  = registers::rw_bit<PINL, 0x03>;
                using PINL2  = registers::rw_bit<PINL, 0x02>;
                using PINL1  = registers::rw_bit<PINL, 0x01>;
                using PINL0  = registers::rw_bit<PINL, 0x00>;

                using DDRL   = registers::rw_extended_io_register<0x10A, 8, 0b11111111>;
                using DDL7   = registers::rw_bit<DDRL, 0x07>;
                using DDL6   = registers::rw_bit<DDRL, 0x06>;
                using DDL5   = registers::rw_bit<DDRL, 0x05>;
                using DDL4   = registers::rw_bit<DDRL, 0x04>;
                using DDL3   = registers::rw_bit<DDRL, 0x03>;
                using DDL2   = registers::rw_bit<DDRL, 0x02>;
                using DDL1   = registers::rw_bit<DDRL, 0x01>;
                using DDL0   = registers::rw_bit<DDRL, 0x00>;

                using PORTL  = registers::rw_extended_io_register<0x10B, 8, 0b11111111>;
                using PL7 = registers::rw_bit<PORTL, 0x07>;
                using PL6 = registers::rw_bit<PORTL, 0x06>;
                using PL5 = registers::rw_bit<PORTL, 0x05>;
                using PL4 = registers::rw_bit<PORTL, 0x04>;
                using PL3 = registers::rw_bit<PORTL, 0x03>;
                using PL2 = registers::rw_bit<PORTL, 0x02>;
                using PL1 = registers::rw_bit<PORTL, 0x01>;
                using PL0 = registers::rw_bit<PORTL, 0x00>;


                /* Reserved [0x10C..0x11F] */

                using TCCR5A  = registers::rw_extended_io_register<0x120, 8, 0b11111111>;
                using COM5A1 = registers::rw_bit<TCCR5A, 0x07>;
                using COM5A0 = registers::rw_bit<TCCR5A, 0x06>;
                using COM5B1 = registers::rw_bit<TCCR5A, 0x05>;
                using COM5B0 = registers::rw_bit<TCCR5A, 0x04>;
                using COM5C1 = registers::rw_bit<TCCR5A, 0x03>;
                using COM5C0 = registers::rw_bit<TCCR5A, 0x02>;
                using WGM51 = registers::rw_bit<TCCR5A, 0x01>;
                using WGM50 = registers::rw_bit<TCCR5A, 0x00>;

                using TCCR5B  = registers::rw_extended_io_register<0x121, 8, 0b11011111>;
                using ICNC5 = registers::rw_bit<TCCR5B, 0x07>;
                using ICES5 = registers::rw_bit<TCCR5B, 0x06>;
                using WGM53 = registers::rw_bit<TCCR5B, 0x04>;
                using WGM52 = registers::rw_bit<TCCR5B, 0x03>;
                using CS52 = registers::rw_bit<TCCR5B, 0x02>;
                using CS51 = registers::rw_bit<TCCR5B, 0x01>;
                using CS50 = registers::rw_bit<TCCR5B, 0x00>;

                using TCCR5C  = registers::rw_extended_io_register<0x122, 8, 0b11100000>;
                using FOC5A = registers::rw_bit<TCCR5C, 0x07>;
                using FOC5B = registers::rw_bit<TCCR5C, 0x06>;
                using FOC5C = registers::rw_bit<TCCR5C, 0x05>;

                /* Reserved [0x123] */

                /* Combine TCNT5L and TCNT5H */
                using TCNT5   = registers::rw_extended_io_register<0x124, 16, 0b1111111111111111>;

                using TCNT5L  = registers::rw_extended_io_register<0x124, 8, 0b11111111>;
                using TCNT5H  = registers::rw_extended_io_register<0x125, 8, 0b11111111>;

                /* Combine ICR5L and ICR5H */
                using ICR5    = registers::rw_extended_io_register<0x126, 16, 0b1111111111111111>;

                using ICR5L   = registers::rw_extended_io_register<0x126, 8, 0b11111111>;
                using ICR5H   = registers::rw_extended_io_register<0x127, 8, 0b11111111>;

                /* Combine OCR5AL and OCR5AH */
                using OCR5A   = registers::rw_extended_io_register<0x128, 16, 0b1111111111111111>;

                using OCR5AL  = registers::rw_extended_io_register<0x128, 8, 0b11111111>;
                using OCR5AH  = registers::rw_extended_io_register<0x129, 8, 0b11111111>;

                /* Combine OCR5BL and OCR5BH */
                using OCR5B   = registers::rw_extended_io_register<0x12A, 16, 0b1111111111111111>;

                using OCR5BL  = registers::rw_extended_io_register<0x12A, 8, 0b11111111>;
                using OCR5BH  = registers::rw_extended_io_register<0x12B, 8, 0b11111111>;

                /* Combine OCR5CL and OCR5CH */
                using OCR5C   = registers::rw_extended_io_register<0x12C, 16, 0b1111111111111111>;

                using OCR5CL  = registers::rw_extended_io_register<0x12C, 8, 0b11111111>;
                using OCR5CH  = registers::rw_extended_io_register<0x12D, 8, 0b11111111>;

                /* Reserved [0x12E..0x12F] */

                using UCSR3A = registers::rw_extended_io_register<0x130, 8, 0b11111111>;
                using RXC3   = registers::rw_bit<UCSR3A, 0x07>;
                using TXC3   = registers::rw_bit<UCSR3A, 0x06>;
                using UDRE3  = registers::rw_bit<UCSR3A, 0x05>;
                using FE3    = registers::rw_bit<UCSR3A, 0x04>;
                using DOR3   = registers::rw_bit<UCSR3A, 0x03>;
                using UPE3   = registers::rw_bit<UCSR3A, 0x02>;
                using U2X3   = registers::rw_bit<UCSR3A, 0x01>;
                using MPCM3  = registers::rw_bit<UCSR3A, 0x00>;

                using UCSR3B = registers::rw_extended_io_register<0X131, 8, 0b11111111>;
                using RXCIE3 = registers::rw_bit<UCSR3B, 0x07>;
                using TXCIE3 = registers::rw_bit<UCSR3B, 0x06>;
                using UDRIE3 = registers::rw_bit<UCSR3B, 0x05>;
                using RXEN3  = registers::rw_bit<UCSR3B, 0x04>;
                using TXEN3  = registers::rw_bit<UCSR3B, 0x03>;
                using UCSZ32 = registers::rw_bit<UCSR3B, 0x02>;
                using RXB83  = registers::rw_bit<UCSR3B, 0x01>;
                using TXB83  = registers::rw_bit<UCSR3B, 0x00>;

                using UCSR3C = registers::rw_extended_io_register<0x132, 8, 0b11111111>;
                using UMSEL31 = registers::rw_bit<UCSR3C, 0x07>;
                using UMSEL30 = registers::rw_bit<UCSR3C, 0x06>;
                using UPM31  = registers::rw_bit<UCSR3C, 0x05>;
                using UPM30  = registers::rw_bit<UCSR3C, 0x04>;
                using USBS3  = registers::rw_bit<UCSR3C, 0x03>;
                using UCSZ31 = registers::rw_bit<UCSR3C, 0x02>;
                using UCSZ30 = registers::rw_bit<UCSR3C, 0x01>;
                using UCPOL3 = registers::rw_bit<UCSR3C, 0x00>;

                /* Reserved [0x133] */

                /* Combine UBRR3L and UBRR3H */
                using UBRR3  = registers::rw_extended_io_register<0x134, 16, 0b1111111111111111>;

                using UBRR3L = registers::rw_extended_io_register<0x134, 8, 0b11111111>;
                using UBRR3H = registers::rw_extended_io_register<0x135, 8, 0b00001111>;

                using UDR3   = registers::rw_extended_io_register<0X136, 8, 0b11111111>;

                /* Reserved [0x137..1FF] */

                /* Interrupt vectors */
                /* Vector 0 is the reset vector */
                /* External Interrupt Request 0 */
#define INT0_vect_num       1
#define INT0_vect           _VECTOR(1)
#define SIG_INTERRUPT0          _VECTOR(1)

                /* External Interrupt Request 1 */
#define INT1_vect_num       2
#define INT1_vect           _VECTOR(2)
#define SIG_INTERRUPT1          _VECTOR(2)

                /* External Interrupt Request 2 */
#define INT2_vect_num       3
#define INT2_vect           _VECTOR(3)
#define SIG_INTERRUPT2          _VECTOR(3)

                /* External Interrupt Request 3 */
#define INT3_vect_num       4
#define INT3_vect           _VECTOR(4)
#define SIG_INTERRUPT3          _VECTOR(4)

                /* External Interrupt Request 4 */
#define INT4_vect_num       5
#define INT4_vect           _VECTOR(5)
#define SIG_INTERRUPT4          _VECTOR(5)

                /* External Interrupt Request 5 */
#define INT5_vect_num       6
#define INT5_vect           _VECTOR(6)
#define SIG_INTERRUPT5          _VECTOR(6)

                /* External Interrupt Request 6 */
#define INT6_vect_num       7
#define INT6_vect           _VECTOR(7)
#define SIG_INTERRUPT6          _VECTOR(7)

                /* External Interrupt Request 7 */
#define INT7_vect_num       8
#define INT7_vect           _VECTOR(8)
#define SIG_INTERRUPT7          _VECTOR(8)

                /* Pin Change Interrupt Request 0 */
#define PCINT0_vect_num     9
#define PCINT0_vect         _VECTOR(9)
#define SIG_PIN_CHANGE0         _VECTOR(9)

                /* Pin Change Interrupt Request 1 */
#define PCINT1_vect_num     10
#define PCINT1_vect         _VECTOR(10)
#define SIG_PIN_CHANGE1         _VECTOR(10)

#if defined(__ATmegaxx0__)
                /* Pin Change Interrupt Request 2 */
#define PCINT2_vect_num     11
#define PCINT2_vect         _VECTOR(11)
#define SIG_PIN_CHANGE2         _VECTOR(11)

#endif /* __ATmegaxx0__ */

                /* Watchdog Time-out Interrupt */
#define WDT_vect_num        12
#define WDT_vect            _VECTOR(12)
#define SIG_WATCHDOG_TIMEOUT        _VECTOR(12)

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

            }; /* end of struct megaxx01 */

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

        }}} /* end of namespace vAVR */

#endif /* _AVR_IOMXX0_1_H_ */
