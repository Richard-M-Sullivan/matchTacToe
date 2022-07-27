#pragma once

#include <boardstate.h>
#include <gamegraphconnection.h>
#include <iostream>
#include <vector>
#include <algorithm>

class GameAlgorithms{

    public:
        virtual ~GameAlgorithms(){};

        virtual std::string getType() = 0;
        virtual BoardState getStartBoard() = 0;
        virtual int getBoardScore(BoardState board) = 0;
        virtual bool getWon(BoardState board) = 0;
        virtual BoardState getMaxBoard(BoardState board) = 0;
        virtual std::vector<GameGraphConnection> getConnections(BoardState board) = 0;
        virtual std::string getFileName() = 0;
};
