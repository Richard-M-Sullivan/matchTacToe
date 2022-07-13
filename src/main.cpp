#include <iostream>
#include <abstractgamefactory.h>

int main(int argc, char* argv[]){
    
    //check if the number of arguments is correct
    if(argc <= 1){
        std::cout<<"You must specify the games that you want to create"
                 <<"instructions for."<<std::endl;
        return -1;
    }

    GameFactory* gameFactory = NULL;
    GameGraph* gameGraph = NULL;
    GameBuilder* gameBuilder = NULL;
    GameSerializer* gameSerializer = NULL;

    // for each argument passed in create the apropriate game
    std::string argument = "";
    for(int i=1; i<argc; i++){
        argument = argv[i];
        
        if(argument == "tictactoe" ||
           argument == "hexapawn"){
            gameFactory = AbstractGameFactory::createGameFactory(argument);
        }
        else{
            std::cout<<"invalid argument"<<std::endl;
            continue;
        }

        // create the graph, build the datastructure and write its contents
        // into a file
        gameGraph = gameFactory->makeGameGraph();
        gameBuilder = gameFactory->makeGameBuilder();
        gameSerializer = gameFactory->makeGameSerializer();

        //print the size of the gameGraph
        std::cout<<gameGraph->getNumEntries()<<std::endl;

        // try and build the game graph
        std::cout<<gameBuilder->makeGameGraph(*gameGraph)<<std::endl;
            
        // free memory in preparation for next command
        delete gameFactory;
        delete gameGraph;
        delete gameBuilder;
        delete gameSerializer;
    }

    return 0;
}
