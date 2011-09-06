

#include <interrupt.h>
#include "launchpad-msp430.h"
#include <io.h>

static irq_handler_f irq_handlers[IRQ_NUM_SOURCES];

static void stub_irq_handler(void)
{
}

void __attribute__((__interrupt__(TIMERA0_VECTOR))) timera0_isr(void)
{
    irq_handlers[IRQ_TIMER_A0]();
}

void __attribute__((__interrupt__(TIMERA1_VECTOR))) timera1_isr(void)
{
    irq_handlers[IRQ_TIMER_A1]();
}

void __attribute__((__interrupt__(PORT1_VECTOR))) port1_isr(void)
{
    unsigned int status = P1IFG;
    
    unsigned int i = 0;
    while (status) {
        if (status & 1) {
            irq_handlers[IRQ_GPIO_PORT1_0 + i]();
            P1IFG &= ~(1<<i); // clear
        }
        status >>= 1;
        i++;
    }
}

void interrupts_enable(void)
{
    __bis_SR_register(GIE);
}

void interrupts_disable(void)
{
    __bic_SR_register(GIE);
}

void interrupts_configure(void)
{
    int i;
    for (i = 0; i < IRQ_NUM_SOURCES; ++i) {
        irq_handlers[i] = stub_irq_handler;
    }
}

void interrupt_set_handler(IRQSource irq, irq_handler_f handler)
{
    irq_handlers[irq] = handler;
}

typedef enum
{
    IRQ_ENABLE,
    IRQ_CONFIG,
    IRQ_DISABLE
} IRQConfig;

static void config_irq(IRQSource irq, IRQConfig conf, int edge)
{
    switch (irq)
    {
    case IRQ_GPIO_PORT1_0:
    case IRQ_GPIO_PORT1_1:
    case IRQ_GPIO_PORT1_2:
    case IRQ_GPIO_PORT1_3:
    case IRQ_GPIO_PORT1_4:
    case IRQ_GPIO_PORT1_5:
    case IRQ_GPIO_PORT1_6:
    case IRQ_GPIO_PORT1_7:
        if (conf == IRQ_DISABLE) {
            P1IE &= ~(1 << (irq - IRQ_GPIO_PORT1_0));
        } else if (conf == IRQ_ENABLE) {
            P1IE |= (1 << (irq - IRQ_GPIO_PORT1_0));
        } else if ((conf == IRQ_CONFIG) && edge) {
            P1IES |= (1 << (irq - IRQ_GPIO_PORT1_0));
        }
        break;

    case IRQ_GPIO_PORT2_0:
    case IRQ_GPIO_PORT2_1:
    case IRQ_GPIO_PORT2_2:
    case IRQ_GPIO_PORT2_3:
    case IRQ_GPIO_PORT2_4:
    case IRQ_GPIO_PORT2_5:
    case IRQ_GPIO_PORT2_6:
    case IRQ_GPIO_PORT2_7:
        if (conf == IRQ_DISABLE) {
            P2IE &= ~(1 << (irq - IRQ_GPIO_PORT2_0));
        } else if (conf == IRQ_ENABLE) {
            P2IE |= (1 << (irq - IRQ_GPIO_PORT2_0));
        } else if ((conf == IRQ_CONFIG) && edge) {
            P2IES |= (1 << (irq - IRQ_GPIO_PORT2_0));
        }
        break;

    case IRQ_TIMER_A0:
    case IRQ_TIMER_A1:
    case IRQ_NUM_SOURCES:
        break;

    }
}

void irq_configure(IRQSource irq, int edge)
{
    config_irq(irq, IRQ_CONFIG, edge);
}

void irq_enable(IRQSource irq)
{
    config_irq(irq, IRQ_ENABLE, 0 /*unused*/);
}

void irq_disable(IRQSource irq)
{
    config_irq(irq, IRQ_DISABLE, 0 /*unused*/);
}

