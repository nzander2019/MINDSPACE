# include "header.h"

/*
Function: menu
Date Created: February 22, 2020
Date Last Modified: February 23, 2020
Description: displays menu and gets user selection, and chooses path
Paramters: none
Returns: select (integer from user input)
*/
int menu()
{
	int select = 0;


	printf("\n");
	printf(" ***      ***    *******   ****   ****    *******        *****     ******         **        *******    ********       \n");
	printf(" ****    ****      ***     *****  ****    ****   **    ***   **    ****  **     **  **     ****   **   ********       \n");
	printf(" **** ** ****      ***     **** * ****    ****   ***    ****       ****  **    **    **    ****        ***            \n");
	printf(" ****    ****      ***     ****  *****    ****   ***      ****     ******     *** ** ***   ****        *******        \n");
	printf(" ****    ****      ***     ****   ****    ****   **         ***    ****       ***    ***   ****        ***            \n");
	printf(" ****    ****      ***     ****   ****    ****   *      **  ***    ****       ***    ***   ****   **   ********       \n");
	printf(" ****    ****    *******   ****   ****    *******        *****     ****       ***    ***    *******    ********       \n");

	printf("\n\n 1) Instructions");
	printf("\n 2) Begin");
	printf("\n 3) Exit\n");

	scanf("%d", &select);

	switch (select)
	{
	case 1: // instructions
		instructions();
		break;
	case 2: // begin
		begin_game();
		break;
	case 3: // exit
		/*system("cls");*/
		printf("Thank you for playing.\n");
		exit(0);
		break;
	default:
		break;
	}
}

/*
Function: get_input
Date Created: February 22, 2020
Date Last Modified: February 22, 2020
Description: gets user input as a string, checks if exit key pressed
Parameters: char input[] (string)
Returns: none
*/
void get_input(char input[]) {
	fgets(input, 10, stdin);

	int i = strlen(input) - 1;
	if (input[i] == '\n')
		input[i] = '\0';

	char exit_key[10] = "Q";
	if (strcmp(input, exit_key) == 0)
	{
		printf("Thank you for playing.\n");
		exit(0);
	}
	clear_screen();
}

/*
Function: clear_screen
Date Created: February 22, 2020
Date Last Modified: February 22, 2020
Description: prompts user to press key, then clears screen
Parameters: none
Returns: none
*/
void clear_screen()
{
	printf("\n");
	system("pause");
	system("cls");
}

/*
Function: instructions
Date Created: February 22, 2020
Date Last Modified: February 23, 2020
Description: displays instructions to the screen
Parameters: none
Returns: none
*/
void instructions()
{
	system("cls");
	printf("Hello. Welcome to the game.\n");
	printf("You are alone, trapped in a room. You must seek a way out.\n");
	printf("You cannot see or hear anything. The only sense of reality you have is what I tell you.\n");
	printf("Therefore, trusting me is vital to your survival.\n");
	printf("\n\n");
	printf("Now.\n");
	printf("I will provide you with some hints before we begin.\n\n");
	printf("You must use keywords to interact with your environment. There are four directions in which you can move.\n");
	printf("Type 'face' to choose a direction of the room to face. You will then be prompted to select a direction, 'North', 'South', 'East', or 'West'.\n");
	printf("Type 'examine' to examine objects.\n");
	printf("Type 'take' to pick up objects and store them in your inventory.\n");
	printf("Type 'use' to utilize the objects you have in your inventory.\n");
	printf("\n\n");
	printf("Note: enter all commands and item names in lowercase (i.e. if you want to examine an item, type 'examine.'\n");
	printf("If you want to face North, enter 'north'.)\n\n");
	printf("Also, you may quit at any time by entering 'Q' and you may access your inventory by pressing 'I'.\n\n");
	printf("You are ready to begin.\n");
	system("pause");
	system("cls");
	printf("Oh, wait...\n");
	printf("One more thing: every action you take absorbs time. If you run out of time, you lose.\n\n");
	printf("Enjoy the game.\n");
	system("pause");
	system("cls");
	menu();
}

