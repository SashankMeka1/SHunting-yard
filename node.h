#include "tree_node.h"
#ifndef NODE_H
#define NODE_H
class node{
	private:
	node * next;
	char value;//set up variables getters setters
	tree_node * tree;
	public:
	~node();
	tree_node * get_tree();
	node(char in_value, tree_node * in_tree);
	node * getnext();
	void setnext(node * in_node);
	char getvalue();
	void setvalue(char in_char);
	node * getprev();
	void setprev(node * in_node);
};
#endif
