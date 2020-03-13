/*
 * LCD_HD44780.h
 *
 *  Created on: Apr 15, 2017
 *      Author: IBNU
 */

#ifndef LCD_HD44780_H_
#define LCD_HD44780_H_

#include "stm32f4xx.h"
//#include "stm32f4_discovery.h"

/* Defininitions */
#define RS_PORT		GPIOC
#define RS_PIN		GPIO_PIN_5
#define RW_PORT		GPIOA
#define RW_PIN		GPIO_PIN_7
#define EN_PORT		GPIOA
#define EN_PIN		GPIO_PIN_5
#define D4_PORT		GPIOA
#define D4_PIN		GPIO_PIN_3
#define D5_PORT		GPIOA
#define D5_PIN		GPIO_PIN_1
#define D6_PORT		GPIOC
#define D6_PIN		GPIO_PIN_3
#define D7_PORT		GPIOC
#define D7_PIN		GPIO_PIN_1

/* Global Function Here */
void LCD_Init(void);
void LCD_PutChar(unsigned char c);
void LCD_Putstr(char *s);
void LCD_Clear(void);
void LCD_GotoXY(unsigned char col, unsigned char row);

#endif /* LCD_HD44780_H_ */
