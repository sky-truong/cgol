#include <stdio.h>
#include <string.h>

int chop (char *line) {
    int lineLength;
    int i;
lineLength = strlen (line);
for ( i = 0; i < lineLength; i++ ) {
    if ( line[i] == '\n' ) {
        line[i] = '\0';
        return (0);
    }
}
return (-1);
}

