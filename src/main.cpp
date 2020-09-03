#include <iostream> 
#include "tictactoe.h"// this includes the board class
#include "matchboxmanager.h"//this allows you to use matchboxes to generate
                          //game inputs

void clearScreen();

int main() { 
    
    Board board;//create the board
    MatchboxManager manager;//create a manager for manipulating matchboxes
 
    int move  = 0;
    int input = 0;

    board.display();
    std::cout<<std::endl;
    

    while(board.getState() == 0){
        if(move % 2 == 0){
            std::cin>>input;
            board.makeMove(input);
        }
        else{
            manager.getMatchbox(board.getBoard());
            board.makeMove(manager.getBead());
        }
        board.display();
        std::cout<<std::endl;

        move++;
    }
    
    manager.print();

    if(board.getState() == 1){
        manager.updateBoxes(0);
    }
    else if(board.getState() == 2){
        manager.updateBoxes(1);
    }
    else{
        manager.updateBoxes(3);
    }

    manager.print();

    return 0;
}
