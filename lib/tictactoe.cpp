#include "tictactoe.h"

Board::Board(){

    for(int i=0;i<9;i++){ //init every position as 0
        this->location[i] = 0;
    }

    turnNumber = 0;//turn is 0 and state is 0
    state = 0;
}

Board::~Board(){//nothing needs to be deleted because allocated on stack

}

std::string Board::getBoard(){
    std::string boardCode = "";//create a holder for our board number

    for (int i=0; i< 9; i++){ //this appends each number index to the string
        
        boardCode += std::to_string(this->location[i]);
    }

    return boardCode;//return the boardcode
}

bool Board::makeMove(int pos){
    bool success = false;// default is a bad move

    pos --;//this will convert input into an index
    
    if (this->location[pos] == 0){//if the spot is empty
        this->location[pos] = this->turnNumber%2 +1;//set it to the player
        this->turnNumber ++;//increase the move number
        success = true;//and record that the move was a successful attempt
    }
    
    return success;//return if move was good or bad
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
