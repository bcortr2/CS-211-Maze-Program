CC=gcc
CFLAGS=-I.
DEPS = project6.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

project5: main.o maze.o pathfind.o push.o pop.o create.o print_coords.o
	gcc -o project6 main.o maze.o pathfind.o push.o pop.o create.o print_coords.o -I.
	
clean :
	rm project6.exe main.o maze.o pathfind.o push.o pop.o create.o print_coords.o

