#include <stdlib.h>
#include <stdio.h>
#include "project6.h"

//pop stack function
void pop(STACK *s, int *x, int *y){
	*x = s->pos[s->top].x;
	*y = s->pos[s->top].y;
	s->top--;
}
