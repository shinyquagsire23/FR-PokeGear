#define retToOW			0x08086194 + 1
#define loopTable		0x03005E00
#define loopTableData	0x03005E08
#define objBaseAddr		0x02020630
#define dummyAnimTable	0x082EC69C
#define dummyAnimData	0x082EC6A8
#define dummyAnimRoutine 0x08007429
#define mapHeader		0x02037318
#define time			0x03005CFA
#define dayOfWeek		*(u8 *) 0x0203D90C //CrystalDust only
#define dayOfWeekTextTable	0x08343900 //CrystalDust only
#define hourFormat		(*(u8  *) 0x0203D90E)
#define globalVars		(*(u32 *) 0x0203CF40)

#define KEYS            *(volatile u8*)0x030022EE
#define KEYSHOLD        *(volatile u8*)0x030022EC
#define KEYSSCROLL      *(volatile u8*)0x030022F0
#define KEYSLR          *(volatile u8*)0x030022EF
#define KEYSHOLDLR      *(volatile u8*)0x030022ED
#define KEYSSCROLLLR    *(volatile u8*)0x030022F1

void updateEverything()
{

	int (*func)(void) = (int (*)(void))0x080A910D;
	func();

	int (*func2)(void) = (int (*)(void))0x080069C1;
	func2();
	
	int (*func3)(void) = (int (*)(void))0x08006A0D;
	func3();
	
	int (*func4)(void) = (int (*)(void))0x080A1A1D;
	func4();
}

void updateEverything2()
{
	int (*func)(void) = (int (*)(void))0x080A19C1;
	func();

	int (*func2)(void) = (int (*)(void))0x08007189;
	func2();
	
	int (*func3)(void) = (int (*)(void))0x0800742D;
	func3();

}

void storeCallback(int *addr)
{
	int (*func)(u32) = (int (*)(void))0x08000541;
	func(addr);
}	

void storeCallback2(int *addr)
{	
	int (*func)(u32) = (int (*)(void))0x080006F1;
	func(addr);
}

void storeToLoopTable(int *addr, int *slotNum)
{
	int (*func)(u32,u8) = (int (*)(void))0x080A8FB1;
	func(addr,slotNum);
}

void clearOAMs()
{
	int (*func)(void) = (int (*)(void))0x08006975;
	func();
}

void initStuff()
{
	clearOAMs();
	
	int (*func)(void) = (int (*)(void))0x0800870D;
	func();
}

void clearOAM(int address)
{
	int (*func)(int) = (int (*)(void))0x080075F5;
	func(address);
	
	int (*func2)(int) = (int (*)(void))0x080070E9;
	func2(address);
}

void initSomeStuff()
{
	int (*func)(void) = (int (*)(void))0x080AC379;
	func();
	
	int (*func2)(void) = (int (*)(void))0x0809F775;
	func2();
	
	int (*func3)(void) = (int (*)(void))0x08085D35;
	func3();
}

u32 malloc(int *size)
{
	int (*func)(u32) = (int (*)(u32))0x08000B39;
	return func(size);
}

void free(int *addr)
{
	int (*func)(u32) = (int (*)(void))0x08000B61;
	func(addr);
}

void clearLoopTable()
{
	int (*func)(void) = (int (*)(void))0x080A8F51;
	func();
}

void clearKeyPresses()
{
	int (*func)(void) = (int (*)(void))0x080005BD;
	func();
}

void drawText(int *boxNumber, int *font, int *x, int *y, int *bar, int *baz, int *chars)
{
	int (*func)(int,int,int,int,int,int,int) = (int (*)(void))0x08199E65;
	func(boxNumber,font,x,y,bar,baz,chars);
}

//void drawBox(void *foo, void *font, void *x, void *y, void *bar, void *baz, void *chars);

void drawTextBox(void *r0, void *r1)
{
	int (*func)(void) = (int (*)(void))0x08003F21;//0x0810B995;
	func();
}

void somethingText(void *r0, void *r1)
{
	int (*func)(void) = (int (*)(void))0x0800445D;
	func();
}

void somethingText2(void *r0, void *r1)
{
	int (*func)(void) = (int (*)(void))0x080F6CD1;
	func();
}

