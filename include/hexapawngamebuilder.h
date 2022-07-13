#pragma once

#include <gamebuilder.h>
#include <iostream>

class HexapawnGameBuilder : public GameBuilder{
    
    public:
        HexapawnGameBuilder();
        ~HexapawnGameBuilder();
        
        bool makeGameGraph(GameGraph &gameGraph);
};
