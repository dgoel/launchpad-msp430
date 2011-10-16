COMPILER_PREFIX = msp430
CFLAGS = -O2 -g3 -Wall -mmcu=msp430x2231 -I. -fdata-sections -ffunction-sections

all: liblaunchpad-msp430.a

OBJFILES = init.o \
	gpio.o \
	led.o \
	button.o \
	interrupt.o \
	timer.o

%.a: $(OBJFILES)
	$(COMPILER_PREFIX)-ar rvs $@ $^

%.o: %.c
	$(COMPILER_PREFIX)-gcc $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -rf *.o *.a