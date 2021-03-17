#include <stdio.h>
#include <application.h>

void display(short board[ROW][COLUMN]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            printf("%d ,%d", board[i][j],EMPTY);
        }
    }
    
    printf("\n");
}

void getInput(){

}

void update(){

}


