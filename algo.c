#include <stdio.h>
#include "vertex.h"
#include "graph.h"

Graph *graph = NULL;

void build_graph_cmd() {
    Graph_free(graph);
    int number_of_nodes;
    scanf("%d", &number_of_nodes);
    graph = Graph_alloc();
    int src;
    pvertex prev = NULL;

    for (int i = 0; i <= number_of_nodes; i++) {
        char n;
        scanf(" %c", &n);
        if (n == 110) {
            scanf(" %d", &src);
        }


        if (src == 0) {
            Graph_insertFirst(graph, src);
            prev = graph->_head;
        } else {
            insertLast(src, graph);
            prev = prev->next;
        }

        int dest;
        int weight;
        int first = -1;

        while (scanf("%d", &dest)) {
            scanf("%d", &weight);

            if (first == -1) {
                first_edge(prev, src, dest, weight);
                first = 0;
            } else {
                add_edge(src, dest, weight, prev);
            }
        }
    }

}

void insert_node_cmd() {
    int node_id;
    scanf("%d", &node_id);
    pvertex temp = get_node(node_id, &(graph->_head));
    if (temp == NULL) {
        insertLast(node_id, graph);
    } else {
        Node_free(temp);
        insertLast(node_id, graph);
        pvertex curr = get_node(node_id, &(graph->_head));
        int dest;
        int weight;
        int first = -1;

        while (scanf("%d", &dest)) {
            scanf("%d", &weight);
            if (first == -1) {
                first_edge(curr, node_id, dest, weight);
                first = 0;
            } else {
                add_edge(node_id, dest, weight, curr);
            }
        }
    }
}

void delete_node_cmd() {
    int id;
    scanf("%d", &id);
    if (id == graph->_head->id) {
        pvertex *temp = &graph->_head;
        graph->_head = graph->_head->next;
        Node_free((*temp));
        temp = NULL;
    } else {
        pvertex node_to_del = get_node(id, &(graph->_head));
        Node_free(node_to_del);
        del_in_edges(graph->_head, id);
        node_to_del = NULL;
    }
}

void print_graph() {
    pvertex nodeId = graph->_head;
    while (nodeId != NULL) {
        printf("Node %d: ", nodeId->id);

        pedge edgeId = nodeId->edges;
        while (edgeId != NULL) {
            pvertex dest = get_node(edgeId->dest,&(graph->_head));
            printf("dest %d: weight %d, ", dest->id, edgeId->weight);
            edgeId = edgeId->next;
        }
        printf("\n");
        nodeId = nodeId->next;
    }
}


int shortsPath_cmd() {
    return 0;
}