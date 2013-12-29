#define DMA3Source		(*(u32 *) 0x040000D4)
#define DMA3Dest		(*(u32 *) 0x040000D8)
#define DMA3Options		(*(u32 *) 0x040000DC)

#define config			(*(u8  *) globalVars)
#define currentCard		(*(u8  *)(globalVars + 1))
#define previousCard	(*(u8  *)(globalVars + 2))
#define fadeScreenDone	(*(u8  *)(0x02037FD4 + 7))

#include "include/gba_keys.h"

void init2();
void init3();
void animateButtonSlideIn();
void main();
void updateEverything2();
void loadGFXLoop();
void checkTimeLoop();
void animateCardSwap();
void individualUpdate();
void swapCards();
void quit();
void BCheck();

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
#include "img_bins/pkgearmap.h"
#include "img_bins/pkgearphone.h"
#include "img_bins/pkgearbuttons.h"
#include "img_bins/pkgearnumbers.h"
#include "img_bins/johtomap.h"

//081C7250
void init2() {
	 globalVars = malloc(0x5C);
		if (globalVars == 0)
			storeCallback(retToOW);
		else {
			initMallocSpace(globalVars,0x17);
			
			clearLoopTable();
			storeCallback2(0);
			
			storeToLoopTable((void *) init3 + 1,0);
			storeCallback((void *) updateEverything + 1);
			storeCallback2((void *) updateEverything2 + 1);
		}
}

void initMallocSpace(int pointer, int i) {
	for(int *tempSpace = (u32 *)pointer; i != 0 ; i -= 1, tempSpace++) {
		*tempSpace = 0;
	}
}

//081C742C
void init3(int loopTableNumber) {
	int *currentLoop = ((u8 *)(loopTableNumber * 0x28) + loopTableData);
	
	switch(*currentLoop) {
	case 0:
		mallocSubSpace(0x0,0x500);
		mallocSubSpace(0x1,0x500);
		mallocSubSpace(0x2,0x1000);
		mallocSubSpace(0x3,0x2C);
		
		int blank = 0;
		DMA3Source = &blank;
		DMA3Dest = getAllocdSubSpace(2);
		DMA3Options = 0x85000400;
		
		initMallocSpace(getAllocdSubSpace(3),0xB);
		initStuff();
		(*currentLoop)++;
		break;
	case 1:
		storeToLoopTable((void *) loadGFXLoop + 1,1);
		(*currentLoop)++;
		break;
	case 2:
		if(grabLoopTableEntry((void *) loadGFXLoop + 1) == 0xFF) {
			playSound(0x6E);
			*currentLoop = 0;
			*(int *)(loopTable + (loopTableNumber * 0x28)) = (void *) animateButtonSlideIn + 1;
		}
		break;
	}
}

void animateButtonSlideIn(int loopTableNumber) {
	if(fadeScreenDone == 0) {
		u8 *counter = (u8 *)((loopTableNumber * 0x28) + loopTableData);
		if(*counter < 0x8) {
			for(int i=0;i<=0x4;i++) {
				(*((u16 *)((i * 0x44) + objBaseAddr + 0x20)))+= 4;
			}
			(*counter)++;
		}
		else {
			*counter = 0;
			*(int *)(loopTable + (loopTableNumber * 0x28)) = (void *) main + 1;
		}
	}
}

void main(int loopTableNumber) {
	int cardChanged = 0;
	if(keyScrollingLR(KEY_L)) {
		currentCard--;
		if(currentCard == 1) {
			if((config & 1) == 0)
				currentCard = 0;
		} else if(currentCard == 3) {
			leftChecker:
			if((config & (1 << 1)) == 0)
				currentCard = 2;
		} else if(currentCard == 4) {
			leftChecker2:
			if((config & (1 << 2)) == 0) {
				currentCard = 3;
				goto leftChecker;
			}
		} else if(currentCard > 4) {
			currentCard = 4;
			goto leftChecker2;
		}
		cardChanged = 1;
		goto testNothingElse;
	}
	if(keyScrollingLR(KEY_R)) {
		currentCard++;
		if(currentCard == 1) {
			if((config & 1) == 0)
				currentCard = 2;
		} else if(currentCard == 3) {
			if((config & (1 << 1)) == 0) {
				currentCard = 4;
				goto rightChecker;
			}
		} else if(currentCard == 4) {
			rightChecker:
			if((config & (1 << 2)) == 0)
				currentCard = 0;
		} else if(currentCard > 4) 
			currentCard = 0;
		cardChanged = 1;
		goto testNothingElse;
	}
	BCheck(loopTableNumber);
	cardKeyPressChecks(currentCard);
	testNothingElse:
	if(cardChanged == 1) {
		playSound(0x5);
		*(u8 *)(loopTableData + (loopTableNumber * 0x28)) = 4;
		*(int *)(loopTable + (loopTableNumber * 0x28)) = (void *) animateCardSwap + 1;
	}
}

