#include <stdio.h>
#include <stdlib.h>

int displayArray (char *grid, int row, int col, int tick) {
    int i, j, index;

    system("clear");
    index = 0;
    printf (" ");
    while ( index < col ) {
        printf ("-");
        index++;
    }
    printf ("\n");

    for ( i = 0; i < row; i++ ) {
        printf ( "|");
        for ( j = 0; j < col; j++ ) {
            printf ( "%c", *(grid+(i*col)+j) );
        }
        printf ( "|");
        printf ("\n");
    }

    index = 0;
    printf (" ");
    while ( index < col ) {
        printf ("-");
        index++;
    }
    printf ("%d", tick);
    printf ("\n");

    return (0);
}