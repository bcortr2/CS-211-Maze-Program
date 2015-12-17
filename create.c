#include<stdlib.h>
#include<stdio.h>
#include"project6.h"

//create new stack
STACK *create_stk(STACK *c){
	c = malloc(sizeof(STACK));
	c->pos = malloc(sizeof(COORDS)*2);
	c->top = -1;
	c->arr_size  = 2;
	return c;
}
