#
# Makefile for AVR libraries
#
# Compiler: avr-g++
#
# Author: Nelson Vides
# Date: April 2018
#

CC = avr-g++
CPPFLAGS = -Wall -Wextra -Werror -Woverflow -std=c++14 -fno-exceptions -Wno-int-to-pointer-cast
AVRFLAGS = -mmcu=atmega2560 -D F_CPU=16000000UL
INCLUDES = -I ./include
SOURCES = main.cpp
OUTDIR = bin
OBJ_DIR := $(SOURCES:%.cpp=bin/%)

debug: CPPFLAGS += -g -o debug.out -D__DEBUG
standard: CPPFLAGS += -Os -o standard.out
release: CPPFLAGS += -O2 -o release.out
sourcecode: CPPFLAGS += -E -o sourcecode.out

all :
	$(CC) $(SOURCES) $(CPPFLAGS) $(AVRFLAGS) $(INCLUDES) 

debug: all
standard: all
release: all
sourcecode: all

clean:
	rm -f $(OUTDIR)/% Makefile.bak
	
rebuild:
	clean all

