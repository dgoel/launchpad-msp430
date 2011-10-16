
#include <button.h>
#include <gpio.h>
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

void button_set_handler(irq_handler_f handler, ButtonEvent ev)
{
    irq_disable(IRQ_GPIO_PORT1_3);
    interrupt_set_handler(IRQ_GPIO_PORT1_3, handler);
    irq_configure(IRQ_GPIO_PORT1_3, ev == BUTTON_PRESSED ? 1 : 0);
    irq_enable(IRQ_GPIO_PORT1_3);
}
