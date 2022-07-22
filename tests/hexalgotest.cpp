#include <hexapawnalgorithms.h>
#include <gamegraph.h>
#include <iostream>

void checkType(HexapawnAlgorithms algorithm);
void checkDefaultBoard(HexapawnAlgorithms algorithm);
void checkScoring(HexapawnAlgorithms algorithm);
void checkFlip(HexapawnAlgorithms algorithm);
void checkGetMaxBoard(HexapawnAlgorithms algorithm);
void checkGetNextConnections(HexapawnAlgorithms algorithm);
void checkWon(HexapawnAlgorithms algorithm);

int main(){
    // instantialte the algorithm class for hexapawn games
    HexapawnAlgorithms algorithm;

    // check to see if correct type
    checkType(algorithm);

    // check to see if default board state is created and has correct move num
    checkDefaultBoard(algorithm);

    // check to see if board scoring is correct
    checkScoring(algorithm);

    // check to see if the board flipping algorithm is correct
    checkFlip(algorithm);

    // check to see if the maximum board is produced for each permutation
    checkGetMaxBoard(algorithm);

    // check to see all the next boards are generated
    checkGetNextConnections(algorithm);

    // check to see if the board winning works
    checkWon(algorithm);

    return 0;
}

void checkType(HexapawnAlgorithms algorithm){
    std::cout<< algorithm.getType() <<std::endl;
}

void checkDefaultBoard(HexapawnAlgorithms algorithm){
    std::cout<<"making default board"<<std::endl;

    BoardState boardState = algorithm.getStartBoard();
    std::cout<<boardState.state<<" : "<<boardState.moveNum<<std::endl;
}

void checkScoring(HexapawnAlgorithms algorithm){

    BoardState boardState = algorithm.getStartBoard();
    std::cout<<boardState.state<<" : "<<boardState.moveNum<<std::endl;

    // check to see if board scoring is correct
    std::cout<<"score: "<<algorithm.getBoardScore(boardState)<<std::endl;

    // first check with x's
    for(int i=0; i<algorithm.BOARDLEN; i++){
        boardState.state = "_________";
        boardState.state[i] = 'x';

        std::cout<<boardState.state<<": score = "<<algorithm.getBoardScore(boardState)<<std::endl;
    }

    // then check with o's
    for(int i=0; i<algorithm.BOARDLEN; i++){
        boardState.state = "_________";
        boardState.state[i] = 'o';

        std::cout<<boardState.state<<": score = "<<algorithm.getBoardScore(boardState)<<std::endl;
    }

    // then check with all o's and x's
    boardState.state = "xxxxxxxxx";
    std::cout<<boardState.state<<": score = "<<algorithm.getBoardScore(boardState)<<std::endl;

    boardState.state = "ooooooooo";
    std::cout<<boardState.state<<": score = "<<algorithm.getBoardScore(boardState)<<std::endl;
}

void checkFlip(HexapawnAlgorithms algorithm){
    std::cout<<"\nFlip Check\n"<<std::endl;

    // create board and set state
    BoardState board;
    board.state = "123456789";
    board.moveNum = 0;

    // prrint the board
    std::cout<<board.state<<std::endl;

    // flip and print the board
    board = algorithm.flipBoard(board);
    std::cout<<board.state<<std::endl;
}

void checkGetMaxBoard(HexapawnAlgorithms algorithm){
    std::cout<<"\nMax Board Check\n"<<std::endl;

    // create board and set state
    BoardState board;
    board.moveNum = 0;

    std::cout<<"Original Board  Final Board"<<std::endl;
    for(int i=0; i<9; i++){
        //generate a board
        board.state = "_________";
        board.state[i] = 'x';
        board.state[(i+1)%9] = 'o';

        // print the original board
        std::cout<<board.state<<"\t";

        // flip and print the board
        board = algorithm.getMaxBoard(board);
        std::cout<<board.state<<std::endl;
    }
}

void checkGetNextConnections(HexapawnAlgorithms algorithm){

    std::cout<<"\nNext Boards Check\n"<<std::endl;

    BoardState board = algorithm.getStartBoard();

    std::vector<GameGraphConnection> connections = algorithm.getConnections(board);

    for(int i=0; i<connections.size(); i++){
        connections.at(i).print();
        std::cout<<"\n";
    }

}
void checkWon(HexapawnAlgorithms algorithm){
    std::cout<<"\nWon Boards Check\n"<<std::endl;

    // starting position
    BoardState board = algorithm.getStartBoard();
    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // x top left
    std::cout<<"x top left"<<std::endl;
    board.state = "x___oo__x";
    board.moveNum = 5;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // x top middle
    std::cout<<"x top middle"<<std::endl;
    board.state = "_xoo__xx_";
    board.moveNum = 3;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // x top right
    std::cout<<"x top right"<<std::endl;
    board.state = "__xoo_x__";
    board.moveNum = 5;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // o bottom left
    std::cout<<"o bottom left"<<std::endl;
    board.state = "oo___xo__";
    board.moveNum = 4;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // o bottom middle
    std::cout<<"o bottom middle"<<std::endl;
    board.state = "o_o__x_o_";
    board.moveNum = 4;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // o bottom right
    std::cout<<"o bottom right"<<std::endl;
    board.state = "_oox____o";
    board.moveNum = 4;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    //one possible move x
    std::cout<<"one possible move for x"<<std::endl;
    board.state = "___ooox__";
    board.moveNum = 5;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    //one possible move o
    std::cout<<"one possible move for o"<<std::endl;
    board.state = "o_o__xx_x";
    board.moveNum = 3;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // stale mate
    std::cout<<"stale mate"<<std::endl;
    board.state = "__oo_xx__";
    board.moveNum = 3;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";
}
