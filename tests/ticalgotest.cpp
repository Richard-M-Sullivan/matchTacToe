#include <tictactoealgorithms.h>
#include <gamegraph.h>
#include <iostream>

void checkType(TicTacToeAlgorithms algorithm);
void checkDefaultBoard(TicTacToeAlgorithms algorithm);
void checkScoring(TicTacToeAlgorithms algorithm);
void checkRotation(TicTacToeAlgorithms algorithm);
void checkFlip(TicTacToeAlgorithms algorithm);
void checkGetMaxBoard(TicTacToeAlgorithms algorithm);
void checkGetNextConnections(TicTacToeAlgorithms algorithm);
void checkWon(TicTacToeAlgorithms algorithm);

int main(){
    // instantialte the algorithm class for tictactoe games
    TicTacToeAlgorithms algorithm;

    // check to see if correct type
    checkType(algorithm);

    // check to see if default board state is created and has correct move num
    checkDefaultBoard(algorithm);

    // check to see if board scoring is correct
    checkScoring(algorithm);

    // check to see if the board rotation algorithm is correct
    checkRotation(algorithm);

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

void checkType(TicTacToeAlgorithms algorithm){
    std::cout<< algorithm.getType() <<std::endl;
}

void checkDefaultBoard(TicTacToeAlgorithms algorithm){
    std::cout<<"making default board"<<std::endl;

    BoardState boardState = algorithm.getStartBoard();
    std::cout<<boardState.state<<" : "<<boardState.moveNum<<std::endl;
}

void checkScoring(TicTacToeAlgorithms algorithm){

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

void checkRotation(TicTacToeAlgorithms algorithm){
    std::cout<<"\nRotation Check\n\n";

    // create board and set state
    BoardState boardState;
    boardState.state = "123456789";
    boardState.moveNum = 0;

    // print the board
    std::cout<<boardState.state<<std::endl;

    // rotate and print the board in all rotated positions to ensure rotation
    // is happening correctly
    for(int i=0; i<4; i++){
        boardState = algorithm.rotateBoard(boardState);
        std::cout<<boardState.state<<std::endl;
    }
}

void checkFlip(TicTacToeAlgorithms algorithm){
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

void checkGetMaxBoard(TicTacToeAlgorithms algorithm){
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

void checkGetNextConnections(TicTacToeAlgorithms algorithm){

    std::cout<<"\nNext Boards Check\n"<<std::endl;

    BoardState board = algorithm.getStartBoard();

    std::vector<GameGraphConnection> connections = algorithm.getConnections(board);

    for(int i=0; i<connections.size(); i++){
        connections.at(i).print();
        std::cout<<"\n";
    }

}
void checkWon(TicTacToeAlgorithms algorithm){
    std::cout<<"\nWon Boards Check\n"<<std::endl;

    //empty
    BoardState board = algorithm.getStartBoard();
    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // horiz o top
    std::cout<<" o horizontal top"<<std::endl;
    board.state = "oooxx_xox";
    board.moveNum = 8;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // horiz x mid
    std::cout<<" x horizontal middle"<<std::endl;
    board.state = "ooxxxxo__";
    board.moveNum = 7;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // horiz o bot
    std::cout<<" o horizontal bottom"<<std::endl;
    board.state = "xx__x_ooo";
    board.moveNum = 6;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // vert x right
    std::cout<<" x vertical right"<<std::endl;
    board.state = "_oxo_x__x";
    board.moveNum = 5;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // vert o mid
    std::cout<<" o vertical middle"<<std::endl;
    board.state = "xox_o_xo_";
    board.moveNum = 6;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // vert x left
    std::cout<<" x vertical left"<<std::endl;
    board.state = "x_oxo_x__";
    board.moveNum = 5;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // diag x tl -> br
    std::cout<<" x diagonal top left -> bottom right"<<std::endl;
    board.state = "_oxox_x__";
    board.moveNum = 5;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // diag o tr -> bl
    std::cout<<" o diagonal top right -> bottom left"<<std::endl;
    board.state = "o_x_oxx_o";
    board.moveNum = 6;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";

    // full almost win
    std::cout<<"full almost win"<<std::endl;
    board.state = "xoxxoxoxo";
    board.moveNum = 6;

    std::cout<<board.state<<" : won = "<<algorithm.getWon(board)<<"\n\n";
}
