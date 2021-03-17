#include <stdio.h>
#include <application.h>

int main(void){

    //setup stuff
        //matchbox table - list of matchboxes in memory
        //game board - 9x9 matrix of characters
        short board[ROW][COLUMN] = {EMPTY};

        //game settings - global variables used in the update function

    //enter game loop
        //display
            //display game board
            display(board);
        
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
