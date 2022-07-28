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

bool TicTacToeAlgorithms::getWon(BoardState board){
    // if there are too few moves then no win
    // xxx oo must be move five for there to be a win
    if(board.moveNum < 5){
        return false;
    }

    char symbol;
    bool win;

    // if there are horizontal connections then won
    for(int row=0; row<3; row++){
        win = true; //assume win
        
        symbol = board.state[row*3]; // the first item in the row

        if(symbol == '_'){ // if the item is empty then no need to look at remaing items
            win = false;
        }
        // if you are looking at an x or o, then look for win
        else{
            for(int column=0; column<3; column++){ // look at the remaining items
                // if they dont match, then no win
                if(board.state[row*3 + column] != symbol){
                    win = false;
                    break;
                }
            }
        }
        
        // if a row produces a win then return
        if(win){
            return true;
        }
    }

    // if there are vertical connections then won
    for(int column=0; column<3; column++){
        win = true; //assume win

        symbol = board.state[column]; // the first item in the row
        
        if(symbol == '_'){ // if the item is empty then no need ot look at remaning items
            win = false;
        }
        // if you are looking at an x or o, then look for win
        else{
            for(int row=0; row<3; row++){ // look at the remaining items
                // if they dont match, then no win
                if(board.state[row*3 + column] != symbol){
                    win = false;
                    break;
                }
            }
        }
        // if a row produces a win then return
        if(win){
            return true;
        }
    }

    // if ther are diagonal connections then won
    for(int diagonal=0; diagonal<2; diagonal++){
        win = true; //assume win

        symbol = board.state[1*3 + 1]; // the first item in the row

        if(symbol == '_'){
            win = false;
            break;
        }

        // check left diagonal
        if(diagonal == 0){
            for(int pos=0; pos<3; pos++){ // look at the remaining items
                // if they dont match, then no win
                if(board.state[pos*3 + pos] != symbol){
                    win = false;
                    break;
                }
            }
        }
        // check right diagonal
        else{
            for(int pos=0; pos<3; pos++){ // look at the remaining items
                // if they dont match, then no win
                if(board.state[pos*3 + (2-pos)] != symbol){
                    win = false;
                    break;
                }
            }

        }

        // if a row produces a win then return
        if(win){
            return true;
        }
    }

    // if no connections found return false
    return false;
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
       // if(flip != 0){
            board = flipBoard(board);
       // }

        for(int rotation=0; rotation < 4; rotation++){
            // only need to rotate the board after checking the starting
            // position
           // if(rotation != 0){
                board = rotateBoard(board);
          //  }

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
        
std::vector<GameGraphConnection> TicTacToeAlgorithms::getConnections(BoardState board){
    // create a vector to hold new connections
    std::vector<GameGraphConnection> connections;

    // flag to help identify duplicates
    bool duplicate;

    // figure out whose turn it is
    char symbol = (board.moveNum % 2 == 0) ? 'x':'o';
    
    // create new boards for every possible move.
    // Add unique boards to the list of connections.
    // If a board is not unique, then append move num to that connection
    for(int i=0; i<BOARDLEN; i++){

        // create new board for possible move
        if(board.state[i] == '_'){
            // create a new board
            BoardState newBoard;

            // make the move and store it in to the new board
            newBoard.state = board.state;
            newBoard.state[i] = symbol;

            newBoard.moveNum = board.moveNum + 1;
            
            // make it the maximum position
            newBoard = getMaxBoard(newBoard);
            
            // check for duplicates
            duplicate = false;
            
            for(int j=0; j< connections.size(); j++){
                // if there is a duplicate board add the choice to that connection
                if(connections.at(j).getNextBoard().state == newBoard.state){
                   duplicate = true; 
                   connections.at(j).addChoice(i);
                   break;
                }
            }

            // if ther is not a duplicate board add the board and choice to the connection
            if(duplicate == false){
                GameGraphConnection newConnection;

                newConnection.addChoice(i);
                newConnection.setNextBoard(newBoard);

                connections.push_back(newConnection);
            }
        }
    }

    return connections;
}

std::string TicTacToeAlgorithms::getFileName(){
    return "tictactoe.txt";
}
