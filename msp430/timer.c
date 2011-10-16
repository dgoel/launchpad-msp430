
#include <timer.h>
#include <interrupt.h>
#include "launchpad-msp430.h"
#include <io.h>

void timer_init(TimerType which,
                TimerClkSrc src,
                TimerClkDivider div)
{
    switch (which) {
    case TIMER_A:
        TACTL |= (src | div);
        break;

    case TIMER_B:
        // TODO: fill this in
        break;
    }
}

void timer_match_enable(TimerType which,
                        unsigned int val,
                        timer_match_callback_f func)
{
    switch (which) {
    case TIMER_A:
        TACCR0 = val;
        interrupt_set_handler(IRQ_TIMER_A0, func);
        break;

    case TIMER_B:
        break;
    }
}

void timer_enable(TimerType which)
{
    switch (which) {
    case TIMER_A:
        TACCTL0 = CCIE;
        break;

    case TIMER_B:
        break;
    }
}

void timer_disable(TimerType which)
{
    switch (which) {
    case TIMER_A:
        TACCTL0 &= ~CCIE;
        break;

    case TIMER_B:
        break;
    }
}