/*
Function: begin_game
Date Created: February 22, 2020
Date Last Modified: February 23, 2020
Description: runs main body of the game
Paramters: none
Returns: none
*/
void begin_game()
{
	char select, discard;
	
	// inventory
	char inventory[10] = "\0";

	// command and item variables

	// commands
	char examine[10] = "examine", face[10] = "face", use[10] = "use",
		take[10] = "take";
	// South items
	char candle[10] = "candle", book[10] = "book";
	// directions
	char str2[10] = "", north[10] = "north", south[10] = "south", east[10] = "east", west[10] = "west", exit_key[10] = "Q";
	// North items
	char door[10] = "door", padlock[10] = "padlock";
	// West items
	char key[10] = "key", painting[10] = "painting", eyes[10] = "eyes"; 
	// East items
	char safe[10] = "safe", keypad[10] = "keypad",
		ans[10] = "1234", tape[10] = "tape";

	int complete = 0;
	int N = 0, E = 0, S = 1, W = 0,
		take_candle = 0, take_key = 0, take_tape = 0, safe_unlock = 0, i = 0, loop = 0;

	// opening description
	printf("\n");
	system("cls");
	printf("You wake up in an unfamiliar space.");
	printf("\nThe room is dark.\n\n");
	scanf("%c", &discard);

	// actual gameplay; will loop until player solves room or time runs out
	while (complete != 1) 
	{
		// user makes command selection
		face_direction(N, S, E, W, take_candle);
		printf("Do you want to examine [an item], face [a direction], use [an item] or take [an item]?\n");
		get_input(str2);

		// check inventory
		open_inventory(inventory, str2);

		// EXAMINE FUNCTIONS
		if (strcmp(examine, str2) == 0)
		{
			// getting item to examine
			face_direction(N, S, E, W, take_candle);
			printf("What do you want to examine? \n");
			get_input(str2);
			open_inventory(inventory, str2);

			// examine without candle, must be in inventory
			if ((S == 0) && take_candle != 1)
			{
				printf("It's too dark to see anything.");
			}
			// south
			else if (S == 1) {
				// examine candle
				if ((strcmp(candle, str2) == 0) && (take_candle != 1)) {
					printf("There's a lit candle on the table. It smells like vanilla.");
					loop++;
				}
				// examine book
				else if (strcmp(book, str2) == 0) {
					printf("There's a book. You look inside and it says: 1 0 0 1 1 0 1 0 0 1 0.\n");
					printf("Below the numbers, a crude drawing of a keypad is shown.\n");
					loop++;
				}
				// invalid input
				else
					printf("There is no %s on the table.", str2);
			}
			// north 
			else if (N == 1)
			{
				// examine door
				if ((strcmp(door, str2)) == 0)
				{
					printf("There's a door with a padlock.");
					loop++;
				}
				// examine padlock
				if (strcmp(padlock, str2) == 0)
				{
					printf("On the doorknob, there's a padlock.\n");
					if (take_key == 0)
						printf("It looks like it needs a key.");
					loop++;
				}
			}
			// east
			else if (E == 1)
			{
				// examine safe (safe opened)
				if ((strcmp(safe, str2) == 0) && (safe_unlock != 0)) {
					printf("In the safe, a letter reads:\n");
					printf("Blind the window to the soul.\n");
					if (take_tape == 0) {
						printf("At a closer look, you see a roll of duct tape.");
					}
					loop++;
				}
				// examine safe
				else if (strcmp(safe, str2) == 0) {
					printf("There's a safe with a keypad.");
					loop++;
				}
				// examine keypad
				if (strcmp(keypad, str2) == 0) {
					printf("It looks like the keypad can be used.\n");
					loop++;
				}
			}
			// west
			else if (W == 1)
			{
				// examine painting
				if ((strcmp(painting, str2) == 0) && (safe_unlock != 0)) {
					printf("It's a painting of a beautiful lady.\n");
					printf("Her eyes bore into your own.\n");
					printf("...\n");
					printf("Upon closer inspection, you notice four Roman numerals in each corner of the painting: I, II, III, and IV\n");
					loop++;
				}
				// examine key
				if (strcmp(key, str2) == 0 && take_tape == 3)
				{
					printf("It looks like it would fit in a padlock.\n");
					loop++;
				}
			}
			clear_screen();
		}

		// FACE FUNCTIONS
		if (strcmp(face, str2) == 0)
		{
			// get direction
			printf("Where do you want to face? (north/south/east/west)\n");
			get_input(str2);
			open_inventory(inventory, str2);

			// north
			if (strcmp(north, str2) == 0) {
				N = 1;
				S = 0;
				E = 0;
				W = 0;
				loop++;
			}
			// south
			else if (strcmp(south, str2) == 0) {
				N = 0;
				S = 1;
				E = 0;
				W = 0;
				loop++;
			}
			// east
			else if (strcmp(east, str2) == 0) {
				N = 0;
				S = 0;
				E = 1;
				W = 0;
				loop++;
			}
			// west
			else if (strcmp(west, str2) == 0) {
				N = 0;
				S = 0;
				E = 0;
				W = 1;
				loop++;
			}
		}

		// USE SECTION
		if (strcmp(use, str2) == 0)
		{
			// get item to use
			face_direction(N, S, E, W, take_candle);
			printf("What do you want to use?\n");
			get_input(str2);

			// east
			if (E == 1)
			{
				// use keypad
				if (strcmp(keypad, str2) == 0) {
					printf("Enter a four digit number code.\n");
					get_input(str2);
					if (strcmp(ans, str2) == 0) {
						printf("You hear the safe unclick.\n");
						safe_unlock = 1;
						loop++;
					}
				}
			}
			// west
			if (W == 1)
			{
				// use tape
				if ((take_tape == 1) && (strcmp(tape, str2) == 0)) {
					printf("What part of the woman's face do you put the tape over?\n");
					get_input(str2);
					if ((strcmp(eyes, str2) == 0)) {
						take_tape = 3;
						i--;
						inventory[i] = "\0";
						printf("The painting shakes. You see a key fall out from behind it.\n");
						loop++;
					}
				}
			}
			// north
			if (N == 1)
			{
				// use key (END GAME)
				if (take_key == 1 && strcmp(key, str2) == 0) {

					take_key = 3;
					i--;
					inventory[i] = "\0";
					printf("Congratulations. May we meet again.\n");
					complete = 1;
					clear_screen();
				}
			}
		}

		// TAKE FUNCTIONS
		if (strcmp(take, str2) == 0)
		{
			// get item to take
			face_direction(N, S, E, W, take_candle);
			printf("What do you want to take?\n");
			get_input(str2);
			open_inventory(inventory, str2);

			// try to take without candle in inventory
			if ((S == 0) && take_candle != 1)
			{
				printf("It's too dark to see anything.");
			}
			// south
			else if (S == 1) 
			{
				// take candle
				if (strcmp(candle, str2) == 0 && take_candle == 0) {

					printf("You have taken the candle from the table.\n");
					take_candle = 1;
					inventory[i] = 'c';
					i++;
					loop++;
				}
				// take book (attempt)
				if (strcmp(book, str2) == 0)
				{
					printf("You cannot take the book from the table.\n");
				}
			}
			// west
			else if (W == 1)
			{
				// take key
				if ((take_tape == 3) && strcmp(key, str2) == 0 && (take_key == 0)) {

					printf("You have taken the key.\n");
					take_key = 1;
					inventory[i] = 'k';
					i++;
					loop++;
				}
				// invalid option
				else
					printf("You cannot take %s.\n", str2);
			}
			// east
			else if (E == 1) {
				// take tape
				if ((take_tape == 0) && (strcmp(tape, str2) == 0)) {

					printf("You have taken the tape.\n");
					take_tape = 1;
					inventory[i] = 't';
					i++;
					loop++;
				}
				// invalid option
				else
					printf("You cannot take %s.\n", str2);
			}
			clear_screen();
		}

		// time lapsing
		if (loop == 15)
		{
			printf("Your candle is halfway melted.\n");
		}
		if (loop == 25)
		{
			printf("Your candle begins to flicker.\n");
			printf("\n\nTime is running out...\n\n");
			clear_screen();
		}
		if (loop == 30)
		{
			printf("Your time has run out.\n");
			exit(0);
		}
	}
}

