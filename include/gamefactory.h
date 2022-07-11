#pragma once

#include <string>
#include <gamegraph.h>

class GameFactory{

    public:
    virtual ~GameFactory(){};
    virtual std::string getType() = 0;

    virtual GameGraph* makeGameGraph() = 0;

};
