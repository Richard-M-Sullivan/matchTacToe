#pragma once

#include <iostream>
#include <string>
#include <vector>

typedef std::string BoardState;

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

        void setBoardState(BoardState board);
        void setConnections(std::vector<GameGraphConnection> connections);
};

class GameGraph{
    private:
        std::vector<GameGraphEntry> entries;

    public:
        GameGraph();
        ~GameGraph();

        int getNumEntries();

        GameGraphEntry getEntry(int index);
        void addEntry(GameGraphEntry entry);
};
