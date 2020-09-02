#include <iostream> 
#include "tictactoe.h"// this includes the board class

int main() { 
    
    Board board;//create the board
    int move = 0;//create a variable to hold move selections
    int state = 0;//hold the state of the game

    for(int i = 0; i < 10; i ++){//for loop to test program
        board.display();//display the board
        std::cout<<board.getBoard()<<std::endl;//print the boardCode
        std::cin>>move;
        board.makeMove(move);//let the player make their move
        state = board.getState();
        if(state == 0){
            std::cout<<"play on.!"<<std::endl;
        }
        else if(state == 1){
            std::cout<<"player 1 wins"<<std::endl;
        }
        else if(state == 2){
            std::cout<<"player 2 wins"<<std::endl;
        }
        else if(state == -1){
            std::cout<<"tie game.!"<<std::endl;
        }
        else{
            std::cout<<"an error occured: illegal state"<<std::endl;
        }
    }
    return 0; 
}
