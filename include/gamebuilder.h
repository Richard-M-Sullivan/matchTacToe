#pragma once

#include <gamegraph.h>
#include <iostream>
#include <fstream>
#include <sys/stat.h>

class GameBuilder{
    private:

    public:
        virtual ~GameBuilder(){};

        virtual bool makeGameGraph(GameGraph &gameGraph) = 0;

};
