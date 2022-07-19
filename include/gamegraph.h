#pragma once

#include <gamealgorithms.h>
#include <boardstate.h>

#include <iostream>
#include <string>
#include <vector>

class GameGraphConnection{
    private:
        std::vector<int> choiceNums;
        BoardState nextBoard;

    public:
        GameGraphConnection();
        ~GameGraphConnection();

        std::vector<int> getChoices();
        BoardState getNextBoard();

        void setChoices(std::vector<int> choices);
        void setNextBoard(BoardState nextBoard);
};

class GameGraphEntry{
    private:
        BoardState board;
        std::vector<GameGraphConnection> connections;
    public:
        GameGraphEntry();
        ~GameGraphEntry();

        BoardState getBoardState();
        std::vector<GameGraphConnection> getConnections();

        void setBoardState(std::string board, int move);
        void setConnections(std::vector<GameGraphConnection> connections);
};

class GameGraph{
    private:
        std::vector<GameGraphEntry> entries;
        GameAlgorithms* helperFunctions;

    public:
        GameGraph();
        ~GameGraph();

        int getNumEntries();

        GameGraphEntry getEntry(int index);
        std::vector<GameGraphEntry> addEntry(GameGraphEntry entry);
};
