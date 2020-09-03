#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>


struct Matchbox{
    int beads[9];
    int selectedIndex;
    std::string boardCode;
};

class MatchboxManager {
    private:
    Matchbox boxList[9];
    int boxNum;

    public:
    MatchboxManager();
    ~MatchboxManager();

    void print();
    bool getMatchbox(std::string boardcode);
    int getBead();
    bool updateBoxes(int);

};
