#include "tf_mp3.h"
/*播放不同顺序文件的引脚配置数组*/
char sound0[] = {1,1,1,1,1};
char sound1[] = {1,1,1,1,0};
char sound2[] = {1,1,1,0,1};
char sound3[] = {1,1,0,1,1};
char sound4[] = {1,0,1,1,1};
char sound5[] = {0,1,1,1,1};
char sound6[] = {0,0,1,1,0};
char sound7[] = {0,0,1,1,1};
char sound8[] = {0,1,0,0,0};
char sound9[] = {0,1,0,0,1};
char sound10[] = {0,1,0,1,0};
char sound11[] = {0,1,0,1,1};

SONG_STRUCT song1;
int touch_times;
/*根据按键十进制编码发出声响*/
void PlaySound(int num)
{
	switch (num)
	{
		case 1:TfMp3Out(sound1);break;
		case 2:TfMp3Out(sound2);break;
		case 3:TfMp3Out(sound3);break;
		case 4:TfMp3Out(sound4);break;
		case 5:TfMp3Out(sound5);break;
		case 6:TfMp3Out(sound6);break;
		case 7:TfMp3Out(sound7);break;
		case 8:TfMp3Out(sound8);break;
		case 9:TfMp3Out(sound9);break;
		case 10:TfMp3Out(sound10);break;
		case 11:TfMp3Out(sound11);break;
		default :TfMp3Out(sound0);break;
	}
}
/*配置歌曲音调和长度*/
void SongInit()
{
	song1.lenth = 43;
	song1.song[0] = 0;
	
	song1.song[1] = 1;
	song1.song[2] = 1;
	song1.song[3] = 5;
	song1.song[4] = 5;
	song1.song[5] = 6;
	song1.song[6] = 6;
	song1.song[7] = 5;
	
	song1.song[8] = 4;
	song1.song[9] = 4;
	song1.song[10] = 3;
	song1.song[11] = 3;
	song1.song[12] = 2;
	song1.song[13] = 2;
	song1.song[14] = 1;
	
	song1.song[15] = 5;
	song1.song[16] = 5;
	song1.song[17] = 4;
	song1.song[18] = 4;
	song1.song[19] = 3;
	song1.song[20] = 3;
	song1.song[21] = 2;
	
	song1.song[22] = 5;
	song1.song[23] = 5;
	song1.song[24] = 4;
	song1.song[25] = 4;
	song1.song[26] = 3;
	song1.song[27] = 3;
	song1.song[28] = 2;
	
	song1.song[29] = 1;
	song1.song[30] = 1;
	song1.song[31] = 5;
	song1.song[32] = 5;
	song1.song[33] = 6;
	song1.song[34] = 6;
	song1.song[35] = 5;
	
	song1.song[36] = 4;
	song1.song[37] = 4;
	song1.song[38] = 3;
	song1.song[39] = 3;
	song1.song[40] = 2;
	song1.song[41] = 2;
	song1.song[42] = 1;
}
/*根据按键数量的累加播放预存歌曲*/
void PlayMusic(SONG_STRUCT song)
{
	if(KeyPush() > 0)
	{
		/*播放完成后重复播放*/
		if(touch_times < song.lenth)
			touch_times ++;
		else
			touch_times = 0;
		/*连音时插入停止，保证两个音分离*/
		if(song.song[touch_times] == song.song[touch_times-1])
			PlaySound(song.song[0]);
		
		PlaySound(song.song[touch_times]);
	}
	else
		PlaySound(song.song[0]);
}
/*控制引脚，播放mp3文件*/
void TfMp3Out(char *val)
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,val[4]);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,val[3]);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,val[2]);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,val[1]);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,val[0]);
}

