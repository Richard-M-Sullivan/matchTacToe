#include "tictactoe.h"

Board::Board(){

    for(int i=0;i<10;i++){
        this->location[i] = 0;
    }

    this->turnNumber = 0;
    this->state = 0;
}

Board::~Board(){

}

int Board::getBoard(){
    int boardCode = 0;//create a holder for our board number

    for (int i=0; i< 10; i++){ //this will add a number into the ones
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
    std::cout<<"display"<<std::endl;
}
