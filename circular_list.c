#include <stdio.h>
#include "circular_list.h"

void init_circular_list(node** pl){
	*pl = NULL;
}

void delete_circular_list(node** pl){
	
	if(is_empty(*pl))
		return;
	
	node* aux;
	
	for(aux = *pl; aux->next != *pl; ){	//While the next node isn´t the head.
		
		//Stores the address of the node to be deleted.
		node* current_node = aux;
		
		//aux points to the next node.
		aux = aux->next;
		
		free(current_node);
	}
	free(aux);
	*pl = NULL;
}

void shift_circ(node** pl, int num){
	
	node* new_node = (node*)malloc(sizeof(node));
	
	if(new_node == NULL){
		perror("Failed to allocate memory!");
		exit(1);
	}
	
	//Fills the data.
	new_node->num = num;
	
	if(is_empty(*pl)){
		
		//new_node points to itself.
		new_node->next = new_node;
		
		//Moves the head of the list to new_node.
		*pl = new_node;
	}
	else{
		node* aux;
		
		//Finds the last node (where the loop restarts);
		for(aux = *pl; aux->next != *pl; aux = aux->next);
		
		//new_node points to the head of the list.
		new_node->next = *pl;
		
		//Moves the head of the list to new_node.
		*pl = new_node;
		aux->next = new_node;
	}
}

bool is_empty(node* l){
	return (l == NULL)? true : false;
}

void print_circ(node* l, int loops){
	
	if(is_empty(l)){
		printf("{ }\n");
		return;
	}
	
	node* aux;
	
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