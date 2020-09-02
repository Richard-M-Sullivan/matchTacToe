#include "tictactoe.h"

Board::Board(){

    for(int i=0;i<10;i++){
        this->location[i] = i;//the I here needs to be changed to 0!!
    }

    turnNumber = 0;
    state = 0;
}

Board::~Board(){

}

int Board::getBoard(){
    int boardCode = 0;//create a holder for our board number

    for (int i=0; i< 9; i++){ //this will add a number into the ones
        boardCode *= 10;       //place, then shift it over, and repeat
                               //until all the numbers are in sequence
        boardCode += this->location[i];
    }

    return boardCode;
}

bool Board::makeMove(){

}

int Board::getState(){

}

void Board::display(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout<< this->location[i*3+j] <<" ";
        }
        std::cout<<"\n";
    }
    
}
