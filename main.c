//Start menu table is at 083A7344 in Fire Red. It is formated two pointers per entry 
//with one pointer being the text and the other being the actual routine. 

//On Fire Red extra ASM and repointing is required to expand the menu larger, but 
//Emerald should be able to replace the PokeNav fairly easily.

//To implement the menu option properly and smoothly take a look at 0806F480 in a Fire Red ROM. This is the entry for the Bag. You can either do this in C or ASM. ASM is recommended but C should actually work perfectly fine.

//EXAMPLE
/*
0806F480 sub_0806F480:                           
0806F480 PUSH    {LR}
0806F482 LDR     R0, =set_to_r1_on_option_menu @Tracks fade so that we switch at just the right moment
0806F484 LDRB    R1, [R0,#7]
0806F486 MOVS    R0, #0x80 @ 'Ç'
0806F488 ANDS    R0, R1
0806F48A CMP     R0, #0
0806F48C BEQ     loc_0806F498 @This is where we load our callback and stuff
0806F48E MOVS    R0, #0
0806F4AC POP     {R1}
0806F4AE BX      R1

0806F498 loc_0806F498:                           
0806F498 BL      sub_0807B004
0806F49C BL      sub_0806EF18
0806F4A0 BL      free_internal_bgmaps_maybe
0806F4A4 LDR     R0, =(sub_08107EB8+1)           @ func
0806F4A6 BL      set_callback2
0806F4AA MOVS    R0, #1
*/ 
#define TITLE			((u8*)0x020370B7)
#define VAR				((u8*)0x020370B8)
#define TIMER			((long*)0x020370BC)
#define BG0HOFFs		*(u16*)0x4000010

#define fadeScreenDone	*((u8  *) 0x02037FD4 + 7)
#define globalVars		(*(u32 *) 0x0203CF40)

#define Tiles		((u16*)0x6000000)
#define OBJData		((u16*)0x6010000)
#define BG0Data     ((u16*)0x600F800)
#define BG1Data     ((u16*)0x600E800)
#define BG2Data     ((u16*)0x600E000)
#define TextData    ((u32*)0x6008000)
#define TBData		((u16*)0x020204B5)
#define second 60;

#include "include/gba_keys.h"

void init2();
void main();
void updateEverything2();
void loadGFXLoop();
void dunno();

void init() {
	if (fadeScreenDone == 0) {
		initSomeStuff();
		storeCallback((void *) init2 + 1);
		return 1;
	}
	else
		return 0;
}

#include <string.h>
#include "include/gba.h"
#include "useful.h"
#include "img_bins/pkgearbg.h"
#include "img_bins/pkgearmenu.h"
#include "img_bins/pkgearbuttons.h"
#include "img_bins/pkgearnumbers.h"

//081C7250
void init2() {
	 globalVars = malloc(0x5C);
		if (globalVars == 0)
			storeCallback(retToOW);
		else {
			initMallocSpace(globalVars);
			
			clearLoopTable();
			storeCallback2(0);
			
			storeToLoopTable((void *) main + 1,0);
			storeCallback((void *) updateEverything + 1);
			storeCallback2((void *) updateEverything2 + 1);
		}
}

void initMallocSpace(int pointer) {
	
	for(int i = 0x17, *tempGlobalVars = ((u8 *)pointer + 0x58); i != 0 ; i -= 1, tempGlobalVars -= 0x1) {
		*tempGlobalVars = 0;
	}
	
}

//081C742C
void main(int loopTableNumber) {
	
	int *currentLoop = ((loopTableNumber * 0x28) + loopTableData);
	
	switch(*currentLoop) {
	case 0:
		loop0();
		(*currentLoop)++;
		break;
	case 1:
		loop1();
		(*currentLoop)++;
		break;
	}
}	
	