void BCheck(int loopTableNumber) {
	if(keyPressed(KEY_B)) {
		playSound(0x6F);
		fadeScreen(0xFFFFFFFF,0xFFFFFFFE,0x0,0x10,0x0000);
		*(int *)(loopTable + (loopTableNumber * 0x28)) = (void *) quit + 1;
	}
}

void quit(int loopTableNumber) {
	if(fadeScreenDone == 0) {
		free(getAllocdSubSpace(0));
		free(getAllocdSubSpace(1));
		free(getAllocdSubSpace(3));
		free(getAllocdSubSpace(3));
		free(&globalVars);
		clearKeyPresses();
		storeCallback(retToOW);
	}
}

void cardKeyPressChecks(int currentCardVal)
{
	switch(currentCardVal) {
	case 0:
		if(keyPressed(KEY_SELECT)) {
			hourFormat = 1 - hourFormat;
			playSound(0x5);
			break;
		}
	case 1:
		//map card
		break;
	case 2:
		//phone card
		break;
	case 3:
		//radio card
		break;
	case 4:
		//contest card?
		break;
	}
}

void animateCardSwap(int loopTableNumber) {
	BCheck(loopTableNumber);
	int *cardAnimCounter = (u8 *)((loopTableNumber * 0x28) + loopTableData);
	if(*cardAnimCounter != 0) {
		(*((u16 *)(*(u32 *)(getAllocdSubSpace(3) + (previousCard << 0x2)) + 0x20)))--;
		(*((u16 *)(*(u32 *)(getAllocdSubSpace(3) + (currentCard << 0x2)) + 0x20)))++;
		(*cardAnimCounter)--;
	} else {
		*cardAnimCounter = 0;
		*(int *)(loopTable + (loopTableNumber * 0x28)) = (void *) swapCards + 1;
	}
}

void swapCards(int loopTableNumber) {
	BCheck(loopTableNumber);
	if(previousCard != currentCard) {
		unloadCard(previousCard);
		loadCard(currentCard);
	}
	if(clearTempTileSpace() == 0)
		*(int *)(loopTable + (loopTableNumber * 0x28)) = (void *) main + 1;
}

const u8 dayOfWeekBoxData[8] = {
	0x00, 0x0D, 0x02, 0x08, 0x03, 0x0F, 0x01, 0x00
};

const u8 hourFormatBoxData[8] = {
	0x00, 0x0A, 0x0B, 0xE, 0x03, 0x0F, 0x18, 0x00
};

const u8 hourFormatText[21] = { // SELECT: Switch time mode
    0xCD, 0xBF, 0xC6, 0xBF, 0xBD, 0xCE, 0xF0, 0x00, 0xCD, 0xEB, 0xDD, 0xE8, 0xD7, 0xDC, 0x00, 0xE1, 
    0xE3, 0xD8, 0xD9, 0xFF, 
};

const u8 boxPalData[3] = { // background color, text color, text shadow color (color number)
	0x00, 0x02, 0x03
};

const u8 tutorialText[47] = { // Press L or R to change cards.\nPress B to exit.
	0xCA, 0xE6, 0xD9, 0xE7, 0xE7, 0x00, 0xC6, 0x00, 0xE3, 0xE6, 0x00, 0xCC, 0x00, 0xE8, 0xE3, 0x00,
	0xD7, 0xDC, 0xD5, 0xE2, 0xDB, 0xD9, 0x00, 0xD7, 0xD5, 0xE6, 0xD8, 0xE7, 0xAD, 0xFE, 0xCA, 0xE6,
	0xD9, 0xE7, 0xE7, 0x00, 0xBC, 0x00, 0xE8, 0xE3, 0x00, 0xD9, 0xEC, 0xDD, 0xE8, 0xAD, 0xFF
};

