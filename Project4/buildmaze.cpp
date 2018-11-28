/*
    Willia Hardy
    wjh26@zips.uakron.edu
    2905323

*/

// Include statements
#include <iostream>
#include <string>
#include <limits>
#include <stdlib.h>
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
bool isConnected(int n1, int n2, DisjSets &ds);


// main function
int main(int argc, const char *argv[])
{
    srand(time(NULL));

    int rows = 0;
    int cols = 0;
    string displaySmash;

    for (;;)
    {
        cout << "Please enter the number of rows greater than 1: ";
        if (cin >> rows)
        {
            if (rows > 0)
            {
                break;
            }
            else
            {
                cout << "Please enter an integer greater than 1" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else
        {
            cout << "Please enter a valid integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (;;)
    {
        cout << "Please enter the number of columns greater than 1: ";
        if (cin >> cols)
        {
            if (cols > 0)
            {
                break;
            }
            else
            {
                cout << "Please enter an integer greater than 1" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else
        {
            cout << "Please enter a valid integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (;;)
    {
        cout << "Would you like to see each iteration of the maze: ";
        if (cin >> displaySmash)
        {
            if (displaySmash == "n" || displaySmash == "y")
            {
                break;
            }
            else
            {
                cout << "Please enter either 'y' or 'n'" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else
        {
            cout << "Please enter a valid integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    //Display the maze
    maze m(rows, cols);
    m.printMaze();

    const int lastCell = m.getMaze() - 1;
    int i = 0;
    DisjSets ds(m.getMaze());

    //Smash the neighboring walls
    while (!isConnected(0, lastCell, ds))
    {

        int r1 = -1;
        int r2 = -1;
        twoRandom(r1, r2, lastCell);

        if (!isConnected(r1, r2, ds) && m.neighbors(r1, r2))
        {
            m.smashWall(r1, r2);
            ds.unionSets(ds.find(r1), ds.find(r2));
            if (displaySmash == "y")
            {
                cout << "Neighbors " << r1 << ", " << r2 << " wall smashed below" << endl;
                m.printMaze();
            }
        }
    }
    if (displaySmash != "y")
    {
        m.printMaze();
    }

    return 0;

}

// generates two different random numbers in range of maxN and sets them to n1 and n2
void twoRandom(int &n1, int &n2, int maxN)
{
    n1 = rand() % (maxN + 1);
    n2 = rand() % (maxN + 1);
}

bool isConnected(int n1, int n2, DisjSets &ds)
{
    const int f1 = ds.find(n1);
    const int f2 = ds.find(n2);
    return f1 == f2;
}

