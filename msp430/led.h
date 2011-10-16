

#ifndef __LED_H__
#define __LED_H__

typedef enum
{
    LED_RED,
    LED_GREEN
} LEDType;

void led_init(void);

void led_on(LEDType led);

void led_off(LEDType led);

void led_toggle(LEDType led);

#endif // __LED_H__
