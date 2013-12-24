//Pavleen Thukral
#ifndef _MAIN_H_
#define _MAIN_H_

#define KEY_A 1
#define KEY_B 2
#define KEY_SELECT 4
#define KEY_START 8
#define KEY_RIGHT 16
#define KEY_LEFT 32
#define KEY_UP 64
#define KEY_DOWN 128
#define KEY_R 256
#define KEY_L 512
int* KEYS = (int*)0x04000130;
#define PRESSED(key) (!((*KEYS) & key)) 

void checkDeath();

void drawSnake();

void drawScore();
void drawHealth();

void moveSnake();
void checkCatch();
void drawTarget();
void checkButton();


#endif