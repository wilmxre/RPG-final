#pragma once
#ifndef RANDOMIZE_H
#define RANDOMIZE_H
#define _GNU_SOURCE

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#define C_SIZ 25 //max number of characters in line
#define L_SIZ 100 //number of lines in text


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

#include "Character.h"

char* pickRandomString(char* filename); //random function for selecting a line from a file
char* randomMale(); //select male name from file
char* randomFemale(); //select female name from file
char* randomJob(); //select job from file
int randomEx(int ex, int mod); //generate random given a range and excluding a number

#endif
