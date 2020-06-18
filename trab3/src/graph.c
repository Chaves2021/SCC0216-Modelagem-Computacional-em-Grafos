#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <dyn_list_simple.h>
#include <defines.h>

struct graph_elem
{
	int value;
	enum status
	{
		not_visited,
		visited,
		processed
	}status;
	//A dynamic list simply linked array that represents the adjacency list
	DYN_LIST_SIMPLE *list;
};

//Graph struct
struct graph
{
	GRAPH_ELEM **elem;
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
	graph->elem = (GRAPH_ELEM **) malloc(n_vertex * sizeof(GRAPH_ELEM *));
	for(i = 0; i < n_vertex; i++) 
	{
		graph->elem[i] = (GRAPH_ELEM *) malloc(sizeof(GRAPH_ELEM));
		graph->elem[i]->list = dyn_list_simple_create();
	}

	return graph;
}

//The function returns an int log
int graph_edge_insert(GRAPH *graph, int vertex0, int vertex1)
{
	if(!graph) return ERROR;
	if(!graph->elem || !graph->elem[vertex0]) return ERROR;
	if(!graph->elem[vertex0]->list) return ERROR;

	dyn_list_simple_insert(graph->elem[vertex0]->list, vertex1);
	//dyn_list_simple_insert(graph->elem[vertex1]->list, vertex0);
	graph->count_edges++;

	return SUCCESS;
}

//The function returns an int log
int graph_edge_remove(GRAPH *graph, int vertex0, int vertex1)
{
	if(!graph) return ERROR;
	if(!graph->elem || !graph->elem[vertex0]) return ERROR;
	if(!graph->elem[vertex0]->list) return ERROR;

	dyn_list_simple_remove(graph->elem[vertex0]->list, vertex1);
	//dyn_list_simple_remove(graph->elem[vertex1]->list, vertex0);
	graph->count_edges--;

	return SUCCESS;
}

//The function returns an int log
int graph_print_list(GRAPH *graph)
{
	if(!graph) return ERROR;
	if(!graph->elem) return ERROR;

	int i;
	for(i = 0; i < graph->count_vertex; i++) 
	{
		printf("%d: ", i);
		dyn_list_simple_print(graph->elem[i]->list);
		printf("\n");
	}
	printf("\n");

	return SUCCESS;
}

//The function returns an int log
int graph_delete(GRAPH *graph)
{
	if(!graph) return ERROR;
	if(!graph->elem) return ERROR;

	int i;
	for(i = 0; i < graph->count_vertex; i++) 
	{
		//TODO
		//dyn_list_simple_delete(graph->elem[i]->list);
		free(graph->elem[i]);
	}
	free(graph->elem);
	free(graph);

	return SUCCESS;
}

//TODO
int graph_dfs(GRAPH *graph)
{
	if(!graph) return ERROR;
	if(!graph->elem) return ERROR;
}

//TODO
int *graph_topological_order(GRAPH *graph)
{
	int *sequence;
}

int graph_is_cyclical(GRAPH *graph)
{
	if(!graph) return ERROR;

	if(graph_dfs(graph) == CYCLICAL) return TRUE; 
	else return FALSE;
}
