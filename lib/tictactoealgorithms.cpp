#include <tictactoealgorithms.h>

TicTacToeAlgorithms::~TicTacToeAlgorithms(){

}

std::string TicTacToeAlgorithms::getType(){
    return "tic tac toe algorithms";
}

// create a BoardState object and set it to an empty tic tac toe board on the
// move number 0, then return it
BoardState TicTacToeAlgorithms::getStartBoard(){
    
    BoardState board;

    board.state = "_________";
    board.moveNum = 0;

    return board;
}

int TicTacToeAlgorithms::getBoardScore(BoardState board){

    int score = 0;

    // look at each position in the board and calculate score by adding
    // up the values assigned to each position. 
    
    /*
          X weights         Y weights
           512|256|128      256|128| 64
          ----+---+---      ---+---+----
            64| 32| 16       32| 16|  8   
          ----+---+---      ---+---+----
             8|  4|  2        4|  2|  1
    */
    for(int i=0; i<BOARDLEN; i++){

        if(board.state[i] == 'x'){
            score += 2<<(BOARDLEN - (i+1));
        }
        else if(board.state[i] == 'o'){
            score += 1<<(BOARDLEN - (i+1));
        }
    }

    return score;
}
