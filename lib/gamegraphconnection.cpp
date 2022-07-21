#include <gamegraphconnection.h>

// GameGraphConneciton:: this is a list of moves that result in an ending board
// state

GameGraphConnection::GameGraphConnection(){

}

GameGraphConnection::~GameGraphConnection(){

}

// return a vector containing the choices that lead to the next board of the
// current connection
std::vector<int> GameGraphConnection::getChoices(){
    return choiceNums;
}

// return the next board that the choices connect to
BoardState GameGraphConnection::getNextBoard(){
    return nextBoard;
}

void GameGraphConnection::setChoices(std::vector<int> choices){
    this->choiceNums = choices;
}

void GameGraphConnection::setNextBoard(BoardState nextBoard){
    this->nextBoard.state = nextBoard.state;
    this->nextBoard.moveNum = nextBoard.moveNum;
}

void GameGraphConnection::addChoice(int choice){
    choiceNums.push_back(choice);
}

void GameGraphConnection::print(){
    for(int i=0; i<choiceNums.size(); i++){
        std::cout<<choiceNums.at(i)<<" ";
    }
    std::cout<<"--> "<<nextBoard.state<<" : "<<nextBoard.moveNum;
}

