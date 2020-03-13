/*
 * sensor.c
 *
 *  Created on: May 5, 2017
 *      Author: IBNU
 */

#include "sensor.h"

uint8_t PbStartPressed(void){
	uint8_t FlagDetect=0;
	unsigned int Timeout_loop=0;
	unsigned int Timeout_value=8000000;
	if(HAL_GPIO_ReadPin(Pb_Start_Port, Pb_Start_Pin) == GPIO_PIN_RESET){
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(Pb_Start_Port, Pb_Start_Pin) == GPIO_PIN_RESET){
			while(HAL_GPIO_ReadPin(Pb_Start_Port, Pb_Start_Pin) == GPIO_PIN_RESET && Timeout_loop++<=Timeout_value);
			if (Timeout_loop>=Timeout_value){
				/* Timeout User Code */
				USART2_PutStr("\r\nPush button start mengalami error\r\n");
			}
			else {
				/* Normal User Code */
				FlagDetect=1;
			}
		}
	}
	return FlagDetect;
}
uint8_t PbResetPressed(void){
	uint8_t FlagDetect=0;
	unsigned int Timeout_loop=0;
	unsigned int Timeout_value=8000000;
	if(HAL_GPIO_ReadPin(Pb_Reset_Port, Pb_Reset_Pin) == GPIO_PIN_SET){
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(Pb_Reset_Port, Pb_Reset_Pin) == GPIO_PIN_SET){
			while(HAL_GPIO_ReadPin(Pb_Reset_Port, Pb_Reset_Pin) == GPIO_PIN_SET && Timeout_loop++<=Timeout_value);
			if (Timeout_loop>=Timeout_value){
				/* Timeout User Code */
				USART2_PutStr("\r\nPush button reset mengalami error\r\n");
			}
			else {
				/* Normal User Code */
				FlagDetect=1;
			}
		}
	}
	return FlagDetect;
}

uint8_t Sensor1Detected(void){
	uint8_t FlagDetect=0;
	unsigned int Timeout_loop=0;
	unsigned int Timeout_value=8000000;
	if(HAL_GPIO_ReadPin(Pb_Sensor1_Port, Pb_Sensor1_Pin) == GPIO_PIN_RESET){
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(Pb_Sensor1_Port, Pb_Sensor1_Pin) == GPIO_PIN_RESET){
			while(HAL_GPIO_ReadPin(Pb_Sensor1_Port, Pb_Sensor1_Pin) == GPIO_PIN_RESET && Timeout_loop++<=Timeout_value);
			if (Timeout_loop>=Timeout_value){
				/* Timeout User Code */
				USART2_PutStr("\r\nSensor 1 mengalami error\r\n");
			}
			else {
				/* Normal User Code */
				FlagDetect=1;
			}
		}
	}
	return FlagDetect;
}

uint8_t Sensor2Detected(void){
	uint8_t FlagDetect=0;
	unsigned int Timeout_loop=0;
	unsigned int Timeout_value=8000000;
	if(HAL_GPIO_ReadPin(Pb_Sensor2_Port, Pb_Sensor2_Pin) == GPIO_PIN_RESET){
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(Pb_Sensor2_Port, Pb_Sensor2_Pin) == GPIO_PIN_RESET){
			while(HAL_GPIO_ReadPin(Pb_Sensor2_Port, Pb_Sensor2_Pin) == GPIO_PIN_RESET && Timeout_loop++<=Timeout_value);
			if (Timeout_loop>=Timeout_value){
				/* Timeout User Code */
				USART2_PutStr("\r\nSensor 2 mengalami error\r\n");
			}
			else {
				/* Normal User Code */
				FlagDetect=1;
			}
		}
	}
	return FlagDetect;
}

uint8_t Sensor3Detected(void){
	uint8_t FlagDetect=0;
	unsigned int Timeout_loop=0;
	unsigned int Timeout_value=8000000;
	if(HAL_GPIO_ReadPin(Pb_Sensor3_Port, Pb_Sensor3_Pin) == GPIO_PIN_RESET){
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(Pb_Sensor3_Port, Pb_Sensor3_Pin) == GPIO_PIN_RESET){
			while(HAL_GPIO_ReadPin(Pb_Sensor3_Port, Pb_Sensor3_Pin) == GPIO_PIN_RESET && Timeout_loop++<=Timeout_value);
			if (Timeout_loop>=Timeout_value){
				/* Timeout User Code */
				USART2_PutStr("\r\nSensor 3 mengalami error\r\n");
			}
			else {
				/* Normal User Code */
				FlagDetect=1;
			}
		}
	}
	return FlagDetect;
}

