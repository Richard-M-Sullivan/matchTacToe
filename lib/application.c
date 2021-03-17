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
            printf("[1]: play tic tac toe\n");
            printf("[2]: options\n");
            printf("[3]: train match boxes\n\n");
            break;

        case PLAY:
            printf("play menu\n\n");
            printf("[1]: back\n");
            printf("use the arrow keys to select a cell.\n");
            printf("then use space bar to make your move\n");
            printf("not implamented yet\n\n");
            break;

        case OPTION:
            printf("options menu\n\n");
            printf("[1]: back\n");
            printf("no optins to display\n\n");
            break;

        case TRAIN:
            printf("train menu\n\n");
            printf("[1]: back\n");
            printf("no options to display\n\n");
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
    switch(menuSelect){
        case MAIN:
            switch(userInput){
                case '1':
                    menuSelect = PLAY;
                    break;

                case '2':
                    menuSelect = OPTION;
                    break;

                case '3':
                    menuSelect = TRAIN;
                    break;
            }
            break;

        case PLAY:
            switch(userInput){
                case '1':
                    menuSelect = MAIN;
                    break;
            }
            break;

        case OPTION:
            switch(userInput){
                case '1':
                    menuSelect = MAIN;
                    break;
            }
            break;

        case TRAIN:
            switch(userInput){
                case '1':
                    menuSelect = MAIN;
                    break;
            }
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
