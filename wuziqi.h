#ifndef WUZIQI_H
#define WUZIQI_H

#define row 19
#define line 19
int map[row][line];  
int flag; //flag表示当前回合数，偶数表示黑棋回合，奇数表示白棋回合

void menuview();
void init();
void gameview_Showmap();
bool playmore(int,int);
int iswin(int,int);
void winmenu();
void gameview();

#endif