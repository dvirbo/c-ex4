CC = gcc
AR = ar
FLAGS= -Wall -Werror -g
all: graph 
graph: main.o graph.a
	$(CC) $(FLAGS) -o graph main.o graph.a
graph.a: graph.o algo.o
	$(AR) -rcs graph.a graph.o algo.o
main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c graph.h
graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c graph.h
algo.o: algo.c graph.h
	$(CC) $(FLAGS) -c algo.c graph.h


.PHONY: all clean
clean:
	rm -f *.o *.a graph