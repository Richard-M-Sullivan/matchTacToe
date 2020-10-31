
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
        valid = False
        index = 0
        for row in range(len(self.board)):
            for column in range(len(self.board[row])):
                if (index == moveChoice): 
                    if(self.board[row][column] == 0):
                        self.board[row][column] = pieceNum
                        valid = True
                index += 1

        return valid

    #goes through the board and sets it to all 0s
    def clear(self):
        for i in range(len(self.board)):
            for j in range(len(self.board[i])):
                self.board[i][j] = 0

    def string(self):
        string = ''
        for row in self.board:
            for item in row:
                string += str(item) 

        return string


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
        valid = False
        #update the board with the right piece at the correct space
        if(self.board.update((self.turn%2)+1,moveNum)):
            self.turn += 1
            valid = True

        return valid

    def human_submit_move(self):
        valid = False

        while(not valid):
            choice = input("enter 1 - 9 to pick a space on the board")
            if(self.submit_move(int(choice)-1)):
                valid = True
            else:
                print("invalid move try again...")

    #display the board in the terminal
    def printBoard(self):

    #iterate through the board and print each item in a row on the same line
    #and print a newline after each row
        for row in self.board.board:
            for item in row:
                print(item,end=' ')
                
            print()

    #set all the values of the board to their initial state
    def clearBoard(self):
        self.board.clear()

    #clear the board and reset the turn number
    def reset(self):
        self.clearBoard()
        self.turn = 0

    #return a string of the board
    def getString(self):
        return self.board.string()



