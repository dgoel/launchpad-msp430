

#ifndef __GPIO_H__
#define __GPIO_H__

typedef enum
{
    GPIO_INPUT =   0x01,
    GPIO_OUTPUT =  0x02,
    GPIO_PULL_UP = 0x04,
    GPIO_PULL_DOWN = 0x08
} GPIOConfig;

void gpio_init(unsigned int port, unsigned int num, GPIOConfig config);

void gpio_set_high(unsigned int port, unsigned int num);

void gpio_set_low(unsigned int port, unsigned int num);

unsigned char gpio_is_low(unsigned int port, unsigned int num);

unsigned char gpio_is_high(unsigned int port, unsigned int num);

#endif // __GPIO_H__
