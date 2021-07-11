# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: Toy.elf 

#additional rules for files
Toy.elf: ${COMMON_OBJECTS} blinkMain.o stateMachines.o led.o wdInterruptHandler.o lib/libTimer.a p1_interrupt_handler.o switches.o buzzer.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: Toy.elf
	msp430loader.sh Toy.elf

clean:
	rm -f *.o *.elf

wdInterruptHandler.o: stateMachines.h led.h switches.h buzzer.h

stateMachines.o: stateMachines.h led.h switches.h buzzer.h
