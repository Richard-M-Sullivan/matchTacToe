#pragma once

#include <boardstate.h>
#include <iostream>
#include <vector>
#include <algorithm>

class GameAlgorithms{

    public:
        virtual ~GameAlgorithms(){};

        virtual std::string getType() = 0;
        virtual BoardState getStartBoard() = 0;
};
