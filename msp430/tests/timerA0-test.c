
#include <init.h>
#include <led.h>
#include <button.h>
#include <timer.h>
#include <io.h>

void test_toggle(void)
{
    led_toggle(LED_RED);
    led_toggle(LED_GREEN);
}

int main(void)
{
    system_init();
    led_init();
    button_init();
    interrupts_configure();
    interrupts_enable();

    led_on(LED_RED);
    led_off(LED_GREEN);

    // config timer A to toggle leds
    timer_init(TIMER_A, TIMER_SRC_SMCLK, TIMER_DIV_8, TIMER_COUNT_UP);
    timer_match_enable(TIMER_A, 32000, test_toggle);

    while (1) {;}
    return 0;
}
