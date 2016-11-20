#ifndef _FLOW_H
#define _FLOW_H

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "key.h"
#define _FULL_LIGHT 100;

void LightDown(void);
void Pwm2Play(void);
void LightPlay(void);
#endif
