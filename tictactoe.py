
class Board:
    #create a 2 dimensional list to represent the tic tac toe board
    board = [[0,0,0],[0,0,0],[0,0,0]]
    
    def __init__(self):
        print("board created")

    def __del__(self):
        print("board destroyed")

    #takes in the number of the piece to add to the board, andit adds that
    #piece to the board at the index move choice
    def update(self,pieceNum,moveChoice):
        index = 0
        for row in range(len(self.board)):
            for column in range(len(self.board[row])):
                if (index == moveChoice): 
                    self.board[row][column] = pieceNum
                index += 1

    #goes through the board and sets it to all 0s
    def clear(self):
        for i in range(len(self.board)):
            for j in range(len(self.board[i])):
                self.board[i][j] = 0


class Game:
    #the game has a board and keeps track of the important aspects
    #of the board game, while providing functions to facilitate the game
    board = Board()
    turn = 0

    def __init__(self):
        print("game created")

    def __del__(self):
        print("game destroyed")

    # returns the turn number
    def get_turn(self):
        return self.turn

    # allows you to submit a move, and the game updates the board
    # with the correct piece (does not check for valid moves, so be careful)
    def submit_move(self, moveNum):
        
        #update the board with the right piece at the correct space
        self.board.update((self.turn%2)+1,moveNum) 

        self.turn += 1

    #display the board in the terminal
    def printBoard(self):

    #iterate through the board and print each item in a row on the same line
    #and print a newline after each row
        for row in self.board.board:
            for item in row:
                print(item,end=' ')
                
            print()


    def clearBoard(self):
        self.board.clear()


    def reset(self):
        self.clearBoard()
        self.turn = 0


