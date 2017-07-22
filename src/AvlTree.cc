#include "AvlTree.h"
#include <algorithm>

static int Height(AvlNode P)
{
	if(!P)
	{
		return -1;
	}
	else
	{
		return P->height;
	}
}

static AvlNode SingleRotateWithLeft(AvlNode K1)
{
	AvlNode K2=K1->left;
	K1->left=K2->right;
	K2->right=K1;
	K1->height=std::max(Height(K1->left),Height(K1->right))+1;
	K2->height=std::max(Height(K2->left),K1->height)+1;
	return K2;
}

static AvlNode SingleRotateWithRight(AvlNode K1)
{
	AvlNode K2=K1->right;
	K1->right=K2->left;
	K2->left=K1;
	K1->height=std::max(Height(K1->left),Height(K1->right))+1;
	K2->height=std::max(K1->height,Height(K2->right))+1;
	return K2;
}

static AvlNode DoubleRotateWithLeft(AvlNode K1)
{
	K1->left=SingleRotateWithRight(K1->left);

	return SingleRotateWithLeft(K1);

}

static AvlNode DoubleRotateWithRight(AvlNode K1)
{
	K1->right=SingleRotateWithLeft(K1->right);
	return SingleRotateWithRight(K1);
}

AvlNode Find(int x,AvlNode T)
{
	if(!T)
	{
		return NULL;
	}
	else if(T->value<x)
	{
		return Find(x,T->right);
	}
	else if(T->value>x)
	{
		return Find(x,T->left);
	}
	else
		return T;
}

AvlNode FindMin(AvlNode T)
{
	if(!T)
	{
		return NULL;
	}
	while(T->left)
	{
		T=T->left;
	}
	return T;


}

AvlNode FindMax(AvlNode T)
{
	if(!T)
	{
		return NULL;
	}
	while(T->right)
	{
		T=T->right;
	}
	return T;
}

AvlNode Insert(AvlNode T,int val)
{
	if(!T)
	{
		T=new AvlTree(val);
		return T;
	}
	else if(val<T->value)
	{
		T->left=Insert(T->left,val);
		if(Height(T->left)-Height(T->right)==2)
		{
			if(val < T->left->value)
			{
				//单旋转
				T=SingleRotateWithLeft(T);
			}
			else
			{
				//双旋转
				T=DoubleRotateWithLeft(T);

			}
		
		}

	}
	else if(val>T->value)
	{
		T->right=Insert(T->right,val);
		if(Height(T->right)-Height(T->left)==2)
		{
			if(val > T->right->value)
			{
				//单旋转
				T=SingleRotateWithRight(T);
			}
			else
			{
				//双旋转
				T=DoubleRotateWithRight(T);
			}
		}
	}

	T->height=std::max(Height(T->left),Height(T->right))+1;
	return T;

}

AvlNode Delete(AvlNode T,int val)
{
	if(T==NULL)
	{
		return NULL;
	}

	if(val<T->value)
	{
		T->left=Delete(T->left,val);
		if(Height(T->right)-Height(T->left)==2)
		{
			if(Height(T->right->left)>Height(T->right->right))
			{
				T=DoubleRotateWithRight(T);
			}
			else
			{
				T=SingleRotateWithRight(T);
			}
		}
	}
	else if(val>T->value)
	{
		T->right=Delete(T->right,val);
		if(Height(T->left)-Height(T->right)==2)
		{
			if(Height(T->left->right)>Height(T->left->left))
			{
				T=DoubleRotateWithLeft(T);
			}
			else
			{
				T=SingleRotateWithLeft(T);
			}
		}
	}
	else 
	{
		if(T->left && T->right)
		{
			AvlNode tmp=FindMin(T->right);
			T->value=tmp->value;
			T->right=Delete(T->right,tmp->value);
			if(Height(T->left)-Height(T->right)==2)
			{
				if(Height(T->left->right)>Height(T->left->left))
				{
					T=DoubleRotateWithLeft(T);
				}
				else
				{
					T=SingleRotateWithLeft(T);
				}
			}
		}
		else if(!T->left && !T->right)
		{
			delete T;
			T=NULL;
		}
		else
		{
			if(T->left)
			{
				AvlNode tmp=T;
				T=T->left;
				delete tmp;
			}
			else
			{
				AvlNode tmp=T;
				T=T->right;
				delete tmp;
			}
			
		}
	}
	if(T)
	{
		T->height=std::max(Height(T->left),Height(T->right))+1;
	}
	return T;



}

AvlTree::~AvlTree()
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

void printMid(AvlNode T)
{
	if(!T)
	{
		return;
	}
	else
	{
		printMid(T->left);
		printf("(%d,%d)   ",T->value,Height(T));
		printMid(T->right);
	
	}

}

void printPrev(AvlNode T)
{
	if(!T)
	{
		return;
	}
	else
	{
		printf("(%d,%d)   ",T->value,Height(T));
		printPrev(T->left);
		printPrev(T->right);
	
	}


}