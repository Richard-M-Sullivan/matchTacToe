#pragma once

#include <iostream>

class GameAlgorithms{

    public:
        virtual ~GameAlgorithms(){};

        virtual std::string getType() = 0;
};
