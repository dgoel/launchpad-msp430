

#include <gpio.h>
#include <io.h>
#include "launchpad-msp430.h"


void gpio_init(unsigned int port, unsigned int num, GPIOConfig config)
{
    if (config & GPIO_OUTPUT) {
        if (port == 1) {
            P1DIR |= (1<<num);
        }
    }
}

void gpio_set_high(unsigned int port, unsigned int num)
{
}

void gpio_set_low(unsigned int port, unsigned int num)
{
}

unsigned char gpio_is_low(unsigned int port, unsigned int num)
{
    return 0;
}

unsigned char gpio_is_high(unsigned int port, unsigned int num)
{
    return 0;
}
