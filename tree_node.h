#ifndef TREE_NODE_H
#define TREE_NODE_H
struct tree_node{//struct with variables and constructors
	tree_node * right;
	tree_node * left;
	char value;
	tree_node(char in_value, tree_node * in_left, tree_node * in_right);
	~tree_node();
};
#endif
