#include <stdio.h>
#include <stdlib.h>
#include "project6.h"
//recursively print out path to exit found by program
void print_coords(STACK *s){
 if (s->top == -1)
        return;
    int x, y;

    pop(s, &x, &y);

    print_coords(s);
    //everything popped, print starting with first pushed in
    printf("%i,%i\n", x, y);
}
