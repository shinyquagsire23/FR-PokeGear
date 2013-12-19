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

//081C7250
void init2() {
	 globalVars = malloc(0x5C);
		if (globalVars == 0)
			storeCallback(retToOW);
		else {
			initMallocSpace(globalVars); //F68264 - doesn't work???
			
			clearLoopTable();
			storeCallback2(0);
			
			storeToLoopTable((void *) main + 1,0);
			storeCallback((void *) updateEverything + 1);
			storeCallback2((void *) updateEverything2 + 1);
		}
}

void initMallocSpace(int pointer) {
	
	int tempGlobalVars = pointer + 0x58;
	int blank = 0;
	
	for(int i = 0x16; i == 0 ; i -= 1, tempGlobalVars -= 0x4) {
		int *tempGlobalVars = 0;
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
	int allocdBGSpace = mallocBGSpace(0x0,0x82C);
	if (allocdBGSpace == 0)
		return 0;
	initStuff();
	return 1;
}

//1C76FC
void loop1()
{
	storeToLoopTable((void *) loadGFXLoop + 1,1);
}

//1C7764
void loadGFXLoop(int loopTableNumber) {

	int *currentLoop = ((loopTableNumber * 0x28) + loopTableData);
	
	if (*currentLoop == 0) {
		changeIO(0,OBJ_ENABLE | OBJ_MAP_1D);
		initSomeMoreStuff();
		
		const u32 mapDataUnk[2] = {
			0x00000050, 0x10160100
		};
		
		initMapData(0x0,mapDataUnk,0x1);
		clearStuff();
		*currentLoop = 1;
	}
	else if(*currentLoop == 1) {
		int allocdBGSpace = getAllocdBGSpace(0);
		loadTilesIntoBGSpace(0,0x08DC7B80,0,0,0);
		createNewBGSpace(0,(allocdBGSpace + 0x2C));
		whatEvenIsThis(0,(allocdBGSpace + 0x2C));
		loadTilemapIntoBGSpace(0,0x08DC7D84,0,0);
		loadNewPalette(0x08DC7B60,0,0x20);
		somethingWithBG(0);
		*currentLoop = 2;
	}
	else if(*currentLoop == 2) {
		if (checkForLoadedBGs() == 0) {
			initBG0WithText();
			*currentLoop = 3;
		}
	}
	else if(*currentLoop == 3) {
		if (checkForSomethingIDunno() == 0) {
		//	loadSprites();
			
			enableBG(0);
			storeToLoopTable((void *) dunno + 1,1);
			unfadeScreen();
			*currentLoop = 4;
		}
	else
		return;
	}
}

void dunno()
{
	//Something for later, but empty for now
}

const u8 tutorialText[23] = {
	0xF8, 0x00, 0xF8, 0x01, 0xBF, 0xD2, 0xC3, 0xCE, 0xFF //(A)(B)EXIT
};

//caught at A12
void initBG0WithText()
{
	int *allocdBGSpace;
	allocdBGSpace = getAllocdBGSpace(0);
	textboxBGInit(boxInitStuff);
	loadBoxPalette(0,0xFC,0xF0);
	loadText(textBuffer,tutorialText);
	//*(allocdBGSpace + 0x10) = 0;
}

int getAllocdBGSpace(int BG)
{
	return ((globalVars + 0x10) + (BG << 2));
}
	
int mallocBGSpace(int BG, int size)
{
	int *i = (globalVars + 0x10) + (BG << 2);
	i = malloc(size);
	return i;
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
