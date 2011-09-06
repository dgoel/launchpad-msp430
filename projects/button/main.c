
#include <init.h>
#include <led.h>
#include <button.h>
#include <interrupt.h>

static void button_update(void)
{
    led_toggle(LED_RED);
}

int main(void)
{
    system_init();
    led_init();
    button_init();
    interrupts_configure();
    interrupts_enable();

    button_set_handler(button_update, BUTTON_PRESSED);

    led_on(LED_RED);
    led_on(LED_GREEN);

    while (1) {;}
    return 0;
}
