/*
 * fsm.c
 *
 *  Created on: Oct 29, 2022
 *      Author: Administrator
 */

#include "global.h"
#include "fsm.h"
#include "button.h"
#include "software_timer.h"
#include "main.h"
#include "rfid_reader.h"



int state=UNLOCK;
int admin_id;

void fsm_run() {
	switch (state) {
	case INIT:
		//quet the admin va luu vao bo nho
		//sau khi co the duoc quet , thay doi state
		//hien thuc sau
		admin_id=reader();
		state=UNLOCK;
		break;
	case UNLOCK:
		//dua ra tin hieu mo cua
		HAL_GPIO_WritePin(GPIOA, SIGNAL_Pin, GPIO_PIN_SET);

		//neu bam nut dong cua, qua trang thai dong cua
		if (flagForButtonPress[LOCK_IDX]==1) {
			flagForButtonPress[LOCK_IDX]=0;
			state=LOCK;
		}
		//bam nut dang ki the
		else if (flagForButtonPress[REGISTER_IDX]==1)  {
			state=REG_PROCESS;
		}
		//bam nut reset
		else if (flagForButtonPress[RESET_IDX]) {
			state=MEM_DELETE;
		}
		//quet the
		break;
	case LOCK:
		//dua ra tin hieu dong cua
		HAL_GPIO_WritePin(GPIOA, SIGNAL_Pin, GPIO_PIN_RESET);

		//neu bam nut dong cua, qua trang thai dong cua
		if (flagForButtonPress[UNLOCK_IDX]==1) {
			flagForButtonPress[UNLOCK_IDX]=0;
			state=UNLOCK;
		}
		//bam nut dang ki the
		else if (flagForButtonPress[REGISTER_IDX]==1)  {
			state=REG_PROCESS;
		}
		//bam nut reset
		else if (flagForButtonPress[RESET_IDX]) {
			state=MEM_DELETE;
		}
		//quet the
		break;

	case WRONG1:

		break;
	case WRONG2:
		break;
	case ALARM:
		HAL_GPIO_WritePin(GPIOA, BUZZER_Pin, GPIO_PIN_SET);
		break;
	case MEM_DELETE:
		break;
	case REG_PROCESS:
		break;

	}
}
