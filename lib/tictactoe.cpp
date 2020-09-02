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
    
}

bool Board::makeMove(){

}

int Board::getState(){

}

void Board::display(){
    std::cout<<"display"<<std::endl;
}
