#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include "vertex.h"

typedef struct _Graph {
    pvertex _head;
    int _size;
}Graph;

Graph* Graph_alloc();
void Graph_free(Graph* list);
int Graph_size(const Graph* list);
void Graph_insertFirst(Graph* list, int data);
double Graph_firstData(const Graph* list);
void insertLast(int data, Graph* list);

#endif