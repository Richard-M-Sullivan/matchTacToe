#include "tictactoe.h"

Board::Board(){

    for(int i=0;i<9;i++){
        this->location[i] = 0;
    }

    turnNumber = 0;
    state = 0;
}

Board::~Board(){

}

std::string Board::getBoard(){
    std::string boardCode = "";//create a holder for our board number

    for (int i=0; i< 9; i++){ //this will add a number into the ones
                              //place, then shift it over, and repeat
                              //until all the numbers are in sequence
        
        boardCode += std::to_string(this->location[i]);
    }

    return boardCode;
}

bool Board::makeMove(){

}

int Board::getState(){
    

}

void Board::display(){
    //double four loops to treat array as 2d
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout<< this->location[i*3+j] <<" ";//print each row
        }
        std::cout<<"\n";//put a newline at the end of each row
    }
    
}
