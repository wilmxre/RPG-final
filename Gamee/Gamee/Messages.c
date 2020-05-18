#include "Character.h"
#include "Messages.h"
#include "Randomize.h"
#include "Mechanics.h"

int PICK = 0;
char* name = "";
int gender = 0;
int choice = 0;

void welcomeScreenBasic() {
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%-48s%s", " ", "  _|          _|              _|");
	printf("\n%-48s%s", " ", "  _|          _|     _|_|     _|     _|_|_|     _|_|     _|_|_|  _|_|       _|_|           _|_|_|_|     _|_|");
	printf("\n%-48s%s", " ", "  _|    _|    _|   _|_|_|_|   _|   _|         _|    _|   _|    _|    _|   _|_|_|_|           _|       _|    _|");
	printf("\n%-48s%s", " ", "    _|  _|  _|     _|         _|   _|         _|    _|   _|    _|    _|   _|                 _|       _|    _|");
	printf("\n%-48s%s\n\n\n\n", " ", "      _|  _|         _|_|_|   _|     _|_|_|     _|_|     _|    _|    _|     _|_|_|             _|_|     _|_|");

	printf("\n%-48s%s", " ", "    _|_|_|     _|_|     _|    _|   _|      _|   _|_|_|_|_|   _|_|_|       _|_|     _|          _|   _|      _|");
	printf("\n%-48s%s", " ", "  _|         _|    _|   _|    _|   _|_|    _|       _|       _|    _|   _|    _|   _|          _|   _|_|    _|");
	printf("\n%-48s%s", " ", "  _|         _|    _|   _|    _|   _|  _|  _|       _|       _|    _|   _|    _|   _|    _|    _|   _|  _|  _|");
	printf("\n%-48s%s", " ", "  _|         _|    _|   _|    _|   _|    _|_|       _|       _|    _|   _|    _|     _|  _|  _|     _|    _|_|");
	printf("\n%-48s%s", " ", "    _|_|_|     _|_|       _|_|     _|      _|       _|       _|_|_|       _|_|         _|  _|       _|      _|");

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	pressAny();
}

void welcomeScreen() {
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("%-24s%s", " ", "  _|          _|              _|");
	printf("\n%-24s%s", " ", "  _|          _|     _|_|     _|     _|_|_|     _|_|     _|_|_|  _|_|       _|_|           _|_|_|_|     _|_|");
	printf("\n%-24s%s", " ", "  _|    _|    _|   _|_|_|_|   _|   _|         _|    _|   _|    _|    _|   _|_|_|_|           _|       _|    _|");
	printf("\n%-24s%s", " ", "    _|  _|  _|     _|         _|   _|         _|    _|   _|    _|    _|   _|                 _|       _|    _|");
	printf("\n%-24s%s\n\n\n\n", " ", "      _|  _|         _|_|_|   _|     _|_|_|     _|_|     _|    _|    _|     _|_|_|             _|_|     _|_|");

	printf("\n%-24s%s", " ", "    _|_|_|     _|_|     _|    _|   _|      _|   _|_|_|_|_|   _|_|_|       _|_|     _|          _|   _|      _|");
	printf("\n%-24s%s", " ", "  _|         _|    _|   _|    _|   _|_|    _|       _|       _|    _|   _|    _|   _|          _|   _|_|    _|");
	printf("\n%-24s%s", " ", "  _|         _|    _|   _|    _|   _|  _|  _|       _|       _|    _|   _|    _|   _|    _|    _|   _|  _|  _|");
	printf("\n%-24s%s", " ", "  _|         _|    _|   _|    _|   _|    _|_|       _|       _|    _|   _|    _|     _|  _|  _|     _|    _|_|");
	printf("\n%-24s%s", " ", "    _|_|_|     _|_|       _|_|     _|      _|       _|       _|_|_|       _|_|         _|  _|       _|      _|");
	
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	pressAny();
}

void StartMessage() {
	printf(" Please maximize your console's screen for a better experience!");
	Sleep(3000);
	system("cls");
	welcomeScreen();
	//welcomeScreenBasic();      //// uncomment this and comment the line above this, if you have your basic console window settings on
	printf(" Before we start...");
	Sleep(2000);  //2000
	system("cls");
}

void PrintStats(Character* character)
{
	(character->gender == 1)

		? printf(" The character's info:\n\t======================\n\tName: %s\n\tAge: % i\n\tGender: male\n\tJob: % s", 
			character->name, character->age, character->occupation)
		: printf(" The character's info:\n\t======================\n\tName: %s\n\tAge: %i\n\tGender: female\n\tJob: %s",
			character->name, character->age, character->occupation);
	printf("\n\t======================");
	pressAny();
}

void PrintStatsOther(Character** character, int index)
{
	(character[index]->gender == 1)
		? printf(" The character's info:\n\t======================\n\tName: %s\n\tAge: % i\n\tGender: male\n\tJob: % s",
			character[index]->name, character[index]->age, character[index]->occupation)
		: printf(" The character's info:\n\t======================\n\tName: %s\n\tAge: %i\n\tGender: female\n\tJob: %s",
			character[index]->name, character[index]->age, character[index]->occupation);
	printf("\n\t======================");
	pressAny();
}


