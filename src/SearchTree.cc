#include "SearchTree.h"

#include <stdlib.h>   //free
#include <stdio.h>

/*
SearchTree TreeNode::MakeEmpty(SearchTree root)
{
	if(root)
	{
		MakeEmpty(root->left);
		MakeEmpty(root->right);
		delete root;

	}
	return NULL;
}
*/

TreeNode::~TreeNode()
{
	if(left)
	{
		delete left;
	}
	if(right)
	{
		delete right;
	}
	
}

Position Find(SearchTree root,int value)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->value==value)
	{
		return root;
	}
	else if(root->value<value)
	{
		return Find(root->right,value);
	}
	else
	{
		return Find(root->left,value);
	}
}
Position FindMin(SearchTree root)
{
	if(root==NULL)
	{
		return NULL;
	}
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}
Position FindMax(SearchTree root)
{
	if(root==NULL)
	{
		return NULL;
	}
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root;
}
SearchTree Insert(SearchTree root,int value)
{
	if(root==NULL)
	{
		root=new TreeNode(value);
		
	}
	else if(root->value<value)
			root->right=Insert(root->right,value);
	else if(root->value>value)
			root->left=Insert(root->left,value);
	
	return root;
}

SearchTree Delete(SearchTree root,int del)
{
	if(root==NULL)
	{
		
	}
	else if(root->value<del)
	{
		root->right=Delete(root->right,del);
		
	}
	else if(root->value>del)
	{
		root->left=Delete(root->left,del);
		
	}
	else 
	{
		if(root->right && root->left)
		{
			SearchTree tmp=FindMin(root->right);
			root->value=tmp->value;
			root->right=Delete(root->right,tmp->value);
			
		}
		else if(!root->right && !root->left)
		{
			
			delete root;
			root=NULL;
		}
		else
		{
			SearchTree tmp = root;
			if(root->left)
			{
				root=root->left;
			}
			else if(root->right)
			{
				root=root->right;
			}
			free(tmp);
		}
	}
	return root;

}

void printMid(SearchTree root)
{
	if(!root)
	{
		return;
	}
	else
	{
		printMid(root->left);
		printf("%d   ",root->value);
		printMid(root->right);	
	}


}
void printPrev(SearchTree root)
{
	if(!root)
	{
		return;
	}
	else
	{
		printf("%d   ",root->value);
		printPrev(root->left);
		printPrev(root->right);	
	}
}