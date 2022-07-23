#include <abstractgamefactory.h>

#include <iostream>

int main(){

    // create hexapawn factory
    GameFactory* gameFactory = AbstractGameFactory::createGameFactory("hexapawn");

    // build hexapawn related data structures
    GameGraph* gameGraph = gameFactory->makeGameGraph();
    GameBuilder* gameBuilder = gameFactory->makeGameBuilder();
    GameSerializer* gameSerializer = gameFactory->makeGameSerializer();

    // construct the graph
    gameBuilder->makeGameGraph(*gameGraph);

    // serialize the graph

    // free memory
    delete gameFactory;

    delete gameGraph;
    delete gameBuilder;
    delete gameSerializer;

    return 0;
}
