#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include "../Linked List Library/linked_list.h"	//Includes only node definition

void init_circular_list(node** pl);

void delete_circular_list(node** pl);

void shift_circ(node** pl, int num);

bool is_empty(node* l);

void print_circ(node* l);

#endif