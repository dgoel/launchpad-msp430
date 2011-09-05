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
    if (config & GPIO_INPUT) {
        if (port == 1) {
            P1DIR &= ~(1<<num);
        }
    }
    if ((config & GPIO_PULL_UP) || (config & GPIO_PULL_DOWN)) {
        if (port == 1) {
            P1REN |= (1<<num);
        }
    }
}

void gpio_set_high(unsigned int port, unsigned int num)
{
    if (port == 1) {
        P1OUT |= (1<<num);
    }
}

void gpio_set_low(unsigned int port, unsigned int num)
{
    if (port == 1) {
        P1OUT &= ~(1<<num);
    }
}

unsigned char gpio_is_low(unsigned int port, unsigned int num)
{
    if (port == 1) {
        return ((P1IN & (1<<num)) == 0);
    }
    return 0;
}

unsigned char gpio_is_high(unsigned int port, unsigned int num)
{
    return !gpio_is_low(port, num);
}
