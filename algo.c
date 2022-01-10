#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int weight = inf;
int size = -1;
int j;
pnode graph;

pDInode nodeList(pnode first, int src)
{
    pDInode head = NULL;
    pDInode *id = &head;
    while (first != NULL)
    {
        (*id) = (pDInode)malloc(sizeof(DInode));
        if ((*id) == NULL)
        {
            return NULL;
        }

        (*id)->node = first;

        if (first->node_num == src)
        {
            (*id)->prev = (*id);
            (*id)->weight = 0;
        }
        else
        {
            (*id)->prev = NULL;
            (*id)->weight = inf;
        }
        (*id)->tag = 0;
        (*id)->next = NULL;
        id = &((*id)->next);
        first = first->next;
    }
    return head;
}

pDInode getpDInode(pDInode list, int id)
{
    while (list != NULL)
    {
        if (list->node->node_num == id)
        {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

pDInode popMin(pDInode head)
{
    pDInode min = NULL;
    while (head != NULL)
    {
        if ( head->weight < inf && !head->tag && (min == NULL || min->weight < head->weight))
        {
            min = head;
        }
        head = head->next;
    }
    if (min != NULL)
    {
        min->tag = 1; //visit
    }
    return min;
}

int shortsPath_cmd(pnode head, int src, int dest)
{
    pDInode list = nodeList(head, src);

    pDInode u = popMin(list);
    while (u != NULL)
    {
        pedge edgeIndex = u->node->edges;
        while (edgeIndex != NULL)
        {
            //relaxation
            pDInode v = getpDInode(list, edgeIndex->endpoint->node_num);
            int newDist = u->weight + edgeIndex->weight;
            if (v->weight > newDist)
            {
                v->weight = newDist;
                v->prev = u;
            }
            edgeIndex = edgeIndex->next;
        }
        u = popMin(list);
    }
    int dis = getpDInode(list, dest)->weight;

    if(dis == inf){
        dis  = -1;
    }

    while (list != NULL)  // iter all the list and free
    {
        pDInode temp = list;
        list = list->next;
        free(temp);
    }
    return dis;
}

int *createList(){
    int *list = (int *)malloc(sizeof(int) * size);
    if (list == NULL)
    {
        return NULL;
    }
    int i = 0;
    while(i<size){
        scanf("%d", &list[i]);
        i++;
    }
    return list;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void calculateWeight(int *arr)
{
    int tempWeight = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int dis = shortsPath_cmd(graph, arr[i], arr[i + 1]);
        if (dis == -1)
        {
            tempWeight = inf;
            return;
        }
        tempWeight += dis;
    }
    if (tempWeight < weight)
    {
        weight = tempWeight;
    }
}
int *copyList(int *list){
    int *copy = (int *)malloc(sizeof(int) * size);
    if(copy == NULL){
        return NULL;
    }
    int i = 0;
    while (i<size){
        copy[i] = list[i];
        i++;
    }
    return copy;
}

void allPaths(int first, int *arr){
    if (first == size - 1)
    {
        calculateWeight(arr);
        return;
    }
    for (int i = first; i < size; ++i)
    {
        int *copy = copyList(arr);
        swap(&copy[first], &copy[i]);
        allPaths(first + 1, copy);
        free(copy);
        copy = NULL;
    }
}

int TSP_cmd(pnode head){
    graph = head;
    scanf("%d", &size);
    int *list = createList();
    // int *copy = copyList(list);
    allPaths(0, list);
    if(weight == inf){
        weight = -1;
    }
    return  weight;
}
