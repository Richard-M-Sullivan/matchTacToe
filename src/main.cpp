#include <iostream> 
#include "tictactoe.h"// this includes the board and game manager 


int main() { 
    
    Board board;
    board.display();
    std::cout<<board.getBoard()<<std::endl;

    return 0; 
}
