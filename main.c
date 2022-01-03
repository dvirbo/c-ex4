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
//        } else if (func == 'S') {
//            shortsPath_cmd(*head);
//        }
        }
    }
    deleteGraph_cmd(head);
    return 0;
}