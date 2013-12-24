//Pavleen Thukral

#include "mylib.h"

//#include <debugging.h>

u16* videoBuffer = (u16*)0x6000000;


// A function to set pixel (r, c) to the color passed in. 
void setPixel(int r, int c, u16 color) { 
	videoBuffer[OFFSET(r,c)] = color;
}

// A function to draw a FILLED rectangle starting at (r, c) 
void drawRect(int r, int c, int width, int height, u16 color){ 
	int x = c; 
	int y = r;
	while(x<=c+width){
		while(y<=r+height){
			setPixel(y,x,color);
			y++;
		}
		y = r;
		x++;
	}

} 

/* drawimage3 
 * A function that will draw an arbitrary sized image 
 * onto the screen (with DMA). 
 * @param r row to draw the image 
 * @param c column to draw the image 
 * @param width width of the image 
 * @param height height of the image 
 * @param image Pointer to the first element of the image. 
 */ 
// void drawImage3(int r, int c, int width, int height, const u16* image) 
// { 
// 	int i;
// 	for(i=0;i<height;i++){
// 		int j;
// 		for(j=0;j<width;j++){
// 			setPixel(r+i,c+j,image[(i*width)+j]);
// 		}
// 	}
// }



void drawImage3(int r, int c, int width, int height, const u16* image){
	int row;
	for(row = 0; row < height; row++){
		DMA[3].src = image+row*width;
		DMA[3].dst = videoBuffer+OFFSET(row+r, c);
		DMA[3].cnt = DMA_ON | width;
	}
}





































