#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void display_init(void);
void display_all_on(void);
void display_all_off(void);

#ifdef __cplusplus
}
#endif

#endif
