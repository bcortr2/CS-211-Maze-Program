#include <stdio.h>
#include <stdlib.h>
#include "project6.h"

int path_find(MAZE m1, STACK *s, int debug){
	int found_flag = 0, i, j;
	int xcord = m1.xstart, ycord = m1.ystart;
//put starting coordinate on stack, mark as visited
	push(s, xcord, ycord);
	m1.arr[xcord][ycord] = '+';
//check in each cardinal direction for an unblocked, unvisited coordinate. Repeat until stack is empty or end found
	while (s->top != -1 && !found_flag){
		xcord = s->pos[s->top].x;
		ycord = s->pos[s->top].y;

		if (xcord == m1.xend && ycord == m1.yend){
			found_flag = 1;
			return 1;
		}
		if (m1.arr[xcord + 1][ycord] != '*' && m1.arr[xcord + 1][ycord] != '+'){
			push(s, xcord+1, ycord);
			m1.arr[xcord+1][ycord] = '+';
		}
		else if (m1.arr[xcord][ycord + 1] != '*' && m1.arr[xcord][ycord+1] != '+'){
			push(s, xcord, ycord+1);
			m1.arr[xcord][ycord+1] = '+';
		}
		else if (m1.arr[xcord-1][ycord] != '*' && m1.arr[xcord - 1][ycord] != '+'){
			push(s, xcord-1, ycord);
			m1.arr[xcord-1][ycord] = '+';
		}
		else if (m1.arr[xcord][ycord-1] != '*' && m1.arr[xcord][ycord-1] != '+'){
			push(s, xcord, ycord-1);
			m1.arr[xcord][ycord-1] = '+';
		}
		else{
			pop(s, &xcord, &ycord);
			if (debug)
				printf("Coordinate %i,%i was popped off the stack\n", xcord, ycord);
		}
	}
	return 0;
}

