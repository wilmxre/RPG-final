#include "Menu.h"

void quit()
{
	char key;
	system("cls");
	printf(" press escape to quit\n\n");
	do {
		key = _getch();
		switch (key) {
			case 32:
				printf(" You pressed space, not ESCAPE", key);
				putchar('\n');
				break;
			case '\t':
				printf(" You pressed tab, not ESCAPE", key);
				putchar('\n');
				break;
			case 27:
				exit(0);
			case '\r':
				printf(" You pressed enter, not ESCAPE", key);
				putchar('\n');
				break;
			default:
				printf(" You pressed %c, not ESCAPE", key);
				putchar('\n');
		}
	} while (key != 27);
}

void TryAgain(Character* character)
{
	char answer;
	printf(" Are you happy with your character? Please type y or n\n\tAnswer: ");
	do {
		answer = _getch();
		switch (answer) {
		case 'y':
			return;
		case 'n':
			system("cls");
			printf(" You can start creating your character again!");
			Sleep(2000);
			system("cls");
			Destroy(character);
			Dummy();  //helps for reading the name again
			character = Create();
			PrintStats(character);
			TryAgain(character);
			break;
		default:
			printf("\n You've entered %c. Please enter y or n!\n\tAnswer: ", answer);
		}
	} while (answer != 'n');
}

void Dummy() { fgets(dummy, 2, stdin); }  //fgets puts a \n before reading, this one stores that \n
