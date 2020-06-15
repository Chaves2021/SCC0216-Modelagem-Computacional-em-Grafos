#ifndef _GRAPH_
#define _GRAPH_

typedef struct graph GRAPH;

//Function to create a graph
GRAPH *graph_create(int);
//Function to insert an edge in the graph matrix
int graph_edge_insert(GRAPH *, int, int);
//Function to remove an edge in the graph matrix
int graph_edge_remove(GRAPH *, int, int);
//Function to print the graph matrix
int graph_print_matrix(GRAPH *);
//Function to delete the graph and all memory allocated by it
int graph_delete(GRAPH *);

#endif
