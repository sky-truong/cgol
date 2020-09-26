#include <stdio.h>
#include <stdlib.h>
#include "GameOfLife.h"

int countNeighbor (char grid[ROWS][COLS], int x, int y);

int applyRules (char grid[ROWS][COLS], char futureGrid[ROWS][COLS]) {
    int x, y, numNeighbors;
    numNeighbors = 0;

    for ( x = 0; x < ROWS; x++ ) {
        for ( y = 0; y < COLS; y++ ) {
            numNeighbors = countNeighbor ( grid, x, y );
            if ( grid[x][y] == ALIVE && numNeighbors < 2 ) { /*Underpopulation*/
                futureGrid[x][y] = DEAD;
            } else if ( grid[x][y] == ALIVE && numNeighbors > 3 ) { /*Overpopulation*/
                futureGrid[x][y] = DEAD;
            } else if ( grid[x][y] == DEAD && numNeighbors == 3 ) { /*Reproduction*/
                futureGrid[x][y] = ALIVE;
            } else { /*Just right*/
                futureGrid[x][y] = grid[x][y];
            }
        }
    }
    return (0);
}
