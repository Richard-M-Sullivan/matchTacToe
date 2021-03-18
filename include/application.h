#ifndef APPLICATION_h
#define APPLICATION_h

#include <ncurses.h>
#include <ticTacToe.h>

#define FALSE 0
#define TRUE 1

typedef enum {MAIN,PLAY,OPTION,TRAIN,TIC_TAC_TOE} menu;

void application_init();

void application_display();

void application_update();

void application_getInput();

void application_shutDown();

int application_QUIT;


#endif
