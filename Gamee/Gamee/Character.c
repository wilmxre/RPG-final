#include "Character.h"

//++++++++++++++++++++++++-----START-OF-CREATE-----++++++++++++++++++++++++//
Character* Create()
{
	////-------------------------\CHARACTER-------------------------//
	Character* character = malloc(sizeof(Character) * 1);

	if (!character) {
		printf("You ran out of memory!");
		exit(1);
	}
	//-------------------------CHARACTER/-------------------------////


	////-------------------------\CHARACTER NAME-------------------------//
	character->name = malloc(sizeof(char) * 30);

	if (!character->name) {
		printf("You ran out of memory!");
		exit(1);
	}

	printf(" Enter your character's name!\n\tName: "); 

	while (true) {
		fgets(character->name, 25, stdin);

		if (strlen(character->name) > 0 && character->name[strlen(character->name) - 1] == '\n')
			character->name[strlen(character->name) - 1] = '\0';

		int cntr = 0;
		for (int i = 0; i < strlen(character->name); i++) {
			if (isalpha(character->name[i]) != 0 || character->name[i] == 32) {
				cntr++;
			}
		}

		if (cntr == strlen(character->name))
			break;

		printf(" Your character's name has number in it! Please type only letters!\n");
		printf(" Enter your character's name!\n\tName: ");
	}

	system("cls");
	//-------------------------CHARACTER NAME/-------------------------////


	////-------------------------\CHARACTER JOB-------------------------//
	character->occupation = malloc(sizeof(char) * 30);

	if (!character->occupation) {
		printf("You ran out of memory!");
		exit(1);
	}

	printf(" Enter your character's job!\n\tJob: ");
	while (true) {
		fgets(character->occupation, 25, stdin);

		if (strlen(character->occupation) > 0 && character->occupation[strlen(character->occupation) - 1] == '\n')
			character->occupation[strlen(character->occupation) - 1] = '\0';

		int cntr_2 = 0;
		for (int i = 0; i < strlen(character->occupation); i++) {
			if (isalpha(character->occupation[i]) != 0 || character->occupation[i] == 32) {
				cntr_2++;
			}
		}

		if (cntr_2 == strlen(character->occupation))
			break;

		printf(" Your character's occupation has number in it! Please type only letters!\n");
		printf(" Enter your character's job!\n\tJob: ");
	}

	system("cls");
	//-------------------------CHARACTER JOB/-------------------------////


	////-------------------------\CHARACTER AGE-------------------------//
	character->age = 25; 

	printf(" Enter your character's age!\n\tAge: ");
	while (true) {
		scanf("%d", &character->age);

		if (character->age > 0 && character->age < 100)
			break;

		printf(" Please enter a valid age!\n\tAge: ");
	}
	system("cls");
	//-------------------------CHARACTER AGE/-------------------------////


	character->hp = 100;  //CHARACTER HP\\


	////-------------------------\CHARACTER GENDER-------------------------//
	character->gender = 1; 

	printf(" Enter your gender! If you are a man press 1, if a woman press 0\n\tGender: ");
	while (true) {
		scanf("%i", &character->gender);

		if (character->gender == 0 || character->gender == 1) {
			break;
		}

		printf(" Please enter a valid gender!\n\tGender: ");
	}

	system("cls");
	//-------------------------CHARACTER GENDER/-------------------------////


	dummy = malloc(sizeof(char));  //for some error

	character->pick = 0;

	return character;
}

//+++++++++++++++++++++++++-----END-OF-CREATE-----+++++++++++++++++++++++++//



////-------------------------\DESTROY CHARACTER-------------------------//
void* Destroy(Character* character)
{
	character->hp = 100;
	character->age = 25;
	character->gender = 1;
	character->pick = 0;
	free(character->name);
	free(character->occupation);
	free(character);
	free(dummy);
}
//-------------------------DESTROY CHARACTER/-------------------------////



////-------------------------\CREATE-OTHER-CHARACTERS-------------------------//
Character* CreateOthers() {

	Character** other_character;

	other_character = malloc(sizeof(Character*) * (TOT + 1)); // Do not cast malloc in C
	
	if (!other_character) {
		printf("You ran out of memory!");
		exit(1);
	}

	for (int i = 0; i <= TOT; i++) {
		other_character[i] = malloc(sizeof(Character) * 100);
		other_character[i]->name = malloc(sizeof(char) * 100);
		other_character[i]->occupation = malloc(sizeof(char) * 100);
	}


	for (int i = 0; i <= TOT; i++) {
		if (!other_character[i]) {
			printf("You ran out of memory!");
			exit(1);
		}

		if (!other_character[i]->name) {
			printf("You ran out of memory!");
			exit(1);
		}

		if (!other_character[i]->occupation) {
			printf("You ran out of memory!");
			exit(1);
		}
	}

	for (int i = 1; i <= TOT - 6; i++) {
		other_character[i]->age = rand() % 24 + 19;
		other_character[i]->gender = 1;
		other_character[i]->hp = 100;
		strcpy(other_character[i]->name, randomMale(i));
		strcpy(other_character[i]->occupation, randomJob());
		other_character[i]->pick = 0;
	}

	for (int i = TOT - 5; i <= TOT; i++) {
		other_character[i]->age = rand() % 20 + 18;
		other_character[i]->gender = 0;
		other_character[i]->hp = 100;
		strcpy(other_character[i]->name, randomFemale(i));
		strcpy(other_character[i]->occupation, randomJob());
		other_character[i]->pick = 0;
	}

	return other_character;
}
////-------------------------\CREATE-OTHER-CHARACTERS-------------------------//

void FreeOthers(Character** character) {
	for (int i = 0; i <= TOT; i++) {
		free(character[i]->occupation);
		free(character[i]->name);
		character[i]->age = 0;
		character[i]->gender = 0;
		character[i]->pick = 0;
		character[i]->hp = 0;
		free(character[i]);
	}
	free(character);
}

