all: cgol

chop.o: chop.c
	gcc -ansi -Wall -c chop.c

displayArray.o: displayArray.c
	gcc -ansi -Wall -c displayArray.c

countNeighbors.o: countNeighbors.c
	gcc -ansi -Wall -c countNeighbors.c

applyRules.o: applyRules.c
	gcc -ansi -Wall -c applyRules.c

switchGrid.o: switchGrid.c
	gcc -ansi -Wall -c switchGrid.c

sameGrid.o: sameGrid.c
	gcc -ansi -Wall -c sameGrid.c

cgol.o: cgol.c
	gcc -ansi -Wall -c cgol.c

cgol: cgol.o chop.o displayArray.o countNeighbors.o applyRules.o switchGrid.o sameGrid.o
	gcc -ansi -Wall -o cgol cgol.o chop.o displayArray.o countNeighbors.o applyRules.o switchGrid.o sameGrid.o

clean:
	rm cgol cgol.o chop.o displayArray.o countNeighbors.o applyRules.o switchGrid.o sameGrid.o
