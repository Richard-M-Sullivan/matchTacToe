#pragma once

#include <boardstate.h>

#include <iostream>
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

        void addChoice(int choice);

        void print();
};
