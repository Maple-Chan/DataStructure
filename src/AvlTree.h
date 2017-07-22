#ifndef __AVLTREE_H
#define __AVLTREE_H
#include <stdio.h> //NULL

class AvlTree
{
	public:

	AvlTree(int x=0):value(x),height(0),left(NULL),right(NULL)
	{}
	
	~AvlTree();



	int value;
	AvlTree* left;
	AvlTree* right;
	int height;

};

typedef AvlTree* AvlNode;

AvlNode Find(int x,AvlNode T);

AvlNode FindMin(AvlNode T);

AvlNode FindMax(AvlNode T);

AvlNode Insert(AvlNode T,int val);

AvlNode Delete(AvlNode T,int val);

void printMid(AvlNode T);

void printPrev(AvlNode T);
#endif