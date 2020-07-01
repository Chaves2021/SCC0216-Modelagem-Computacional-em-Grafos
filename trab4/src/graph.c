#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <dyn_list_simple.h>
#include <defines.h>

struct graph_elem
{
	int value;
	int isVisited;
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
		graph->elem[i]->value = i;
	}

	return graph;
}

//The function returns an int log
int graph_edge_insert(GRAPH *graph, int vertex0, int vertex1, int dist, int price)
{
	if(!graph) return ERROR;
	if(!graph->elem || !graph->elem[vertex0]) return ERROR;
	if(!graph->elem[vertex0]->list) return ERROR;

	dyn_list_simple_insert(graph->elem[vertex0]->list, vertex1, dist, price);
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
		dyn_list_simple_delete(graph->elem[i]->list);
		free(graph->elem[i]);
	}
	free(graph->elem);
	free(graph);

	return SUCCESS;
}

int graph_isVisited(GRAPH *graph)
{
	int i;
	for(i = 0; i < graph->count_vertex; i++)
	{
		if(!graph->elem[i]->isVisited) 
		{
			return FALSE;
		}
	}

	return TRUE;
}

int min_dist(GRAPH *graph, int *dist)
{
	int i;
	int min = EMPTY;

	for(i = 0; i < graph->count_vertex; i++)
	{
		if(!graph->elem[i]->isVisited && dist[i] != INFINITE && (dist[i] < min || min == EMPTY)) 
			min = graph->elem[i]->value;
	}
	return min;
}

int graph_edge_relax(GRAPH *graph, int **dist, int **price, int **prev, int actual)
{
	DYN_LIST_SIMPLE_ELEM *next = graph->elem[actual]->list->first;
	while(next)
	{
		if(graph->elem[next->value]->isVisited == FALSE &&
				((*dist)[next->value] == INFINITE ||
			         (*dist)[next->value] > (*dist)[actual] + next->dist))
		{
			(*dist)[next->value] = (*dist)[actual] + next->dist;
			(*price)[next->value] = (*price)[actual] + next->price;
			(*prev)[next->value] = actual;
			next = next->next;
		}
		else next = next->next;
	}

	return SUCCESS;
}

int graph_dijkstra(GRAPH *graph, int source, int dest)
{
	int i;
	int *dist = (int *) malloc(graph->count_vertex * sizeof(int));
	int *price = (int *) calloc(graph->count_vertex, sizeof(int));
	int *prev = (int *) malloc(graph->count_vertex * sizeof(int));
	int actual = source;
	for(i = 0; i < graph->count_vertex; i++) 
	{
		dist[i] = INFINITE;
		prev[i] = EMPTY;
	}

	dist[source] = 0;

	while(!graph_isVisited(graph))
	{
		if(!graph->elem[actual]->isVisited)
		{
			graph->elem[actual]->isVisited = TRUE;
			graph_edge_relax(graph, &dist, &price, &prev, actual);
			actual = min_dist(graph, dist);
		}
	}

	actual = dest;
	printf("%d ", dest);
	while(prev[actual] != EMPTY) 
	{
		printf("%d ", prev[actual]);
		actual = prev[actual];
	}

	printf("\n%d %d\n", dist[dest], price[dest]);

	return SUCCESS;
}
