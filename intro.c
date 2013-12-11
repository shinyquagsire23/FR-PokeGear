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
#define TITLE     ((u8*)0x020370B7)
#define VAR     ((u8*)0x020370B8)
#define TIMER   ((long*)0x020370BC)
#define init     ((u8*)0x020370B8)
#define BG0HOFFs			*(u16*)0x4000010

#define Tiles     ((u16*)0x6000000)
#define OBJData		((u16*)0x6010000)
#define BG0Data     ((u16*)0x600F800)
#define BG1Data     ((u16*)0x600E800)
#define BG2Data     ((u16*)0x600E000)
#define TextData    ((long*)0x6008000)
#define TBData    ((u16*)0x020204B5)
#define second 60;

#include "include/gba_keys.h"

void sortaMain();

void notMain()
{
	writeToCx(0x0810D48D);
	setCallback2(0x08790001);
	if(keyDown(KEY_B) || init[27] == 11)
   	{
     		//int (*func)(void) = (int (*)(void))0x081087ED;
     		//resetVars();
		VAR[0] = 3;
		//VAR[3] = VAR[3] + 1;
		//int x = func();
	}
	sortaMain();
	return;
}

#include <string.h>
#include "include/gba.h"
#include "useful.h"
#include "img_bins/pkgearbg.h"
#include "img_bins/pkgearmenu.h"

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

