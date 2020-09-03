#include <iostream>
#include <fstream>

struct Matchbox{
    int beadNumber;
    std::string boardCode;
};

class MatchboxManager {
    private:
    Matchbox boxList[9];


    public:
    MatchboxManager();
    ~MatchboxManager();

    bool getMatchbox(std::string boardcode);
    int getBead(std::string boardcode);
    bool updateBoxes(bool);

};
