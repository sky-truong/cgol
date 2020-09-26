#define ROWS 20
#define COLS 40
#define ALIVE 'X'
#define DEAD ' '
#define TICKS 50
#define IN 1
#define OUT 0

int chop (char *);
int displayArray (char *, int, int, int);
int countNeighbors (char grid[ROWS][COLS], int, int);
int applyRules (char grid[ROWS][COLS], char futureGrid[ROWS][COLS]);
int switchGrid (char grid[ROWS][COLS], char futureGrid[ROWS][COLS]);
int sameGrid (char grid[ROWS][COLS], char futureGrid[ROWS][COLS]);

