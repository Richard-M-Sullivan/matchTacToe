#include <iostream> 
#include "tictactoe.h"// this includes the board class
#include "matchboxmanager.h"//this allows you to use matchboxes to generate
                          //game inputs

void clearScreen();

int main() { 
    
    Board board;//create the board
    MatchboxManager manager;//create a manager for manipulating matchboxes
 
    std::cout<<board.getBoard()<<std::endl;

    manager.getMatchbox(board.getBoard());

    return 0;
}
