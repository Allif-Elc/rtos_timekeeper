/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    05 - 05 - 2017
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "define.h"
#include "tim4.h"
#include "HardwareInit.h"
#include "LCD_HD44780.h"
#include "sensor.h"
#include "USART2.h"

int main(void)
{
	HAL_Init();

	SystemClock_Config();

	GPIO_Init();

	TIM4_Init();

	LCD_Init();

	USART2_Init();

	LCD_GotoXY(0,0);
	LCD_Putstr("LCD Ok");
	HAL_Delay(2500);
	LCD_Clear();

	// Cek Serial
	USART2_PutStr("Serial OK\r\n");

	for(unsigned char i = 0; i<3; i++){
		for(unsigned char j = 0; j<4; j++){
			LapHour[i][j] = 0;
			LapMinute[i][j] = 0;
			LapSecond[i][j] = 0;
			LapCount[i][j] = 0;
		}
	}

	for(;;){
		char lcd_buff[20];
		sprintf(lcd_buff, "%02d:%02d:%02d.%02d", hour, minute, second, count);
		LCD_GotoXY(2,0);
		LCD_Putstr(lcd_buff);

		if (PbResetPressed()){
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
		else if (PbStartPressed()){
			if((pbStartCount++)%2 == 0){
				HAL_TIM_Base_Start_IT(&TIM_Handle);
			}
			else {
				HAL_TIM_Base_Stop_IT(&TIM_Handle);
			}
		}
		if (Sensor1Detected()){
			LapHour[0][Car0Count] = hour;
			LapMinute[0][Car0Count] = minute;
			LapSecond[0][Car0Count] = second;
			LapCount[0][Car0Count] = count;
			sprintf(lcd_buff,"C1L%d=%02d:%02d:%02d.%02d\r\n", Car0Count, LapHour[0][Car0Count], LapMinute[0][Car0Count], LapSecond[0][Car0Count], LapCount[0][Car0Count]);
			LCD_GotoXY(0,1);
			LCD_Putstr(lcd_buff);
			USART2_PutStr(lcd_buff);
			if((Car0Count++) >= 3){
				Car0Count = 0;
			}
		}
		if (Sensor2Detected()){
			LapHour[1][Car1Count] = hour;
			LapMinute[1][Car1Count] = minute;
			LapSecond[1][Car1Count] = second;
			LapCount[1][Car1Count] = count;
			sprintf(lcd_buff,"C2L%d=%02d:%02d:%02d.%02d\r\n", Car1Count, LapHour[0][Car1Count], LapMinute[0][Car1Count], LapSecond[0][Car1Count], LapCount[0][Car1Count]);
			LCD_GotoXY(0,1);
			LCD_Putstr(lcd_buff);
			USART2_PutStr(lcd_buff);
			if((Car1Count++) >= 3){
				Car1Count = 0;
			}
		}
		if (Sensor3Detected()){
			LapHour[2][Car1Count] = hour;
			LapMinute[2][Car1Count] = minute;
			LapSecond[2][Car1Count] = second;
			LapCount[2][Car1Count] = count;
			sprintf(lcd_buff,"C3L%d=%02d:%02d:%02d.%02d\r\n", Car2Count, LapHour[0][Car2Count], LapMinute[0][Car2Count], LapSecond[0][Car2Count], LapCount[0][Car2Count]);
			LCD_GotoXY(0,1);
			LCD_Putstr(lcd_buff);
			USART2_PutStr(lcd_buff);
			if((Car2Count++) >= 3){
				Car2Count = 0;
			}
		}
	}
}
