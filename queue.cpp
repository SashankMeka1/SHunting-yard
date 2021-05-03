#include "queue.h"
#include <cstdlib>
using namespace std;
void queue::pop(){//pop and go to the next one
	if(bottom){
		node * to_delete = bottom;
		bottom = bottom->getnext();
		delete to_delete;
	}
}
void queue::push(node * in_node){//push onto queue
	if(bottom){
		top->setnext(in_node);
		top = top->getnext();
	}
	else{
		top = in_node;
		bottom = in_node;
	}
}
node * queue::peak(){//get the one to be popped next
	return bottom;
}
