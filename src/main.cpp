#include <iostream> 
#include "tictactoe.h"// this includes the board class

int main() { 
    
    Board board;//create the board
    int move = 0;//create a variable to hold move selections

    for(int i = 0; i < 10; i ++){//for loop to test program
        board.display();//display the board
        std::cout<<board.getBoard()<<std::endl;//print the boardCode
        std::cin>>move;
        board.makeMove(move);//let the player make their move
    }
    return 0; 
}
