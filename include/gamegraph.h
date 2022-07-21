#pragma once

#include <gamealgorithms.h>
#include <boardstate.h>
#include <gamegraphconnection.h>

#include <iostream>
#include <string>
#include <vector>

class GameGraphEntry{
    private:
        BoardState board;
        std::vector<GameGraphConnection> connections;
    public:
        GameGraphEntry();
        ~GameGraphEntry();

        BoardState getBoardState();
        std::vector<GameGraphConnection> getConnections();

        void setBoardState(BoardState board);
        void setConnections(std::vector<GameGraphConnection> connections);

        void print();
};

class GameGraph{
    private:
        std::vector<GameGraphEntry> entries;
        GameAlgorithms* helperFunctions;

    public:
        GameGraph();
        GameGraph(GameAlgorithms* helperFunctions);

        ~GameGraph();

        int getNumEntries();

        GameGraphEntry getEntry(int index);
        std::vector<GameGraphEntry> addEntry(GameGraphEntry entry);

        void addStartEntry();

        void print();
};
