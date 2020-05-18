#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>

#include "Character.h"
#include "Messages.h"
#include "Menu.h"
#include "Randomize.h"
#include "Mechanics.h"


int main() {
	srand(time(0));
	int kil_nr = 0;

	////-----ACTUAL START-----//
	StartMessage();
	Character* user = Create();
	PrintStats(user);
	TryAgain(user);
	Character** character = CreateOthers(); 
	character[0] = user;
	kil_nr = randomEx(0, TOT);
	Hello(user);
	chooseRoom(character, character[1]);
	firstNight(character);
	whatsNext();
	meetTheCharacters(character);
	voting(character, kil_nr);
	credits();
	quit();
	//---------END--------///	

	return 0;
}