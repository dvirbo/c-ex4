#ifndef GRAPH_
#define GRAPH_
#define inf 1000000
typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_
{
    pnode endpoint;
    int weight;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_
{
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

typedef struct DIJKSTRA_NODE_
{
    pnode node;
    int weight;
    int tag;
    struct DIJKSTRA_NODE_ *prev;
    struct DIJKSTRA_NODE_ *next;
} DInode, *pDInode;


void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void deleteGraph_cmd(pnode *head);
int shortsPath_cmd(pnode head, int src, int dest);
int TSP_cmd(pnode head);

#endif
