#include "flow.h"

int led_pwm[25];
int led_play[25];
int light[25];
extern int string_show;

void LightDown()
{
	for(int i=0;i<25;i++)
	{
		if(led_pwm[i] > 0)
			led_pwm[i]--;
		
		if(led_pwm[i] == 50)
			{
				if(string_show < 17)
					string_show ++;
				else
					string_show = 0;
			}
		
		
		led_play[i] = led_pwm[i];
	}
}

void Pwm2Play()
{
	for(int i=0;i<25;i++)
	{
		if(led_play[i])
		{
			light[i] = 0;
			led_play[i]--;
		}
		else
			light[i] = 1;
	}
}

void LightPlay()
{
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_15,light[0]);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_12,light[1]);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,light[2]);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,light[3]);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,light[4]);
	
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,light[5]);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,light[6]);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,light[7]);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,light[8]);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,light[9]);
	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,light[10]);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,light[11]);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_9,light[12]);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_8,light[13]);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_11,light[14]);
	
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_10,light[15]);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,light[16]);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,light[17]);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,light[18]);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,light[19]);

	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,light[20]);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,light[21]);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,light[22]);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,light[23]);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,light[24]);
	
}
