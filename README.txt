Author: Richard M Sullivan

Purpose:
    The purpose of this project is to explore the concept of
    emergent behavior within a self modifying system. This 
    idea was inspired by Donald Michie's MENACE project, in
    which he used matchboxes to build a primitive ai that 
    plays tic tac toe/ knots and crosses. In this project my
    hope is to create a simulation of MENACE as a means of 
    exploring this technique as an option for solving problems
    in the future.

Instructions:

Execution:


Planning:

how will the program work?
    1 create a board object to hold the state of the board
    
    2 create a matchbox manager to select, generate values,
        save, and update the matchboxes
    
    3 display a menu that will allow you to either train or play
        against the matchbox opponent
    
    4 based on the selection the game will start, and the inputs
        to the matchbox manager and the player will be decided

    5 then in a loop the game will check the state of the board
        to determine if there is a tie a win or none. Then the
        next player will make a move and the loop will continue.
        The loop will exit after it is determined that the game
        has come to an end.

    6 pass the game state to the manager, so it may update the
        matchboxes.

    7 then display another menu to decide if the player wants to
        continue playing or not
    
what components do I need to make?
    1 a board object that holds the state of the board
    2 a game manager that controls input and output to the players
        has access to the board to determine the state of the board
        at all times, and to keep track of whose turn it is
    3 a matchbox, which will consist of a file, whose name holds a
        string that represents the state of the board, and inside
        will hold a set of comma seperated numbers that correspond
        to the number of beads for a move number equal to the pos-
        ition in the list.
    4 a matchbox manager, which will remember the the boxes used,
        and the beads pulled from each box, and then it will update
        them based on the feedback from the game manager

what problems do I expect to face?
    1 code reusibility. 
        I want to make a follow up application that uses the same
        technique as the match box ai in order to play connect four,
        but I want to use the same matchbox management class across
        games. In order to do this I need to make the manager flexible
        enough to be able to read and write matchbox files based on the
        paramaters of the game that the user will provide. Hopefully 
        this can be then turned into a stand alone library to be
        shared with others who are interested in making their own 
        match box projects.

    2 how to implament things within the c++ language.
        It has been a while since I have used the c++ language, and I
        am very rusty. Thankfully I have a strong understanding of the
        basics of how to utilize techniques such as object oriented
        design and the use of libraries and utilities. All I need to do
        is take the general knowledge and understanding that I have,
        and find documentation that alows me to implament the things I
        want in the c++ language. 



