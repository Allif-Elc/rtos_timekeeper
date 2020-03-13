
/*
 * USART2.h
 *
 * Created on: May 5, 2017
 * 		Author: IBNU
 *
 * Konfigurasi PIN:
 * 		PD5 --> Tx
 * 		PD6 --> Rx
 *
 * Definisi Fungsi:
 * 		USART2_Init()				-->	Inisialisasi USART2
 * 		USART2_PutChar(char c)		--> Mengirim karakter melalui USART2
 * 		USART2_PutStr(char *data)	--> Mengirim string melalui USART2
 * 		USART2_IRQHandler()			--> USART2_RXNE Interrupt Handler
*/

#ifndef USART2_H_
#define USART2_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include <string.h>
#include "tim4.h"

GPIO_InitTypeDef GPIO_InitStruct;
extern UART_HandleTypeDef huart2;

extern volatile char received_data;
extern unsigned char pbStartCount;
extern unsigned char Car0Count, Car1Count, Car2Count;
extern unsigned int LapHour[3][4], LapMinute[3][4], LapSecond[3][4], LapCount[3][4];

void USART2_IRQHandler(void);
void USART2_Init(void);
extern void USART2_PutChar(char c);
extern void USART2_PutStr(char *data);

#endif /* USART2_H_ */
