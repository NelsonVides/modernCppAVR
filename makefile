#
# Makefile for AVR libraries
#
# Compiler: avr-g++
#
# Author: Nelson Vides
# Date: April 2018
#

CC=avr-g++
CPPFLAGS = -Wall -Wextra -Werror -Woverflow -std=c++14 -fno-exceptions -Wno-int-to-pointer-cast
AVRFLAGS = -mmcu=atmega2560 -D F_CPU=16000000UL
INCLUDES = -I .\include
SOURCES = main.cpp
OUTDIR = bin

DEBUG = -g -o $(OUTDIR)\debug.out -D__DEBUG
STANDARD = -Os -o $(OUTDIR)\standard.out
RELEASE = -O2 -o $(OUTDIR)\release.out
SOURCECODE = -E -o $(OUTDIR)\sourcecode.out

.PHONY : all
debug : $(SOURCES)
	$(CC) $(CPPFLAGS) $(DEBUG) $(AVRFLAGS) $(INCLUDES) $(SOURCES)
standard : $(SOURCES)
	$(CC) $(CPPFLAGS) $(STANDARD) $(AVRFLAGS) $(INCLUDES) $(SOURCES)
release : $(SOURCES)
	$(CC) $(CPPFLAGS) $(RELEASE) $(AVRFLAGS) $(INCLUDES) $(SOURCES)
sourcecode : $(SOURCES)
	$(CC) $(CPPFLAGS) $(SOURCECODE) $(AVRFLAGS) $(INCLUDES) $(SOURCES)

all : $(SOURCES)
	$(CC) $(CPPFLAGS) $(AVRFLAGS) $(INCLUDES) $(SOURCES)

clean :
	del -f $(OUTDIR)/% Makefile.bak

rebuild :
	clean all