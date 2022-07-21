#include <gamegraph.h>


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


void GameGraphEntry::setBoardState(BoardState board){
    this->board.state = board.state;
    this->board.moveNum = board.moveNum;
}

void GameGraphEntry::setConnections(std::vector<GameGraphConnection> connections){
    this->connections = connections;
}

void GameGraphEntry::print(){
    std::cout<<board.state<<" : "<<board.moveNum<<"\n";
    for(int i=0; i<connections.size(); i++){
        std::cout<<"\t";
        connections.at(i).print();
        std::cout<<"\n";
    }
}

// GameGraph:: complete graph data structure, contains a list of game graph
// entries, which contain a list of game graph connections, which contain a
// list of move numbers followed by an ending board state

GameGraph::GameGraph(){
    std::cout<<"game graph created"<<std::endl;
}
GameGraph::GameGraph(GameAlgorithms* helperFunctions){
    std::cout<<"game graph created"<<std::endl;
    this->helperFunctions = helperFunctions;
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

void GameGraph::addStartEntry(){
    // a graph entry is composed of a board state
    // followed by a list of game graph connections

    // create an entry
    GameGraphEntry entry;

    // set the state property with the initial board state
    BoardState startBoard = helperFunctions->getStartBoard();
    entry.setBoardState(startBoard);

    entry.setConnections( helperFunctions->getConnections(startBoard) );


   
    // add the entry to the entries list
    entries.push_back(entry);
}

void GameGraph::print(){
    for(int i=0; i<entries.size(); i++){
        entries.at(i).print();
        std::cout<<"\n";
    }
}
