#ifndef _GRAPH_
#define _GRAPH_

typedef struct graph GRAPH;

GRAPH *graph_create(int);
int graph_edge_insert(GRAPH *, int, int);
int graph_edge_remove(GRAPH *, int, int);
int graph_print_matrix(GRAPH *);
int graph_delete(GRAPH *);

#endif
