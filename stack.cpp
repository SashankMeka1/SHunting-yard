#include "stack.h"
#include <cstdlib>
void stack::pop(bool del){
	if(top){//pop of teh top and go back
		node * to_delete = top;
		if(top->getprev()){
			top = top->getprev();
			top->setnext(nullptr);	
		}
		else{
			top = nullptr;
		}
		if(del){
			delete to_delete;
		}	
	}
}
void stack::push(node * in_node){// add new node
	if(top){
		top->setnext(in_node);
		in_node->setprev(top);
		top = top->getnext();
	}
	else{
		top = in_node;
	}
}
node * stack::peak(){//give top
	return top;
}
