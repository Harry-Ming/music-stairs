#include "key.h"
extern int led_pwm[25],led_play[25],light[25];
extern int string_show;
/*
获得当前键值
*/
int GetKey()
{
	int key_code;
	key_code = _CODE_NONE;
	
	if(!HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_0))
		key_code = key_code|_CODE_KYE1;
	if(!HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_2))
		key_code = key_code|_CODE_KYE2;
	if(!HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_4))
		key_code = key_code|_CODE_KYE3;
	if(!HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_6))
		key_code = key_code|_CODE_KYE4;
	if(!HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_14))
		key_code = key_code|_CODE_KYE5;
	
	if(!HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_0))
		key_code = key_code|_CODE_KYE6;
	if(!HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_2))
		key_code = key_code|_CODE_KYE7;
	if(!HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0))
		key_code = key_code|_CODE_KYE8;
	if(!HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_9))
		key_code = key_code|_CODE_KYE9;
	if(!HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_8))
		key_code = key_code|_CODE_KYE10;

	return key_code;
}
/*
未离开按键时，保持常亮
*/
void Key2Pwm(int key_code)
{
	int key[10];
	key[0] = key_code & _CODE_KYE1;
	key[1] = key_code & _CODE_KYE2;
	key[2] = key_code & _CODE_KYE3;
	key[3] = key_code & _CODE_KYE4;
	key[4] = key_code & _CODE_KYE5;
	key[5] = key_code & _CODE_KYE6;
	key[6] = key_code & _CODE_KYE7;
	key[7] = key_code & _CODE_KYE8;
	key[8] = key_code & _CODE_KYE9;
	key[9] = key_code & _CODE_KYE10;
	
	if(key[0])
	{
		if(key[5])
			led_pwm[0] = _FULL_LIGHT;
		if(key[6])
			led_pwm[1] = _FULL_LIGHT;
		if(key[7])
			led_pwm[2] = _FULL_LIGHT;
		if(key[8])
			led_pwm[3] = _FULL_LIGHT;
		if(key[9])
			led_pwm[4] = _FULL_LIGHT;	
	}
	
	if(key[1])
	{
		if(key[5])
			led_pwm[5] = _FULL_LIGHT;
		if(key[6])
			led_pwm[6] = _FULL_LIGHT;
		if(key[7])
			led_pwm[7] = _FULL_LIGHT;
		if(key[8])
			led_pwm[8] = _FULL_LIGHT;
		if(key[9])
			led_pwm[9] = _FULL_LIGHT;	
	}
	
	if(key[2])
	{
		if(key[5])
			led_pwm[10] = _FULL_LIGHT;
		if(key[6])
			led_pwm[11] = _FULL_LIGHT;
		if(key[7])
			led_pwm[12] = _FULL_LIGHT;
		if(key[8])
			led_pwm[13] = _FULL_LIGHT;
		if(key[9])
			led_pwm[14] = _FULL_LIGHT;	
	}
	
	if(key[3])
	{
		if(key[5])
			led_pwm[15] = _FULL_LIGHT;
		if(key[6])
			led_pwm[16] = _FULL_LIGHT;
		if(key[7])
			led_pwm[17] = _FULL_LIGHT;
		if(key[8])
			led_pwm[18] = _FULL_LIGHT;
		if(key[9])
			led_pwm[19] = _FULL_LIGHT;	
	}
	
	if(key[4])
	{
		if(key[5])
			led_pwm[20] = _FULL_LIGHT;
		if(key[6])
			led_pwm[21] = _FULL_LIGHT;
		if(key[7])
			led_pwm[22] = _FULL_LIGHT;
		if(key[8])
			led_pwm[23] = _FULL_LIGHT;
		if(key[9])
			led_pwm[24] = _FULL_LIGHT;	
	}

}

