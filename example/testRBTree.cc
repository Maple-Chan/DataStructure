#include "RBTree.hpp"

#include <iostream>
using namespace std;

int main()
{
	RBTree<int>* rbtree=new RBTree<int>();
	
	rbtree->insert(5);
	rbtree->insert(10);
	rbtree->insert(15);
	rbtree->insert(3);
	
	rbtree->print();
	//rbtree.insert(15,15);
	//rbtree.insert(70,70);
	//rbtree.insert(20,20);
	rbtree->remove(10);
	rbtree->print();
	//rbtree.print(cout);
	rbtree->destroy();
	return 0;
}