## Author: Richard M Sullivan

# MatchTacToe 
###### an A.I. that plays tic tac toe created by simulating boxes of beads.

#### Purpose:

The purpose of this project is to explore the concept of
emergent behavior within a self modifying system. This 
idea was inspired by Donald Michie's MENACE project, in
which he used matchboxes to build a primitive ai that 
plays tic tac toe/ knots and crosses. In this project my
hope is to create a simulation of MENACE as a means of 
exploring this technique as an option for solving problems
in the future.

-----------------------------------------------------------
#### Instructions:

To run the project cd into the root of the project directory. Then run the 
command: "python3 matchbox.py". This will allow you to play tic tac toe
with your matchbox ai. If it is the first time using the application expect 
to program to start adding files to the matchbox folder. If you want to have
your AI start from scratch, then you need to make sure that the matchbox folder
is empty. If you want to train your AI, then use the train function in the 
application. After your AI is trained the matchbox folder will contain all
of the boxes which your AI uses to play. If you want to read about how the
AI works, so you can use it for other projects, then scroll down to "How
Will The Program Work" for an explanation of the AI's implementation.

-------------------------------------------------------------------------
#### Dependencies:

This Project will require you to install two libraries. 
1. pygame
2. numpy
After you have these installed you should be ready to go. I do not believe
that it matters what version you have of each library, but in theory if
you have the newest versions then you should be able to run the application.

I hope this helps.

---------------------------------------------------------------------------

| the remainder of the file is the planning and work that went into the 
creation of this applicaiton. If you are interested in reading further go 
ahead, but know that this is mainly for documenting my thought process 
throughout the project. | 
|-----------------------------------------------------------------------------|

#### Prologue:

This is version 2 of the Matchbox AI project. It exists because the completed
version of V1 did not work as expected, and it was unstable and unusable. 
The code was poorly structured, due to trying to sprint through the programming
without taking into consideration the design of the program. Another flaw,
which helped lead to my downfall, was the lack of comments in the code. This
left me at a cross roads - I could either refactor and crush the bugs in the
current project, or I could cut my losses and start again fresh. I think that,
due to the small nature of this project, I will just do the latter because
it would take longer to go back and relearn how my code works in the first 
place (it has been a while since I have looked at the code base). 

Being that I am going to start over, I am going to change the structure of
my code as to better decouple the AI class from the implementation of the
game. This is because I would like to be able to repurpose the AI in this
project for use in other board games. 

I also think that I over used the class system in c++ because I was under the 
impression that in object oriented programming you should make everything an 
object, but I think that in many cases the paradigm is a little obtuse. I 
think in many cases it is better to utilize a structure instead of making a 
full blown class to handle a simple unit of data.

The last short coming of the previous code was the lack of comments in the
code. This made it difficult to come back later and keep the code running and 
up to date. Documentation is super important, especially because I want this 
code to be made for the public to observe and perhapse utilize in one's own
project. 

I have also decided that I want to rewrite the application in Python3 because
it has lots of features that are easily usable, and is simpler than c++. 
Because this is a personal project and would not benefit from running at 
blazing speeds I see no reason to use a lower level language for a project
like this. Python seems to fulfill all of the requirements that I need, while
providing a faster development time due to simple syntax and automated memory
management.

#### Planning:

##### how will the program work?

In order to generalize the AI, all you have to do is pass it a string
that represents the board, and a list of possible move choices.
Then the AI will use that information in order to generate a
number that corresponds to its move choice.

The string should represent the state of the
board; if the board is a 3x3 then you will have 9 spaces on the board, so just
pass a string of 9 characters to the AI. There is only one rule that applies to
the string, and that is that the string should not contain spaces ' '.

The list should be a list of numbers that correspond to the possible moves that
can be selected. The numbers do not matter and do not have to be in order. An
example would be for tic tac toe where the numbers could represent a space on
the board, so if only the corners are open you could send a list of moves that
look like this [1,3,7,9]. The ai will return one of those numbers passed to it.

The way that this will work is that the program will read the string and either
create a file of tht name and use the list to fill in the informaiton needed to
make its selection, or it will load that informaiton from a file that already
has been created.

The file in this case represents a box, and what is inside of the file
represents the beads. In each file we will have a list of numbers representing,
for each item in the list, a different move, and the number of each item is the
number of beads that are present for that move. To select a bead we add up all
of the beads to get a total count, which is the max value for a generated 
random number. We then subtract each number from the random one until we reach
0, which tells us to stop and use that bead. Then we can take the index that
we stopped on and apply it to the list of possible moves provided by the user,
and return their move number that has the same index of our selected bead.

