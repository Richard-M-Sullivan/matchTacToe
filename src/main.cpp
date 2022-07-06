#include <iostream>

int main(int argc, char* argv[]){
    
    //check if the number of arguments is correct
    if(argc <= 1){
        std::cout<<"You must specify the games that you want to create"
                 <<"instructions for."<<std::endl;
        return -1;
    }

    //collect arguments in a string and perform desired acitons
    std::string argument = "";

    for(int i=1; i<argc; i++){
        argument = argv[i];
        
        if(argument == "tictactoe"){
            std::cout<<"lets make a tic tac toe graph"<<std::endl;
            std::cout<<"creating the tic tac toe factory"<<std::endl;
        }
        else if(argument == "hexapawn"){
            std::cout<<"lets make a hexapawn graph"<<std::endl;
            std::cout<<"creating the hexapawn factory"<<std::endl;
        }
        else{
            std::cout<<"invalid argument"<<std::endl;
            break;
        }

        std::cout<<"making "<<argument<<" game container"<<std::endl;
        std::cout<<"making "<<argument<<" builder"<<std::endl;
        std::cout<<"building "<<argument<<" graph"<<std::endl;
        std::cout<<"storing "<<argument<<" graph in container"<<std::endl;

        std::cout<<"making "<<argument<<" serializer"<<std::endl;
        std::cout<<"serializing "<<argument<<" graph"<<std::endl;
    }

    return 0;
}
