#include <stdio.h>

#define ROW 3
#define COLUMN 3

enum boardCell{EMPTY, X, O};

void display(short board[ROW][COLUMN]);

int main(void){

    //setup stuff
        //matchbox table - list of matchboxes in memory
        //game board - 9x9 matrix of characters
        short board[ROW][COLUMN] = {EMPTY};

        display(board);
        //game settings - global variables used in the update function

    //enter game loop
        //display
            //display game board
        
        //get input
            //get input and validate it from the user
            //get input and validate it from the matchbox

        //update the game
            //update the board
            //check game state

    //shutdown stuff
        //reward/punish the matchboxes based on performance
        //log the changes
        //save matchbox data
        //uninitialize data

    return 0;
}

// display
void display(short board[ROW][COLUMN]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            printf("%d ", board[i][j]);
        }
    }
    printf("\n");
}
// get input
// update