To seed each box, new boxes will have one bead for each move. Then when the box
is rewarded, the selected bead is placed back in the box plus 1 extra. When
the box is punished the selected bead is removed from the box. By adding beads
you make that good move more likely to happen in the future. By taking beads
out you make that move less likely to happen. When a move reaches 0 beads the
program adds back one bead for each move number effectively making the losing
move less likely, but still possible. In the event that a move reaches 0 and
one of the moves has 100 beads, then we let it remain at zero because we can
be sure that the other move is a better option. If we try to add beads back we
limit the number of beads to a maximum value of 100. This is because once a
good move is identified, then there is no need to keep increasing the beads in
your good move. The number 100 used is an arbitrary selection only chosen 
because it seemed sufficiently large.

The way we track whether to punish or reward boxes is by saving all of the
moves that we make in a list. In this list we save the string for the board, so
we can find the right box to edit, and we save the index of the selected move,
so we know which move to add or take beads away from. Then in the event that
we won, we go through the list and either punish every box, or we reward every
box. When we punish/reward the boxes we remove them from the list until it is
empty so another game can be started.

Note that for training the ai, you will have to create another instance of the
ai manager because it is meant to be a single player. If you try to use only
one to make both players moves, then the result of the game is applied to both
sides even though one side would win while the other would lose. You would end
up rewarding both sides or punishing both sides, which would mean that your
model would not be trained properly.

-------------------------------------------------------------------------------

##### what components do I need to make?

--------------------------------------------------------------

##### problems I expect to face in version 2

1. code structure.
I need to be careful to think about how to organize my code to make sure
that it is organized enough so it stays neat as it grows. I want to avoid
spaghetti code hell.

2. learning about how to structure modules and packages.
In order to make my code more portable and organized I think even the file 
structure of the project should be compartmentalized in a way that makes
sense.

##### problems faced in version 1 

1. code reusability. 
I want to make a follow up application that uses the same
technique as the match box ai in order to play connect four,
but I want to use the same matchbox management class across
games. In order to do this I need to make the manager flexible
enough to be able to read and write matchbox files based on the
paramaters of the game that the user will provide. Hopefully 
this can be then turned into a stand alone library to be
shared with others who are interested in making their own 
match box projects.

2. how to implement things within the c++ language.
It has been a while since I have used the c++ language, and I
am very rusty. Thankfully I have a strong understanding of the
basics of how to utilize techniques such as object oriented
design and the use of libraries and utilities. All I need to do
is take the general knowledge and understanding that I have,
and find documentation that alows me to implement the things I
want in the c++ language. 

-------------------------------------------------------------------

##### Major Project Accomplishments:

###### 9/4/2020
1. created a new github account that is seperate from my student
account for school to hold personal projects

2. created a new repository and populated it with a makefile of
my own design

3. created an empty project and wrote out a the readme.txt file

###### 9/5/2020
4. created the board class, which allows you to manage the tictactoe
board
    
5. completed the game logic
    
6. created the matchbox manager and identified important methods to
fill in later
    
7. created a folder that will hold the matchboxes in the future

8. version 1 completed, but lots of bugs.

###### 10/20/2020
9. version 2 created. C++ removed and project started again with Python3.

10. Created readme for version 2.

##### 10/29/2020
11. Fleshed out design for the matchbox AI in the readme.

-----------------------------------------------------------------------
    
#### Project Aspirations:
- [x] create README.md for version 2
- [x] Flesh out how the matchbox AI will work
- [x] Write matchbox ai class
- [] Write tic tac toe in the terminal
- [] Write function that gets a string from the board
- [] Implement searching and creating files
- [] Implement seeding files
- [] Implement making a move selection
- [] Write a function that takes ai move and puts it on the tic tac toe board
- [] Implement storing boards and move selections in a list
- [] Implement punishing/rewarding the boxes
- [] allow option to chose if you want to be x or o
- [] allow an option to train ai in tic tac toe program
- [] Implement selecting what ai you want to use, so you can have different
versions for the same game
- [] Implement AI locking, so once an AI has reached a level of proficiency
that you want you can lock it to prevent changes.
- [] Rewrite tic tac toe to be implemented in pygame to have rich visuals


-----------------------------------------------------------------
