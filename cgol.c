#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameOfLife.h"

int main ( int argc, char *argv[] ) {

    /*Read in file variables*/
    char grid [ROWS][COLS];
    char futureGrid [ROWS][COLS];
    int i, j;
    int numRows, numTotal, state;
    numRows = numTotal = 0;
    state = OUT;
    char c;
    FILE *f1;
    int tick, flag, originalTick;
    originalTick = tick = flag = 0;

    /*User's input variables*/
    char strStart[10];
    char strCont[10];
    int repeat, end;
    repeat = end = 0;

    if ( argc < 1 || argc > 3 ) {
        printf ( "Please input seed text file name and number of run times.\n");
    } else if ( argc != 3 ) {
        tick = TICKS;
    } else {
        tick = atoi(argv[2]);
    }

    originalTick = tick;

    /*Open seed file*/
    if ( (f1 = fopen(argv[1], "r")) != NULL ) {
        /*Check if 20x40*/
        while ( (c = fgetc(f1)) != EOF ) {
            if ( c == '\n') {
                numRows++;
            }
            if ( c == ' ' || c == '\n' ) {
                state = OUT;
            } else if ( state == OUT ) {
                state = IN;
                numTotal++;
            }
        }
        if ( (numRows != ROWS) && (numTotal != ROWS*COLS) ) {
            printf ("Please use 20x40 seed file.\n");
            return (0);
        }
        rewind(f1);
        /*Read in*/
        for ( i = 0; i < ROWS; i++ ) {
            for ( j = 0; j < COLS; j++ ) {
                fscanf( f1, " %c", &grid[i][j] ); /*Scan char and skip space*/
                if ( grid[i][j] == '0' ) { /* 0's to blanks */
                    grid[i][j] = DEAD;
                } else if ( grid[i][j] == '1' ) { /* 1's to X's */
                    grid[i][j] = ALIVE;
                }
            }
        }
    } else {
    printf ( "Cannot open %s\n", argv[1] );
    return ( -2 );
   }
    /*Close seed file*/
    fclose(f1);

    /*Print original grid*/
    displayArray ( &grid[0][0], ROWS, COLS, 0 );

    /*Ask user to start*/
    while (repeat == 0) {
        printf ("Start? (y or n): ");
        fgets (strStart, 10, stdin);
        chop(strStart);

        if (strcmp ("y", strStart) == 0 ) {
            repeat = 1;
        } else if ( strcmp ("y", strStart) != 0 && strcmp ("n", strStart) != 0) {
            printf ("Please input y or n.\n");
            repeat = 0;
        } else {
            return (0);
        }
    }

    /*Game of Life*/
    i = 1;
    flag = 0;
    repeat = 0;
    while ( end == 0) {
        while ( (i < tick+1) && (flag == 0) ) {
            repeat = 0;
            applyRules ( grid, futureGrid );
            system ("sleep 0.25");
            displayArray ( &futureGrid[0][0], ROWS, COLS, i );
            flag = sameGrid(grid, futureGrid);
            switchGrid ( grid, futureGrid);
            i++;
        }
        if ( flag != 0 ) {
            end = 1;
            return (0);
            }
        while (repeat == 0) {
            printf ("Continue? (y or n): ");
            fgets (strCont, 10, stdin);
            chop(strCont);

            if (strcmp ("y", strCont) == 0 ) {
                end = 0;
                repeat = 1;
                tick = originalTick + tick;
            } else if ( strcmp ("y", strCont) != 0 && strcmp ("n", strCont) != 0) {
                printf ("Please input y or n.\n");
                repeat = 0;
            } else {
                repeat = 1;
                end = 1;
            }
        }
    }
    return (0);
}
