/*
 * HardwareInit.h
 *
 *  Created on: May 5, 2017
 *      Author: IBNU
 */

#ifndef HARDWAREINIT_H_
#define HARDWAREINIT_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "define.h"

void SystemClock_Config(void);
void GPIO_Init(void);

#endif /* HARDWAREINIT_H_ */
