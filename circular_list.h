#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

typedef struct cl_node cl_node;

struct cl_node{
	int num;
	cl_node* next;
	
};

void init_circular_list(cl_node** pl);

void delete_circular_list(cl_node** pl);

void shift_circ(cl_node** pl, int num);

bool is_empty_cl(cl_node* l);

void print_circ(cl_node* l, int loops);

#endif