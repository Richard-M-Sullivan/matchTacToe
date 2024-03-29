#pragma once

#include <gamefactory.h>
#include <hexapawngamebuilder.h>
#include <hexapawnalgorithms.h>
#include <string>

class HexapawnFactory : public GameFactory{

    public:
        HexapawnFactory();
        ~HexapawnFactory();

        std::string getType();
        GameGraph* makeGameGraph();
        GameBuilder* makeGameBuilder();

};
