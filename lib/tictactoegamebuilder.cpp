#include <tictactoegamebuilder.h>

TicTacToeGameBuilder::TicTacToeGameBuilder(){
    std::cout<<"tictactoe game builder created"<<std::endl;
}

TicTacToeGameBuilder::~TicTacToeGameBuilder(){
    std::cout<<"tictactoe game builder destroyed"<<std::endl;
}

bool TicTacToeGameBuilder::makeGameGraph(GameGraph &gameGraph){
    // add starting entry
    gameGraph.addStartEntry();

    return true;
}
