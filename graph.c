#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


void build_graph_cmd(pnode *head) {
    deleteGraph_cmd(head);
    int node_amount = 0;
    scanf("%d", &node_amount);
    char newNode;
    scanf("%c", &newNode);
    int count = 0;
    while (count < node_amount) {
        scanf("%c", &newNode); // in the first node it doesn't work..(will be 0)
        insert_node_cmd(head);
        count++;
    }
}

pnode getNode(pnode *head, int id) {
    pnode nodeId = *head;
    while (nodeId != NULL) {
        if (nodeId->node_num == id) {
            return nodeId;
        }
        nodeId = nodeId->next;
    }
    return NULL;
}

void insert_node_cmd(pnode *head) {
    int id = -1;
    int dest = -1;

    scanf("%id", &id);
    pnode src = getNode(head, id);
    if (src == NULL) { // the first node
        src = (pnode) malloc(sizeof(node));
        if (src == NULL) { //check if the malloc works
            return;
        }
        src->node_num = id;
        src->next = *head;
        src->edges = NULL;
        *head = src;
    } else {
        pedge e = src->edges;
        while (e != NULL) {
            // iterate until the last edge in edges - using to insert new node and delete all the prev edges
            pedge tmp = e->next;
            free(e);
            e = tmp;
        }
        src->edges = NULL;
    }
    int check = scanf("%d", &dest);
    pedge *edg = &(src->edges);
    while (check != 0 && check != EOF) {

        pnode destN = getNode(head, dest); //check if exist
        if (destN == NULL) { // if the est node isn't exist:
            destN = (pnode) malloc(sizeof(node));
            if (destN == NULL) {
                return;
            }
            destN->node_num = dest;
            destN->edges = NULL;
            destN->next = *head;
            *head = destN;
        }
        int weight = -1;
        scanf("%d", &weight);
        *edg = (pedge) malloc(sizeof(edge));
        if ((*edg) == NULL) { //check if the malloc works
            return;
        }
        (*edg)->weight = weight;
        (*edg)->endpoint = destN;
        (*edg)->next = NULL;
        edg = &((*edg)->next); //to the next adder
        check = scanf("%d", &dest);

    }
}

void deleteGraph_cmd(pnode *head) {
    pnode nodeId = *head;
    while (nodeId != NULL) {
        pedge edgeId = nodeId->edges;
        while (edgeId != NULL) {
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

void delete_node_cmd(pnode *head) {
    int key = -1;
    // define the needed variables:
    pnode nextNode = NULL;
    pnode currNode = NULL;
    pnode delNode = NULL;
    pedge currEdge = NULL;
    pedge nextEdge = NULL;

    scanf("%d", &key);
    delNode = getNode(head, key);
    // delete the node:
    if((*head) == delNode){ //head  == node to delete
        nextNode = (*head)->next;
        *head = nextNode;
    }
    else {
        currNode = *head;
        nextNode = currNode->next;
        while (nextNode != NULL) {
            if (nextNode == delNode) {
                nextNode = nextNode->next;
            }
            currNode = nextNode;
        }
    }
    currNode = *head; //reset the curr
    // in & out edges:
    while(currNode != NULL) {
        if (currNode->edges != NULL) { // the del node have out edges:
            currEdge = currNode->edges;
            if (currEdge->endpoint == delNode) { //in edges:
                nextEdge = currEdge->next;
                free(currEdge);
                currEdge = nextEdge;
            }
            else {
                currEdge = currNode->edges;
                while (currEdge->next != NULL) {
                    nextEdge = currEdge->next;
                    if (nextEdge->endpoint == delNode) {
                        nextEdge = nextEdge->next;
                        free(nextEdge);
                        currEdge = nextEdge;
                        break;
                    }
                    currEdge = currEdge->next;
                }
            }
        }
        currNode = currNode->next;
    }

    currEdge = delNode->edges;
    nextEdge = NULL;
    while (currEdge != NULL) {
        nextEdge = currEdge->next;
        free(currEdge);
        currEdge = nextEdge;
    }
    free(delNode);
}