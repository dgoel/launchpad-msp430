ARCH=msp430
BOARD=launchpad
MCU=msp430x2231

COMPILER_PREFIX=$(ARCH)
CFLAGS += -O0 -g3 -Wall -mmcu=$(MCU) -I../ -ffunction-sections -fdata-sections
LDFLAGS += -L../ -l$(BOARD)-$(ARCH) -Wl,--gc-sections
LIBS = lib$(BOARD)-$(ARCH).a

TESTS_ELFS= $(TESTS:=.elf)
TESTS_OBJS= $(TESTS:=.o)
TESTS_MAPS= $(TEST:=.map)

all: $(TESTS_ELFS)

%.elf: %.o
	$(COMPILER_PREFIX)-gcc -o $@ $^ $(LDFLAGS) -Wl,-Map=$(<:.o=.map)
	$(COMPILER_PREFIX)-size $@

%.o: %.c
	$(COMPILER_PREFIX)-gcc $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -rf $(TESTS_ELFS) $(TESTS_OBJS) $(TESTS_MAPS)

