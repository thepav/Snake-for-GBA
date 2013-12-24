//Pavleen Thukral

#ifndef _MYLIB_H_
#define _MYLIB_H_

typedef unsigned int u32;

typedef struct 
{
	const volatile void *src;
	volatile void *dst;
	volatile u32 cnt;
} DMAREC;

#define DMA ((volatile DMAREC *)0x040000B0)

#define REG_DMA0SAD         *(u32*)0x40000B0  
#define REG_DMA0DAD         *(u32*)0x40000B4  
#define REG_DMA0CNT         *(u32*)0x40000B8  

/* DMA channel 1 register definitions */
#define REG_DMA1SAD         *(u32*)0x40000BC 
#define REG_DMA1DAD         *(u32*)0x40000C0  
#define REG_DMA1CNT         *(u32*)0x40000C4  

/* DMA channel 2 register definitions */
#define REG_DMA2SAD         *(u32*)0x40000C8  
#define REG_DMA2DAD         *(u32*)0x40000CC  
#define REG_DMA2CNT         *(u32*)0x40000D0  

/* DMA channel 3 register definitions */
#define REG_DMA3SAD         *(u32*)0x40000D4  
#define REG_DMA3DAD         *(u32*)0x40000D8  
#define REG_DMA3CNT         *(u32*)0x40000DC  

/* Defines */
#define DMA_CHANNEL_0 0
#define DMA_CHANNEL_1 1
#define DMA_CHANNEL_2 2
#define DMA_CHANNEL_3 3

#define DMA_DESTINATION_INCREMENT (0 << 21)
#define DMA_DESTINATION_DECREMENT (1 << 21)
#define DMA_DESTINATION_FIXED (2 << 21)
#define DMA_DESTINATION_RESET (3 << 21)

#define DMA_SOURCE_INCREMENT (0 << 23)
#define DMA_SOURCE_DECREMENT (1 << 23)
#define DMA_SOURCE_FIXED (2 << 23)

#define DMA_REPEAT (1 << 25)

#define DMA_16 (0 << 26)
#define DMA_32 (1 << 26)

#define DMA_NOW (0 << 28)
#define DMA_AT_VBLANK (1 << 28)
#define DMA_AT_HBLANK (2 << 28)
#define DMA_AT_REFRESH (3 << 28)

#define DMA_IRQ (1 << 30)
#define DMA_ON (1 << 31)

#define START_ON_FIFO_EMPTY 0x30000000



    // a constant definition exported by library:
//    #define MAX_FOO  20
#define REG_DISPCTL *(u16 *)0x4000000
#define MODE3 3
#define BG2_ENABLE (1<<10)
#define COLOR(r,g,b) ((r) | (g)<<5 | (b)<<10)
#define RED COLOR(31,0,0)
#define WHITE COLOR(31,31,31)
#define MINT COLOR(0,31,20)
#define CYAN COLOR(0,31,27)
#define PURPLE COLOR(31,0,28)
#define OFFSET(a,b) ((a)*240+(b))

//#define OFFSET (r,c,rowien) ((r)*(rowien)+(c))



    typedef unsigned short u16;
    extern u16* videoBuffer; 	
    void setPixel(int,int,u16); 
    void drawRect(int,int,int,int,u16);
    void drawHollowRect(int,int,int,int,u16);
    void drawImage3(int,int,int,int,const u16*);
    
#endif