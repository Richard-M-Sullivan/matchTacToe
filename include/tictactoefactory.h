#pragma once

#include <gamefactory.h>
#include <string>

class TicTacToeFactory : public GameFactory{

    public:
        TicTacToeFactory();
        ~TicTacToeFactory();

        std::string getType();

};