const u8 callingText[26] = { // Whom do you want to call?
    0xD1, 0xDC, 0xE3, 0xE1, 0x00, 0xD8, 0xE3, 0x00, 0xED, 0xE3, 0xE9, 0x00, 0xEB, 0xD5, 0xE2, 0xE8, 
    0x00, 0xE8, 0xE3, 0x00, 0xD7, 0xD5, 0xE0, 0xE0, 0xAC, 0xFF
};

void loadCard(currentCardVal) {
	switch(currentCardVal) {
	case 0:
		loadTilemapIntoBGSpace(1,pkgearmenuMap,0,0);
		loadPalette(pkgearmenuPal + 0xA,0xA,0x8);
		prepTextSpace(0,0);
		reloadBG(1);
		loadNormalTextbox(0,1,tutorialText,0,1,0,0);
		writeBoxToTilemap(0,3);
		int dayOfWeekBox = loadTextbox(dayOfWeekBoxData);
		*(u8 *)(globalVars + 4) = dayOfWeekBox;
		int hourFormatBox = loadTextbox(hourFormatBoxData);
		*(u8 *)(globalVars + 5) = hourFormatBox;
		loadDayOfWeek();
		enableBox(dayOfWeekBox);
		writeBoxToTilemap(dayOfWeekBox,3);
		enableBox(hourFormatBox);
		writeBoxToTilemap(hourFormatBox,3);
		drawText(hourFormatBox,1,1,5,boxPalData,0,hourFormatText);
		reloadBG(0);
		firstLoadClockImages();
		storeToSubRoutine(*(u8 *)(globalVars + 3),0,(void *) checkTimeLoop + 1);
		//clock card
		break;
	case 1:
		fillMapSpace(0,0,0,0xE,0x20,0x6);
		reloadBG(0);
		loadTilemapIntoBGSpace(1,pkgearmapMap,0,0);
		reloadBG(1);
		loadTilesIntoBGSpace(2,johtomapTiles,0,0,0);
		loadTilemapIntoBGSpace(2,johtomapMap,0,2);
		reloadBG(2);
		//map card
		break;
	case 2:
		loadTilemapIntoBGSpace(1,pkgearphoneMap,0,0);
		reloadBG(1);
		loadPalette(pkgearphonePal,0xA,0x8);
		prepTextSpace(0,0);
		loadNormalTextbox(0,1,callingText,0,1,0,0);
		writeBoxToTilemap(0,3);
		reloadBG(0);
		//phone card
		break;
	case 3:
		loadTilemapIntoBGSpace(1,pkgearmenuMap,0,0);
		reloadBG(1);
		loadPalette(pkgearradioPal,0xA,0x8);
		prepTextSpace(0,0);
		int FF = 0xFF;
		loadNormalTextbox(0,1,&FF,0,1,0,0);
		writeBoxToTilemap(0,3);
		reloadBG(0);
		//radio card
		break;
	case 4:
		//contest card?
		break;
	}
	previousCard = currentCardVal;
}

void unloadCard(int previousCardVal) {
	switch(previousCardVal) {
	case 0:
		clearTextbox(*(u8 *)(globalVars + 4));
		*(u8 *)(globalVars + 4) = 0;
		clearTextbox(*(u8 *)(globalVars + 5));
		*(u8 *)(globalVars + 5) = 0;
		for(int i=0;i<=0x5;i++) {
			clearOAM(*(u32 *)(getAllocdSubSpace(3) + ((i + 5) << 2)));
			*(u32 *)(getAllocdSubSpace(3) + ((i + 5) << 2)) = 0;
		}
		fillMapSpace(0,0,0,0,0x20,0xE);
		//clock card
		break;
	case 1:
		fillMapSpace(0,0,0,0,0x20,0x14);
		fillMapSpace(2,0,0,0,0x20,0x14);
		reloadBG(2);
		//map card
		break;
	case 2:
		fillMapSpace(0,0,0,0,0x20,0xE);
		//phone card
		break;
	case 3:
		fillMapSpace(0,0,0,0,0x20,0xE);
		//radio card
		break;
	case 4:
		//contest card?
		break;
	}
}

