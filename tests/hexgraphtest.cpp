#include <abstractgamefactory.h>

#include <iostream>

int main(){
    GameFactory* gameFactory = AbstractGameFactory::createGameFactory("hexapawn");

    GameGraph* gameGraph = gameFactory->makeGameGraph();
    GameBuilder* gameBuilder = gameFactory->makeGameBuilder();

    gameBuilder->makeGameGraph(*gameGraph);

    gameGraph->print();

    std::cout<<"num entries= ";
    std::cout<<gameGraph->getNumEntries();
    std::cout<<"\nnum odd entries= ";
    std::cout<<gameGraph->getNumOddEntries();
    std::cout<<"\nnum even entries= ";
    std::cout<<gameGraph->getNumEvenEntries();

    for(int i=0; i<8; i++){
        std::cout<<"\nnum entries on move "<<i<<" = "<<gameGraph->getNumMoveEntries(i);
    }

    delete gameBuilder;
    delete gameGraph;

    return 0;
}
