#include <hexapawngamebuilder.h>

HexapawnGameBuilder::HexapawnGameBuilder(){
}

HexapawnGameBuilder::~HexapawnGameBuilder(){
}


bool HexapawnGameBuilder::makeGameGraph(GameGraph &gameGraph){
    // check if serialized file exists
    struct stat buff;
    if( stat("hexapawn.txt", &buff) == 0 ){

        //open the file
        std::fstream fs("hexapawn.txt",std::fstream::in);
        std::string line;

        GameGraphEntry entry;

        BoardState board;

        std::vector<GameGraphConnection> connections;

        bool firstTime = true;

        // go through the file line by line
        while(std::getline(fs,line)){
            // on the first go through the entry is not built yet
            if(!firstTime && ( line[0] == '_' || line[0] == 'x' || line[0] == 'o') ){
                // set the board and connections of the entry
                entry.setBoardState(board);
                entry.setConnections(connections);

                // add the entry to the graph
                gameGraph.addEntry(entry);

                // clean up of used variables
                board.state = "";
                board.moveNum = 0;

                connections.clear();
            }
            else{
                firstTime = false;
            }

            // if the line is a board, then set the board properties to be added
            // to the entry
            if(line[0] == '_' || line[0] == 'x' || line[0] == 'o'){
                //tokenize the line and build the board state object
                std::stringstream ss(line);

                std::getline(ss,line,',');
                board.state = line;

                std::getline(ss,line,',');
                board.moveNum = std::stoi(line);
            }// end board state if

            // if the line is a connection, then build the connection and add
            // it to the current entry
            else{
                std::stringstream ss(line);

                std::getline(ss,line,',');

                GameGraphConnection connection;

                do{

                    connection.addChoice(std::stoi(line));
                    std::getline(ss,line,',');

                }while(line[0] != '_' && line[0] != 'x' && line[0] != 'o');
                BoardState tempBoard;

                tempBoard.state = line;
                std::getline(ss,line,',');

                tempBoard.moveNum = std::stoi(line);

                connection.setNextBoard(tempBoard);

                connections.push_back(connection);
            }// end connection else
        }// end while file input
        
        // now that we have parsed the file, we have added every single entry
        // except the last one, so we add it one last time
        entry.setBoardState(board);
        entry.setConnections(connections);
        gameGraph.addEntry(entry);
    }// end if file is found

    // if file not found generate graph from scratch
    else{
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
    }

    return true;
}
