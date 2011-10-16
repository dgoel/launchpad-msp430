#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <interrupt.h>

typedef enum
{
    BUTTON_PRESSED,
    BUTTON_RELEASED
} ButtonEvent;


void button_init(void);

void button_set_handler(irq_handler_f h, ButtonEvent ev);
unsigned char button_is_pressed(void);


#endif // __BUTTON_H__
