#include <iostream>
#include <string>

class Board{
    
    private:
    int location[9];//this holds the board information
                    //0= no piece, 1=p1 piece, 2=p2 piece

    int turnNumber; //this is used to identify whose turn it is
    
    int state;      //this holds the state of the game
                    //0=not over, 1=p1 win, 2=p2 win, -1=tie

    public:
    Board();        //sets all values to their initial state
    ~Board();       //cleans up

    std::string getBoard(); //returns a number showing the board values
                            //ex: 0 1 2
                            //    0 1 0 -> 012010212
                            //    2 1 2

    bool makeMove();//allows you to specify a location and places the
                    //correct piece there if the move is valid
    
    int getState(); //returns the state of the board
    
    void display(); //prints the content of the board in a human readable
                    //format
};
