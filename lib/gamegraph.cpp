#include <gamegraph.h>


// GameGraphEntry:: this is a single entry in the graph, and it contains an
// initial board, followed by a list of moves and ending board states

GameGraphEntry::GameGraphEntry(){}

GameGraphEntry::~GameGraphEntry(){}

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
}

GameGraph::GameGraph(GameAlgorithms* helperFunctions){
    this->helperFunctions = helperFunctions;
}

GameGraph::~GameGraph(){
    delete helperFunctions;
}


int GameGraph::getNumEntries(){
    return entries.size();
}

int GameGraph::getNumOddEntries(){
    int count = 0;

    for(int i=0; i<entries.size(); i++){
        if(entries.at(i).getBoardState().moveNum % 2 == 1){
            count++;
        }
    }
    return count;
}

int GameGraph::getNumEvenEntries(){
    int count = 0;

    for(int i=0; i<entries.size(); i++){
        if(entries.at(i).getBoardState().moveNum % 2 == 0){
            count++;
        }
    }
    return count;
}

int GameGraph::getNumMoveEntries(int moveNum){
    int count = 0;

    for(int i=0; i<entries.size(); i++){
        if(entries.at(i).getBoardState().moveNum == moveNum){
            count++;
        }
    }
    return count;

}

bool GameGraph::hasEntry(BoardState board){
    // go through the entries in reverse order

    // this is because entries are built at the end of the list, so matches are
    // most likely to occur at the end of the list for the same moveNum.
    for(int i=entries.size()-1; i >= 0; i--){
        
        // if you made it past all the current items in your move number then
        // you are guarenteed not to find it, so leave the loop
        if(entries.at(i).getBoardState().moveNum < board.moveNum){
            break;
        }
        // if you find a match return true
        if(entries.at(i).getBoardState().state == board.state){
            return true;
        }
    }

    // if the search was unsuccessful then return false
    return false;
}

GameGraphEntry GameGraph::getEntry(int index){
    if(index < entries.size() && index >= 0){
        return entries.at(index);
    }
    else{
        GameGraphEntry empty;
        return empty;
    }
}

void GameGraph::addEntry(BoardState board){
    // if the entry is too full do nothing
    if(board.moveNum > 7){
        return;
    }

    // if the board is an already won game do nothing
    if( helperFunctions->getWon(board) == true ){
        return;
    }

    // if the entry already exists do nothing
    if(hasEntry(board)){
        return;
    }

    // otherwise add the entry

    // create an empty entry
    GameGraphEntry entry;
    
    //set the board state
    entry.setBoardState(board);
    // calcualte and set the connections
    entry.setConnections( helperFunctions->getConnections(board) );

    // add the entry to the list
    entries.push_back(entry);
}
void GameGraph::addEntry(GameGraphEntry entry){
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

void GameGraph::serialize(){
    // create file stream object to write out to a file specified by the game
    // helper functions

    std::fstream fs(helperFunctions->getFileName(),std::fstream::out);

    // containers to hold data
    GameGraphEntry entry;
    std::vector<GameGraphConnection> connections;
    GameGraphConnection connection;
    std::vector<int>choices;

    //for each entry in the graph
    for(int i=0; i< entries.size(); i++){
        entry = getEntry(i);

        // write out the board state of the entry on a line
        fs << entry.getBoardState().state  << ","
           << entry.getBoardState().moveNum << "\n";

        // for each connection write out the move list followed by the ending board
        // state on a line
        connections = entry.getConnections();
        for(int j=0; j< connections.size(); j++){

            connection = connections.at(j);

            choices = connection.getChoices();
            for(int k=0; k< choices.size(); k++){

                fs << choices[k] <<",";
            }
            fs << connection.getNextBoard().state   << ","
               << connection.getNextBoard().moveNum << "\n";
        }
    }
}
