/**************************************************************************
 * Assigned to: Courtney DeTello                                          *
 * Created by: Courtney DeTello                                           *
 * Compatibility and Assembly by: Suchir Moharil and Courtney DeTello     *
 * Purpose: Save State of Game and Leaderboard for Battleship             *
 * Date: 6 November 2021                                                  *
 **************************************************************************/


const char SAVENAME[60] = "battleShip.bin";
const char SAVELEADER[60] = "leaderboard.bin";


void saveGame(int mCount, Ship ships[], char sB[][COLS], char gB[][COLS]){
	FILE *ptr;
	ptr = fopen(SAVENAME, "wb");
	if(ptr == NULL){
		printf("Cannot save information.\n");
		PAUSE;
		return;
	}//stuff must be saved, so it is not in an "else"
	fwrite(&mCount, sizeof(int), 1, ptr);//saves mCount
	fwrite(ships, sizeof(Ship), NUM_SHIPS, ptr);//saves ship struct
	fwrite(sB, sizeof(char), ROWS * COLS, ptr);//saves shipboard
	fwrite(gB, sizeof(char), ROWS * COLS, ptr);//saves gameboard
	fclose(ptr);
}

char reloadGame(int *mCount, Ship ships[], char sB[][COLS], char gB[][COLS]){
	FILE *ptr;
	ptr = fopen(SAVENAME, "rb");
	if(ptr == NULL){
		printf("No information to load.\n");
		PAUSE;
		return 'N';
	}
	else{
		char choice;
		printf("Would you like to continue the saved game (Y/N) ?: "); //ask the user to continue from last game?
		scanf("%c", &choice);
		FLUSH;
		choice = toupper(choice);
		if(choice != 'Y') {//start a new game
			printf("\nOkay - lets start a new game!\n");
			PAUSE;
			return 'N';
		}
		else { //load last game
			fread(&mCount, sizeof(int), 1, ptr);//recovers mCount
			fread(ships, sizeof(Ship), NUM_SHIPS, ptr);//recovers ship struct
			fread(sB, sizeof(char), ROWS * COLS, ptr);//recovers shipboard
			fread(gB, sizeof(char), ROWS * COLS, ptr);//recovers gameboard
			fclose(ptr);
			return 'Y';
		}
	}
	
	
}

void saveLeaderboard(int leaderBoard[TOP+1]) {
	FILE* ptr;
	ptr = fopen(SAVELEADER, "wb");
	if (ptr == NULL) {
		printf("Cannot save information.\n");
		PAUSE;
	}// leaderboard must always be saved, so fwrite is not in an "else"
	fwrite(leaderBoard, sizeof(int), TOP + 1, ptr);//saves leaderboard
	fclose(ptr);
}

void readLeaderboard(int leaderBoard[TOP+1]) {
	FILE* ptr;
	ptr = fopen(SAVELEADER, "rb");
	if (ptr == NULL) {
		printf("No information to load.\n");
		PAUSE;
	}
	else {
		
		fread(leaderBoard, sizeof(int), TOP + 1, ptr);//recovers leaderboard
		fclose(ptr);
	}
}