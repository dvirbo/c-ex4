#include <stdio.h>
#include "graph.h"
int main() {
    pnode p = NULL;
    pnode *head = &p; //currently, head is pointer to pointer
    char func;
    while (scanf("%c", &func) != EOF) {
        if (func == 'A') {
            build_graph_cmd(head);
        } else if (func == 'B') {
            insert_node_cmd(head);
        } else if (func == 'D') {
            delete_node_cmd(head);
        } else if (func == 'S') {
            int src = -1, dest  =-1;
            scanf("%d %d", &src, &dest);
            int distance = shortsPath_cmd(*head, src, dest);
            printf("Dijsktra shortest path: %d \n", distance);
        }
        else if (input == 'T') {
        int weight = TSP_cmd(*head);
        printf("TSP shortest path: %d \n", weight);

    }
    deleteGraph_cmd(head);
    return 0;
}