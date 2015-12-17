#ifndef PROJECT6_H_INCLUDED
#define PROJECT6_H_INCLUDED

typedef struct coords {
    int x;
    int y;

} COORDS;

typedef struct stack_struct{
    COORDS * pos;
        int top;
    int arr_size;
} STACK;

typedef struct mazeStruct
{
 char **arr;
 int xsize, ysize;
 int xstart, ystart;
 int xend, yend;
} MAZE;

MAZE maze_create (MAZE m1, FILE *src, int line);

int path_find(MAZE m1, STACK *s, int debug);

int push(STACK *c, int x, int y);

void pop(STACK *s, int *x, int *y);

STACK *create_stk(STACK *c);

void print_coords(STACK *s);

#endif // PROJECT6_H_INCLUDED
