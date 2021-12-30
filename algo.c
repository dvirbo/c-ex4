#include <stdio.h>
#include "vertex.h"
#include "graph.h"

Graph *graph;

void A(){
    // A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 S 2 0
    // * *
    int number_of_nodes;
    scanf("%d", &number_of_nodes);
    graph = Graph_alloc();
    int src;
    char check;
    vertex *prev = NULL;

    for(int i = 0; i<=number_of_nodes; i++){

        scanf("%d",&src);

        if(src == 0){
            Graph_insertFirst(graph,src,0);
            prev = graph->_head;
        } else{
            insertLast(src,graph);
            prev = prev->next;
        }

        int dest;
        float weight;
        int first = -1;

        while(scanf("%d",&dest)){
            scanf("%f",&weight);
            if(first == -1){
                first_edge(prev,src,dest,weight);
                first = 0;
            } else{
                add_edge(src,dest,weight,prev);
            }
        }
    }
}