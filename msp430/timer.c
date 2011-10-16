
#include <timer.h>
#include <interrupt.h>
#include "launchpad-msp430.h"
#include <io.h>

static
void timerA_init(TimerClkSrc src,
                 TimerClkDivider div,
                 TimerMode mode)
{
    // src
    unsigned int SRC_REGS[] = {TASSEL_0, TASSEL_1, TASSEL_2, TASSEL_3};
    TACTL |= SRC_REGS[src];

    // clock divider
    unsigned int DIV_REGS[] = {ID_0, ID_1, ID_2, ID_3};
    TACTL |= DIV_REGS[div];

    // mode
    unsigned int MODE_REGS[] = {MC_0, MC_1, MC_2, MC_3};
    TACTL |= MODE_REGS[mode];
}


void timer_init(TimerNum which,
                TimerClkSrc src,
                TimerClkDivider div,
                TimerMode mode)
{
    switch (which) {
    case TIMER_A:
        timerA_init(src, div, mode);
        break;

    case TIMER_B:
        // TODO: fill this in
        break;
    }
}

void timer_match_enable(TimerNum which,
                        unsigned int val,
                        timer_match_callback_f func)
{
    switch (which) {
    case TIMER_A:
        TACCR0 = val;
        interrupt_set_handler(IRQ_TIMER_A0, func);
        timer_enable(which);
        break;

    case TIMER_B:
        break;
    }
}

void timer_enable(TimerNum which)
{
    switch (which) {
    case TIMER_A:
        TACCTL0 = CCIE;
        break;

    case TIMER_B:
        break;
    }
}

void timer_disable(TimerNum which)
{
    switch (which) {
    case TIMER_A:
        TACCTL0 &= ~CCIE;
        break;

    case TIMER_B:
        break;
    }
}







