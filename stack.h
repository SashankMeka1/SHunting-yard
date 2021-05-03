#include "node.h"
class stack{
	private:
	node * top;
	node * bottom;
	public://variables getters and setters
	void pop(bool del);
	void push(node * in_node);	
	node * peak();
};
