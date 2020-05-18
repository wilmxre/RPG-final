#pragma once
#ifndef MENU_H
#define MENU_H

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include "Character.h"
#include <stdio.h>


void quit(); //exits from console
void TryAgain(Character* character); //tries again in case of wrong input
void Dummy(); //help for some error

#endif // !MENU_H

