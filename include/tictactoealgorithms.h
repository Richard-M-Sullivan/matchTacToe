#pragma once

#include <gamealgorithms.h>

#include <iostream>
#include <string>

class TicTacToeAlgorithms : public GameAlgorithms{
    public:
        static const int BOARDLEN = 9;
    public:
        ~TicTacToeAlgorithms();

        std::string getType();
        BoardState getStartBoard();
        int getBoardScore(BoardState board);
        BoardState flipBoard(BoardState board);
};
