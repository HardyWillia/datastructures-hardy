/*
    Willia Hardy
    wjh26@zips.uakron.edu
    2905323

*/


#include "maze.h"
#include "mazeCell.h"
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;


/**
 * Construct the disjoint sets object.
 */
maze::maze(int r, int c)
{
    row = r;
    col = c;

    int numCells = getMaze();

    for (int i = 0; i < numCells; ++i)
    {
        mazeCell cell;

        if (i == 0)
        {
            cell.setLeft(false);
            cell.setTop(false);
        }
        else if (i == numCells - 1)
        {
            cell.setRight(false);
            cell.setBot(false);
        }
        theMaze.push_back(cell);
    }
}

// returns true if neigh is cell's neighbor
//(i.e. in position left, right, top or bot
// with respect to cell)
bool maze::neighbors(int cell, int neigh) const
{
        bool neighbors;

    // if the two cells are in the same column
    if (getCellCol(cell) == getCellCol(neigh))
    {
        // determine the difference between the rows
        int row_diff = abs(getCellRow(cell) - getCellRow(neigh));

        // if the difference is 1, this means they are right next to each other
        if (row_diff == 1)
        {
            neighbors = true;
        }

        else
        {
            neighbors = false;
        }
    }

    // if the two cells are in the same row
    if (getCellRow(cell) == getCellRow(neigh))
    {
        // determine the difference between the columns
        int col_diff = abs(getCellCol(cell) - getCellCol(neigh));

        // if the difference is 1, this means they are right next to each other
        if (col_diff == 1)
        {
            neighbors = true;
        }

        else
        {
            neighbors = false;
        }
    }

        return neighbors;
}

// get rid of cell's wall between cell and neighbor
// Note: this method should be invoked twice from the driver
// code to smashWall(a,b) and to smashWall(b,a)
void maze::smashWall(int cell, int neigh)
{

    //Determine the location of the cell
    int cellCol = getCellCol(cell);
    int cellRow = getCellRow(cell);

    //Find out where the neighbor is
    int neighCol = getCellCol(neigh);
    int neighRow = getCellRow(neigh);

    //Find the distance of the columns and rows
    int colDif = cellCol - neighCol;
    int rowDif = cellRow - neighRow;


    //Determine neighbors to the left, right, above and below
    mazeCell &cellCell = theMaze[cell];
    mazeCell &neighCell = theMaze[neigh];

    if (colDif == 1 && rowDif == 0)
    {
        // Neighbor is to the left
        cellCell.setLeft(false);
        neighCell.setRight(false);
    }
    else if (colDif == -1 && rowDif == 0)
    {
        // Neighbor is to the right
        cellCell.setRight(false);
        neighCell.setLeft(false);
    }
    else if (colDif == 0 && rowDif == -1)
    {
        // Neighbor is below
        cellCell.setBot(false);
        neighCell.setTop(false);
    }
    else if (colDif == 0 && rowDif == 1)
    {
        // Neighbor is above
        cellCell.setTop(false);
        neighCell.setBot(false);
    }
}

//print the maze
void maze::printMaze()
{
    // this is for top
    for(int i = 0; i < getCol(); i++)
    {
        if (i == 0)
        {
            cout << "  ";
        }
        else
        {
            cout << " _";
        }
    }

    cout << "\n";

    int numCells = getMaze();

    for (std::vector<mazeCell>::iterator it = theMaze.begin(); it != theMaze.end(); ++it)
    {
        const int i = it - theMaze.begin();
        mazeCell c = *it;
        if ((i + 1) % getCol() == 0)
        {
            // Know its the right side
            cout << (c.getLeft() ? "|" : " ") << (c.getBot() ? "_" : " ") << (i == numCells - 1 ? " " : "|");
            cout << endl;
        }
        else if (i % getCol() == 0)
        {
            // Know its the left side
            cout << (i == 0 ? " " : "|") << (c.getBot() ? "_" : " ");
        }
        else
        {
            // Other Cell
            cout << (c.getLeft() ? "|" : " ") << (c.getBot() ? "_" : " ");
        }
    }
    cout << endl;
}
