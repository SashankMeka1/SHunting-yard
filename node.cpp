#include "node.h"
node::node(char in_value, tree_node * in_tree){
	value = in_value;//read in value and tree_nodes
	tree = in_tree;
}
tree_node * node::get_tree(){//give the tree
	return tree;
}
node * node::getnext(){//get next node
	return next;
}
node::~node(){
	return;
}
void node::setnext(node * in_node){//ste teh next node
	next = in_node;
}
char node::getvalue(){//get the node's value
	return value;
}
void node::setvalue(char in_char){//set the value
	value = in_char;
}
