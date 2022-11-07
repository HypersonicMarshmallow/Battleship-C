/**************************************************************************
 * Assigned to: KL                                                        *
 * Created by: CD                                                         *
 * Compatibility and Assembly by: SM and CD                               *
 * Purpose: Board and Leaderboard Display for Battleship                  *
 * Date: 6 November 2021                                                  *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#define FLUSH myFlush()
#define ROW 10
#define COL 10
#define NOSHIPS 5

void displayBoard(char a[ROW][COL], Ship s[], int mCount, int leaderBoard[]);

void displayLeaders(int leaderBoard[])//self explanatory
{
	printf("\nOur Top 10 Leaders!\n");
	for (int i = 0; i < 10; i++) {
		printf("%i.%i\n", i + 1, leaderBoard[i]);
	}
}

void displayBoard(char a[ROW][COL], Ship s[], int mCount, int leaderBoard[])//self explanatory
{
	printf("\n---------------------------------------------------------------------------\n");
	printf("\n\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n\n"); //header of board
	int x, y; //x = row; y = column
	for (x = 0; x < ROW; x++) 
	{
		printf("\n%c\t", 'A' + x); // Populates the number value into a letter after A until A + 10
		for(y = 0; y < COL; y++)
		{
			printf("%c\t", a[x][y]); //
		}
	}
	printf("\n\n");
	printf("Missiles Fired: %i", mCount);
	printf("\n\n");
}
	


