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
	int in_degree, out_degree;
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
		graph->elem[i]->in_degree = 0;
		graph->elem[i]->out_degree = 0;
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
	graph->elem[vertex0]->out_degree++;
	graph->elem[vertex1]->in_degree++;
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

int find_first_vertex(GRAPH *graph)
{
	int i;
	for(i = 0; i < graph->count_vertex; i++)
	{
		if(!graph->elem[i]->in_degree && 
				graph->elem[i]->status == not_visited) 
		{
			return i;
		}
	}
	return CYCLICAL;
}

int __graph_dfs(GRAPH *graph, int cur_vertex, int **sequence, int *index)
{
	DYN_LIST_SIMPLE_ELEM *next_vertex;

	graph->elem[cur_vertex]->status = visited;
	next_vertex = graph->elem[cur_vertex]->list->first;
	while(next_vertex)
	{
		if(graph->elem[next_vertex->value]->status == visited)
		{
			*index = -1;
		}
		else if(graph->elem[next_vertex->value]->status == not_visited &&
				*index != -1)
		{
			__graph_dfs(graph, next_vertex->value, sequence, index);
		}
		next_vertex = next_vertex->next;
	}
	graph->elem[cur_vertex]->status = processed;
	if(*index != -1)
	{
		//Add in the index and after increment it
		(*sequence)[(*index)++] = graph->elem[cur_vertex]->value;
	}
	return SUCCESS;
}

int check_all_vertex(GRAPH *graph)
{
	int i;
	int flag = TRUE;
	for(i = 0; i < graph->count_vertex && flag; i++)
	{
		if(graph->elem[i]->status != processed) flag = FALSE;
	}
	return flag;
}

int *graph_topological_order(GRAPH *graph)
{
	if(!graph) return NULL;
	if(!graph->elem) return NULL;

	int index = 0;
	int *sequence;
	int cur_vertex;
	cur_vertex = find_first_vertex(graph);
	if(cur_vertex == CYCLICAL) return NULL;
	sequence = (int *) malloc(graph->count_vertex * sizeof(int));

	__graph_dfs(graph, cur_vertex, &sequence, &index);
	while(!check_all_vertex(graph)) 
	{
		cur_vertex = find_first_vertex(graph);
		__graph_dfs(graph, cur_vertex, &sequence, &index);
	}
	if(index == -1) return NULL;
	else return sequence;


}
