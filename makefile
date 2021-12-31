CC = gcc
AR = ar
FLAGS= -Wall -Werror -g
all: graph

graph: main.o graph.a

main.o: main.c graph.h
		$(CC) $(FLAGS) -c main.c
graph.a: graph.o vertex.o algo.o
		$(AR) -rcs graph.a graph.o vertex.o
graph.o: graph.c graph.h
		$(CC) $(FLAGS) -c graph.c
vertex.o: vertex.c vertex.h
		$(CC) $(FLAGS) -c vertex.c vertex.h
algo.o: algo.c algo.h
		$(CC) $(FLAGS) -c algo.c algo.h

.PHONY: all clean
clean:
		rm -f *.o *.a graph