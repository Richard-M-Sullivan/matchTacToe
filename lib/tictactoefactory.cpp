#include <tictactoefactory.h>
#include <iostream>

TicTacToeFactory::TicTacToeFactory(){

}

TicTacToeFactory::~TicTacToeFactory(){

}

std::string TicTacToeFactory::getType(){
    return "tictactoe";
}

GameGraph* TicTacToeFactory::makeGameGraph(){
    return new GameGraph();
}

GameBuilder* TicTacToeFactory::makeGameBuilder(){
    return new TicTacToeGameBuilder();
}

GameSerializer* TicTacToeFactory::makeGameSerializer(){
    return new GameSerializer();
}