void fadeScreen(int *bitmask, int *r1, int *r2, int *r3, int *color)
{

	int (*func)(u32,u16,u16,u16,u16) = (int (*)(void))0x080A1AD5;
	func(bitmask,r1,r2,r3,color);
		
}

void fadeSong()
{
	__asm("mov r0, #0x4");
	int (*func)(void) = (int (*)(void))0x0806b155;
	int x = func();
}

void copyPal(void *source, void *dest)
{
	__asm("mov r2, #0x8");
	SystemCall(0xC);
}

void copyMem(void *source, void *dest, void *size)
{
	__asm("mov r2, #0x8");
	SystemCall(0xC);
}

void playSong(int *songNum)
{
	int (*func)(void) = (int (*)(void))0x081DD0F5;
	int x = func();
}

void playCry(int *pkmnNum, int *fx)
{
	int (*func)(void) = (int (*)(void))0x08071dF1;
	int x = func();
}

void playSound(int *soundNum)
{
	int (*func)(u16) = (int (*)(void))0x080A37A5;
	func(soundNum);
}

void changeIO(int *offset, int *value)
{
	int (*func)(u32,u16) = (int (*)(void))0x080010B5;
	func(offset,value);
}

void initSomeMoreStuff()
{
	int (*func)(void) = (int (*)(void))0x08003605;
	func();
	
	int (*func2)(u8) = (int (*)(void))0x080017BD;
	func2(0x0);
}

void something2(int *a, int *b, int *c)
{
	int (*func)(void) = (int (*)(void))0x08001B91;
	int i = func();
}

void something(int *a, int *b, int *c)
{
	int (*func)(void) = (int (*)(void))0x080F6F1D;
	int i = func();
}

void initMapData(u8 *startBG, u32 *BGData, u8 *BGCount)
{
	int (*func)(u8,u32,u8) = (int (*)(void))0x080017E9;
	func(startBG,BGData,BGCount);
}

void clearStuff()
{
	int (*func)(void) = (int (*)(void))0x08199D99;
	func();
	
	int (*func2)(void) = (int (*)(void))0x08199A21;
	func2();
}

void createNewBGSpace(u8 *r0, u32 *newSpace)
{
	int (*func)(u8,u32) = (int (*)(void))0x08002251;
	func(r0,newSpace);
}

void underloadPalette(int address, int offset, int size)
{
	offset = ((offset << 1) + 0x02037714);
	size = size << 0xA;
	size = size >> 0xB;
	int (*func)(u32,u32,u8) = (int (*)(void))0x082E7085;
	func(address,offset,size);
}

void loadPalette(int address, int offset, int size)
{
	int (*func)(u32,u8,u8) = (int (*)(void))0x080A1939;
	func(address,offset,size);
}

void reloadBG(u8 *BG)
{
	int (*func)(u8) = (int (*)(void))0x0800236D;
	func(BG);
}

u8 clearTempTileSpace()
{
	int (*func)(void) = (int (*)(u8))0x08199A45;
	return func();
}

const u8 instsData[3] = {
	0xF, 0x1, 0x2
};

void boxPrint(u8 foo, u8 font, u8 x, u8 y, u32 bar, u32 baz, u32 txtpointer)
{
	int (*func3)(u8,u8,u8,u8,u32,u32,u32) = (int (*)(void))0x08199E65;
	func3(foo,font,x,y,bar,baz,txtpointer);
}

void writeBoxToTilemap(u8 r0, u8 r1)
{
	int (*func)(u8,u8) = (int (*)(void))0x08003659;
	func(r0,r1);
}

void clearBoxSpace(int boxNumber, int colorNum)
{
	int (*func)(u8,u8) = (int (*)(void))0x08003C49;
	func(boxNumber,colorNum);
}

u8 checkForSomethingIDunno()
{
	int (*func)(void) = (int (*)(void))0x08001AD5;
	return func();
}

void enableBG(int *BG)
{
	int (*func)(u8) = (int (*)(void))0x08001B31;
	func(BG);
}

void loadTilesIntoBGSpace(u8 r0, u32 GFXAddr, u8 r2, u8 r3, u8 sp)
{
	int (*func)(u8,u32,u8,u8,u8) = (int (*)(void))0x08199A91;
	func(r0,GFXAddr,r2,r3,sp);
}

