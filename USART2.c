/*
 * USART2.c
 *
 *  Created on: May 5, 2017
 *      Author: IBNU
 */

#include "USART2.h"

GPIO_InitTypeDef GPIO_InitStruct;
UART_HandleTypeDef huart2;

volatile char received_data=0;

unsigned char pbStartCount = 0;
unsigned char Car0Count = 0, Car1Count = 0, Car2Count = 0;
unsigned int LapHour[3][4], LapMinute[3][4], LapSecond[3][4], LapCount[3][4];

void USART2_IRQHandler(void)
{
	if(__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE)){
		received_data = USART2->DR;
		if (received_data == '1'){
			if((pbStartCount++)%2 == 0){
				HAL_TIM_Base_Start_IT(&TIM_Handle);
			}
			else {
				HAL_TIM_Base_Stop_IT(&TIM_Handle);
			}
		}
		else if (received_data == '2'){
			count = 0;
			second = 0;
			minute = 0;
			hour = 0;
			Car0Count = 0;
			Car1Count = 0;
			Car2Count = 0;
			for(unsigned char i = 0; i<3; i++){
				for(unsigned char j = 0; j<4; j++){
					LapHour[i][j] = 0;
					LapMinute[i][j] = 0;
					LapSecond[i][j] = 0;
					LapCount[i][j] = 0;
				}
			}
		}
		else if(received_data == '3'){
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
		}
		else if (received_data == '4'){
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
		}
		else if (received_data == '5'){
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
		}
		else if (received_data == '6'){
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
		}
	}
}

void USART2_Init(void){

	__HAL_RCC_USART2_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	huart2.Instance = USART2;
	huart2.Init.BaudRate = 9600;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&huart2);

	HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART2_IRQn);

	__HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);
}

void USART2_PutChar(char c){
	uint8_t ch;
	ch = c;

	HAL_UART_Transmit(&huart2, (uint8_t *)&ch,1,10);
	while(__HAL_UART_GET_FLAG(&huart2, UART_FLAG_TC) == RESET);
}

void USART2_PutStr(char *data){
	int i = 0;
	int n = strlen(data);
	for(i=0; i<n; i++){
		USART2_PutChar(data[i]);
	}
}
