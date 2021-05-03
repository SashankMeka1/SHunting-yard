#include "tree.h"
#include <iostream>
using namespace std;
tree::tree(){//set up stack queue and 2nd stack for tree building and shunting yard
	main_stack = new stack();
	main_queue = new queue();
	tree_stack = new stack();
}
tree::~tree(){//delete everything
	delete main_stack;
	delete main_queue;
	if(root){
		delete root;
	}
}
int tree::get_precedence(char input){
	if(input == '^'){//give precedence of operators for shunting yard
		return 3;
	}
	else if(input == '/' or input == '*'){
		return 2;
	}
	else if(input == '+' or input == '-'){
		return 1;
	}
	return 0;
}
char* tree::shunting(char * input){//loop throgh input string
	for(int i = 0; input[i] != '\0'; ++i){
		if(isalnum(input[i])){//add numbers and variables onto printqueu
			main_queue->push(new node(input[i], nullptr));
		}
		else if(input[i] == ')'){//if right bracket pop off until left bracket is seen
			while(main_stack->peak() and main_stack->peak()->getvalue() != '('){
				main_queue->push(main_stack->peak());
				main_stack->pop(false);
			}
			main_stack->pop(true);		
		}
		else if(input[i] == '('){//push left bracket
			main_stack->push(new node(input[i], nullptr));
		}
		else if(input[i] != ' '){//pop off operators from stack if they have more precedence then add new operator
			while(main_stack->peak() and get_precedence(main_stack->peak()->getvalue()) >= get_precedence(input[i])){
				main_queue->push(main_stack->peak());
				main_stack->pop(false);
			}
			main_stack->push(new node(input[i], nullptr));
		}

	}
	while(main_stack->peak()){//if stack is not empty put it onto print queue
		main_queue->push(main_stack->peak());
		main_stack->pop(false);
	}
	tree_size = 0;
	while(main_queue->peak()){//copy the print queue to input to get postfix
		input[tree_size] = main_queue->peak()->getvalue();
		main_queue->pop();
		tree_size++;
	}
	input[tree_size] = '\0';
	return input;
}
void tree::build_tree(char * input){
	tree_node * left;
	tree_node * right;
	input = shunting(input);
	for(int i = 0; i < tree_size; i++){//use stack to build tree from postfix
		if(isalnum(input[i])){//add variables and numbers to stack
			tree_stack->push(new node(input[i], new tree_node(input[i], nullptr, nullptr)));	
		}
		else{//if an operator, then just take previous two operands and build tree out of them
			right = tree_stack->peak()->get_tree();
			tree_stack->pop(true);
			left = tree_stack->peak()->get_tree();
			tree_stack->pop(true);
			tree_stack->push(new node(input[i], new tree_node(input[i],left, right)));

		}
	}//remaining node is tree node
	root = tree_stack->peak()->get_tree();
	tree_stack->pop(true);
}
void tree::inorder(tree_node * root){//inorder postorder and preorder traversals for infix postfix and prefix respectively
	if(root->left){
		inorder(root->left);
	}
	cout << root->value;
	if(root->right){
		inorder(root->right);
	}
}
void tree::preorder(tree_node * root){
	cout << root->value;
	if(root->left){		
		preorder(root->left);
	}
	if(root->right){
		preorder(root->right);
	}
}
void tree::postorder(tree_node * root){
 	if(root->left){
		postorder(root->left);
	}
	if(root->right){
		postorder(root->right);
	}
	cout << root->value;
}
