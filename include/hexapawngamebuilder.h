#pragma once

#include <gamebuilder.h>

class HexapawnGameBuilder : public GameBuilder{
    
    public:
        HexapawnGameBuilder();
        ~HexapawnGameBuilder();
        
        bool makeGameGraph(GameGraph &gameGraph);
};
