#pragma once

#include <gamealgorithms.h>

#include <iostream>
#include <string>

class TicTacToeAlgorithms : public GameAlgorithms{
    private:
        static const int BOARDLEN = 9;

    public:
        ~TicTacToeAlgorithms();

        std::string getType();

        BoardState getStartBoard();

        int getBoardScore(BoardState board);
        bool getWon(BoardState board);

        BoardState rotateBoard(BoardState board);
        BoardState flipBoard(BoardState board);

        BoardState getMaxBoard(BoardState board);
        std::vector<GameGraphConnection> getConnections(BoardState board);

        std::string getFileName();
};