const u32 mapDataUnk[4] = { // first byte half = bg number, 2nd, 3rd, and 4th = 1st, 2nd, and 4th byte halves of BGXCNT
	0x000001F8, 0x000011C1, 0x000021D6, 0x000031E3
};

const u8 textboxData[12] = { //BG number, X pos, Y pos, width, height, palette slot, tile number (2 bytes); list terminator = 0xFF, 0x00, 0x00, 0x00
	0x00, 0x06, 0x0F, 0x17, 0x04, 0x0F, 0x94, 0x01,
	0xFF, 0x00, 0x00, 0x00
};

//1C7764
void loadGFXLoop(int loopTableNumber) {

	int *currentLoop = ((loopTableNumber * 0x28) + loopTableData + 4);
	
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
		int allocdSubSpace = getAllocdSubSpace(0);
		loadTilesIntoBGSpace(1,pkgearmenuTiles,0,2,0);
		createNewBGSpace(1,(allocdSubSpace));
		underloadPalette(pkgearmenuPal,0,0x60);
		(*currentLoop)++;
	}
	else if(*currentLoop == 3) {
		int allocdSubSpace = getAllocdSubSpace(1);
		loadTilesIntoBGSpace(3,pkgearbgTiles,0,0,0);
		createNewBGSpace(3,(allocdSubSpace));
		loadTilemapIntoBGSpace(3,pkgearbgMap,0,0);
		reloadBG(3);
		(*currentLoop)++;
	}
	else if(*currentLoop == 4) {
		int allocdSubSpace = getAllocdSubSpace(2);
		createNewBGSpace(2,(allocdSubSpace));
		(*currentLoop)++;
	}
	else if(*currentLoop == 5) {
		if (clearTempTileSpace() == 0) {
			textboxBGInit(textboxData);
			(*currentLoop)++;
		}
	}
	else if(*currentLoop == 6) {
		if (checkForSomethingIDunno() == 0) {
			if(checkFlag(0x130))
				config = config | 1;
			if(checkFlag(0x89B))
				config = config | (1 << 1);
			if(checkFlag(0x10C9))
				config = config | (1 << 2);
			loadSprites();
			*(u8 *)(globalVars + 3) = loopTableNumber;
			loadCard(0);
			
			fadeScreen(0xFFFFFFFF,0xFFFFFFFE,0x10,0,0x0000);
			enableBG(0);
			enableBG(1);
			enableBG(2);
			enableBG(3);
			(*currentLoop)++;
		}
	}
	else {
		loadStandardBoxBorders();
		(*currentLoop) = 0;
		*(int *)(loopTable + (loopTableNumber * 0x28)) = (void *) individualUpdate + 1;;
	}
}

void individualUpdate(int loopTableNumber) {
	int (*callRoutine)(int) = (int (*)(void))grabSubRoutine(loopTableNumber,0);
	callRoutine(loopTableNumber);
}

void checkTimeLoop(int loopTableNumber)
{
	if(*(u8 *)((loopTableNumber * 0x28) + loopTableData + 4) != *((u8 *) time + 2) || *(u8 *)((loopTableNumber * 0x28) + loopTableData + 6) != hourFormat) {
		for(int i=0;i<=0x5;i++) //load clock images
			checkTime(*(u32 *)(getAllocdSubSpace(3) + ((i + 5) << 2)),i);
		*(u8 *)((loopTableNumber * 0x28) + loopTableData + 4) = *((u8 *) time + 2);
		*(u8 *)((loopTableNumber * 0x28) + loopTableData + 6) = hourFormat;
	}
	if(*(u8 *)((loopTableNumber * 0x28) + loopTableData + 5) != dayOfWeek) {
		loadDayOfWeek();
		*(u8 *)((loopTableNumber * 0x28) + loopTableData + 5) = dayOfWeek;
	}
}

