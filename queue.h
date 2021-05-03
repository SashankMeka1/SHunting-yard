#include "node.h"
class queue{
	private://variables getters and setters
	node * bottom;
	node * top;
	public:
	void pop();
	void push(node * in_node);
	node * peak();
};
