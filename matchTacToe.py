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
#instantiate the game class to manage the tic tac toe board
game = tictactoe.Game()

#flag for the menu loop
quit = False

#menu loop and holds game loop
while(quit == False):
    
    #get player input 
    choice = input("type x to go first\ntype o to go second\ntype t to train\
the AI")

    #player turn as well as computer1 and computer2 hold whether they play
    #on odd or even numbered games. computer1 and computer2 don't change, but
    #what will change is the playerTurn. 0 means they go first and on even
    #numbered turns, and 1 means they go second and on odd numbered turns
    playerTurn = 0

    if(choice == 'o'):
        playerTurn = 1
    
    #display the board on the screen
    game.printBoard()

    #game loop (the loop is dependant on the testing variable)
    testing = 0

    while(testing <= 2):
        
        #based on the turn determine whose turn it is
        #then submit the move
        if (game.get_turn() % 2 == playerTurn):
            game.submit_move(testing)

        #computer1's turn
        elif (game.get_turn() % 2 == 0):
            game.submit_move(testing)

        #computer2's turn
        else:
            game.submit_move(testing)
        
        testing += 1
        
        #display the board on the screen
        game.printBoard()


    #if they chose not to play again, set quit to true
    choice = input("would you like to play again? y/n")
    if(choice == 'n'):
        quit = True
    
    #clear the board for the next round
    game.reset()


