#include "key.h"

/*
获得当前键值
*/
int GetKey()
{
	int key_code;
	key_code = _CODE_NONE;
	
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0))
		key_code = key_code|_CODE_KYE1;
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1))
		key_code = key_code|_CODE_KYE2;
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_2))
		key_code = key_code|_CODE_KYE3;
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_3))
		key_code = key_code|_CODE_KYE4;
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4))
		key_code = key_code|_CODE_KYE5;
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5))
		key_code = key_code|_CODE_KYE6;
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6))
		key_code = key_code|_CODE_KYE7;
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7))
		key_code = key_code|_CODE_KYE8;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0))
		key_code = key_code|_CODE_KYE9;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1))
		key_code = key_code|_CODE_KYE10;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2))
		key_code = key_code|_CODE_KYE11;

	return key_code;
}

int KeyPush()
{
	key_push = (key_last | key_now) - key_last;

	if(_CODE_KYE11 & key_push)
		return 11;
	else if(_CODE_KYE10 & key_push)
		return 10;
	else if(_CODE_KYE9 & key_push)
		return 9;
	else if(_CODE_KYE8 & key_push)
		return 8;
	else if(_CODE_KYE7 & key_push)
		return 7;
	else if(_CODE_KYE6 & key_push)
		return 6;
	else if(_CODE_KYE5 & key_push)
		return 5;
	else if(_CODE_KYE4 & key_push)
		return 4;
	else if(_CODE_KYE3 & key_push)
		return 3;
	else if(_CODE_KYE2 & key_push)
		return 2;
	else if(_CODE_KYE1 & key_push)
		return 1;
	else 
		return 0;
}

void Key2Light()
{
	int light;
	light = KeyPush();
	switch (light)
	{
		case 1:HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_12); break;
		case 2:HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_11); break;
		case 3:HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_10); break;
		case 4:HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_9); break;
		case 5:HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_8); break;
		case 6:HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_15); break;
		case 7:HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_14); break;
		case 8:HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_13); break;
		case 9:HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_12); break;
		default: break;
	}
}
