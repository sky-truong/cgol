#include <stdio.h>
#include <stdlib.h>
#include "GameOfLife.h"

int switchGrid ( char grid[ROWS][COLS], char futureGrid[ROWS][COLS] ) {
    int x, y;

    for ( x = 0; x < ROWS; x++ ) {
        for ( y = 0; y < COLS; y++ ) {
            grid[x][y] = futureGrid[x][y];
        }
    }
    return (0);
}
