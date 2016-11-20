#include "userinc.h"

u32 systick_getus()
{
  int cur_val[2];
  int cur_tick[2];
  cur_val[0] = SysTick->VAL;
  cur_tick[0] = HAL_GetTick();
  cur_val[1] = SysTick->VAL;
  cur_tick[1] = HAL_GetTick();
  if(cur_val[0]<cur_val[1])
    return cur_val[0]/SystemCoreClock/100000+cur_tick[0]*1000;
  else if(cur_tick[0]<cur_tick[1])
    return cur_val[0]/SystemCoreClock/100000+cur_tick[0]*1000;
  else
    return cur_val[0]/SystemCoreClock/100000+(cur_tick[0]-1)*1000;
}

/***Î¢ÃëÑÓÊ±º¯Êý***/
void systick_delayus(int delay_us)
{
  int cur_us;
  cur_us = systick_getus();
  while(systick_getus()-cur_us < delay_us);
}


