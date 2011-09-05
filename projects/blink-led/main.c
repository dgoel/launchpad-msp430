
#include <init.h>
#include <led.h>
#include <button.h>

int main(void)
{
    system_init();
    led_init();
    button_init();

    led_on(LED_RED);
    led_off(LED_GREEN);

    while (1) {
        int i = 0;
        while (i++ < 16000) {;}

        led_toggle(LED_RED);
        led_toggle(LED_GREEN);
    }
    return 0;
}
