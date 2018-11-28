// Include statements
#include <iostream>
#include <string>
#include <limits>
#include "mazeCell.h"
#include "maze.h"
#include "DisjSets.h"

// using statements
using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;

// function prototypes
void twoRandom(int &n1, int &n2, int maxN);


// main function
int main(int argc, const char *argv[])
{
    srand(time(NULL));

    int rows = 0;
    int cols = 0;
    string displaySmash;


}

// generates two different random numbers in range of maxN and sets them to n1 and n2
void twoRandom(int &n1, int &n2, int maxN)
{
    n1 = rand() % (maxN + 1);
    n2 = rand() % (maxN + 1);
}