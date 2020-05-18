#include "Mechanics.h"
#include "Messages.h"
#include "Randomize.h"
#include "Menu.h"

int size = TOT;
bool is_it = false;
extern int choice;

void pressAny() {
	putchar('\n');
	putchar('\n');
	printf(" Press any key to continue...");
	_getch();
	system("cls");
}

void meetTheCharacters(Character** character)
{
	system("cls");
	printf(" But before everything starts, let me introduce you the other guests. This is what everybody told about themselves.\n\n%-2s%-29s%-27s%s"," ", "NAME:", "OCCUPATION:", "RESIDENCE:");
	putchar('\n');
	putchar('\n');

	for (int i = 1; i <= size; i++) {
		if (character[i]->gender == 1) {
			printf("  %c  Mr. %-22s%-26s Room .|%d|.\n", 254, character[i]->name, character[i]->occupation, 1 + rand() % 90 + 10);
		}
		else if (character[i]->age < 27) {
			printf("  %c  Miss %-21s%-26s Room .|%d|.\n", 254, character[i]->name, character[i]->occupation, 1 + rand() % 90 + 10);
		}
		else {
			printf("  %c  Ms. %-22s%-26s Room .|%d|.\n", 254, character[i]->name, character[i]->occupation, 1 + rand() % 90 + 10);
		}
	}
	pressAny();
}

void nameNR(Character** character) {
	for (int i = 1; i <= size; i++) {
		if (character[i]->gender == 1) {
			printf("  %c  Mr. %-22s<%d>\n", 254, character[i]->name, i);
		}
		else if (character[i]->age < 27) {
			printf("  %c  Miss %-21s<%d>\n", 254, character[i]->name, i);
		}
		else {
			printf("  %c  Ms. %-22s<%d>\n", 254, character[i]->name, i);
		}
	}
}

void showHP(Character** character) {
	printf("Now let's see how many HP does each of you have.\n\n");
	printf("  %-28s%-4s\n\n", "NAME:", "HP:");
	for (int i = 0; i <= size; i++) {
		printf("  %c  %-25s%-4d%%", 254, character[i]->name, character[i]->hp);
		putchar('\n');
	}
	pressAny();
}

void voting(Character** character, int kil_nr)
{
	int nokill = 0;
	int pick_array[TOT+1] = { 0 };
	int pick = 0;
	int max = INT_MIN;
	int itsyou = 0;
	int day = 0;
	int mid = 0;
	mid = size / 2;
	int tempp = 0;

	printf(" So here comes the voting. Pick carefully and good luck on finding the killer. The sooner, the better!"
			"\n Everybody starts out with 100 HP. If you don't pick the right person, you'll lose 10 HP."
			"\n If you HP drops below 60, you'll end up losing 15 HP after every wrong pick.\n So open your eyes, and find the killer quickly!"
			"\n\n If there are enough votes on the same person, that person will die. Plain and simple."
			"\n You have to take the risk, so if no more killing will happen after you killed the suspect, you killed the killer.\n");

	while (size >= 3) {  //voting lasts until killer was found, you died or you, another guest and the killer is left
		//printf(" killer: %s\n", character[kil_nr]->name); 

		if (size == mid) {
			printf(" Things are getting out of control. Do you want to end everything here and run away?\n Press 5 if yes. ");
			scanf("%d", &tempp);
			if (tempp == 5) {
				printf("\n You ran away. Goodbye!\n");
				pressAny();
				return 0;
			}
			system("cls");
		}

		printf("\n It's time for the voting!\n");
		printf(" Please type the number next to the suspected character, then press ENTER!\n\n");
		nameNR(character);
		printf("\n I think the killer is character number ");
		scanf("%d", &character[0]->pick);
		//_getch();
		system("cls");

		printf("  %-29s%-25s%s\n\n", "NAME:", "PICK:", "NR:");
		printf("  %c  %-24s->%-25s<%d>\n", 254, character[0]->name, character[character[0]->pick]->name, character[0]->pick);

		//whenToKill(character);

				for (int i = 1; i <= size; i++) {
					pick = randomEx(i, size);
					character[i]->pick = pick;
					if (choice == 1) {
						character[1]->pick = character[0]->pick;
						if (kil_nr == 1) {
							kil_nr = randomEx(1, TOT);
						}
					}
					pick_array[pick]++;
					printf("  %c  %-24s->%-25s<%d>\n", 254, character[i]->name, character[character[i]->pick]->name, character[i]->pick);
				}
				pick_array[character[0]->pick]++;
				if (choice == 1) {
					pick_array[character[1]->pick]++;
				} 
				printf("\n The votes are in!\n\n");
				printf("  %-27s%s\n\n", "NAME:", "VOTES:");
				for (int i = 0; i <= size; i++) {
					if (pick_array[i] > 0) {
						printf("  %c  %-24s.[%d].\n", 254, character[i]->name, pick_array[i]);
					}
				}
				//_getch();
				for (int i = 0; i <= size; i++) {
					if (pick_array[i] > max) {
						max = pick_array[i];
						itsyou = i;
					}
				}

				printf("\n The most voted person is %s with %d votes.\n", character[itsyou]->name, max); //_getch();

				if (max >= size / 3 + 1) { /////////30% + 1 votes
					if (itsyou == kil_nr) {
						printf(" Congratulations! You've killed the killer!\n It was %s all along.", character[kil_nr]->name);
						pressAny();
						return;
					}
					nokill = 1;
					printf("\n You voted %s out with %d votes.\n", character[itsyou]->name, max);
					character[itsyou]->hp = 0;
					removeIfDead(character, itsyou);
				}
				else printf("\n Unfortunately, there weren't enough votes! You couldn't decide, let's see what will happen this night.");

				////----Reset----//
				for (int i = 0; i <= size; i++) {
					pick_array[i] = 0;
				}
				max = INT_MIN;
				pick = 0;
				itsyou = 0;
				//----Reset----////


				for (int i = 0; i <= size; i++) {
					if (!(character[i]->pick == kil_nr) && character[i]->hp >= 60) {
						character[i]->hp -= 10;
					}
					else if (!(character[i]->pick == kil_nr) && character[i]->hp < 60) {
						character[i]->hp -= 15;
					}

					if (character[0]->hp <= 0) {
						printf(" Your hp decreased to 0. You are dead."
							"\n GAME OVER!");
						return;
					}

					character = removeIfDead(character, i);
				}

				if (character[kil_nr]-> hp <= 0) {
					printf(" Congratulations! You've killed the killer!\n It was %s all along.", character[kil_nr]->name);
					pressAny();
					return;
				}

		pressAny();
		showHP(character);

		printf(" You still didn't find the killer. Let's try it again.\n\n");
		if (nokill == 0) {
			printf(" Day %d has come. The killer had another victim this night.\n", ++day);
			kill(character, kil_nr);
		}
		nokill = 0;
	}

	//pressAny();
	//system("cls");
	////FreeOthers(character);
	//credits();
	//quit();
}


Character** removeIfDead(Character** character, int index) {
	if (character[index]->hp <= 0) {
		printf(" Unfortunately %s has DIED!\n", character[index]->name);
		character[index] = character[size--];
	}
	return character;
}


void kill(Character** character, int kil_nr) {
	int pick = 1;
	int temp = 0;
	while (true) {
		pick = randomEx(kil_nr, size);
		if (character[kil_nr]->hp > 0) {
			temp = character[pick]->hp;
			character[pick]->hp = 0;
			if (pick != 0)
				break;
			character[pick]->hp = temp;
		}
	}
	removeIfDead(character, pick);
}