void checkTime(int spriteAddr, int i)
{
		int hour = *((u8 *) time);
		int AMPM;
		if(hourFormat == 0) {
			if(hour >= 12) {
				hour -= 12;
				AMPM = 1;
			} else
				AMPM = 0;
			if(hour == 0)
				hour = 12;
		} else AMPM = 2;
		int hourTop = divide(hour,10);
		int hourBottom = modulo(hour,10);
		int minutes = *((u8 *) time + 1);
		int minutesTop = divide(minutes,10);
		int minutesBottom = modulo(minutes,10);
		int seconds = *((u8 *) time + 2);
		int spriteNumber;
		if(i == 0) {
			if(hourTop != 0)
				spriteNumber = hourTop + 1;
			else
			spriteNumber = 0;
		}
		else if(i == 1)
			spriteNumber = hourBottom + 1;
		else if(i == 2)
			spriteNumber = (seconds & 1) + 11;
		else if(i == 3)
			spriteNumber = minutesTop + 1;
		else if(i == 4)
			spriteNumber = minutesBottom + 1;
		else
			spriteNumber = AMPM + 13;
		*((u16 *)spriteAddr + 0x2) = (spriteNumber << 0x2) + *((u16 *)spriteAddr + 0x20) + (*((u16 *)spriteAddr + 0x2) & 0xFC00);
}

void loadDayOfWeek()
{
	int dayOfWeekText = *(int *)((dayOfWeek << 2) + dayOfWeekTextTable);
	int size = getTextSizeInPixels(1,dayOfWeekText,0xFFFFFFFF);
	clearBoxSpace(*(u8 *)(globalVars + 4),0);
	drawText(*(u8 *)(globalVars + 4),1,(0x40 - size) >> 1,5,boxPalData,0,dayOfWeekText);
}

int getAllocdSubSpace(int sub)
{
	return *((int *)((globalVars + 0x10) + (sub << 2)));
}
	
int mallocSubSpace(int sub, int size)
{
	int *i = ((u8 *)(globalVars + 0x10 + (sub << 2)));
	*i = malloc(size);
	return *i;
}

const int spritePicData[4] = {
	pkgearbuttonsTiles, 0x00000E00, pkgearnumbersTiles, 0x00010880
};

const int spritePalTable[4] = {
	pkgearbuttonsPal, 0x00000000, 0x00000000, 0x00000000
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
	for(int i=0, address = &spritePicData;i<0x2;i++)
		loadMultipleSpriteFrames(address + (i<<0x3));
	loadSpritePalettesFromTable(spritePalTable);
	
	for(int i=0;i<=0x4;i++) { //load side icons
		int spriteAddr = createSprite(buttonData,0,((i << 0x5) + 0x10),0x0);
		*(u32 *)(getAllocdSubSpace(3) + (i << 2)) = spriteAddr;
		int spriteNumber;
		if(i == 0) {
			*((u16 *)spriteAddr + 0x10) = 0xFFF0;
			continue;
		}
		else if(i == 1) {
			if((config & 1) == 0)
				*((u8 *)spriteAddr + 0x3E) = *((u8 *)spriteAddr + 0x3E) | 4;
			spriteNumber = getCurrentRegion() + 1;
		} else if(i == 2)
			spriteNumber = i + 2;
		else if(i == 3) {
			if((config & (1 << 1)) == 0)
				*((u8 *)spriteAddr + 0x3E) = *((u8 *)spriteAddr + 0x3E) | 4;
			spriteNumber = i + 2;
		} else if(i == 4) {
			if((config & (1 << 2)) == 0)
				*((u8 *)spriteAddr + 0x3E) = *((u8 *)spriteAddr + 0x3E) | 4;
			spriteNumber = i + 2;
		}
		*((u16 *)spriteAddr + 0x2) = (spriteNumber << 0x4) + *((u16 *)spriteAddr + 0x2);
		*((u16 *)spriteAddr + 0x10) = 0xFFEC;
	}
}

const u32 OAMData2[2] = {
	0x40000000, 0x00000000
};

const u32 numberData[6] = {
	0x00000001, OAMData2, dummyAnimTable, 0x00000000,
	dummyAnimData, dummyAnimRoutine
};

const u8 clockX[6] = {
	108, 122, 130, 139, 153, 165
};

void firstLoadClockImages() {
	for(int i=0;i<=0x5;i++) { //load clock images
		int spriteAddr = createSprite(numberData,clockX[i],0x40,0x0);
		*(u32 *)(getAllocdSubSpace(3) + ((i + 5) << 2)) = spriteAddr;
		checkTime(spriteAddr,i);
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
