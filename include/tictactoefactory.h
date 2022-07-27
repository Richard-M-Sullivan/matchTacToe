#pragma once

#include <gamefactory.h>
#include <tictactoegamebuilder.h>
#include <tictactoealgorithms.h>
#include <string>

class TicTacToeFactory : public GameFactory{

    public:
        TicTacToeFactory();
        ~TicTacToeFactory();

        std::string getType();
        GameGraph* makeGameGraph();
        GameBuilder* makeGameBuilder();

};
