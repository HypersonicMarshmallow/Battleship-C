/************************************************************
 * Assigned to: SM                                          *
 * Created by: SM                                           *
 * Compatibility and Assembly by: SM                        *
 * Purpose: Main Method and Randomizer for Battleship       *
 * Date: 6 November 2021                                    *
 ************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define BOARD_DIM 10
#define NUM_SHIPS 5
#define PAUSE system("pause")
#define FLUSH myFlush()
#define ROWS 10
#define COLS 10
#define TOP 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "COP2220C_Battleship_Randomizer.h"
#include "COP2220C_Battleship_DisplayBoard.h"
#include "COP2220C_Battleship_GetUserChoice.h"
#include "COP2220C_Battleship_PlayGame.h"
#include "COP2220C_Battleship_SaveGame.h"

int main() {
	int mCount = 0;
    int leaderBoard[TOP+1];
    readLeaderboard(&leaderBoard);
	srand(time(0));
	char shipBoard[BOARD_DIM][BOARD_DIM];
    char userBoard[BOARD_DIM][BOARD_DIM];
    Ship shipList[NUM_SHIPS];
    printf("\n================Welcome to Battleship!====================\n");
	char gameWasReloaded = reloadGame(&mCount, shipList, shipBoard, userBoard, leaderBoard);
    if(gameWasReloaded != 'Y') //if they dont want to reload previous game
	{
		initializeBoard(shipBoard);
	    initializeBoard(userBoard);
	    populateStruct(shipList);
	    placeShips(shipList, shipBoard);
	}//up top this point is all setup
	playGame(shipList, shipBoard, userBoard, mCount, leaderBoard);//actual gameplay
}

void initializeBoard(char board[BOARD_DIM][BOARD_DIM]) {//board setup
    for (int i = 0; i < BOARD_DIM; i++) {
        for (int j = 0; j < BOARD_DIM; j++) {
            board[i][j] = '.';
        }//end inner for
    }//end outer for
}//end initializeBoard

void populateStruct(Ship list[]) {//struct setup
    list[0].letter = 'B';
    list[1].letter = 'S';
    list[2].letter = 'R';
    list[3].letter = 'V';
    list[4].letter = 'G';
    list[0].holes = 2;
    list[1].holes = 3;
    list[2].holes = 3;
    list[3].holes = 4;
    list[4].holes = 5;
    for (int i = 0; i < NUM_SHIPS; i++) {
        list[i].hits = 0;
    }
    for (int i = 0; i < NUM_SHIPS; i++) {
        list[i].floating = 1;
    }
}

void printBoard(char board[BOARD_DIM][BOARD_DIM]) {//function created for testing purposes
    for (int i = 0; i < BOARD_DIM; i++) {
        printf("\n");
        for (int j = 0; j < BOARD_DIM; j++) {
            printf("%c", board[i][j]);
        }//end inner for
    }//end outer for
}//end printBoard

int randomizeRow() {//randomizes start row for ship
    int rowStart = rnGesus(0, BOARD_DIM - 1);
    return rowStart;
}//end randomizeRow

int randomizeColumn() {//randomizes start column for ship
    int colStart = rnGesus(0, BOARD_DIM - 1);
    return colStart;
}//end randomizeColumn

int randomizeDirection() {//randomizes check direction for ship
    int direction = rnGesus(0, 3);
    return direction;
}//end randomizeDirection

void placeShips(Ship list[], char board[BOARD_DIM][BOARD_DIM]) {
	for (int i = 0; i < NUM_SHIPS; i++) {
        int invalid = 1;
        int row;
        int col;
        int dir; //declares row, col, and dir
        while (invalid) {
            row = rnGesus(0, 9);
            col = rnGesus(0, 9);
            dir = rnGesus(0, 3);
            for (int j = 0; j < list[i].holes; j++) {
                switch (dir) {
                    case DIR_RIGHT://checks to the right direction
                        if (board[row][col + j] == '.' && (col + list[i].holes < BOARD_DIM)) {
                            invalid = 0;
                        }
                        else {
                            invalid = 1;
                            j = list[i].holes;//terminates for loop
                        }
                        break;
                    case DIR_DOWN://checks to the down direction
                        if (board[row+j][col] == '.' && (row + list[i].holes < BOARD_DIM)) {
                            invalid = 0;
                        }
                        else {
                            invalid = 1;
                            j = list[i].holes;
                        }
                        break;
                    case DIR_LEFT://checks to the left direction
                        if (board[row][col - j] == '.' && (col - list[i].holes >= 0)) {
                            invalid = 0;
                        }
                        else {
                            invalid = 1;
                            j = list[i].holes;
                        }
                        break;
                    case DIR_UP://checks to the up direction
                        if (board[row-j][col] == '.' && (row - list[i].holes >= 0)) {
                            invalid = 0;
                        }
                        else {
                            invalid = 1;
                            j = list[i].holes;
                        }
                        break;
                    default: 
                        break;
                }//end switch
            }//end for
        }//end while
        for (int l = 0; l < list[i].holes; l++) {
			switch (dir) {//places ships in the given direction
            case DIR_RIGHT:
                board[row][col + l] = list[i].letter;
                break;
            case DIR_DOWN:
                board[row+l][col] = list[i].letter;
                break;
            case DIR_LEFT:
                board[row][col - l] = list[i].letter;
                break;
            case DIR_UP:
                board[row - l][col] = list[i].letter;
                break;
            default:
                break;
            }//end switch
        }//end for
    }//end for
}//end placeShips



int rnGesus(int minVal, int maxVal) {//Random Number Generator
    int outVal = rand() % (maxVal - minVal + 1) + minVal; //produces number between minVal and maxVal inclusive
    return outVal;
}//end rnGesus
