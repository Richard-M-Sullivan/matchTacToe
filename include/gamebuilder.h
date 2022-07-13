#pragma once

#include <gamegraph.h>
#include <iostream>

class GameBuilder{
    private:

    public:
        virtual ~GameBuilder(){};

        virtual bool makeGameGraph(GameGraph &gameGraph) = 0;

};
