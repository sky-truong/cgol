#include <stdio.h>
#include <stdlib.h>
#include "GameOfLife.h"

int sameGrid (char grid[ROWS][COLS], char futureGrid[ROWS][COLS]) {
    int x, y;
    int count = 0;

    for ( x = 0; x < ROWS; x++ ) {
        for ( y = 0; y < COLS; y++ ) {
            if ( grid[x][y] != futureGrid[x][y] ) {
                count++;
            }
        }
    }
    if ( count != 0 ) {
        return (0);
    }
    return (1);
}
