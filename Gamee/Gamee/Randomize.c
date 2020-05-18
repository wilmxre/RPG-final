#include "Randomize.h"

char* pickRandomString(char* filename) {
	char line[L_SIZ][C_SIZ];
	FILE* file = NULL;
	
	file = fopen(filename, "r");
	if (!file) {
		printf("The file wasn't opened");
		exit(1);
	}

	int i = 0;
	while (fgets(line[i], sizeof(line[i]), file)) { 
		if (line[i][strlen(line[i]) - 1] == '\n')     /// replaces the new line with a null,
			line[i][strlen(line[i]) - 1] = 0;		  /// because of fgets
		i++;
	}

	return line[rand() % 100];
}


char* randomMale() {
	char* male_character = malloc(sizeof(char) * 35);
	strcpy(male_character, pickRandomString("names_m.txt"));
	return male_character;
}

char* randomFemale() {
	char* female_character = malloc(sizeof(char) * 35);
	strcpy(female_character, pickRandomString("names_f.txt"));
	return female_character;
}

char* randomJob() {
	char* job = malloc(sizeof(char) * 35);
	strcpy(job, pickRandomString("jobs.txt"));
	return job;
}

int randomEx(int ex, int mod) {
	int random = rand() % mod + 1;

	if (random == ex) {
		if ((random + 1) < mod)
			random++;
		else
			random--;
		return random;
	}

	else return random;
}
