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
          X weights         O weights
           768|384|192      256|128| 64
          ----+---+---      ---+---+----
            96| 48| 24       32| 16|  8   
          ----+---+---      ---+---+----
            12|  6|  3        4|  2|  1
    */
    for(int i=0; i<BOARDLEN; i++){

        if(board.state[i] == 'x'){
            score += 3<<(BOARDLEN - (i+1));
        }
        else if(board.state[i] == 'o'){
            score += 1<<(BOARDLEN - (i+1));
        }
    }

    return score;
}

BoardState TicTacToeAlgorithms::rotateBoard(BoardState board){

    char temp;

    // flip board across diagonal 

    // iterate through all the elements to the right of the top left to bottom
    // right diagonal
    for(int row=0; row<3; row++){
        for(int column = row+1; column<3; column++){
            // swap the elements mirrored across the diagoanal
            temp = board.state[row *3 + column];
            board.state[row *3 + column] = board.state[column *3 + row];
            board.state[column *3 + row] = temp;
        }
    }

    // flip board horisontally
    return flipBoard(board);
}

BoardState TicTacToeAlgorithms::flipBoard(BoardState board){

    char temp;

    // iterate through all the elements to the left of the middle column 
    // swap with all the elements on the right of the middle column
    for(int row=0; row<3; row++){
        // swap the elements mirrored across the middle column
        temp = board.state[row *3 + 0];
        board.state[row *3 + 0] = board.state[row *3 + 2];
        board.state[row *3 + 2] = temp;
    }

    return board;
}

BoardState TicTacToeAlgorithms::getMaxBoard(BoardState board){
    // create holder for max board and max score and set it to the original
    // board
    BoardState maxBoard = board;
    int maxScore = getBoardScore(maxBoard);
    int newScore = 0;

    // rotate and flip the board to find a board of a greater score if one is
    // found then replace max board and max score with the new board and score
    for(int flip=0; flip <= 1; flip++){
        // only need to flip the board after all 4 rotations
        if(flip != 0){
            board = flipBoard(board);
        }

        for(int rotation=0; rotation < 4; rotation++){
            // only need to rotate the board after checking the starting
            // position
            if(rotation != 0){
                board = rotateBoard(board);
            }

            // find score of new board
            newScore = getBoardScore(board);
            
            // if the score is bigger then update maxBoard and maxScore
            if(newScore > maxScore){
                maxBoard = board;
                maxScore = newScore;
            }
        }
    }
    return maxBoard;
}
        
std::vector<BoardState> TicTacToeAlgorithms::getNextBoards(BoardState board){
    // create a vector to hold new boards
    std::vector<BoardState> boards;
    // flag to see if there is a duplicate board
    bool duplicate;

    // figure out whose turn it is
    char symbol = (board.moveNum % 2 == 0) ? 'x':'o';
    
    // create new boards for every possible move and add unique boards to the
    // list
    for(int i=0; i<BOARDLEN; i++){

        if(board.state[i] == '_'){
            // create a new board
            BoardState newBoard;

            // make the move and store it in to the new board
            newBoard.state = board.state;
            newBoard.state[i] = symbol;

            newBoard.moveNum = board.moveNum + 1;
            
            // make it the maximum position
            newBoard = getMaxBoard(newBoard);
            
            // add it to the list if no duplicates
            duplicate = false;
            
            for(int j=0; j< boards.size(); j++){
                if(boards.at(j).state == newBoard.state){
                   duplicate = true; 
                   break;
                }
            }

            if(duplicate == false){
                boards.push_back(newBoard);
            }
        }
    }

    return boards;
}
