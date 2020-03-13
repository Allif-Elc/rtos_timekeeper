/*
 * sensor.h
 *
 *  Created on: May 5, 2017
 *      Author: IBNU
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "define.h"

uint8_t PbStartPressed(void);
uint8_t PbResetPressed(void);
uint8_t Sensor1Detected(void);
uint8_t Sensor2Detected(void);
uint8_t Sensor3Detected(void);

#endif /* SENSOR_H_ */
