#ifndef _TF_MP3_H
#define _TF_MP3_H

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "key.h"

typedef struct SONG_STRUCT
{
	int lenth;
	char song[128];
}SONG_STRUCT;

void PlayMusic(SONG_STRUCT);
void TfMp3Out(char *);
void PlaySound(int);
void SongInit(void);

#endif
