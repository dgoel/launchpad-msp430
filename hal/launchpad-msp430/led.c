

#include <led.h>
#include <gpio.h>
#include <io.h>
#include "launchpad-msp430.h"

#define LED_DIR  P1DIR
#define LED_OUT  P1OUT

void led_init(void)
{
    // set led pins as output
    gpio_init(1, LED_RED_PIO, GPIO_OUTPUT);
    gpio_init(1, LED_GREEN_PIO, GPIO_OUTPUT);
}

void led_on(LEDType led)
{
    switch (led)
    {
    case LED_RED:
        LED_OUT |= (1<<LED_RED_PIO);
        break;

    case LED_GREEN:
        LED_OUT |= (1<<LED_GREEN_PIO);
        break;
    }
}

void led_off(LEDType led)
{
    switch (led)
    {
    case LED_RED:
        LED_OUT &= ~(1<<LED_RED_PIO);
        break;

    case LED_GREEN:
        LED_OUT &= ~(1<<LED_GREEN_PIO);
        break;
    }
}

void led_toggle(LEDType led)
{
    switch (led)
    {
    case LED_RED:
        LED_OUT ^= (1<<LED_RED_PIO);
        break;

    case LED_GREEN:
        LED_OUT ^= (1<<LED_GREEN_PIO);
        break;
    }
}
