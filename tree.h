#include "tree_node.h"
#include "stack.h"
#include "queue.h"
class tree{
	private:
	stack *main_stack;
	stack * tree_stack;//variables getters and setters
	queue *main_queue;
	int tree_size;
	public:
	tree_node * root;
	tree();
	~tree();
	void inorder(tree_node * root);
	void preorder(tree_node * root);
	void postorder(tree_node * root);
	char *shunting(char * input);
	void build_tree(char * input);
	int get_precedence(char input);	


};
