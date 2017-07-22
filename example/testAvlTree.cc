#include "AvlTree.h"




int main()
{
	AvlNode root=new AvlTree(5);
	root=Insert(root,3);
	root=Insert(root,6);
	root=Insert(root,4);
	root=Insert(root,7);
	root=Insert(root,2);
	root=Insert(root,1);

	printMid(root);
	printf("\n");
	printPrev(root);
	printf("\n");

	root=Delete(root,3);

	printMid(root);
	printf("\n");
	printPrev(root);
	printf("\n");


	delete root;
	return 0;

}