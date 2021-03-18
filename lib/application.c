#include <stdio.h>
#include <application.h>


short board[ROW][COLUMN] = {EMPTY};
menu menuSelect;
char userInput;


void application_init(){
    //init application variables
    application_QUIT = FALSE;
    menuSelect = MAIN;
    userInput = ' ';
    //init ncurses library
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

}



void application_display() {
    //clear the screen buffer
    clear();

    //based on the menu select draw the appropriate menu to the screen buffer
    switch(menuSelect){
        case MAIN:
            printw("MATCH TAC TOE\n\n");
            printw("[1]: play tic tac toe\n");
            printw("[2]: options\n");
            printw("[3]: train match boxes\n\n");
            break;

        case PLAY:
            printw("play menu\n\n");
            printw("[1]: back\n");
            printw("use the arrow keys to select a cell.\n");
            printw("then use space bar to make your move\n");
            printw("not implamented yet\n\n");
            break;

        case OPTION:
            printw("options menu\n\n");
            printw("[1]: back\n");
            printw("no optins to display\n\n");
            break;

        case TRAIN:
            printw("train menu\n\n");
            printw("[1]: back\n");
            printw("no options to display\n\n");
            break;

        default:
            printw("default\n");
            break;
    }
    
    //show the buffer to the screen
    refresh();
}



void application_getInput(){
    //grab a  character from the keyboard
    userInput = getch(); 
}



void application_update(){
    // apply logic based on the menu selection
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

    //end menu specific logic

    //if the user inputs q set application_QUIT flag to TRUE
    // (this is used to control exiting the game loop)
    if (userInput == 'q'){ 
        application_QUIT = TRUE;
    }
}



void application_shutDown(){
    //shut down the ncurses library
    endwin();
}
