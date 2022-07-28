#pragma once

#include <gamebuilder.h>

class TicTacToeGameBuilder : public GameBuilder{

    public:
        TicTacToeGameBuilder();
        ~TicTacToeGameBuilder();

        bool makeGameGraph(GameGraph &gameGraph);
};
