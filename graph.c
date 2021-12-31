#include "graph.h"
#include "vertex.h"

Graph* Graph_alloc() {
    Graph* p= (Graph*)malloc(sizeof(Graph));
    p->_head= NULL;
    p->_size= 0;
    return p;
}

void Graph_free(Graph* list) {
    if (list==NULL) return;
    pvertex p1= list->_head;
    pvertex p2;
    while(p1) {
        p2= p1;
        p1= p1->next;
        Node_free(p2);
    }
    free(list);
    free(p1);
    free(p2);
    p1 = NULL;
    p2 = NULL;
}

int Graph_size(const Graph* list) {
    return list->_size;
}

double Graph_firstData(const Graph* list) {
    return list->_head->id;
}

void Graph_insertFirst(Graph* list, int data) {
    list->_head= add_node(data, list->_head);
    ++(list->_size);
}

void insertLast(Graph* list,int data) {
    pvertex head= list->_head;
    pvertex ptr ,temp;
    ptr = head;
    temp = add_node(data, NULL);
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}
