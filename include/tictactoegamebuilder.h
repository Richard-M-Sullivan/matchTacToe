#pragma once

#include <gamebuilder.h>
#include <iostream>

class TicTacToeGameBuilder : public GameBuilder{

    public:
        TicTacToeGameBuilder();
        ~TicTacToeGameBuilder();

        bool makeGameGraph(GameGraph &gameGraph);
};
