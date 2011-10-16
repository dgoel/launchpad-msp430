
#ifndef __MSP430_TIMER_H__
#define __MSP430_TIMER_H__

typedef enum {
    TIMER_A,
    TIMER_B
} TimerNum;

typedef enum {
    TIMER_STOP,
    TIMER_COUNT_UP,
    TIMER_COUNT_CONTINUOUS,
    TIMER_COUNT_UP_DOWN
} TimerAMode;

typedef enum {
    TIMER_SRC_TACLK,
    TIMER_SRC_ACLK,
    TIMER_SRC_SMCLK,
    TIMER_SRC_INCLK
} TimerClkSrc;

typedef enum {
    TIMER_DIV_1,
    TIMER_DIV_2,
    TIMER_DIV_4,
    TIMER_DIV_8
} TimerClkDivider;

typedef (*timer_match_callback_f)(void);

void timer_init(TimerType which,
                TimerClkSrc src,
                TimerClkDivider div);

void timer_match_enable(TimerType which,
                        unsigned int val,
                        timer_match_callback_f func);

void timer_enable(TimerType which);
void timer_disable(TimerType which);

#endif // __MSP430_TIMER_H__