void loadTilemapIntoBGSpace(u8 r0, u32 mapAddr, u8 r2, u8 r3)
{
	int (*func)(u8,u32,u8,u8) = (int (*)(void))0x080022F1;
	func(r0,mapAddr,r2,r3);
}

void textboxBGInit(u32 *addr) //clears all textboxes, loads all boxes from list, and inits BG 0
{
	int (*func)(u32) = (int (*)(void))0x080031C1;
	func(addr);
}

void prepTextSpace(u8 r0, u8 r1)
{
	int (*func)(u8,u8) = (int (*)(void))0x081973C5;
	func(r0,r1);
}

void loadNormalTextbox(u8 r0, u8 r1, u32 textPointer, u8 r3, u8 sp0, u8 sp4, u8 sp8)
{
	int (*func)(u8,u8,u32,u8,u8,u8,u8) = (int (*)(void))0x080045D1;
	func(r0,r1,textPointer,r3,sp0,sp4,sp8);
}

void swiB(u32 origin, u32 dest, u32 options)
{
	int (*func)(u32,u32,u32) = (int (*)(void))0x082E7085;
	func(origin,dest,options);
}

void loadStandardBoxBorders()
{
	int (*func)(u8,u16,u8) = (int (*)(void))0x0809877D;
	func(0x0,(0x80 << 0x2),0xF0);
	
	int (*func2)(u8,u16,u8) = (int (*)(void))0x0809882D;
	func2(0x0,(0x85 << 0x2),0xE0);
}

void loadMultipleSpriteFrames(int address)
{
	int (*func)(int) = (int (*)(void))0x08034531;
	func(address);
}

u8 grabPalNumber(int offset)
{
	int (*func)(int) = (int (*)(void))0x080087D5;
	return func(offset);
}

u32 createSprite(int *addr, int *XPos, int *YPos, int *x)
{
	int (*func)(u32,u16,u16,u8) = (int (*)(u8))0x08006DF5;
	u32 result = func(addr,XPos,YPos,x);
	
	return (result*0x44) + objBaseAddr;
}

u8 getCurrentRegion()
{
	int mapHeaderNumber = *((int *) mapHeader + 0x14);
	int mapNumber = *((int *) mapHeaderNumber + 0x08F0AC30);
	if(mapNumber > 4)
		mapNumber = 0;
	return mapNumber;
}

int getTextSizeInPixels(int font, int text, int r2)
{
	int (*func)(int,int,int) = (int (*)(u8))0x08005ED9;
	return func(font,text,r2);
}

void enableBox(u8 box)
{
	int (*func)(u8) = (int (*)(void))0x0800378D;
	func(box);
}

int grabSubRoutine(int entry, int offset) //loop table entry number, halfword offset
{
	int (*func)(int,int) = (int (*)(void))0x080A92B5;
	return func(entry,offset);
}

void storeToSubRoutine(int entry, int offset, int addr) //loop table entry number, halfword offset, routine address
{
	int (*func)(int,int,int) = (int (*)(void))0x080A927D;
	func(entry,offset,addr);
}

int grabLoopTableEntry(int addr)
{
	int (*func)(int) = (int (*)(void))0x080A921D;
	return func(addr);
}

u8 checkFlag(int flag)
{
	int (*func)(int) = (int (*)(void))0x0809D791;
	return func(flag);
}

u8 loadTextbox(int data)
{
	int (*func)(int) = (int (*)(void))0x08003381;
	return func(data);
}

void clearTextbox(int box)
{
	int (*func)(int) = (int (*)(void))0x08003575;
	func(box);
}

void clearAllTextboxes()
{
	int (*func)(void) = (int (*)(void))0x08003605;
	func();
}

void fillMapSpace(int BG, int tile, int startX, int startY, int width, int height)
{
	int (*func)(int,int,int,int,int,int) = (int (*)(void))0x08002705;
	func(BG,tile,startX,startY,width,height);
}

int divide(int numerator, int denominator)
{
	int i;
	for(i=0;numerator >= denominator;i++)
		numerator -= denominator;
	return i;
}

int modulo(int numerator, int denominator)
{
	int i;
	for(i=0;numerator >= denominator;i++)
		numerator -= denominator;
	return numerator;
}
