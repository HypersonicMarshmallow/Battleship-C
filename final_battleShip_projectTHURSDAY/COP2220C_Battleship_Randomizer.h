/**************************************************************************
 * Assigned to: Suchir Moharil                                            *
 * Created by: Suchir Moharil                                             *
 * Compatibility and Assembly by: Suchir Moharil                          *
 * Purpose: Ship Struct for Battleship                                    *
 * Date: 6 November 2021                                                  *
 **************************************************************************/

#define DIR_RIGHT 0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_UP 3


typedef struct {//ship struct
    char letter;
    int holes;
    int hits;
    int floating;
}Ship;


void initializeBoard(char board[BOARD_DIM][BOARD_DIM]);
void populateStruct(Ship list[]);

int randomizeRow();
int randomizeColumn();

int randomizeDirection();

void placeShips(Ship list[], char board[BOARD_DIM][BOARD_DIM]);
void printBoard(char board[BOARD_DIM][BOARD_DIM]);
int rnGesus(int minVal, int maxVal);
