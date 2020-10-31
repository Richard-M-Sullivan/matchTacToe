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


#game loop (loop will only run once for testing by setting test to false at the
#end of the loop )

testing = True
while(testing):
    print("game started")
    testing = False

print("game finished")