void Hello(Character* character)
{
	system("cls");
	printf(" Hello %s!\n Welcome to 'Le Hotel Paradis', probably the best place you've ever been to!"
		"\n This hotel takes place in one of the most inaccessible locations in the world, but i guarantee you, it'll be worth your time and money."
		"\n You'll leave this location with a huge satisfaction."
		" Or maybe you'll like this place so much, you won't even leave it any soon, hahaha.\n Buut anyways, let's talk about your accommodation.", character->name);
	pressAny();
		printf(" We have two free rooms for the night, please choose the one you would like to occupy.\n");
	printf(
			" The first room has a beautiful view to the sunset, but it will cost more."
			"\n The other one is a lot cheaper, but you'll have to share a room with another guest."
			"\n Which room would you like to take?"
	);
	putchar('\n');
	putchar('\n');
}

void killerShowYourself(Character** killer, int index) {
	printf(" THE KILLER WAS %s, index: %d!", killer[index]->name, index);
	pressAny();
}

void chooseRoom(Character** character) {
	printf(" Enter your choice!\n\t(0) Expensive\n\t(1) Cheap\n My pick: ");
	scanf("%d", &choice);
	while (true) {
		if (choice != 0 && choice != 1) {
			printf(" Please enter 0 or 1!");
			printf("\n\t(0) Expensive\n\t(1) Cheap\nMy pick: ");
			scanf("%d", &choice);
			system("cls");
		}
		else if (choice == 0) {
			system("cls");
			printf(" Alright then, it seems like you have a lot of money, huhh? \n It will cost you 50 gold for a night"
				", but i'm sure it will worth your money.\n Please go to the second floor and occupy Room %d.", rand() % 100);
			break;
		}
		else if (choice == 1) {
			PICK = 1;
			name = character[1]->name;
			gender = character[1]->gender;
			system("cls");
			 printf(" Don't worry about this room, it's nothing to be scared about!"
				"\n The thing is, the hotel is almost full with guests and all the cheap rooms are rented out.");
			if (character[1]->gender == 0){
				if (character[1]->age < 30) {
					printf("\n You'll share the room with Ms. %s.", character[1]->name);
				}
				else
					printf("\n You'll share the room with Miss. %s.", character[1]->name);
			}
			else
				printf("\n You'll share the room with Mr. %s.", character[1]->name);
			break;
		}

	}
	pressAny();
	
}

void firstNight(Character** character) {
	printf(" You are very hungry and go to the dining hall.\n It fascinates you what you see there and you get even more excited when you finally eat the delicacies."
		"\n After you finished eating, you go to the bar, talk to a few people and spend the time there for a few hours."
		"\n The night comes. Everybody leaves the bar and goes to their room.");
	
	if (PICK == 1) {
		printf("\n You met your roommate.\n");
		if (character[1]->gender == 1) {
			printf("\n %s seems like a nice person and he tells you funny stories to kill the time until you all go to sleep."
				"\n You also tell some things about yourself, he shows his interest and gets to know that you are a(n) %s."
				"\n He asks questions regarding that and you are happily giving him the answers."
				"\n You both earn each others trust and respect.", character[1]->name, character[0]->occupation);
		}
		else {
			printf("\n %s seems like a nice person and she tells you funny stories to kill the time until you all go to sleep."
				"\n You also tell some things about yourself, she shows her interest and gets to know that you are a(n) %s."
				"\n She asks questions regarding that and you are happily giving her the answers."
				"\n You both earn each others trust and respect.", character[1]->name, character[0]->occupation);
		}
	pressAny();
	printf(" At 4 A.M. almost everybody wakes up to a gruesome scream.\n After a few minutes everybody runs to the hall to find out what happened."
		"\n You get to the scene with %s and your face turns pale.\n The image is horrifying. Ever person in the staff is laying on the ground, motionless."
		"\n You are all shocked and speechless. Everybody is dead, without a doubt."
		"\n Finally a guest, named %s breaks the deadly silence and checks the lifeless bodies."
		"\n He confirms the unbelievable truth: noone has a pulse.", character[1]->name, character[5]->name);
	}
	else {
		printf(" You go to your room and immediatelly aim to your bed."
		"\n You are very tired, the way to the hotel was long and exhausting."
		"\n You try to sleep, but even though you are dog-tired you can't."
		"\n Finally you manage to fall asleep."
		" After one or two hours of sleeping you hear a noise and wake up. 'Maybe i was just dreaming', you think, and you fall asleep again.");
		pressAny();
		printf("At 4 A.M. almost everybody wakes up to a gruesome scream. After a few minutes everybody runs to the hall to find out what happened."
			"\n You get to the scene and your face turns pale. The image is horrifying. Ever person in the staff is laying on the ground, motionless."
			"\n You are all shocked and speechless. Everybody is dead, without a doubt."
			"\n Finally a guest, named %s breaks the deadly silence and checks the lifeless bodies."
			"\n He confirms the unbelievable truth: noone has a pulse.", character[5]->name);
	}
	pressAny();
}

void whatsNext() {
	printf(" You all just stand there, without realising what just happened. After a while, you start talking with each other."
			"\n After all the talk you all agree on some facts:\n"
			"\n\t%c  you are in the middle of nowhere, there's no way help will come soon"
			"\n\t%c  the killer is between the guests, without a doubt"
			"\n\t%c  nobody is safe anymore"
			"\n\t%c  you need to find the killer, before he picks his next victim", 254, 254, 254, 254);
	printf("\n\n You'll vote every night to find out who is the killer.\n If you think someone is suspicious or is acting strange, don't hesitate!");
	pressAny();
}

void credits() {
	system("cls");
	printf(" This game was made for a Data Structures and Algorithms project and it was written in C."
		   "\n\tCreated by wilmxre. Copyright 2020. All rights reserved.");
	Sleep(5000);
}