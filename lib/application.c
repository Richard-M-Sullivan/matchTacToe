#include <stdio.h>
#include <application.h>

short board[ROW][COLUMN] = {EMPTY};

void application_init(){
    printf("application init: setting QUIT to false. \n\n");
    application_QUIT = FALSE;
}

void application_display() {
    printf("application display: displaying game board. \n\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");

}

void application_getInput(){
    printf("application getInput: \n\n");

}


void application_update(){
    printf("application update: setting quit to TRUE. \n\n");
    application_QUIT = TRUE;
}

void application_shutDown(){
    printf("application shutdown: \n\n");
}
