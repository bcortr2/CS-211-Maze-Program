#include<stdlib.h>
#include<stdio.h>
#include"project6.h"

int push(STACK *c, int x, int y){

	c->top++;
	//if more memory needed, resize and continue
	if (c->top == c->arr_size){
		c->arr_size = c->arr_size*2;
		c->pos = realloc(c->pos, (c->arr_size) * sizeof(COORDS));
	}
	c->pos[c->top].x = x;
	c->pos[c->top].y = y;

	return 1;
}


