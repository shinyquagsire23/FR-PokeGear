#define stationPokemon 8
#define stationMusic 14
#define stationLucky 16
#define stationBuena 20
#define stationUnown 26
#define stationSignal 40

#define musicPokedexShow 0x190
#define musicOaksTalk 0x201
#define musicLullaby 0x196
#define musicMarch 0x196
#define musicLucky 0x1AA
#define musicBuena 0x196
#define musicUnown 0x196
#define musicSignal 0x196
#define musicTakeover 0x1B0

const u8 oaksPkmnTalkText[14] = { // OAK's [Pk][Mn] Talk
    0xC9, 0xBB, 0xC5, 0xB4, 0xE7, 0x00, 0x53, 0x54, 0x00, 0xCE, 0xD5, 0xE0, 0xDF, 0xFF,
};

const u8 pokemonMusicText[14] = { // POKéMON Music
    0xCA, 0xC9, 0xC5, 0x1B, 0xC7, 0xC9, 0xC8, 0x00, 0xC7, 0xE9, 0xE7, 0xDD, 0xD7, 0xFF,
};

const u8 luckyChannelText[14] = { // Lucky Channel
    0xC6, 0xE9, 0xD7, 0xDF, 0xED, 0x00, 0xBD, 0xDC, 0xD5, 0xE2, 0xE2, 0xD9, 0xE0, 0xFF,
};

const u8 buenasPasswordText[17] = { // BUENA'S PASSWORD
    0xBC, 0xCF, 0xBF, 0xC8, 0xBB, 0xB4, 0xCD, 0x00, 0xCA, 0xBB, 0xCD, 0xCD, 0xD1, 0xC9, 0xCC, 0xBE, 0xFF,
};

const u8 pokedexShowText[13] = { // POKéDEX Show
    0xCA, 0xC9, 0xC5, 0x1B, 0xBE, 0xBF, 0xD2, 0x00, 0xCD, 0xDC, 0xE3, 0xEB, 0xFF,
};

const u8 questionMarksText[6] = { // ?????
    0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xFF,
};

void rocketRadio(){
	loadNormalTextbox(0,1,questionMarksText,0,1,0,0);
}

void oaksTalkRadio(){
	loadNormalTextbox(0,1,questionMarksText,0,1,0,0);
}

void pokedexShowRadio(){
	loadNormalTextbox(0,1,questionMarksText,0,1,0,0);
}

void lullabyRadio(){
	loadNormalTextbox(0,1,questionMarksText,0,1,0,0);
}

void marchRadio(){
	loadNormalTextbox(0,1,questionMarksText,0,1,0,0);
}

void luckyRadio(){
	loadNormalTextbox(0,1,questionMarksText,0,1,0,0);
}

void buenaRadio(){
	loadNormalTextbox(0,1,questionMarksText,0,1,0,0);
}

void unownRadio(){
	loadNormalTextbox(0,1,questionMarksText,0,1,0,0);
}

void signalRadio(){
	loadNormalTextbox(0,1,questionMarksText,0,1,0,0);
}

