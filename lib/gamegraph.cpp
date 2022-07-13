#include <gamegraph.h>


// GameGraphConneciton:: this is a list of moves that result in an ending board
// state

GameGraphConnection::GameGraphConnection(){
    nextBoard = "";
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
    this->nextBoard = nextBoard;
}

// GameGraphEntry:: this is a single entry in the graph, and it contains an
// initial board, followed by a list of moves and ending board states

GameGraphEntry::GameGraphEntry(){
    board = "";
}

GameGraphEntry::~GameGraphEntry(){

}

// GameGraph:: complete graph data structure, contains a list of game graph
// entries, which contain a list of game graph connections, which contain a
// list of move numbers followed by an ending board state

GameGraph::GameGraph(){
    std::cout<<"game graph created"<<std::endl;
}

GameGraph::~GameGraph(){
    std::cout<<"game graph destroyed"<<std::endl;
}


int GameGraph::getNumEntries(){
    return entries.size();
}
