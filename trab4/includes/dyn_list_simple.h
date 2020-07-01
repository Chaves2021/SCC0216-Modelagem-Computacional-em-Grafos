#ifndef _DYN_LIST_SIMPLE_
#define _DYN_LIST_SIMPLE_

struct dyn_list_simple_elem
{
	int value;
	int dist;
	int price;
	struct dyn_list_simple_elem *next;
};
typedef struct dyn_list_simple_elem DYN_LIST_SIMPLE_ELEM;

struct dyn_list_simple
{
	DYN_LIST_SIMPLE_ELEM *first;
	DYN_LIST_SIMPLE_ELEM *last;
	int n_elem;
};
typedef struct dyn_list_simple DYN_LIST_SIMPLE;

//Function to create a list
DYN_LIST_SIMPLE *dyn_list_simple_create();
//Function to insert an element in the list
int dyn_list_simple_insert(DYN_LIST_SIMPLE *, int);
//Function to remove an element in the list
int dyn_list_simple_remove(DYN_LIST_SIMPLE *, int);
//Function to print the list
int dyn_list_simple_print(DYN_LIST_SIMPLE *);
//Function to delete the list and all memory allocated by it
int dyn_list_simple_delete(DYN_LIST_SIMPLE *);

//TODO
int dyn_list_simple_remove_first(DYN_LIST_SIMPLE *);

#endif
