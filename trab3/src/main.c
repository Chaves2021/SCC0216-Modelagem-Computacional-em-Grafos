#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <defines.h>

int main(void)
{
	GRAPH *graph;
	int n_vertex, n_relations;
	int v0, v1;
	int i;

	scanf("%d %d", &n_vertex, &n_relations);
	graph = graph_create(n_vertex);

	for(i = 0; i < n_relations; i++)
	{
		scanf("%d %d", &v0, &v1);
		graph_edge_insert(graph, v0, v1);
	}

	int *sequence = graph_topological_order(graph);
	if(!sequence) printf("-1\n");
	else
	{
	}
	return SUCCESS;
}
