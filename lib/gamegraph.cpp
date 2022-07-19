#include <gamegraph.h>


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
    this->nextBoard = nextBoard;
}

// GameGraphEntry:: this is a single entry in the graph, and it contains an
// initial board, followed by a list of moves and ending board states

GameGraphEntry::GameGraphEntry(){

}

GameGraphEntry::~GameGraphEntry(){

}

BoardState GameGraphEntry::getBoardState(){
    return board;
}

std::vector<GameGraphConnection> GameGraphEntry::getConnections(){
    return connections;
}


void GameGraphEntry::setBoardState(std::string board, int move){
    this->board.state = board;
    this->board.moveNum = move;
}

void GameGraphEntry::setConnections(std::vector<GameGraphConnection> connections){
    this->connections = connections;
}


// GameGraph:: complete graph data structure, contains a list of game graph
// entries, which contain a list of game graph connections, which contain a
// list of move numbers followed by an ending board state

GameGraph::GameGraph(){
    std::cout<<"game graph created"<<std::endl;
}

GameGraph::~GameGraph(){
    delete helperFunctions;
    std::cout<<"game graph destroyed"<<std::endl;
}


int GameGraph::getNumEntries(){
    return entries.size();
}

GameGraphEntry GameGraph::getEntry(int index){

    if(getNumEntries() > index){
        return entries.at(index);
    }

    GameGraphEntry empty;
    return empty;
}


std::vector<GameGraphEntry> GameGraph::addEntry(GameGraphEntry entry){
    entries.push_back(entry);
}

