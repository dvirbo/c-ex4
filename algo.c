#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

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
pDInode minInList(pDInode head)
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

int shortsPath_cmd(pnode head, int src, int dest)
{
    pDInode list = nodeList(head, src);

    pDInode u = minInList(list);
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
        u = minInList(list);
    }
    int dis = getpDInode(list, dest)->weight;

    if(dis == inf){
        dis  = -1;
    }

    while (list != NULL)
    {
        pDInode temp = list;
        list = list->next;
        free(temp);
    }
    return dis;
}