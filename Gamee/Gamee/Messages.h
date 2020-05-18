#pragma once
#ifndef MESSAGES_H
#define MESSAGES_H

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#define TOT 15

#include <stdio.h>
#include <string.h>

void welcomeScreenBasic(); //ascii welcoming message
void welcomeScreen(); //same
void StartMessage(); //speaks for itself
void PrintStats(Character* character); // writes out the character's stats to the console
void PrintStatsOther(Character** character, int index); // writes out the other character's stats to the console
void Hello(Character* character); //---start
void killerShowYourself(Character** killer, int index); //speaks for itself
void chooseRoom(Character** character); //same
void firstNight(Character** character); //story time
void whatsNext(); //story continues
void credits(); //bragging about me

#endif // !MESSAGES_H

