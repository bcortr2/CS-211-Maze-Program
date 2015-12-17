#include <stdio.h>
#include <stdlib.h>
#include "project6.h"

MAZE maze_create (MAZE m1, FILE *src, int line) {
	int xpos, ypos;
	int i,j;

	// initialize the maze to empty
	for (i = 0; i < m1.xsize+2; i++)
		for (j = 0; j < m1.ysize+2; j++)
			m1.arr[i][j] = '.';

	// mark the borders of the maze with *'s
	for (i=0; i < m1.xsize+2; i++) {
		m1.arr[i][0] = '*';
		m1.arr[i][m1.ysize+1] = '*';
	}
	for (i=0; i < m1.ysize+2; i++) {
		m1.arr[0][i] = '*';
		m1.arr[m1.xsize+1][i] = '*';
	}

	/* mark the starting and ending positions in the maze */
	m1.arr[m1.xstart][m1.ystart] = 's';
	m1.arr[m1.xend][m1.yend] = 'e';

	/* mark the blocked positions in the maze with *'s */
	while (fscanf (src, "%d %d", &xpos, &ypos) != EOF) {
		line++;
		/*if blocked coordinates given in file are outside of the size of the maze,
		 or the starting or ending position would be blocked, report to user and skip line*/
		if (xpos > m1.xsize || ypos > m1.ysize)
			fprintf(stderr, "Error encountered in line %i of file: blocked position was outside of given grid size. Line skipped\n", line);
		else if (m1.arr[xpos][ypos] == m1.arr[m1.xstart][m1.ystart] || m1.arr[xpos][ypos] == m1.arr[m1.xend][m1.yend])
			fprintf(stderr, "Error encountered in line %i of file: starting and ending positions cannot be blocked. Line skipped\n", line);
		else
			m1.arr[xpos][ypos] = '*';
	}
	// print out the initial maze
	for (i = 0; i < m1.xsize+2; i++) {
		for (j = 0; j < m1.ysize+2; j++)
			printf ("%c", m1.arr[i][j]);
		printf("\n");
	}
	return m1;
}
