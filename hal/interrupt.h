

#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

void interrupts_enable(void);

void interrupts_disable(void);

void interrupts_configure(void);

typedef enum
{
    /* GPIO interrupts */
    IRQ_GPIO_PORT1_0,
    IRQ_GPIO_PORT1_1,
    IRQ_GPIO_PORT1_2,
    IRQ_GPIO_PORT1_3,
    IRQ_GPIO_PORT1_4,
    IRQ_GPIO_PORT1_5,
    IRQ_GPIO_PORT1_6,
    IRQ_GPIO_PORT1_7,
    IRQ_GPIO_PORT2_0,
    IRQ_GPIO_PORT2_1,
    IRQ_GPIO_PORT2_2,
    IRQ_GPIO_PORT2_3,
    IRQ_GPIO_PORT2_4,
    IRQ_GPIO_PORT2_5,
    IRQ_GPIO_PORT2_6,
    IRQ_GPIO_PORT2_7,

    /* Timers */
    IRQ_TIMER_A0,
    IRQ_TIMER_A1,


    /* End */
    IRQ_NUM_SOURCES
} IRQSource;

typedef void (*irq_handler_f)(void);

void irq_configure(IRQSource irq, int edge);

void irq_enable(IRQSource irq);

void irq_disable(IRQSource irq);

void interrupt_set_handler(IRQSource irq, irq_handler_f handler); 


#endif // __INTERRUPT_H__
