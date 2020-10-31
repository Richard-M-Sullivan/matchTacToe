"""
Author: Richard M. Sullivan
    And my partner in crime - The Great Allison Anson

This is an example of how you can use the matchboxAI library in a tic tac toe
application. I hope this inspires you to use it in creative ways that are 
beyond the scope of just simple board games.

"""


# import the neccessary libraries
from matchboxAI import matchbox_manager
import tictactoe

#instantiate the AI to play the game
AI = matchbox_manager.Matchbox_Manager()
#instantiate the class to manage the tic tac toe board
game = tictactoe.Game()


#game loop (the loop is dependant on the testing variable)
testing = 0

while(testing <= 2):
    print("game started")
    
    #based on the turn determine whose turn it is
    if (game.get_turn() % 2 == 0):
        print("player 1")        
        game.submit_move(1)
    else:
        print("player 2")
        game.submit_move(1)
    
    testing += 1

print("game finished")




