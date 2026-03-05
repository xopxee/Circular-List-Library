#include <stdio.h>
#include "circular_list.h"

void init_circular_list(cl_node** pl){
	*pl = NULL;
}

void delete_circular_list(cl_node** pl){
	
	if(is_empty_cl(*pl))
		return;
	
	cl_node* aux;
	
	for(aux = *pl; aux->next != *pl; ){	//While the next cl_node isn´t the head.
		
		//Stores the address of the cl_node to be deleted.
		cl_node* current_cl_node = aux;
		
		//aux points to the next cl_node.
		aux = aux->next;
		
		free(current_cl_node);
	}
	free(aux);
	*pl = NULL;
}

void shift_circ(cl_node** pl, int num){
	
	cl_node* new_cl_node = (cl_node*)malloc(sizeof(cl_node));
	
	if(new_cl_node == NULL){
		perror("Failed to allocate memory!");
		exit(1);
	}
	
	//Fills the data.
	new_cl_node->num = num;
	
	if(is_empty_cl(*pl)){
		
		//new_cl_node points to itself.
		new_cl_node->next = new_cl_node;
		
		//Moves the head of the list to new_cl_node.
		*pl = new_cl_node;
	}
	else{
		cl_node* aux;
		
		//Finds the last cl_node (where the loop restarts);
		for(aux = *pl; aux->next != *pl; aux = aux->next);
		
		//new_cl_node points to the head of the list.
		new_cl_node->next = *pl;
		
		//Moves the head of the list to new_cl_node.
		*pl = new_cl_node;
		aux->next = new_cl_node;
	}
}

bool is_empty_cl(cl_node* l){
	return (l == NULL)? true : false;
}

void print_circ(cl_node* l, int loops){
	
	if(is_empty_cl(l)){
		printf("{ }\n");
		return;
	}
	
	cl_node* aux;
	
	printf("{ ");
	for(int i = 0; i < loops; i++){
		
		printf("| ");
		for(aux = l; aux->next != l; aux = aux->next){
			printf("%d ", aux->num);
		}
		printf("%d ", aux->num);
	}
	printf("| }\n");
}