void loop0()
{
	mallocBGSpace(0x0,0x500);
	mallocBGSpace(0x1,0x1000);
	mallocBGSpace(0x2,0x1000);
	initStuff();
	return 1;
}

//1C76FC
void loop1()
{
	storeToLoopTable((void *) loadGFXLoop + 1,1);
}

const u32 mapDataUnk[4] = { // first byte half = bg number, 2nd, 3rd, and 4th = 1st, 2nd, and 4th byte halves of BGXCNT
	0x000001F8, 0x000011C1, 0x000021D6, 0x000031E3
};

//1C7764
void loadGFXLoop(int loopTableNumber) {

	int *currentLoop = ((loopTableNumber * 0x28) + loopTableData);
	
	if (*currentLoop == 0) {
		changeIO(0,OBJ_ENABLE | OBJ_MAP_1D);
		initSomeMoreStuff();
		
		initMapData(0x0,mapDataUnk,0x4);
		clearStuff();
		(*currentLoop)++;
	}
	else if(*currentLoop == 1) {
		int blank = 0;
		swiB(&blank,(0xC0 << 0x13),0x05006000);
		(*currentLoop)++;
	}
	else if(*currentLoop == 2) {
		loadStandardBoxBorders();
		(*currentLoop)++;
	}
	else if(*currentLoop == 3) {
		int allocdBGSpace = getAllocdBGSpace(0);
		loadTilesIntoBGSpace(1,pkgearmenuTiles,0,2,0);
		createNewBGSpace(1,(allocdBGSpace));
		loadTilemapIntoBGSpace(1,pkgearmenuMap,0,0);
		underloadPalette(pkgearmenuPal,0,0x20);
		reloadBG(1);
		(*currentLoop)++;
	}
	else if(*currentLoop == 4) {
	
		int allocdBGSpace = getAllocdBGSpace(1);
		loadTilesIntoBGSpace(3,pkgearbgTiles,0,0,0);
		createNewBGSpace(3,(allocdBGSpace));
		loadTilemapIntoBGSpace(3,pkgearbgMap,0,0);
		reloadBG(3);
		(*currentLoop)++;
	}
	else if(*currentLoop == 5) {
		if (checkForLoadedBGs() == 0) {
			initBG0WithText();
			(*currentLoop)++;
		}
	}
	else if(*currentLoop == 6) {
		if (checkForSomethingIDunno() == 0) {
			loadSprites();
			
			unfadeScreen();
			enableBG(0);
			enableBG(1);
			enableBG(2);
			enableBG(3);
			(*currentLoop)++;
		}
	else
		return;
	}
}

const u8 tutorialText[47] = { // Press L or R to change cards.\nPress B to exit.
	0xCA, 0xE6, 0xD9, 0xE7, 0xE7, 0x00, 0xC6, 0x00, 0xE3, 0xE6, 0x00, 0xCC, 0x00, 0xE8, 0xE3, 0x00,
	0xD7, 0xDC, 0xD5, 0xE2, 0xDB, 0xD9, 0x00, 0xD7, 0xD5, 0xE6, 0xD8, 0xE7, 0xAD, 0xFE, 0xCA, 0xE6,
	0xD9, 0xE7, 0xE7, 0x00, 0xBC, 0x00, 0xE8, 0xE3, 0x00, 0xD9, 0xEC, 0xDD, 0xE8, 0xAD, 0xFF
};


const u8 textboxData[12] = { //BG number, X pos, Y pos, width, height, palette slot, tile number (2 bytes), list terminator
	0x00, 0x07, 0x0F, 0x16, 0x04, 0x0F, 0x94, 0x01, 0xFF, 0x0, 0x0, 0x0
};

void initBG0WithText()
{
	textboxBGInit(textboxData);
	prepTextSpace(0,0);
	loadNormalTextbox(0,1,tutorialText,0,1,0,0);
	writeBoxToTilemap(0,3);
}

int getAllocdBGSpace(int BG)
{
	return *((int *)((globalVars + 0x10) + (BG << 2)));
}
	
