#ifndef _GRAPH_
#define _GRAPH_

typedef struct graph_elem GRAPH_ELEM;
typedef struct graph GRAPH;

//Function to create a graph
GRAPH *graph_create(int);
//Function to insert an edge in the graph list
int graph_edge_insert(GRAPH *, int, int, int, int);
//Function to delete the graph and all memory allocated by it
int graph_delete(GRAPH *);
//TODO
int graph_dijkstra(GRAPH *, int, int);

#endif
