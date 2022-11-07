/************************************************************
 * Assigned to: CD                                          *
 * Created by: CD                                           *
 * Compatibility and Assembly by: CD                        *
 * Purpose: Get User Input for Battleship                   *
 * Date: 6 November 2021                                    *
 ************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#define PAUSE system("pause")
#define FLUSH myFlush()
#define ROWS 10
#define COLS 10

int getChoice(int* row, int* column, int mCount, Ship ships[], char sB[][COL], char gB[][COL], int leader[]);
int quitGame(int row, int column, int mCount, Ship ships[], char sB[][COL], char gB[][COL], int leader[]);
void saveGame(int mCount, Ship ships[], char sB[][COLS], char gB[][COLS]);
void saveLeaderboard(int leaderBoard[TOP+1]);
void myFlush();

int getChoice(int *row, int *column, int mCount, Ship ships[], char sB[][COL], char gB[][COL], int leader[]) //bringing in int by referrence
{
	char r, c;
	char badEntry = 'Y';
	do
	{
		printf("Enter a row letter (A-J) and a column number(0-9), or type QQ to quit: ");
		scanf("%c%c", &r ,&c); //get the users input and make it uppercase // cannot do in scanf
		FLUSH;
		r = toupper(r);
		c = toupper(c);
		badEntry = 'N'; //assuming the entry is valid
		switch(r) //
		{
				case 'A':
					*row = 0;
					break;
				case 'B':
					*row = 1;
					break;
				case 'C':
					*row = 2;
					break;
				case 'D':
					*row = 3;
					break;
				case 'E':
					*row = 4;
					break;
				case 'F':
					*row = 5;
					break;
				case 'G':
					*row = 6;
					break;
				case 'H':
					*row = 7;
					break;
				case 'I':
					*row = 8;
					break;
				case 'J':
					*row = 9;
					break;
				case 'Q':
					*row = -1;//what value should this be?
					break;
				default: //? not sure what to put here - need to check the user enteres a letter. need this for Row and Column
					//printf("Invalid entry - Must be a letter between A-J or Q to quit");
					badEntry = 'Y';
					break;
				}
				//*row = r-'A';
			switch(c)
			{
				case '0':
					*column = 0;
					break;
				case '1':
					*column = 1;
					break;
				case '2':
					*column = 2;
					break;
				case '3':
					*column = 3;
					break;
				case '4':
					*column = 4;
					break;
				case '5':
					*column = 5;
					break;
				case '6':
					*column = 6;
					break;
				case '7':
					*column = 7;
					break;
				case '8':
					*column = 8;
					break;
				case '9':
					*column = 9;
					break;
				case 'Q':
					*column = -1; //what value should this be?
					break;
				default: //? not sure what to put here - need to check the user enteres a letter. need this for Row and Column
					//printf("Invalid entry - Must be a letter between A-J or Q to quit");
					break;
					
		    }//end switch
		    if((*row == -1 && *column != -1) || (*row != -1 && *column == -1)){ 
				printf("Invalid entry - Must be a letter A-J with a number 0-9 or QQ to quit\n");
				PAUSE;
				badEntry = 'Y';
			}
		    
	}while(badEntry == 'Y');
	int cont = quitGame(*row, *column, mCount, ships, sB, gB, leader);
	return cont;
	    
}

int quitGame(int row, int column, int mCount, Ship ships[], char sB[][COL], char gB[][COL], int leader[]) //pass everything to save for save function
{
	if(row != -1 && column != -1)
	{
		//printf("%i and %i", row, column); //debugging purposes only
		return 1;
	}
	else
	{
		printf("thanks for playing.");
		saveGame(mCount, ships, sB, gB);
		return 0;
	}
}
void myFlush() //clears keyboard cache
{
	while (getchar() != '\n');
}

