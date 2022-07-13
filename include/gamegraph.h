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
};

class GameGraph{
    private:
        std::vector<GameGraphEntry> entries;

    public:
        GameGraph();
        ~GameGraph();

        int getNumEntries();
};
