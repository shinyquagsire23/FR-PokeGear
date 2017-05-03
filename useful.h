#define retToOW			0x08086194 + 1
#define loopTable		0x03005E00
#define loopTableData	0x03005E08
#define objBaseAddr		0x02020630
#define dummyAnimTable	0x082EC69C
#define dummyAnimData	0x082EC6A8
#define dummyAnimRoutine 0x08007429
#define mapHeader		0x02037318
#define time			0x03005CFA
#define dayOfWeek		*(u8  *) 0x0203D90C //CrystalDust only
#define dayOfWeekTextTable	0x08343900 //CrystalDust only
#define regionTable		0x08F0AC30 //CrystalDust only
#define hourFormat		*(u8  *) 0x0203D90E //CrystalDust only
#define radioStation	*(u8  *) 0x0203D910 //CrystalDust only
#define globalVars		*(u32 *) 0x0203CF40
#define townMapVars		*(u32 *) 0x0203A144
#define currentlyPlaying	*(u8 *) 0x03007427
#define radioSelectSound	0x74

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

void callRoutine(int *addr, int *loopTableNum)
{
	int (*func)(int) = (int (*)(void))addr;
	func(loopTableNum);
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

void clearCaveWindow()
{
	int (*func)(void) = (int (*)(void))0x080B9FB9;
	func();
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

void fadeScreen(int *bitmask, int *r1, int *r2, int *r3, int *color)
{

	int (*func)(u32,u16,u16,u16,u16) = (int (*)(void))0x080A1AD5;
	func(bitmask,r1,r2,r3,color);
		
}

void swi0B(int *source, int *dest, int *options)
{
	int (*func)(int,int,int) = (int (*)(void))0x082E7085;
	func(source,dest,options);
}

void swi11(int *source, int *dest)
{
	int (*func)(int,int) = (int (*)(void))0x082E7091;
	func(source,dest);
}

void playSong(int *songNum)
{
	int (*func)(int) = (int (*)(void))0x080A2F11;
	func(songNum);
}

int grabDefaultSong()
{
	int (*func)(void) = (int (*)(void))0x08085739;
	return func();
}

void playCry(int *pkmnNum, int *fx)
{
	int (*func)(void) = (int (*)(void))0x08071dF1;
	func();
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

void disableIOBit(int *offset, int *value)
{
	int (*func)(u32,u16) = (int (*)(void))0x08001209;
	func(offset,value);
}

void initSomething()
{
	int (*func)(void) = (int (*)(void))0x08003605;
	func();
}

void initSomethingElse()
{
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

void clearBoxTileSpace(int boxNumber, int colorNum)
{
	int (*func)(u8,u8) = (int (*)(void))0x08003C49;
	func(boxNumber,colorNum);
}

void clearBoxTilemapSpace(int boxNumber)
{
	int (*func)(u8) = (int (*)(void))0x080038A5;
	func(boxNumber);
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

void loadStandardBoxBorders()
{
	int (*func)(u8,u16,u8) = (int (*)(void))0x0809877D;
	func(0x0,(0x80 << 0x2),0xF0);
	
//	int (*func2)(u8,u16,u8) = (int (*)(void))0x0809882D;
//	func2(0x0,(0x85 << 0x2),0xE0);
}

u16 loadMultipleSpriteFrames(int address)
{
	int (*func)(int) = (int (*)(void))0x08034531;
	return func(address);
}

u8 grabPalNumber(int offset)
{
	int (*func)(int) = (int (*)(void))0x080087D5;
	return func(offset);
}

u32 createSprite(int *addr, int *XPos, int *YPos, int *unk)
{
	int (*func)(u32,u16,u16,u8) = (int (*)(u8))0x08006DF5;
	u32 result = func(addr,XPos,YPos,unk);
	
	return (result*0x44) + objBaseAddr;
}

u8 getCurrentRegion()
{
	int mapNumber = *(u8 *)(*((u8 *) mapHeader + 0x14) + 0x08F0AC30);
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

void loadSelectionPointer(int frame, int pal)
{
	int (*func)(int,int) = (int (*)(int,int))0x08124289;
	func(frame,pal);
}

void loadPlayerHead(int frame, int pal)
{
	int (*func)(int,int) = (int (*)(int,int))0x081240D5;
	func(frame,pal);
}

void removeOAMTileSpace(int tileSpaceNumber)
{
	int (*func)(int) = (int (*)(void))0x08008569;
	func(tileSpaceNumber);
}

void initTownMapStuff(int memaddr, int r1)
{
	int (*func)(int,int) = (int (*)(void))0x08122CDD;
	func(memaddr,r1);
}

int mapCardKeyChecks()
{
	int (*func)(void) = (int (*)(void))0x081230AD;
	return func();
}

void loadMapName(int offset, int number, int length)
{
	int (*func)(int,int,int) = (int (*)(void))0x0812456D;
	func(offset,number,length);
}

int getCurrentIOState(int mode)
{
	int (*func)(int) = (int (*)(int))0x080011B9;
	return func(mode);
}

int getMapNameFromPos(int x, int y, int map)
{
	int (*func)(int,int,int) = (int (*)(int))0x0812386D;
	return func(x,y,map);
}

void clearPointerAndHead()
{
	int (*func)(void) = (int (*)(void))0x0812305D;
	func();
}

void clearPalette(int pal)
{
	int (*func)(int) = (int (*)(void))0x0800884D;
	func(pal);
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
