#include <iostream> 
#include "tictactoe.h"// this includes the board class
#include "matchboxmanager.h"//this allows you to use matchboxes to generate
                          //game inputs

void clearScreen();

int main() { 
    
    
    std::srand(std::time(NULL));
    
    Board board;//create the board
    MatchboxManager manager;//create a manager for manipulating matchboxes
 
    int move  = 0;
    int input = 0;
    bool train = false;

    std::cout<<"train ai, or play (1 or 2)"<<std::endl;
    std::cin>>input;

    if(input == 2){
    
        board.display();
        std::cout<<std::endl;
        

        while(board.getState() == 0){
            if(move % 2 == 0){
                std::cin>>input;
                board.makeMove(input);
            }
            else{
                manager.getMatchbox(board.getBoard());
                board.makeMove(manager.getBead());
            }
            board.display();
            std::cout<<std::endl;

            move++;
        }
        
        if(board.getState() == 1){
            manager.updateBoxes(0);
        }
        else if(board.getState() == 2){
            manager.updateBoxes(1);
        }
        else{
            manager.updateBoxes(3);
        }

    }
    else{
        std::cout<<"training for 1000 games"<<std::endl;
        for(int i=0; i<1000;i++){ 
            MatchboxManager p1;
            MatchboxManager p2;
            Board pboard;

            move = 0;

            while(pboard.getState() == 0){
                if(move % 2 == 0){
                    p1.getMatchbox(pboard.getBoard());
                    pboard.makeMove(p1.getBead());
                    
                }
                else{
                    p2.getMatchbox(pboard.getBoard());
                    pboard.makeMove(p2.getBead());
                }

                move++;
            }
            
            if(pboard.getState() == 1){
                p2.updateBoxes(0);
            }
            else if(pboard.getState() == 2){
                p2.updateBoxes(1);
            }
            else{
                p2.updateBoxes(3);
            }
            
            if(pboard.getState() == 1){
                p1.updateBoxes(1);
            }
            else if(pboard.getState() == 2){
                p1.updateBoxes(0);
            }
            else{
                p1.updateBoxes(3);
            }

        }
    }
    return 0;
}
