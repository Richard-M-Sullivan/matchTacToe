#include <iostream> 
#include "tictactoe.h"// this includes the board class

int main() { 
    
    Board board;//create the board
    int move = 0;//create a variable to hold move selections
    int state = 0;//hold the state of the game
    
    for(int i=0; i < 5; i++){
        std::cout<< "\n\n\n\n\n\n\n\n\n\n" <<std::endl;
    }
        
    while(state == 0){
        board.display();//display the board
    
        std::cout<<"enter a move: #1-9 then press enter "<<std::endl;
        std::cin>>move;
        
        board.makeMove(move);//let the player make their move
        
        state = board.getState();
        
        for(int i=0; i < 5; i++){
            std::cout<< "\n\n\n\n\n\n\n\n\n\n" <<std::endl;
        }

        if(state == 0){
            std::cout<<"play on.!"<<std::endl;
        }
    }

    std::cout<<"final board id: "<<board.getBoard()<<std::endl;

    if(state == 1){
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
    return 0; 
}
