#include <stdio.h>
#include "circular_list.h"

int main(){
	
	node* l;
	init_circular_list(&l);

	for(int i = 10; i >= 1; i--){
		shift_circ(&l, i*37);
	}
	print_circ(l, 3);
	
	delete_circular_list(&l);
	
	return 0;
}

