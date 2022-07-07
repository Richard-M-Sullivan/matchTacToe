#pragma once

#include <string>

class GameFactory{

    public:
    virtual ~GameFactory(){};
    virtual std::string getType() = 0;

};
