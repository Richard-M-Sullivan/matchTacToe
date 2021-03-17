#include <stdio.h>
#include <application.h>


short board[ROW][COLUMN] = {EMPTY};
menu menuSelect;
char userInput;


void application_init(){
    application_QUIT = FALSE;
    menuSelect = MAIN;
    userInput = ' ';
}



void application_display() {

    switch(menuSelect){
        case MAIN:
            printf("MATCH TAC TOE\n\n");
            printf("play tic tac toe\n");
            printf("options\n");
            printf("train match boxes\n");
            break;
        case OPTION:
            printf("options menu\n");
            break;
        case TRAIN:
            printf("train menu\n");
            break;
        default:
            printf("default\n");
            break;
    }

    printf("\n");
}



void application_getInput(){
   userInput = getchar(); 
}



void application_update(){
    switch menuSelect{
        case MAIN:
            break;
        case OPTION:
            break;
        case TRAIN:
            break;
        default:
            break;
    }

    if (userInput == 'q'){ 
        application_QUIT = TRUE;
    }

    userInput = ' ';
}



void application_shutDown(){

}
