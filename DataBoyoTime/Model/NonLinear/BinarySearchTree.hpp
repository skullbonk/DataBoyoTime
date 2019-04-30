//
//  BinarySearchTree.hpp
//  TreeThing
//
//  Created by Fairbanks, Reagan on 4/22/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Tree.hpp"
#include <iostream>

using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
protected:
	//MARK: Protected Methods
	int calculateSize(BinaryTreeNode<Type> * startNode);
	int calculateHeight(BinaryTreeNode<Type> * startNode);
	bool isBalanced(BinaryTreeNode<Type> * startNode);
	bool isComplete(BinaryTreeNode<Type> * startNode, int index, int size);
	
	void inOrderTraversal(BinaryTreeNode<Type> * inStart);
	void preOrderTraversal(BinaryTreeNode<Type> * preStart);
	void postOrderTraversal(BinaryTreeNode<Type> * postStart);
	
	void destroyTree(BinaryTreeNode<Type> * node);
	
	BinaryTreeNode<Type> * getRightMostChild(BinaryTreeNode<Type> * current);
	BinaryTreeNode<Type> * getLeftMostChild(BinaryTreeNode<Type> * current);
	
	void removeNode(BinaryTreeNode<Type> * removeMe);
	
public:
	//MARK: Public Methods
	BinarySearchTree();
	~BinarySearchTree();
	
	BinaryTreeNode<Type> * getRoot();
	
	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();
	void demoTraversalSteps(BinaryTreeNode<Type> * node);
	
	int getSize();
	int getHeight();
	bool isComplete();
	bool isBalanced();
	
	bool contains(Type value);
	void insert(Type itemToInsert);
	void remove(Type value);
	
	Type findMinimum();
	Type findMaximum();
};


template <class Type>
int BinarySearchTree<Type> :: getSize()
{
	return -1;
}

template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
	return -1;
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete()
{
	return false;
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced()
{
	return false;
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
	inOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
	preOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
	postOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
	BinaryTreeNode<Type> * insertMe = new BinaryTreeNode<Type>(itemToInsert);
	BinaryTreeNode<Type> * previous = nullptr;
	BinaryTreeNode<Type> * current = this->root;
	
	if(current == nullptr)
	{
		this->root = insertMe;
	}
	else
	{
		while(current != nullptr)
		{
			previous = current;
			if(itemToInsert < current->getData())
			{
				current = current->getLeftChild();
			}
			else if(itemToInsert > current->getData())
			{
				current = current->getRightChild();
			}
			else // remove cerr after verification of understanding
			{
				cerr << "item already exists - cancelling insert" << endl;
				delete insertMe;
				return; // returns nothing
			}
		}
		
		if(previous->getData() > itemToInsert)
		{
			previous->setLeftChild(insertMe);
		}
		else
		{
			previous->setRightChild(insertMe);
		}
		insertMe->setRootNode(previous);
	}
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type value)
{
	return false;
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type item)
{
	
}

// left root right
template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal(BinaryTreeNode<Type> * currentNode)
{
	if(currentNode != nullptr)
	{
		inOrderTraversal(currentNode->getLeftChild());
		cout << currentNode->getData() << endl;
		inOrderTraversal(currentNode->getRightChild());
	}
}

template <class Type>
BinarySearchTree<Type> :: ~BinarySearchTree()
{
	destroyTree(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: destroyTree(BinaryTreeNode<Type> * node)
{
	if(node != nullptr)
	{
		destroyTree(node->getLeftNode());
		destroyTree(node->getRightNode());
		delete node;
	}
}

#endif /* BinarySearchTree_hpp */
