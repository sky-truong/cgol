#include <stdio.h>
#include <stdlib.h>
#include "GameOfLife.h"

int countNeighbor (char grid[ROWS][COLS], int row, int col) {
    int i, j, rowCheck, colCheck, count, numNeighbors;
    count = numNeighbors = 0;
    for ( i = -1; i < 2; i++ ) {
        for ( j = -1; j < 2; j++ ) {
            rowCheck = row + i;
            colCheck = col + j;
            if ( (rowCheck >= 0 && rowCheck < ROWS) && (colCheck >= 0 && colCheck < COLS) && (grid[rowCheck][colCheck] == 'X') ) {
                count++;
            }
        }
    }
    if ( grid[row][col] == ALIVE ) {
        numNeighbors = count - 1;
    } else if ( grid[row][col] == DEAD ) {
        numNeighbors = count;
    }
    return (numNeighbors);
}
