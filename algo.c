#include <stdio.h>
#include "vertex.h"
#include "graph.h"

Graph *graph;
int bool = 0;

void build_graph_cmd() {
    if (bool == 1) {
        Graph_free(graph);
    }
    int number_of_nodes;
    scanf("%d", &number_of_nodes);
    graph = Graph_alloc();
    int src;
    pvertex prev = NULL;

    for (int i = 0; i <= number_of_nodes; i++) {
        char n;
        if (scanf("%c", &n) == 'n') {
            scanf("%d", &src);
        }

        if (src == 0) {
            Graph_insertFirst(graph, src, 0);
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
    bool = 1;
}

void insert_node_cmd() {
    int node_id;
    scanf("%d", &node_id);
    pvertex temp = get_node(node_id, graph->_head, graph->_size);
    if (temp == NULL) {
        insertLast(node_id, graph);
    } else {
        Node_free(temp);
        insertLast(node_id, graph);
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
        del_in_edges((pvertex *) head, id);
        head = &(curr->next);
        Node_free(curr);
        curr = NULL;
    } else
        while (curr->id != id && curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
        if(curr->id == id){
            *(prev)->next = *(curr)->next;
            del_in_edges((pvertex *) head, id);
            Node_free(curr);
            curr = NULL;
        }
}

int shortsPath_cmd() {

    return 0;
}