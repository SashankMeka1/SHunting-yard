#include<iostream>
#include "tree.h"
using namespace std;
int main(){
	char in[150];
	cout << "Enter infix expression with no spaces."<<endl;
	cin.getline(in, 150);
	tree * Tree = new tree();//get expression run traversals for type of expression
	Tree->build_tree(in);
	cout << "Infix, postfix, or prefix"<<endl;
	cin.getline(in, 150);
	if(in[1] == 'n'){
		Tree->inorder(Tree->root);
	}
	else if(in[1] == 'o'){
		Tree->postorder(Tree->root);
	}
	else if(in[1] == 'r'){
		Tree->preorder(Tree->root);
	}
	delete Tree;
	return 0;
}
