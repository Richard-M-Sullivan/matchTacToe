#include "matchboxmanager.h"

MatchboxManager::MatchboxManager(){
    this->boxNum = -1;

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            boxList[i].beads[j] = 0;
        }

        boxList[i].selectedIndex = -1;
        boxList[i].boardCode = "none";
    }
    std::srand(std::time(NULL));
}

MatchboxManager::~MatchboxManager(){

}

//either creates a new machbox with an initial state, or
//it opens an existing one. After the box is looked at,
//the contents is then saved into the matchbox array.
bool MatchboxManager::getMatchbox(std::string boardCode){
    
    //check if matchbox exists
    std::ifstream boxFileIn;
    boxFileIn.open("./MatchBoxes/"+ boardCode+ ".txt");
    
    //yes - do nothing, no-create matchbox
    if(boxFileIn.is_open()){
    
    }
    else{

        boxFileIn.close();
        //create matchbox and give valid moves beads
        std::ofstream boxFileOut;

        boxFileOut.open("./MatchBoxes/"+boardCode+".txt");
        for(int i=0; i<9; i++){
            if(boardCode.at(i) == '0'){
                boxFileOut<<"100"<<std::endl;
            }
            else{
                boxFileOut<<"0"<<std::endl;
            }
        }
        boxFileOut.close();
        boxFileIn.open("./MatchBoxes/"+ boardCode + ".txt");
    }

    this->boxNum++;
    
    //read values from the box and store them
    int total = 0;
    for(int i=0;i<9;i++){
        std::string text;
        std::getline(boxFileIn,text);
        this->boxList[this->boxNum].beads[i] = std::stoi(text);
        total += std::stoi(text);
    }
    
    if(total > 0){
        int randNum = std::rand() % total;
        int index = 0;
        randNum -= this->boxList[this->boxNum].beads[index];
        while(randNum > 0){
            index ++;
            randNum -= this->boxList[this->boxNum].beads[index];
        }
        
        this->boxList[this->boxNum].selectedIndex = index;
    }
    else{
        this->boxList[this->boxNum].selectedIndex = std::rand() % 9;
    }
    boxFileIn.close();

}

int MatchboxManager::getBead(){
    return this->boxList[this->boxNum].selectedIndex + 1;
}

bool MatchboxManager::updateBoxes(bool gameState){

}




