#ifndef __RBTREE_HPP
#define __RBTREE_HPP
#include <iostream>
using namespace std;



enum RBTColor{RED,BLACK};

template<class T>
class RBTNode
{
	public:
		RBTColor color;
		T key;
		RBTNode *left;
		RBTNode *right;
		RBTNode *parent;

		RBTNode(T value,RBTColor c,RBTNode *p,RBTNode* l,RBTNode* r):
			key(value),
			color(c),
			left(l),
			right(r),
			parent(p)

		{
		}
};


template<class T>
class RBTree
{
	private:
		RBTNode<T>* mRoot;
	public:
		RBTree();
		~RBTree();

		void preOrder();
		void inOrder();
		void postOrder();

		RBTNode<T>* search(T key);

		//T minimum();
		//T maximum();

		//RBTNode<T>* successor(RBTNode<T>* x );

		void insert(T key);
		void remove(T key);

		void destroy();

		void print();
	private:
		void preOrder(RBTNode<T>* tree)const;
		void inOrder(RBTNode<T>* tree)const;
		void postOrder(RBTNode<T>* tree)const;

		RBTNode<T>* search(RBTNode<T>* tree,T key)const;

		void leftRotate(RBTNode<T>* &root,RBTNode<T>* x);

		void rightRotate(RBTNode<T>* &root,RBTNode<T>* x);

		void insert(RBTNode<T>* &root,RBTNode<T>* node);
		void insertFixUp(RBTNode<T>* &root,RBTNode<T>* node);
		
		void remove(RBTNode<T>* &root,RBTNode<T>* node);
		void removeFixUp(RBTNode<T>* &root,RBTNode<T>* node,RBTNode<T>* parent);

		void destroy(RBTNode<T>* &tree);

  #define rb_parent(r) ((r)->parent)
  #define rb_color(r)  ((r)->color)
  #define rb_is_red(r) ((r)->color==RED)
  #define rb_is_black(r) ((r)->color==BLACK)
  #define rb_set_red(r) do{ (r)->color=RED; }while(0)
  #define rb_set_black(r) do{ (r)->color=BLACK; }while(0)
  #define rb_set_parent(r,p) do{ (r)->parentr=(p); }while(0)
  #define rb_set_color(r,c) do{ (r)->color=(c); }while(0)

};




//构造函数
template<class T>
RBTree<T>::RBTree():mRoot(NULL)
{
	mRoot=NULL;
}

template<class T>
RBTree<T>::~RBTree()
{
	destroy();
}

