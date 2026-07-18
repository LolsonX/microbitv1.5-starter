#include "board.h"
#include "display.h"
#include "buttons.h"

void board_init(void)
{
    display_init();
    buttons_init();
}
