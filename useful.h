#define retToOW			(u8 *) 0x08086194 + 1
#define loopTable		(u8 *) 0x03005E00
#define loopTableData	(u8 *) 0x03005E08
#define boxInitStuff	0x082FF080
//#define boxInitStuff	0x0861FA08
#define textBuffer		0x02021FC4

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

void clearOAM()
{
	int (*func)(void) = (int (*)(void))0x08006975;
	func();
}

void initStuff()
{
	clearOAM();
	
	int (*func2)(void) = (int (*)(void))0x0800870D;
	func2();
	
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

void freeMaps()
{
	int (*func)(void) = (int (*)(void))0x080563F1;
	int x = func();
}

void drawBox(void *foo, void *font, void *x, void *y, void *bar, void *baz, void *chars)
{
	int (*func)(void) = (int (*)(void))0x080F6CD1;
	func();
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

void drawText(void *a, void *b, void *c, void *d)
{
	int (*func)(void) = (int (*)(void))0x081333C5;
	func();
}

void unfadeScreen()
{
	fadeScreen2(0xFFFFFFFF,0x0,0x10,0,0x0000);
}

void fadeScreen()
{
	fadeScreen2(0xFFFFFFFF,0x0,0,0x10,0x0000);
}

void fadeScreen2(int *bitmask, int *r1, int *r2, int *r3, int *color)
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

void playSound(int *fxNum)
{
	int (*func)(void) = (int (*)(void))0x080722CD;
	int x = func();
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

void initMapData(u8 *r0, u32 *r1, u8 *r2)
{
	int (*func)(u8,u32,u8) = (int (*)(void))0x080017E9;
	func(r0,r1,r2);
}

void clearStuff()
{
	int (*func)(void) = (int (*)(void))0x08199D99;
	func();
	
	int (*func2)(void) = (int (*)(void))0x08199A21;
	func2();
}

void loadTilesIntoBGSPace(u8 *r0, u32 *gfxData, u8 *r2, u8 *r3)
{
	int (*func)(u8,u32,u8,u8) = (int (*)(void))0x08199A91;
	func(r0,gfxData,r2,r3);
}

void createNewBGSpace(u8 *r0, u32 *newSpace)
{
	int (*func)(u8,u32) = (int (*)(void))0x08199D99;
	func(r0,newSpace);
}

void loadNewPalette(int address, int offset, int size)
{
	offset = ((offset << 1) + 0x02037714);
	size = size << 0xA;
	size = size >> 0xB;
	int (*func)(u32,u8,u8) = (int (*)(void))0x082E7085;
	func(address,offset,size);
}

void somethingWithBG(u8 *BG)
{
	int (*func)(u8) = (int (*)(void))0x0800236D;
	func(BG);
}

u8 checkForLoadedBGs()
{
	int (*func)(void) = (int (*)(u8))0x08199A45;
	return func();
}

void loadPalette(int *addr, int *offset, int *length)
{
	int (*func)(u32,u8,u8) = (int (*)(void))0x080A1939;
	func(addr,offset,length);
	
}

const u8 instsData[3] = {
	0xF, 0x1, 0x2
};

void boxPrint(u8 foo, u8 font, u8 x, u8 y, u32 bar, u32 baz, u32 txtpointer)
{
	int (*func3)(u8,u8,u8,u8,u32,u32,u32) = (int (*)(void))0x08199E65;
	func3(foo,font,x,y,bar,baz,txtpointer);
}

void writeBoxesToTilemap(u8 a, u8 b)
{
	int (*func5)(u8,u8) = (int (*)(void))0x08003659;
	func5(a,b);
}

void fillTileSpace(u8 *r0, u8 *colorNum)
{
	int (*func)(u8,u8) = (int (*)(void))0x08003C49;
	func(r0,colorNum);
}

void loadTutorialText(u32 *textAddr)
{
	int (*func)(u8) = (int (*)(u32))0x08098C19;		//load tutorial bar palette
	loadPalette(func(2),0xB0,0x20);
	fillTileSpace(0x0,0xFF);	
	boxPrint(0x0,0x0,0x2,0x1,instsData,0x00000000,textAddr);
	
	int (*func2)(u8) = (int (*)(void))0x0800378D;
	func2(0x0);
	
	writeBoxesToTilemap(0x0,3);
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

void whatEvenIsThis(int r0, int offset)
{
	int (*func)(u8,u32) = (int (*)(void))0x08002251;
	func(r0,offset);
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

void loadBoxPalette(u8 r0, u8 r1, u8 slot)
{
	int (*func)(u8,u8,u8) = (int (*)(void))0x0809877D;
	func(r0,r1,slot);
}

void loadText(u32 memory, u32 rom)
{
	int (*func)(u32,u32) = (int (*)(void))0x0809877D;
	func(memory,rom);
}

void resetVars()
{
	TIMER[0] = 0;
	TIMER[1] = 0;
	for(int i = 0; i < 90; i++)
	{
		VAR[i] = 0;
	}
}
