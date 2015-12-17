#include <stdio.h>
#include <stdlib.h>
#include "project6.h"

int main(int argc, char *argv[]){
	int i, j, arg = 1, line = 0, size_flag = 0, start_flag = 0, end_flag = 0, found_flag = 0, debug = 0;
	MAZE m1;
	STACK *xy = create_stk(xy);
	FILE *src;
//check if user wants debugging option turned on
	if (argc == 3){
        //check the position of -d debug signal in argv and save it for file reference (if no debugging requested variable initially set to 1
		if (strcmp(argv[1], "-d") == 0){
			debug = 1;
			arg = 2;
		}
		else if (strcmp(argv[2], "-d") == 0){
			debug = 1;
			arg = 1;
		}
		else{
			printf("Too many arguments of incorrect type\n");
			exit(0);
		}
	}
//if file bad exit
	src = fopen( argv[arg], "r" );
	if (src == NULL){
		fprintf(stderr,"File not found\n");
		exit(0);
	}
    //read in size of maze. read until valid data found, skipping invalid data. if none found, exit.
	while(!size_flag){
		line++;
		//in attempting to read valid size data, none was found, inform user, exit
		if (fscanf(src, "%d %d", &m1.xsize, &m1.ysize) == EOF){
			fprintf(stderr, "Not enough valid data was found in the file to complete program. Please check file\n");
			exit(0);
		}
		//inform user of invalid data if any
		if (m1.xsize < 1 || m1.ysize < 1){
			fprintf(stderr, "Error encountered in line %i of file: neither row size nor column size may be zero. Line skipped.\n", line);
		}
		//good data create 2d array
		else {
			m1.arr = malloc (sizeof(char*)*(m1.xsize+2));
			for(i=0;i<m1.xsize+2;i++)
				m1.arr[i] = malloc(sizeof(char) * (m1.ysize + 2));
			size_flag = 1;
		}
	}
    //read in starting position. read until valid data found, skipping invalid data. if none found, exit.
	while (!start_flag){
		line++;
			//in attempting to read valid start location data, none was found, inform user, exit
		if (fscanf (src, "%d %d", &m1.xstart, &m1.ystart) == EOF){
			fprintf(stderr, "Not enough valid data was found in the file to complete program. Please check file\n");
			exit(0);
		}
		//inform user of invalid data if any
		if (m1.xstart > m1.xsize || m1.ystart > m1.ysize)
			fprintf(stderr, "Error encountered in line %i of file: the starting position was outside the stated bounds of the grid. Line skipped\n", line);
		else
			start_flag = 1;
	}
//read in ending position. read until valid data found, skipping invalid data. if none found, exit.
	while(!end_flag){
		line++;
		//in attempting to read valid start location data, none was found, inform user, exit
		if (fscanf (src, "%d %d", &m1.xend, &m1.yend) == EOF){
			fprintf(stderr, "Not enough valid data was found in the file to complete program. Please check file\n");
			exit(0);
		}
		//inform user of invalid data if any
		if (m1.xend > m1.xsize || m1.yend > m1.ysize)
			fprintf(stderr, "Error encountered in line %i of file: the ending position was outside the stated bounds of the grid. Line skipped\n", line);
		else
			end_flag = 1;
	}

	printf ("size: %d, %d\n", m1.xsize, m1.ysize);
	printf ("start: %d, %d\n", m1.xstart, m1.ystart);
	printf ("end: %d, %d\n", m1.xend, m1.yend);

	m1 = maze_create(m1, src, line);

	found_flag = path_find(m1, xy, debug);
//if valid path through maze found, call function to print coordinate path out
	if (found_flag){
		printf("Coordinate path out of maze:\n");
		print_coords(xy);
	}
	//no valid path found out of maze
	else
		printf("The maze has no solution\n");
	/*  below is code that prints out maze with path taken by algorithm if useful
	for (i = 0; i < m1.xsize+2; i++)
	{
		for (j = 0; j < m1.ysize+2; j++)
			printf ("%c", m1.arr[i][j]);
		printf("\n");
	} */

	fclose(src);

	for(i=0;i<m1.xsize+2;i++)
		free(m1.arr[i]);

	free(m1.arr);
	free(xy->pos);
	free(xy);
	return 0;
}

