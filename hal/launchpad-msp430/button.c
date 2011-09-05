
#include <button.h>
#include <gpio.h>
//#include <io.h>
#include "launchpad-msp430.h"

void button_init(void)
{
    // set the button as input
    gpio_init(1, BUTTON_PIO, GPIO_INPUT | GPIO_PULL_UP);
}

unsigned char button_is_pressed(void)
{
    return gpio_is_low(1, BUTTON_PIO);
}
