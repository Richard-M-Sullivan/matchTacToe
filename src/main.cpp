#include <iostream>
#include <abstractgamefactory.h>

int main(int argc, char* argv[]){
    
    //check if the number of arguments is correct
    if(argc <= 1){
        std::cout<<"You must specify the games that you want to create"
                 <<"instructions for."<<std::endl;
        return -1;
    }

    GameFactory* gameFactory = NULL;
    std::string argument = "";

    // for each argument passed in create the apropriate game
    for(int i=1; i<argc; i++){
        argument = argv[i];
        
        if(argument == "tictactoe" ||
           argument == "hexapawn"){
            gameFactory = AbstractGameFactory::createGameFactory(argument);
        }
        else{
            std::cout<<"invalid argument"<<std::endl;
            continue;
        }

        std::cout<<gameFactory->getType()<<std::endl;

        delete gameFactory;
        gameFactory = NULL;
    }

    return 0;
}
