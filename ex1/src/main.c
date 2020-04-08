#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <defines.h>

int main(void)
{
	int n_vertex, n_edges, n_op;
	int vertex0, vertex1;
	int i, op;
	GRAPH *graph;

	scanf("%d %d", &n_vertex, &n_edges);
	graph = graph_create(n_vertex);

	for(i = 0; i < n_edges; i++)
	{
		scanf("%d %d", &vertex0, &vertex1);
		graph_edge_insert(graph, vertex0, vertex1);

	}

	scanf("%d", &n_op);
	scanf("%d", &op);
	for(i = 0; i < n_op; i++)
	{
		switch(op)
		{
			case 1:
				scanf("%d %d", &vertex0, &vertex1);
				graph_edge_insert(graph, vertex0, vertex1);
				break;
			case 2:
				scanf("%d %d", &vertex0, &vertex1);
				graph_edge_remove(graph, vertex0, vertex1);
				break;
			case 3:
				graph_print_matrix(graph);
				break;
			default:
				break;
		}
		scanf("%d", &op);
	}

	graph_delete(graph);
	return SUCCESS;
}
