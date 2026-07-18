#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void buttons_init(void);
bool button_a_pressed(void);
bool button_b_pressed(void);

#ifdef __cplusplus
}
#endif

#endif
