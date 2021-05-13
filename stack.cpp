#include "stack.h"
#include <cstdlib>
void stack::pop(bool del){
	node * to_delete = top;
	top = top->getnext();
	if(del){
		delete to_delete;
	}
}
void stack::push(node * in_node){// add new node
	in_node->setnext(top);
	top = in_node;
}
node * stack::peak(){//give top
	return top;
}
