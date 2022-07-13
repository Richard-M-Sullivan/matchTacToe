#include <gamegraph.h>


// GameGraphConneciton:: this is a list of moves that result in an ending board
// state

GameGraphConnection::GameGraphConnection(){

}

GameGraphConnection::~GameGraphConnection(){

}

// GameGraphEntry:: this is a single entry in the graph, and it contains an
// initial board, followed by a list of moves and ending board states

GameGraphEntry::GameGraphEntry(){

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
