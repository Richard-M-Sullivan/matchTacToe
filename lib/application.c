#include <stdio.h>
#include <application.h>

void print_MainMenu();
void print_PlayMenu();
void print_OptionMenu();
void print_TrainMenu();

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
            print_MainMenu();
            break;

        case PLAY:
            print_PlayMenu();
            break;

        case OPTION:
            print_OptionMenu();
            break;

        case TRAIN:
            print_TrainMenu();
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

void print_MainMenu(){
    printw("MATCH TAC TOE\n\n");
    printw("[1]: play tic tac toe\n");
    printw("[2]: options\n");
    printw("[3]: train match boxes\n\n");
}

void print_PlayMenu(){
    printw("play menu\n\n");
    printw("[1]: back\n");
    printw("use the arrow keys to select a cell.\n");
    printw("then use space bar to make your move\n");
    printw("not implamented yet\n\n");
}

void print_OptionMenu(){
    printw("options menu\n\n");
    printw("[1]: back\n");
    printw("no optins to display\n\n");
}

void print_TrainMenu(){
    printw("train menu\n\n");
    printw("[1]: back\n");
    printw("no options to display\n\n");
}
