/*
 * tim4.c
 *
 *  Created on: May 5, 2017
 *      Author: IBNU
 */

#include "tim4.h"

TIM_HandleTypeDef TIM_Handle;

unsigned int count = 0, second = 0, minute = 0, hour = 0;

void TIM4_IRQHandler(void)
{
	if (__HAL_TIM_GET_FLAG(&TIM_Handle, TIM_FLAG_UPDATE) != RESET)      //In case other interrupts are also running
	{
		if (__HAL_TIM_GET_ITSTATUS(&TIM_Handle, TIM_IT_UPDATE) != RESET)
		{
			__HAL_TIM_CLEAR_FLAG(&TIM_Handle, TIM_FLAG_UPDATE);
			/*put your code here */
			if(count++ >= 99){
				count = 0;
				if (second++ >= 59){
					second = 0;
					if (minute++ >= 59){
						minute = 0;
						if(hour++ >= 23){
							hour = 0;
						}
					}
				}
			}
		}
	}
}

void TIM4_Init(void){
	__TIM4_CLK_ENABLE();

	TIM_Handle.Init.Prescaler = 42000-1;
	TIM_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	TIM_Handle.Init.Period = 10-1; // Deklarasi waktu timer sebesar 10ms
	TIM_Handle.Instance = TIM4;   //Same timer whose clocks we enabled
	HAL_TIM_Base_Init(&TIM_Handle);     // Init timer
	//HAL_TIM_Base_Start_IT(&TIM_Handle); // start timer interrupts
	HAL_NVIC_SetPriority(TIM4_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(TIM4_IRQn);
}
