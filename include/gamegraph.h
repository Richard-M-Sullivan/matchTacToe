#pragma once

#include <gamealgorithms.h>
#include <boardstate.h>
#include <gamegraphconnection.h>

#include <iostream>
#include <fstream>
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
        int getNumOddEntries();
        int getNumEvenEntries();
        int getNumMoveEntries(int moveNum);

        bool hasEntry(BoardState board);
        GameGraphEntry getEntry(int index);
        void addEntry(BoardState board);
        void addEntry(GameGraphEntry entry);

        void addStartEntry();

        void print();
        void serialize();
};
