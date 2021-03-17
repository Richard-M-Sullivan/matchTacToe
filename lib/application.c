#include <stdio.h>
#include <application.h>

short board[ROW][COLUMN] = {EMPTY};

void application_init(){
    application_QUIT = FALSE;
}

void application_display() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            printf("%d ,%d", board[i][j],EMPTY);
        }
    }
    
    printf("\n");
}

void application_update(){
    application_QUIT = TRUE;
}

void application_getInput(){

}

void application_shutDown(){

}
