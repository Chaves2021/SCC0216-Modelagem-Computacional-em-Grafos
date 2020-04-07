#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

struct graph
{
	int **matrix;
	int count_vertex;
	int count_edges;
};

GRAPH *graph_create(int n_vertex, int n_edges)
{
	int i;
	GRAPH *graph;
	graph = (graph *) calloc(1, sizeof(graph));

	graph->matrix = (int **) malloc(n_vertex * sizeof(int *));
	for(i = 0; i < n_vertex; i++) graph->matrix[i] = (int *) calloc(n_vertex, sizeof(int));
	count_vertex = n_vertex;

	return graph;
}

int graph_edge_insert(GRAPH *graph, int vertex0, int vertex1)
{
	if(!graph) return ERROR;
	if(!graph->matrix) return ERROR;

	graph->matrix[vertex0 - 1][vertex1 - 1] = graph->matrix[vertex1 - 1][vertex0 - 1] = 1;
	count_edges++;

	return SUCCESS;
}

int graph_edge_remove(GRAPH *graph, int vertex0, int vertex1)
{
	if(!graph) return ERROR;
	if(!graph->matrix) return ERROR;

	graph->matrix[vertex0 - 1][vertex1 - 1] = graph->matrix[vertex1 - 1][vertex0 - 1] = 0;
	count_edges--;

	return SUCCESS;
}

int graph_print_matrix(GRAPH *graph)
{
	if(!graph) return ERROR;
	if(!graph->matrix) return ERROR;

	for(i = 0; i < graph->count_vertex; i++)
	{
		for(j = 0; j < graph->count_vertex; j++) printf("%d ", graph->matrix[i][j]);
		printf("\n");
	}
	return SUCCESS;
}

int graph_delete(GRAPH *graph)
{
	if(!graph) return ERROR;
	if(!graph->matrix) return ERROR;

	for(i = 0; i < graph->n_vertex; i++) free(graph->matrix[i]);
	free(graph->matrix);
	free(graph);
}
