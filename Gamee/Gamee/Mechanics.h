#pragma once
#ifndef MECHANICS_H
#define MECHANICS_H

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include "Character.h"

void pressAny();
void meetTheCharacters(Character** character); //presenting the characters
void nameNR(Character** character); //showng the names and their number
void showHP(Character** character); //showing the hp
void voting(Character** character, int kil_nr);  //voting for the suspect
Character** removeIfDead(Character** character, int index); //removing character when dead
void kill(Character** character, int kil_nr); //kill character on index

#endif // !MECHANICS_H