/*
Function: open_inventory
Date Created: February 22, 2020
Date Last Modified: February 22, 2020
Description: if user types 'I', inventory contents will be displayed
Parameters: char inventory[] (array), char input[] (string)
Returns: none
*/
void open_inventory(char inventory[], char input[])
{
	if (strcmp(input, "I") == 0)
	{
		check_inventory(inventory);
	}
}

/*
Function: check_inventory
Date Created: February 22, 2020
Date Last Modified: February 22, 2020
Description: checks inventory array to see if empty; if not empty, checks and displays contents
Parameters: char inventory[] (array)
Returns: none
*/
void check_inventory(char inventory[])
{
	int empty = 0;
	for (int i = 0; i < 10; i++)
	{
		if (inventory[i] == 'c')
		{
			printf("You have a candle in your inventory.\n");
			empty = 1;
		}
		if (inventory[i] == 'k')
		{
			printf("You have a key in your inventory.\n");
			empty = 1;
		}
		if (inventory[i] == 't')
		{
			printf("You have tape in your inventory.\n");
			empty = 1;
		}
	}
	if (empty == 0)
	{
		printf("Your inventory is empty.\n");
	}
}

/*
Function: face_direction
Date Created: February 22, 2020
Date Last Modified: February 22, 2020
Description: checks the direction the user has selected, provides description
Parameters: int north, int south, int east, int west, int candle (flags)
Returns: none
*/
void face_direction(int north, int south, int east, int west, int candle)
{
	if (north == 1 && candle == 1) {
		printf("You are facing North and see a door with a padlock.");
	}
	else if (north == 1) {
		printf("You're facing North, but it's too dark to see anything.");
	}
	else if (south == 1 && candle == 1) {
		printf("You are facing South and see a table with a book.");
	}
	else if (south == 1)
	{
		printf("You are facing South and see a table with a candle and a book.");
	}
	else if (east == 1 && candle == 1) {
		printf("You are facing East and see a safe.");
	}
	else if (east == 1) {
		printf("You're facing East, but it's too dark to see anything.");
	}
	else if (west == 1 && candle == 1) {
		printf("You are facing West and see a painting on the wall.");
	}
	else if (west == 1) {
		printf("You're facing West, but it's too dark to see anything.");
	}
	printf("\n");
}





