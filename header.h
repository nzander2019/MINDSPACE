# ifndef MINDSPACE
# define MINDSPACE
# define _CRT_SECURE_NO_WARNINGS

# include <stdio.h>
# include <string.h>
# include <conio.h>
# include <time.h>

/*
Function: main
Date Created: February 22, 2020
Date Last Modified: February 23, 2020
Description: runs main program
Parameters: none
Returns: 0
*/
int main();
/*
Function: menu
Date Created: February 22, 2020
Date Last Modified: February 23, 2020
Description: displays menu and gets user selection, and chooses path
Paramters: none
Returns: select (integer from user input)
*/
int menu();
/*
Function: get_input
Date Created: February 22, 2020
Date Last Modified: February 22, 2020
Description: gets user input as a string, checks if exit key pressed
Parameters: char input[] (string)
Returns: none
*/
void get_input(char input[]);
/*
Function: clear_screen
Date Created: February 22, 2020
Date Last Modified: February 22, 2020
Description: prompts user to press key, then clears screen
Parameters: none
Returns: none
*/
void clear_screen();
/*
Function: instructions
Date Created: February 22, 2020
Date Last Modified: February 23, 2020
Description: displays instructions to the screen
Parameters: none
Returns: none
*/
void instructions();
/*
Function: begin_game
Date Created: February 22, 2020
Date Last Modified: February 23, 2020
Description: runs main body of the game
Paramters: none
Returns: none
*/
void begin_game();
/*
Function: open_inventory
Date Created: February 22, 2020
Date Last Modified: February 22, 2020
Description: if user types 'I', inventory contents will be displayed
Parameters: char inventory[] (array), char input[] (string)
Returns: none
*/
void open_inventory(char inventory[], char input[]);
/*
Function: check_inventory
Date Created: February 22, 2020
Date Last Modified: February 22, 2020
Description: checks inventory array to see if empty; if not empty, checks and displays contents
Parameters: char inventory[] (array)
Returns: none
*/
void check_inventory(char inventory[]);
/*
Function: face_direction
Date Created: February 22, 2020
Date Last Modified: February 22, 2020
Description: checks the direction the user has selected, provides description
Parameters: int north, int south, int east, int west, int candle (flags)
Returns: none
*/
void face_direction(int north, int south, int east, int west, int candle);

# endif
