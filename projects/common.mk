BASEDIR=../..
COMPILER_PREFIX=$(ARCH)
CFLAGS += -O0 -g3 -Wall -mmcu=$(MCU) -I$(BASEDIR)/hal -ffunction-sections -fdata-sections
LDFLAGS += -L$(BASEDIR)/hal/$(BOARD)-$(ARCH) -l$(BOARD)-$(ARCH) -Wl,-Map=$(TARGET).map -Wl,--gc-sections
LIBS = lib$(BOARD)-$(ARCH).a

all: $(TARGET).elf

%.elf: $(OBJS)
	$(COMPILER_PREFIX)-gcc -o $@ $^ $(LDFLAGS)
	$(COMPILER_PREFIX)-size $@

%.o: %.c
	$(COMPILER_PREFIX)-gcc $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -rf *.elf *.o

