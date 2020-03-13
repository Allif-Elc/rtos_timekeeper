/*
 * LCD_HD44780.c
 *
 *  Created on: Apr 15, 2017
 *      Author: IBNU
 */

#include "LCD_HD44780.h"

/* Definitions */
#define SET_EN		HAL_GPIO_WritePin(EN_PORT, EN_PIN, GPIO_PIN_SET);
#define CLR_EN		HAL_GPIO_WritePin(EN_PORT, EN_PIN, GPIO_PIN_RESET);
#define SET_RW		HAL_GPIO_WritePin(RW_PORT, RW_PIN, GPIO_PIN_SET);
#define CLR_RW		HAL_GPIO_WritePin(RW_PORT, RW_PIN, GPIO_PIN_RESET);
#define SET_RS		HAL_GPIO_WritePin(RS_PORT, RS_PIN, GPIO_PIN_SET);
#define CLR_RS		HAL_GPIO_WritePin(RS_PORT, RS_PIN, GPIO_PIN_RESET);

/* Private functions */
static void LCD_Pins_Init(void);
static void LCD_Cmd(uint8_t cmd);
static void LCD_Cmd4bit(uint8_t cmd);
static void Enable(void);

void LCD_Init(void)
{
	/* Init pins */
	LCD_Pins_Init();

	/* Clear Enable */
	CLR_EN;

	/* Delay */
	HAL_Delay(15);

	/* Step 1 */
	LCD_Cmd(0x03);
	HAL_Delay(5);

	/* Step 2 */
	LCD_Cmd(0x03);
	HAL_Delay(5);

	/* Step 3 */
	LCD_Cmd(0x03);
	HAL_Delay(5);

	/* Next Init */
	LCD_Cmd(0x02);
	LCD_Cmd(0x02);
	LCD_Cmd(0x08);
	LCD_Cmd(0x00);
	LCD_Cmd(0x0E);
	LCD_Cmd(0x00);
	LCD_Cmd(0x06);
	LCD_Cmd(0x00);
	LCD_Cmd(0x01);

	/*
	 * Display On/Off Control:
	 * - Bit 3 --> Must be 1
	 * - Bit 2 --> 0 = Display Off, 1 = Display On
	 * - Bit 1 --> 0 = Cursor displayed Off, 1 = Cursor displayed On
	 * - Bit 0 --> 0 = Cursor blink Off, 1 = Cursor blink On
	 */
	LCD_Cmd(0b00001100);
}

void LCD_PutChar(unsigned char c)
{
	SET_RS;
	CLR_RW;

	LCD_Cmd4bit(c >> 4);
	LCD_Cmd4bit(c & 0x0F);
}

void LCD_Putstr(char *s)
{
	char c, i=0;
	while((c=*(s+(i++)))!=0)
		LCD_PutChar(c);
}

void LCD_Clear(void)
{
	LCD_Cmd(0x00);
	LCD_Cmd(0x01);
}

void LCD_GotoXY(unsigned char cols, unsigned char rows)
{
	LCD_Cmd(0x80|(cols+(0x40*rows)));
}

static void Enable(void)
{
	SET_EN;
	HAL_Delay(3);
	CLR_EN;
}

static void LCD_Cmd(uint8_t cmd)
{
	CLR_RS;
	CLR_RW;

	LCD_Cmd4bit(cmd >> 4);
	LCD_Cmd4bit(cmd & 0x0F);
}

static void LCD_Cmd4bit(uint8_t cmd)
{
	HAL_GPIO_WritePin(D7_PORT, D7_PIN, (cmd & 0x08));
	HAL_GPIO_WritePin(D6_PORT, D6_PIN, (cmd & 0x04));
	HAL_GPIO_WritePin(D5_PORT, D5_PIN, (cmd & 0x02));
	HAL_GPIO_WritePin(D4_PORT, D4_PIN, (cmd & 0x01));
	Enable();
}

static void LCD_Pins_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	/* GPIO Ports Clock Enable */
	 __HAL_RCC_GPIOA_CLK_ENABLE();
	 __HAL_RCC_GPIOC_CLK_ENABLE();

	 /* Configure GPIOA LCD Pins */
	 GPIO_InitStruct.Pin = EN_PIN|D4_PIN|D5_PIN|RW_PIN;
	 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	 GPIO_InitStruct.Pull = GPIO_NOPULL;
	 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	 HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	 /* Configure GPIOC LCD Pins */
	 GPIO_InitStruct.Pin = RS_PIN|D7_PIN|D6_PIN;
	 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	 GPIO_InitStruct.Pull = GPIO_NOPULL;
	 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	 HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	 /* Set GPIOA LCD Pins LOW */
	 HAL_GPIO_WritePin(GPIOA, EN_PIN|D4_PIN|D5_PIN|RW_PIN, GPIO_PIN_RESET);

	 /* Set GPIOC LCD Pins LOW */
	 HAL_GPIO_WritePin(GPIOC, RS_PIN|D7_PIN|D6_PIN, GPIO_PIN_RESET);
}
