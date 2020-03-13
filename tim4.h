/*
 *	tim4.h
 *
 *	Created on: May 5, 2017
 *      Author: IBNU
 *
 *	Definisi Fungsi:
 * 		TIM4_IRQHandler()	--> TIM4 overflow interrupt
 * 		TIM4_Init()			--> Inisialisasi Timer4
 */

#ifndef TIM4_H_
#define TIM4_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

extern TIM_HandleTypeDef TIM_Handle;

extern unsigned int count, second, minute, hour;

void TIM4_IRQHandler(void);
void TIM4_Init(void);

#endif /* TIM4_H_ */
