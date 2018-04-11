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
AVRFLAGS = -mmcu=atmega2560
INCLUDES = -I ./include mega328p.h
SOURCES = main.cpp
OUTDIR = bin
OBJ_DIR := $(SOURCES:%.cpp=bin/%)

debug: CPPFLAGS += -g
release: CPPFLAGS += -O2

all :
	$(CC) $(SOURCES) $(CPPFLAGS) $(AVRFLAGS) $(INCLUDES) 

debug: all
release: all

clean:
	rm -f $(OUTDIR)/% Makefile.bak
	
rebuild:
	clean all

