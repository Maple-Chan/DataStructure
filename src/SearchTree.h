#ifndef __SEARCHTREE_H
#define __SEARCHTREE_H


#include <stdio.h> //NULL


class TreeNode;

typedef TreeNode* SearchTree;
typedef TreeNode* Position;

class TreeNode
{
	public:
	TreeNode(int x=0):value(x),left(NULL),right(NULL){}
	~TreeNode();
	//SearchTree MakeEmpty(SearchTree root);
	
	
	int value;
	TreeNode* left;
	TreeNode* right;
	
};

Position Find(SearchTree root,int value);
Position FindMin(SearchTree root);
Position FindMax(SearchTree root);
SearchTree Insert(SearchTree root,int value);
SearchTree Delete(SearchTree root,int del);

void printMid(SearchTree root);
void printPrev(SearchTree root);

#endif