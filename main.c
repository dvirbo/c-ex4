#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
int main()
{
    pnode *head = NULL; //currently, head is pointer to pointer
    char func = '\0';
    while (scanf("%c", &func) != EOF) {
        if (func == 'A') {
            build_graph_cmd(head);
        } else if (func == 'B') {
            insert_node_cmd(head);
        } else if (func == 'D') {
            delete_node_cmd(head);
        } else if (func == 'S') {
            shortsPath_cmd(*head);
        }
    }
    deleteGraph_cmd(head);
    return 0;
}