//遍历：前序遍历、中序遍历、后序遍历
template<class T>
void RBTree<T>::preOrder(RBTNode<T>* tree) const
{
	if(tree)
	{
		cout<<"("<<tree->key<<",  "<<(rb_is_red(tree)?"r":"b")<<")  ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template<class T>
void RBTree<T>::inOrder(RBTNode<T>* tree) const
{
	if(tree)
	{		
		inOrder(tree->left);
		cout<<"("<<tree->key<<",  "<<(rb_is_red(tree)?"r":"b")<<")  ";
		inOrder(tree->right);
	}
}

template<class T>
void RBTree<T>::postOrder(RBTNode<T>* tree) const
{
	if(tree)
	{		
		postOrder(tree->left);
		postOrder(tree->right);
		cout<<"("<<tree->key<<",  "<<(rb_is_red(tree)?"r":"b")<<")  ";
	}
}

template<class T>
void RBTree<T>::preOrder()
{
	preOrder(mRoot);
}

template<class T>
void RBTree<T>::inOrder()
{
	inOrder(mRoot);
}

template<class T>
void RBTree<T>::postOrder()
{
	postOrder(mRoot);
}

template<class T>
void RBTree<T>::print()
{
	preOrder();
	cout<<endl;
	inOrder();
	cout<<endl;
}

//搜索
template<class T>
RBTNode<T>* RBTree<T>::search(RBTNode<T>* tree,T key)const
{
	while(tree && tree->key!=key)
	{
		if(tree->key<key)
		{
			tree=tree->right;
		}
		else
		{
			tree=tree->left;
		}
	
	}
	return tree;
}
template<class T>
RBTNode<T>* RBTree<T>::search(T key)
{
	return search(mRoot,key);
}


//销毁
template<class T>
void RBTree<T>::destroy(RBTNode<T>* &tree)
{
	if(tree)
	{
		destroy(tree->left);
		destroy(tree->right);
		delete tree;
		tree=NULL;
	
	}
}

template<class T>
void RBTree<T>::destroy()
{
	destroy(mRoot);
}

//寻找后继节点
/*
template<class T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T>* x)
{
	
}
*/


//旋转  
//左旋转 
//前提 x的右节点非空
template<class T>
void RBTree<T>::leftRotate(RBTNode<T>* &root,RBTNode<T>* x)
{
	RBTNode<T>* y=x->right;
	
	x->right=y->left;
	if(y->left!=NULL)
	{
		y->left->parent=x;
	}

	
	y->parent=x->parent;
	if(x->parent!=NULL)
	{
		if(x->parent->left==x)
		{
			x->parent->left=y;
		}
		else
		{
			x->parent->right=y;
		}
	}
	else
	{
		root=y;
	}
	y->left=x;
	x->parent=y;

}
//右旋转
//前提:x的左节点非空
template<class T>
void RBTree<T>::rightRotate(RBTNode<T>* &root,RBTNode<T>* x)
{
	RBTNode<T>* y=x->left;
	x->left=y->right;
	if(y->right!=NULL)
	{
		y->right->parent=x;
	}

	y->parent=x->parent;
	if(x->parent!=NULL)
	{
		if(x->parent->left==x)
		{
			x->parent->left=y;
		}
		else
		{
			x->parent->right=y;
		}
	}
	else
	{
		root=y;
	}
	y->right=x;
	x->parent=y;

}

//插入


template<class T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root,RBTNode<T>* node)
{
	RBTNode<T>* parent,*gparent;
	//parent不为NULL，不是根节点
	
	while((parent=rb_parent(node)) && rb_is_red(parent) )
	{
	//能进入这个循环说明parent肯定不是根节点，因为根节点颜色必须为黑色
		gparent=rb_parent(parent);
		if(gparent->left==parent)  
		{
			RBTNode<T>* uncle=gparent->right;
			if(uncle && rb_is_red(uncle))
			{
				rb_set_black(uncle);
				rb_set_black(parent);
				rb_set_red(gparent);
				node=gparent;
				continue;
			}
			else if(parent->right==node)
			{
				RBTNode<T>* tmp=parent;
				leftRotate(root,parent);
				parent=node;
				node=tmp;
			}
			rb_set_red(gparent);
			rb_set_black(parent);
			rightRotate(root,gparent);
	
		
		}
		else
		{
			RBTNode<T>* uncle=gparent->left;
			if(uncle && rb_is_red(uncle))
			{
				rb_set_black(uncle);
				rb_set_black(parent);
				rb_set_red(gparent);
				node=gparent;
				continue;
			}
			else if(parent->left==node)
			{
				RBTNode<T>* tmp=parent;
				rightRotate(root,parent);
				parent=node;
				node=tmp;
			}
			rb_set_red(gparent);
			rb_set_black(parent);
			leftRotate(root,gparent);
		}
	
	}

	rb_set_black(root);

}




template<class T>
void RBTree<T>::insert(RBTNode<T>* &root,RBTNode<T>* node)
{
	RBTNode<T>* y=NULL; //记录要插入节点的父节点
	RBTNode<T>* x=root; //寻找插入节点(从根节点root开始寻找)
	
	while(x!=NULL)
	{
		y=x;
		if(x->key<node->key)
		{
			x=x->right;
		}
		else
		{
			x=x->left;
		}
	}

	node->parent=y;
	if(y!=NULL)
	{
		if(y->key<node->key)
		{
			y->right=node;
		}
		else
		{
			y->left=node;
		}
	}
	else
	{
		root=node;
	}

	node->color=RED;
	insertFixUp(root,node);
}


template<class T>
void RBTree<T>::insert(T key)
{
	
	RBTNode<T>* newNode=new RBTNode<T>(key,RED,NULL,NULL,NULL);
	insert(mRoot,newNode);
}



//删除
template<class T>
void RBTree<T>::remove(RBTNode<T>* &root,RBTNode<T>* node)
{
	RBTNode<T>* child,*parent;
	RBTColor color;
	if(node->left && node->right)
	{
		RBTNode<T>* replace=node->right;
		while(replace->left!=NULL)
			replace=replace->left;
		
		parent=replace->parent;
		child=replace->right;
		color=replace->color;
		
		if(node->parent)
		{
			if(node->parent->left=node)
				node->parent->left=replace;
			else
				node->parent->right=replace;

			
		}
		else
		{
			root=replace;
		}
		

		if(parent==node)
		{
			parent=replace;
		}
		else
		{
			if(child)
				child->parent=parent;
			parent->left=child;
			replace->right=node->right;
			node->right->parent=replace;
		}
		
		replace->left=node->left;
		replace->parent=node->parent;
		replace->color=node->color;
		node->left->parent=replace;
		if(color==BLACK)
			 removeFixUp(root,child,parent);
		delete node;
		return;
	}
	
	if(node->left)
		child=node->left;
	else
		child=node->right;

	parent=node->parent;
	color=node->color;
	if(child)
		child->parent=parent;
	if(parent)
	{
		if(parent->left==node)
			parent->left=child;
		else
			parent->right=child;


	}
	else
	{
		root=child;
	}

	if(color==BLACK)
		removeFixUp(root,child,parent);
	delete node;
	
}

template<class T>
void RBTree<T>::removeFixUp(RBTNode<T>* &root,RBTNode<T>* node,RBTNode<T>* parent)
{
	RBTNode<T>* other;
	while((!node || node->color==BLACK) && node!=root)
	{
		if(parent->left==node)
		{
			other=parent->right;           //other肯定存在，不然如何比node多一个黑色节点？
			if(other->color==RED)
			{
				rb_set_red(parent);
				rb_set_black(other);
				leftRotate(root,parent);
				other=parent->right;
			}

			if((!other->left || rb_is_black(other->left)) &&
			   (!other->right || rb_is_black(other->right)))
			{
				rb_set_red(other);
				node=parent;
				parent=rb_parent(node);
			}
			else
			{
				if(!other->right || rb_is_black(other->right))                       //为什么要检查other->right？因为node可能是NULL节点，所以other->right可能也是空的
				{
					rb_set_red(other);
					rb_set_black(other->left);
					rightRotate(root,other);
					other=parent->right;
				}
				other->color=parent->color;
				parent->color=BLACK;
				other->right->color=BLACK;
				leftRotate(root,parent);
				node=root;
				break;

			}
		}
		else
		{
			other=parent->left;
			if(other->color==RED)
			{
				rb_set_red(parent);
				rb_set_black(other);
				rightRotate(root,parent);
				other=parent->left;
			}

			if((!other->left || rb_is_black(other->left)) &&
			   (!other->right || rb_is_black(other->right)))
			{
				rb_set_red(other);
				node=parent;
				parent=rb_parent(node);

			}
			else
			{
				if(!other->left || rb_is_black(other->left))
				{
					rb_set_red(other);
					rb_set_black(other->right);
					leftRotate(root,other);
					other=parent->left;
				}

				rb_set_black(other->left);
				other->color=parent->color;
				rb_set_black(parent);
				rightRotate(root,parent);
				node=root;
				break;
			}
		}

	}

	if(node)
		node->color=BLACK;
}
template<class T>
void RBTree<T>::remove(T key)
{
	RBTNode<T>* node=search(mRoot,key);
	if(node)
		remove(mRoot,node);
}


#endif