################################################################################
# Makefile for StopWatchTimer
# Author: J.C. Mariscal
################################################################################


# Options ######################################################################
#PORT=/dev/ttyUSB_MySmartUSB
PORT=/dev/ttyUSB0
PROGRAMMER=avr911
TARGET_CPU=atmega88pa
TARGET_PROCESSOR=m88p
CFLAGS=-Wall -Os -c -mmcu=$(TARGET_CPU)
LDFLAGS=-Os -mmcu=$(TARGET_CPU)

# Program ######################################################################
all: program.hex
	echo program build complete

program: program.hex
	avrdude -p $(TARGET_PROCESSOR) -c $(PROGRAMMER) -P $(PORT) -U flash:w:program.hex:i

# Hex File #####################################################################
program.hex: program.elf
	avr-objcopy -O ihex program.elf program.hex

program.elf: main.o init.o lcd.o
	avr-gcc $(LDFLAGS) main.o init.o lcd.o -o program.elf


# Object Files #################################################################
init.o: init.c
	avr-gcc $(CFLAGS) init.c -o init.o

lcd.o: lcd.c
	avr-gcc $(CFLAGS) lcd.c -o lcd.o

main.o: main.c
	avr-gcc $(CFLAGS) main.c -o main.o

# Clean ########################################################################
clean:
	rm -f *.o *.elf *.hex *~
