#include <abstractgamefactory.h>

GameFactory* AbstractGameFactory::createGameFactory(std::string type){

    if(type == "tictactoe"){
        return new TicTacToeFactory();
    }

    if(type == "hexapawn"){
        return new HexapawnFactory();
    }

    return NULL;
}
