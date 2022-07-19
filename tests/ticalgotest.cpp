#include <tictactoealgorithms.h>
#include <gamegraph.h>
#include <iostream>

void checkType(TicTacToeAlgorithms algorithm);
void checkDefaultBoard(TicTacToeAlgorithms algorithm);
void checkScoring(TicTacToeAlgorithms algorithm);

int main(){
    // instantialte the algorithm class for tictactoe games
    TicTacToeAlgorithms algorithm;

    // check to see if correct type
    checkType(algorithm);

    // check to see if default board state is created and has correct move num
    checkDefaultBoard(algorithm);

    // check to see if board scoring is correct
    checkScoring(algorithm);

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
