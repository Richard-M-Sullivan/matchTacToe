#include <tictactoegamebuilder.h>

TicTacToeGameBuilder::TicTacToeGameBuilder(){
    std::cout<<"tictactoe game builder created"<<std::endl;
}

TicTacToeGameBuilder::~TicTacToeGameBuilder(){
    std::cout<<"tictactoe game builder destroyed"<<std::endl;
}

bool TicTacToeGameBuilder::makeGameGraph(GameGraph &gameGraph){
    // add starting entry
    gameGraph.addStartEntry();

    // keep track of entry sizes to track resolved vs unresolved entries.
    // (a resolved intry is one that has been used to make further entries)
    int resolvedEntries = 0;
    int currentEntries = 1;

    // while there are still unresolved entries
    while(resolvedEntries < currentEntries){
        // go through the unresolved entries
        for(int i=resolvedEntries; i<currentEntries; i++){
            // get their connections
            std::vector<GameGraphConnection> connections = gameGraph.getEntry(i).getConnections();           
            // and for each one add a new entry to the graph
            for(int j=0; j<connections.size(); j++){
                gameGraph.addEntry(connections.at(j).getNextBoard());
            }
        }
        // update the number of entries
        resolvedEntries = currentEntries;
        currentEntries = gameGraph.getNumEntries();

        if(resolvedEntries > 1000){
            break;
        }
    }

    return true;
}
