#pragma once

#include <gamebuilder.h>
#include <iostream>
#include <sstream>

class TicTacToeGameBuilder : public GameBuilder{

    public:
        TicTacToeGameBuilder();
        ~TicTacToeGameBuilder();

        bool makeGameGraph(GameGraph &gameGraph);
};
