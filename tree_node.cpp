#include "tree_node.h"
#include <iostream>
using namespace std;
tree_node::tree_node(char in_value, tree_node * in_left, tree_node * in_right){
	value = in_value;
	left = in_left;//create node with value and children
	right = in_right;
}
tree_node::~tree_node(){//delete entire subtree
	if(left){
		delete left;
	}
	if(right){
		delete right;
	}
}
