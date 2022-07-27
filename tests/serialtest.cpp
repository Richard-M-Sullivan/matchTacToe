#include <abstractgamefactory.h>

#include <iostream>

int main(){

    // create hexapawn factory
    GameFactory* gameFactory = AbstractGameFactory::createGameFactory("tictactoe");

    // build hexapawn related data structures
    GameGraph* gameGraph = gameFactory->makeGameGraph();
    GameBuilder* gameBuilder = gameFactory->makeGameBuilder();

    // construct the graph
    gameBuilder->makeGameGraph(*gameGraph);

    // serialize the graph
    gameGraph->serialize();

    // free memory
    delete gameFactory;

    delete gameGraph;
    delete gameBuilder;

    return 0;
}
