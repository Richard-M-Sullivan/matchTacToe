#include <stdio.h>
#include <application.h>

//type declarations
typedef enum 
{
    PLAY_START,
    PLAY_PLAYER_SELECT,

}   select_PlayMenu;


//function definitions
void print_MainMenu();
void print_PlayMenu(select_PlayMenu);
void print_OptionMenu();
void print_TrainMenu();

//variable delarations
short board[ROW][COLUMN] = {EMPTY};
menu menuSelect;
char userInput;
select_PlayMenu playMenuSelection;



void application_init()
{
    //init application variables
    application_QUIT = FALSE;
    menuSelect = MAIN;
    userInput = ' ';
    playMenuSelection = PLAY_START;
    //init ncurses library
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

}



void application_display() 
{
    //clear the screen buffer
    clear();

    //based on the menu select draw the appropriate menu to the screen buffer
    switch(menuSelect)
    {
        case MAIN:
            print_MainMenu();
            break;

        case PLAY:
            print_PlayMenu(playMenuSelection);
            break;

        case OPTION:
            print_OptionMenu();
            break;

        case TRAIN:
            print_TrainMenu();
            break;

        case TIC_TAC_TOE:
            printw("TIC TAC TOE\n\n");
            printw("[1] back to Play Menu\n\n");

            for (int i = 0; i < ROW; i++){
                for(int j = 0; j < COLUMN; j++){
                    printw("%d",board[i][j]);
                }
                printw("\n");
            }

            break;

        default:
            printw("default\n");
            break;
    }
    
    //show the buffer to the screen
    refresh();
}



void application_getInput()
{
    //grab a  character from the keyboard
    userInput = getch(); 
}



void application_update()
{
    // apply logic based on the menu selection
    switch(menuSelect)
    {
        case MAIN:
            switch(userInput)
            {
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
            switch(playMenuSelection)
            {
                case PLAY_START:
                    switch(userInput)
                    {
                        case '1':
                            menuSelect = MAIN;
                            break;
                        case '2':
                            playMenuSelection = PLAY_PLAYER_SELECT;
                        case '3':
                            playMenuSelection = PLAY_PLAYER_SELECT;
                    }
                    break;

                case PLAY_PLAYER_SELECT:
                    switch(userInput)
                    {
                        case '1':
                            playMenuSelection = PLAY_START;
                            break;
                        case '2':
                        //need to update playgame not exist
                            playMenuSelection = PLAY_START;
                            menuSelect = TIC_TAC_TOE;
                            break;
                        case '3':
                        //need to update playgame not exist
                            playMenuSelection = PLAY_START;
                            menuSelect = TIC_TAC_TOE;
                            break;
                    }
                    break;
            }
            break;

        case OPTION:
            switch(userInput)
            {
                case '1':
                    menuSelect = MAIN;
                    break;
            }
            break;

        case TRAIN:
            switch(userInput)
            {
                case '1':
                    menuSelect = MAIN;
                    break;
            }
            break;

        case TIC_TAC_TOE:
            switch(userInput)
            {
                case '1':
                    menuSelect = PLAY;
                    break;
            }
            break;
            
        default:
            break;
    }

    //end menu specific logic

    //if the user inputs q set application_QUIT flag to TRUE
    // (this is used to control exiting the game loop)
    if (userInput == 'q')
    { 
        application_QUIT = TRUE;
    }
}



void application_shutDown()
{
    //shut down the ncurses library
    endwin();
}

void print_MainMenu()
{
    printw("MATCH TAC TOE\n\n");
    printw("[1]: play tic tac toe\n");
    printw("[2]: options\n");
    printw("[3]: train match boxes\n\n");
    printw("press 'q' at any time to exit the application\n\n");
}

void print_PlayMenu(select_PlayMenu selection)
{
    switch(selection)
    {
        case PLAY_START:
            printw("PLAY MENU\n\n");
            printw("[1]: back\n\n");
            printw("select what type of game you would like to play.\n\n");
            printw("[2]: one player\n");
            printw("[3]: two player \n\n");
            break;

        case PLAY_PLAYER_SELECT:
            printw("PLAY MENU\n\n");
            printw("[1]: back\n\n");
            printw("wold you like to be X or O?\n\n");
            printw("[2]: X\n");
            printw("[3]: O\n\n");
            break;

        default:
            printw("play menu: %d\n\n",selection);
            printw("[1]: back\n");
            printw("use the arrow keys to select a cell.\n");
            printw("then use space bar to make your move\n");
            printw("not implamented yet\n\n");
            break;
    }
}

void print_OptionMenu()
{
    printw("options menu\n\n");
    printw("[1]: back\n");
    printw("no optins to display\n\n");
}

void print_TrainMenu()
{
    printw("train menu\n\n");
    printw("[1]: back\n");
    printw("no options to display\n\n");
}
