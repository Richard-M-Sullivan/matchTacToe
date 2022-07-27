#include <hexapawnfactory.h>
#include <iostream>

HexapawnFactory::HexapawnFactory(){

}

HexapawnFactory::~HexapawnFactory(){

}

std::string HexapawnFactory::getType(){
    return "hexapawn";
}

GameGraph* HexapawnFactory::makeGameGraph(){
    GameAlgorithms* helperFunctions = new HexapawnAlgorithms;

    return new GameGraph(helperFunctions);
}

GameBuilder* HexapawnFactory::makeGameBuilder(){
    return new HexapawnGameBuilder();
}
