## Author: Richard M Sullivan

# Match-Tac-Toe 
###### an A.I. that plays tic tac toe created by simulating boxes of beads.


#### Purpose:
The purpose of this project is to explore the concept of emergent behavior
within a self modifying system. This idea was inspired by Donald Michie's
MENACE project, in which he used matchboxes to build a primitive AI that plays
tic tac toe/ knots and crosses. In this project my goal is to make the
instructions to accompany an existing build of the menace computer.

-----------------------------------------------------------
#### Instructions:
-----------------------------------------------------------

-----------------------------------------------------------
#### Documentation of Thought Process:
-----------------------------------------------------------
1. Research and Preparation
 * Learning about graphs
  
  I needed a data structure to hold the information that described the game's
  state and maps possible moves to the subset of matchbox positions.
  At first I considered a tree, but because branches can converge a directed
  graph seemed most appropriate. Thus I learned about different ways to represent
  graphs, and how to construct them.
  
 * going over creational design patterns

  I wanted my program to support creating the instructions for both the game
  hexapawn and tic-tac-toe. I also wanted to make it extensable to add games
  in the future. For aiding in design flexability, I learned about the factory
  patterns and the builder pattern for object creation.
  
2. Application Design
 * command line interface
 
  I felt that calling the program from the terminal, passing in flags for the
  game that you wanted, seemed the simplest method for interacting with the
  program. Given that someone is able to clone the git repository they should be
  able to figure out and understand how to use the command line.
  
 * separation of concerns

  I wanted the option to generate instructions, as well as playing against it on
  a computer. To do this, I felt that it would be easiest to achieve through many
  small programs rather than a single monolythic one. This is why I decided to
  make the project into three sub progams. One program to generate the graph data
  structure and to serialize it into a file. Another program to read a graph, and 
  generate instructions for a physical MENACE computer. And a final program to 
  act as a virtual MENACE computer that you can play against.
 
 * supporting multuple game formats
 
  To do this I will use creational patterns to generate enough abstraction to
  afford the flexability needed.
  
3. Implementation
