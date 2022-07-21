#include <abstractgamefactory.h>

#include <iostream>

int main(){
    GameFactory* gameFactory = AbstractGameFactory::createGameFactory("tictactoe");

    GameGraph* gameGraph = gameFactory->makeGameGraph();
    GameBuilder* gameBuilder = gameFactory->makeGameBuilder();

    gameBuilder->makeGameGraph(*gameGraph);

    gameGraph->print();

    delete gameBuilder;
    delete gameGraph;

    return 0;
}