int mallocBGSpace(int BG, int size)
{
	int *i = ((u8 *)(globalVars + 0x10 + (BG << 2)));
	*i = malloc(size);
	return *i;
}

const int spritePicData[4] = {
	pkgearbuttonsTiles, 0x00000E00, pkgearnumbersTiles, 0x00010780
};

const int spritePalTable[6] = {
	pkgearbuttonsPal, 0x00000000, pkgearnumbersPal, 0x00000001, 0x00000000, 0x00000000
};

const u32 OAMData1[2] = {
	0x80000000, 0x00000000
};

const u32 buttonData[6] = {
	0x00000000, OAMData1, dummyAnimTable, 0x00000000,
	dummyAnimData, dummyAnimRoutine
};

void loadSprites()
{
	for(int i=0, address = &spritePicData;i<=0x2;i++)
	loadMultipleSpriteFrames(address + (i<<0x2));
	loadSpritePalettesFromTable(spritePalTable);
	for(int i=0, *address = getAllocdBGSpace(2);i<=0x4;i++,address++) {
		int x = i << 2;
		int y = i << 4;
		x + i;
		x << 0x12;
		int z = 0xA0 << 0xE;
		x + z;
		address + y;
		int spriteAddr = createSprite(buttonData,0,(x >> 0x10),0x3);
		*address = spriteAddr;
		*((u16 *)spriteAddr + 0x12) = 0x10;
		*((u16 *)spriteAddr + 0x13) = (i << 0x5) + 0x10;
	}
}

void loadSpritePalettesFromTable(int *palTable)
{
	int palNumber;
	int palOffset;
	goto checkForEnd;
start:	
	palNumber = (palNumber << 0x4) + (0x80 << 1);
	palOffset = *palTable;
	underloadPalette(palOffset,palNumber,0x20);
	palTable += 2;
checkForEnd:
	if (*palTable == 0)
		return;
	palNumber = grabPalNumber(*(palTable + 1));
	if(palNumber != 0xFF)
		goto start;
}
	
	

/*
void sortaMain()
{
	if(VAR[0] <= 3)
	{
		clearOAM();
		BG1VOFF = 0;
		BG2VOFF = 0;
		BG3VOFF = 0;
		BG1HOFF = 0;
		BG2HOFF = 0;
		BG3HOFF = 1;
		for(int i = 0; i < 0x400; i++)
		{
			//BG0Data[i] = 0x0;
		}
		for(int i = 0; i < 0x3BE0 / 4; i++)
		{
			TextData[i] = 0x0;
		}
		copyPal(&pkgearbgPal, &BG_PaletteMem[0]);
		LZ77UnCompVram(&pkgearbgTiles, &Tiles[0x0]);
		LZ77UnCompVram(&pkgearmenuTiles, &Tiles[0x200]);
		LZ77UnCompVram(&pkgearbgMap, &BG2Data[0]);
		//LZ77UnCompVram(&pkgearbgMap, &BG0Data[0]);
		LZ77UnCompVram(&pkgearmenuMap, &BG1Data[0]);
		clearPeskyMenu();
		somethingText2(0,2);
		//drawBox(0,1,2,3,4,5,6);
		//drawTextBox(0,3);
		somethingText(2,0);
		drawText(0x8C80120,0,1,0);
		//drawTextBox(0,3);

		//clearPeskyMenu();
		unfadeScreen();
		//drawText(2,1,6,1,0x08478E3B,0xFFFFFFFF,0x084161d4);
		VAR[0] = 7;
	}
		//unfadeScreen();
}

void clearPeskyMenu()
{
		for(int i = 0; i < 0x1BF; i++)
		{
			BG0Data[i] = 0x0;
		}
		for(int i = 0; i < 6; i++)
		{
			//TBData[i] = pkgearText[i];
		}
}
*/
