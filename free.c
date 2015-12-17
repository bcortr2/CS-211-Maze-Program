#include<stdlib.h>
#include<stdio.h>
#include"project6.h"

void free_stk(coord_ptr c){
    free(c->x);
    free(c->y);
    free(c);
    return;
}
