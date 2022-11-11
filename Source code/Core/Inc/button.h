/*
 * button.h
 *
 *  Created on: Oct 29, 2022
 *      Author: Administrator
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define N0_OF_BUTTONS 4
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

#define LOCK_IDX		0
#define UNLOCK_IDX		1
#define REGISTER_IDX	2
#define RESET_IDX		3

void button_reading ( void );
void reset_button_buffer();

extern int flagForButtonPress[N0_OF_BUTTONS];
extern int flagForButtonPress1s[N0_OF_BUTTONS];

#endif /* INC_BUTTON_H_ */
