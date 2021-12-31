#include <stdio.h>
#include "vertex.h"
#include "graph.h"

Graph *graph; //global

void build_graph_cmd() {
    if (graph->_size) {
        Graph_free(graph);
    }
    int number_of_nodes;
    scanf("%d", &number_of_nodes);
    graph = Graph_alloc();
    int src;
    pvertex prev = NULL;
    char n;
    int dest;
    int weight;
    int first = 1; //first node
    for (int i = 0; i <= number_of_nodes; i++) {

        if (scanf("%c", &n) == 'n') {
            scanf("%d", &src);
        }

        if (first) {
            Graph_insertFirst(graph, src);
            prev = graph->_head;
        } else {
            insertLast(graph,src);
            prev = prev->next;
        }


         first = -1;

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
    pvertex temp = get_node(node_id, graph->_head, graph->_size);
    if (temp == NULL) {
        insertLast(graph,node_id);
    } else {
        Node_free(temp);
        insertLast(graph,node_id);
        pvertex curr = get_node(node_id, graph->_head, graph->_size);
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
    //        p = &((*p)->next);
    pvertex *head = &(graph->_head);
    pvertex curr = *head;
    pvertex prev = *head;
    if (curr->id == id) {
        head = &(curr->next);
        del_in_edges((pvertex) head, id);
        Node_free(curr);
        curr = NULL;
    } else
        while (curr->id != id) {
            prev = curr;
            curr = curr->next;
        }
    prev->next = curr->next;
    del_in_edges((pvertex) head, id);
    Node_free(curr);
    curr = NULL;

}

int shortsPath_cmd() {

    return 0;
}