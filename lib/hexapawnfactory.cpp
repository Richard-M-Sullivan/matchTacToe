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
    return new GameGraph();
}
