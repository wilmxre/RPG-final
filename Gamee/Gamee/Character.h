#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

static int TOT = 15;

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <ctype.h>

typedef struct Character {
	char* name;
	int age;
	char* occupation;
	int hp;
	int gender;
	int pick;
}Character;

char* dummy;

Character* Create(); //creates the user
void* Destroy(Character* character); //destroys the user
Character* CreateOthers(); //creates the other characters
void FreeOthers(Character** character); // destroys all characters


#endif // !CHARACTER_H