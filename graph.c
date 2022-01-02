#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



void build_graph_cmd(pnode *head) {
    deleteGraph_cmd(head);
    int node_amount = 0;
    scanf("%d",&node_amount);
    char newNode;
    scanf("%c", &newNode);
    int count = 0;
    while (count < node_amount)
    {
        scanf("%c", &newNode); // in the first node it doesn't work..(will be 0)
        insert_node_cmd(head);
        count++;
    }
}

pnode getNode(pnode *head, int id)
{
    pnode nodeId = *head;
    while (nodeId != NULL)
    {
        if (nodeId->node_num == id)
        {
            return nodeId;
        }
        nodeId = nodeId->next;
    }
    return NULL;
}

void insert_node_cmd(pnode *head){
    int id = -1;
    int dest = -1;
    int weight = -1;

    scanf("%id", &id);
    pnode src = getNode(head, id);
    if(src == NULL){ // the first node
        src = (pnode)malloc(sizeof(node));
        if(src == NULL){ //check if the malloc works
        return;
    }
        src->node_num = id;
        src->next = *head;
        src->edges = NULL;
        *head = src;
} else{
    pedge e = src->edges;
        while (e != NULL){ // iterate until the last edge in edges
            pedge tmp = e->next;
            free(e);
            e = tmp;
        }
       src->edges = NULL;
    }
    int check = scanf("%d", &dest);
    while (check != 0 && check != EOF){

        pnode destN = getNode(head, dest); //check if exist
        if(destN == NULL){ // if the est node isn't exist:
            destN = (pnode)malloc(sizeof (node));
            if(destN == NULL){
                return;
            }
            destN->node_num = dest;
            destN->edges = NULL;
            destN->next = *head;
            *head = destN;
        }
        pedge *edg = &(src->edges);
        scanf("%d", weight);
        *edg = (pedge)malloc(sizeof (edge));
        if((*edg) == NULL){ //check if the malloc works
            return;
        }
        (*edg)->weight = weight;
        (*edg)->endpoint = destN;
        (*edg)->next = NULL;
        edg = &((*edg)->next); //to the next addr
        check = scanf("%d", &dest);

    }
}

void deleteGraph_cmd(pnode *head){
    pnode nodeId = *head;
    while (nodeId != NULL){
        pedge edgeId = nodeId->edges;
        while (edgeId != NULL){
            pedge eTmp = edgeId;
            edgeId = edgeId->next;
            free(eTmp);
        }
        pnode nTmp = nodeId;
        nodeId = nodeId->next;
        free(nTmp);
    }
    *head = NULL;
}

void delete_node_cmd(pnode *head){
    int del = -1;
    scanf("%d", &del);
    pnode curr = *head;
    pnode that = getNode(head,del);

    if(del == curr->node_num) {
        pedge edgeId = that->edges;
        while (edgeId != NULL){
            pedge tmp = edgeId->next;

        }

    }


}