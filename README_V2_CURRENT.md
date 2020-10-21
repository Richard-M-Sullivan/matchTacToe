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
of the boxes which your AI uses to play.

-------------------------------------------------------------------------
#### Dependancies:

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
my code as to better decouple the AI class from the implamentation of the
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
code to be made for the public to observe and perhapse utilize in ones own
project. 

I have also decided that I want to rewrite the application in Python3 because
it has lots of features that are easily usable, and is simpeler than c++. 
Because this is a personal project and would not benefit from running at 
blazing speeds I see no reason to use a lower level language for a project
like this. Python seems to fulfill all of the requirements that I need, while
providing a faster development time due to simple syntax and qutomated memory
management.

#### Planning:

##### how will the program work?

------------------------------------------------------------------

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

1. code reusibility. 
I want to make a follow up application that uses the same
technique as the match box ai in order to play connect four,
but I want to use the same matchbox management class across
games. In order to do this I need to make the manager flexible
enough to be able to read and write matchbox files based on the
paramaters of the game that the user will provide. Hopefully 
this can be then turned into a stand alone library to be
shared with others who are interested in making their own 
match box projects.

2. how to implament things within the c++ language.
It has been a while since I have used the c++ language, and I
am very rusty. Thankfully I have a strong understanding of the
basics of how to utilize techniques such as object oriented
design and the use of libraries and utilities. All I need to do
is take the general knowledge and understanding that I have,
and find documentation that alows me to implament the things I
want in the c++ language. 

-------------------------------------------------------------------

##### Major Project Accomplishments:

###### 9/4/2020
1. created a new gethub account that is seperate from my student
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

-----------------------------------------------------------------------
    
#### Project Aspirations:
- [x] create README.md for version 2
- [ ]

-----------------------------------------------------------------
