#include "microbit.h"

int main(void)
{
    while (true)
    {
        display_all_on();
        nrf_delay_ms(500);
        display_all_off();
        nrf_delay_ms(500);
    }
}
