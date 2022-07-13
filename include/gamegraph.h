#pragma once

#include <iostream>
#include <string>
#include <vector>

typedef std::string BoardState;

class GameGraphConnection{
    private:
        std::vector<int> choiceNum;
        BoardState nextBoard;

    public:
        GameGraphConnection();
        ~GameGraphConnection();
};

class GameGraphEntry{
    private:
        BoardState board;
        std::vector<GameGraphConnection> connections;
    public:
        GameGraphEntry();
        ~GameGraphEntry();
};

class GameGraph{
    private:
        std::vector<GameGraphEntry> entries;

    public:
        GameGraph();
        ~GameGraph();

        int getNumEntries();
};
