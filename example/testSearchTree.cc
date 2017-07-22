#include "SearchTree.h"
#include <stdio.h>

int main()
{
	SearchTree root=new TreeNode(6);
	root->left=new TreeNode(2);
	root->right=new TreeNode(8);
	root->left->left=new TreeNode(1);
	root->left->right=new TreeNode(4);
	root->left->right->left=new TreeNode(3);

	printMid(root);
	printf("\n");
	printPrev(root);
	printf("\n");


	//Insert
	Insert(root,7);
	Insert(root,5);
	printMid(root);
	printf("\n");
	printPrev(root);
	printf("\n");

	//Delete
	Delete(root,4);
	printMid(root);
	printf("\n");
	printPrev(root);
	printf("\n");

	delete root;

	return 0;


}