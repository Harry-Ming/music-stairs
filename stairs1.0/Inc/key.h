#ifndef _KEY_H
#define _KEY_H
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"

extern int key_now,key_last,key_push;

#define _CODE_NONE 0x00000000
#define _CODE_KYE1 0x00000001
#define _CODE_KYE2 0x00000002
#define _CODE_KYE3 0x00000004
#define _CODE_KYE4 0x00000008
#define _CODE_KYE5 0x00000010
#define _CODE_KYE6 0x00000020
#define _CODE_KYE7 0x00000040
#define _CODE_KYE8 0x00000080
#define _CODE_KYE9 0x00000100
#define _CODE_KYE10 0x00000200
#define _CODE_KYE11 0x00000400
#define _CODE_KYE12 0x00000800
#define _CODE_KYE13 0x00001000
#define _CODE_KYE14 0x00002000
#define _CODE_KYE15 0x00004000
#define _CODE_KYE16 0x00008000


void Key2Light(void);
int GetKey(void);
int KeyPush(void);

#endif
