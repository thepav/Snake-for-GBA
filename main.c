//Pavleen Thukral

#include "mylib.h"
#include "shell.h"
#include "heart.h"
#include "numbers.h"
#include "stdlib.h"
#include "gameover.h"
#include "main.h"
#include "startscreen.h"
#include "ball.h"
//#include "time.h"
#include "winscreen.h"

//240x160
int health = 3;
int score = 0;
const u16* nums[11] = {zero,one,two,three,four,five,six,seven,eight,nine,ten};
int pos[12][2] = {{0,0},{NULL,NULL},{NULL,NULL},{NULL,NULL},{NULL,NULL},{NULL,NULL},{NULL,NULL},{NULL,NULL},{NULL,NULL},{NULL,NULL},{NULL,NULL},{NULL,NULL}};
int numShells = 1;
int direction = 0; //0=right,1=down,2=left,3=up
int target[2] = {5,5};
int caught = 0;
int main(){
	REG_DISPCTL = MODE3 | BG2_ENABLE;
	
	while(!PRESSED(KEY_SELECT)){
		drawImage3(0,0,240,160,startscreen);
	}
	drawRect(0,0,240,160,COLOR(0,0,0));
	int a = (rand()%10);
	int b = (rand()%15);
	target[0] = a;
	target[1] = b;
	int gameNotOver = 1;
	while(1){

		if(gameNotOver){
			drawHealth();
			drawScore();
			drawSnake();

			//slow down the game
			for(float i =0;i<3000;i++){}
			checkButton();
			//Clear last snake in chain from screen
			drawRect((pos[numShells-1][0]*15),(pos[numShells-1][1]*16),16,15,COLOR(0,0,0));
			checkCatch();			
			drawTarget();

			moveSnake();
			checkDeath();
			if(health==0){
				gameNotOver=0;
			}
			if(score>10){
				gameNotOver=0;
			}
		}
		else if(health==0){
			drawImage3(0,0,240,160,gameover);
		}
		else{
			drawImage3(0,0,240,160,winscreen);			
		}

		if(PRESSED(KEY_SELECT)){
			health = 3;
			score = 0;
			pos[0][0] = 0;
			pos[0][1] = 0;
			numShells = 1;
			direction = 0; //0=right,1=down,2=left,3=up
			target[0] = rand()%10;
			target[1] = rand()%15;
			caught = 0;
			gameNotOver=1;
			drawRect(0,0,240,160,COLOR(0,0,0));

		}		

	}	

}
void checkButton(){
	if(PRESSED(KEY_RIGHT)){
		direction=0;
	}
	if(PRESSED(KEY_DOWN)){
		direction=1;
	}
	if(PRESSED(KEY_LEFT)){
		direction=2;
	}
	if(PRESSED(KEY_UP)){
		direction=3;
	}
}

void drawTarget(){
	drawImage3((target[0]*15),(target[1]*16),16,15,ball);
}

void checkCatch(){
	if(pos[0][0]==target[0]&&pos[0][1]==target[1]){
		score++;
		pos[numShells][0] = pos[numShells-1][0];
		pos[numShells][1] = pos[numShells-1][1];
		caught =1;
		drawRect((target[0]*15),(target[1]*16),16,15,COLOR(0,0,0));
		target[0] = rand() %10;
		target[1] = rand() %15;

	}	
}

void checkDeath(){
	for (int i =1;i<numShells;i++){
		if(pos[i][0]==pos[0][0] && pos[i][1]==pos[0][1]){
			health--;
			drawRect(0,(240-30),30,12,COLOR(0,0,0));
		}
	}
}

void drawSnake(){
	for(int i = 0;i<numShells;i++){
		drawImage3((pos[i][0]*15),(pos[i][1]*16),16,15,shell);
	}
}

void drawScore(){
	drawImage3(0,(240-40),10,12,nums[score]);
}
void drawHealth(){
	if(health >= 3){
		drawImage3(0,(240-10),10,12,heart);
	}
	if(health >= 2){
		drawImage3(0,(240-20),10,12,heart);
	}
	if(health >= 1){
		drawImage3(0,(240-30),10,12,heart);
	}	
}

void moveSnake(){
	for(int i =numShells-1;i>0;i--){
		pos[i][0] = pos[i-1][0];
		pos[i][1] = pos[i-1][1];
	}
	if(direction==0){
		pos[0][1]+=1;
	}
	if(direction==1){
		pos[0][0]+=1;
	}
	if(direction==2){
		pos[0][1]-=1;
	}
	if(direction==3){
		pos[0][0]-=1;
	}
	if(pos[0][1]>14){
		pos[0][1]=0;
	}
	if(pos[0][1]<0){
		pos[0][1]=14;
	}
	if(pos[0][0]>9){
		pos[0][0]=0;
	}
	if(pos[0][0]<0){
		pos[0][0]=9;
	}
	if(caught){
		numShells++;
		caught=0;
	}
}
