//defines needed by DMAFastCopy
#define REG_DMA3SAD *(volatile unsigned int*)0x40000D4
#define REG_DMA3DAD *(volatile unsigned int*)0x40000D8
#define REG_DMA3CNT *(volatile unsigned int*)0x40000DC
#define DMA_ENABLE 0x80000000
#define DMA_TIMING_IMMEDIATE 0x00000000
#define DMA_16 0x00000000
#define DMA_32 0x04000000
#define DMA_32NOW (DMA_ENABLE | DMA_TIMING_IMMEDIATE | DMA_32)
#define DMA_16NOW (DMA_ENABLE | DMA_TIMING_IMMEDIATE | DMA_16)

//macro to change the video mode
#define SetMode(mode) REG_DISPCNT = (mode)

//define some video addresses
#define REG_DISPCNT *(volatile unsigned short*)0x4000000
#define BGPaletteMem ((unsigned short*)0x5000000)
#define REG_VCOUNT *(volatile unsigned short*)0x4000006
#define REG_DISPSTAT *(volatile unsigned short *)0x4000004
//create a pointer to the video buffer
unsigned short* videoBuffer = (unsigned short*)0x6000000;

//define object attribute memory state address
#define SpriteMem ((unsigned short*)0x7000000)

//define object attribute memory image address
#define SpriteData ((unsigned short*)0x6010000)

//define object attribute memory palette address
#define SpritePal ((unsigned short*)0x5000200)

//misc sprite constants
#define OBJ_MAP_2D 0x0
#define OBJ_MAP_1D 0x40
#define OBJ_ENABLE 0x1000
//background 2 stuff
#define REG_BG2CNT     *(volatile unsigned short *)0x400000C
#define BG2_ENABLE		0x400
#define BG_COLOR256				0x80
#define CharBaseBlock(n)		(((n)*0x4000)+0x6000000)
#define ScreenBaseBlock(n)		(((n)*0x800)+0x6000000)
unsigned short * bg2map;
//background constants
#define ROTBG_SIZE_128x128		0x0
#define ROTBG_SIZE_256x256		0x4000
#define ROTBG_SIZE_512x512		0x8000
#define ROTBG_SIZE_1024x1024	0xC000
#define CHAR_SHIFT				2
#define SCREEN_SHIFT			8
#define WRAPAROUND              0x1
#define BG_MOSAIC_ENABLE 0x40

//attribute0 stuff
#define ROTATION_FLAG 		0x100
#define SIZE_DOUBLE			0x200
#define MODE_NORMAL     	0x0
#define MODE_TRANSPERANT    0x400
#define MODE_WINDOWED		0x800
#define MOSAIC				0x1000
#define COLOR_16			0x0000
#define COLOR_256			0x2000
#define SQUARE              0x0
#define TALL                0x4000
#define WIDE                0x8000

//attribute1 stuff
#define ROTDATA(n)          ((n) << 9)
#define HORIZONTAL_FLIP		0x1000
#define VERTICAL_FLIP		0x2000
#define SIZE_8              0x0
#define SIZE_16             0x4000
#define SIZE_32             0x8000
#define SIZE_64             0xC000

//attribute2 stuff
#define PRIORITY(n)		((n) << 10)
#define PALETTE(n)		((n) << 12)


//sprite structs
typedef struct tagSprite {
	unsigned short attribute0;
	unsigned short attribute1;
	unsigned short attribute2;
	unsigned short attribute3;
}Sprite,*pSprite;

typedef struct tagSpriteRotate {
	unsigned short filler1[3];
	unsigned short pa;
	unsigned short filler2[3];
	unsigned short pb;	
	unsigned short filler3[3];
	unsigned short pc;	
    unsigned short filler4[3];
	unsigned short pd;
}SpriteRotate,*pSpriteRotate;

