#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <dyn_list_simple.h>
#include <defines.h>

//Graph struct
struct graph
{
	//A dynamic list simply linked array that represents the adjacency list
	DYN_LIST_SIMPLE **list;
	int count_vertex;
	int count_edges;
};

//The function returns the graph allocated
GRAPH *graph_create(int n_vertex)
{
	int i;
	GRAPH *graph;
	graph = (GRAPH *) calloc(1, sizeof(GRAPH));

	graph->count_vertex = n_vertex;
	graph->list = (DYN_LIST_SIMPLE **) malloc(n_vertex * sizeof(DYN_LIST_SIMPLE *));
	for(i = 0; i < n_vertex; i++) graph->list[i] = dyn_list_simple_create();

	return graph;
}

//The function returns an int log
int graph_edge_insert(GRAPH *graph, int vertex0, int vertex1)
{
	if(!graph) return ERROR;
	if(!graph->list) return ERROR;

	dyn_list_simple_insert(graph->list[vertex0], vertex1);
	//dyn_list_simple_insert(graph->list[vertex1], vertex0);
	graph->count_edges++;

	return SUCCESS;
}

//The function returns an int log
int graph_edge_remove(GRAPH *graph, int vertex0, int vertex1)
{
	if(!graph) return ERROR;
	if(!graph->list) return ERROR;

	dyn_list_simple_remove(graph->list[vertex0], vertex1);
	dyn_list_simple_remove(graph->list[vertex1], vertex0);
	graph->count_edges--;

	return SUCCESS;
}

//The function returns an int log
int graph_print_list(GRAPH *graph)
{
	if(!graph) return ERROR;
	if(!graph->list) return ERROR;

	int i;
	for(i = 0; i < graph->count_vertex; i++) 
	{
		printf("%d: ", i);
		dyn_list_simple_print(graph->list[i]);
		printf("\n");
	}
	printf("\n");

	return SUCCESS;
}

//The function returns an int log
int graph_delete(GRAPH *graph)
{
	if(!graph) return ERROR;
	if(!graph->list) return ERROR;

	int i;
	for(i = 0; i < graph->count_vertex; i++) dyn_list_simple_delete(graph->list[i]);
	free(graph->list);
	free(graph);

	return SUCCESS;
}

//TODO
//think what dfs can return to see if the graph is circle or not
int graph_dfs(GRAPH *graph)
{
}

int graph_is_circle(GRAPH *graph)
{
	if(!graph) return ERROR;
	if(!graph->list) return ERROR;

	int ret = graph_dfs(graph);
}
