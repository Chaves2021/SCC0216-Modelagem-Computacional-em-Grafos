#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <defines.h>

int main(void)
{
	GRAPH *graph;
	int n_cities, n_flights;
	int city0, city1;
	int dist, price;
	int source, dest;
	int i;

	scanf("%d %d", &n_cities, &n_flights);
	graph = graph_create(n_cities);

	for(i = 0; i < n_flights; i++)
	{
		scanf("%d %d %d %d", &city0, &city1, &dist, &price);
		graph_edge_insert(graph, city0, city1, dist, price);
	}
	scanf("%d %d", &source, &dest);

	graph_dijkstra(graph, source, dest);


	return SUCCESS;
}
