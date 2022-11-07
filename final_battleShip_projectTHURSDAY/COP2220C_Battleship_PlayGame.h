/**************************************************************************
 * Assigned to: Michael Grimes                                            *
 * Created by: Michael Grimes                                             *
 * Compatibility and Assembly by: Suchir Moharil and Courtney DeTello     *
 * Purpose: Gameplay Processing for Battleship                            *
 * Date: 6 November 2021                                                  *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#define PAUSE system("pause")
#define FLUSH myFlush()
#define ROWS 10
#define COLS 10
#define CLS system("cls")

void endGame(int mCount, int leaderBoard[]);

void playGame(Ship ships[], char sB[BOARD_DIM][BOARD_DIM], char gB[BOARD_DIM][BOARD_DIM], int mCount, int leaderBoard[])
{
	int continueRun = 1;
	int missiles = mCount;
	displayLeaders(leaderBoard);
	PAUSE;
	do
	{
		CLS;
		displayBoard(gB, ships, missiles, leaderBoard);
		int r;
		int c;
		if (!((ships[0].floating) | (ships[1].floating) || (ships[2].floating) || (ships[3].floating) || (ships[4].floating))) //if all are "false" because of binary logic operations
		{
			continueRun = 0;
			endGame(missiles, leaderBoard);
			saveLeaderboard(leaderBoard);
			return;
		}
		continueRun = getChoice(&r, &c, missiles, ships, sB, gB, leaderBoard);
		if (!continueRun)
		{
			saveLeaderboard(leaderBoard);
			return;
		}
		if (gB[r][c] != '.') { //check if they have already fired here
			printf("\nAlready fired here!\n");
			PAUSE;
		}
		else {
			missiles++;
			if (sB[r][c] == '.') {
				gB[r][c] = 'M';
			}
			else {
				gB[r][c] = 'H';
				for (int x = 0; x < NUM_SHIPS; x++) //looping through ships
				{
					if (ships[x].letter == sB[r][c]) //seeing if they hit a ship
					{
						ships[x].hits += 1; //adding a count to the hits in the ship
						if (ships[x].holes == ships[x].hits) //checking if its still floating
						{
							ships[x].floating = 0; //ship has sunk
							int y, z;
							for (y = 0; y < ROWS; y++)
							{
								for (z = 0; z < COLS; z++)
								{
									if (sB[y][z] == ships[x].letter) //check ship location
									{
										gB[y][z] = ships[x].letter; //change H to ship letter for sunk ship
									}//end if
								}//end for
							}//end for
						}//end if	
					}//end if
				}//end for
			}//end else
		}//end else
	} while (continueRun);
}//end function

void endGame(int mCount, int leaderBoard[]){
	printf("Thanks for playing! Check out the leader board below!\n");
	printf("Your Score was %i.", mCount);
	leaderBoard[TOP] = mCount;// places current user score in last position
	for (int i = 0; i < TOP; i++) {
		if (leaderBoard[i] < 17 || leaderBoard[i] > ROWS*COLS) {//checks for impossible scores and sets them equal to maximum score
			leaderBoard[i] = ROWS*COLS;// prevents clutter in the leaderboard
		}
	}
	for(int i = 0; i < TOP; i++)
	{
		for (int j = 0; j < TOP - i; j++) 
		{
			if (leaderBoard[j] > leaderBoard[j + 1]) //bubble sorts the scores in leaderBoard
			{
				int temp = leaderBoard[j + 1];
				leaderBoard[j + 1] = leaderBoard[j];
				leaderBoard[j] = temp;
			}
		}
	}
	displayLeaders(leaderBoard);//displays all positions except last
}// We're in the Endgame now

