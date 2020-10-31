
class Board:
    board = [[0,0,0],[0,0,0],[0,0,0]]
    
    def __init__(self):
        print("board created")

    def __del__(self):
        print("board destroyed")
       


class Game:
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
        
        #go through the board and when the index of the tic tac toe grid
        #is equal to the move number provided then update the board with the
        #board and incrament the turn number by one
        index = 0
        for row in self.board.board:
            for item in row:
                if(index == moveNum):
                    item = 2 - (self.turn % 2)
                index += 1

        self.turn += 1
