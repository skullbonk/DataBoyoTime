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
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
	BinaryTreeNode<Type> * current = this->root;
	if(current == nullptr)
	{
		return false;
	}
	else
	{
		while(current != nullptr)
		{
			if(itemToFind == current->getData())
			{
				return true;
			}
			else if(itemToFind < current->getData())
			{
				current = current->getLeftNode();
			}
			else
			{
				current = current->getRightNode();
			}
			return false;
		}
	}
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
		if(this->root == nullptr)
		{
			cout << "Empty tree, removal not possible" << endl;
		}
	else
	{
		BinaryTreeNode<Type> * current = this->root;
		BinaryTreeNode<Type> * previous = nullptr;
		bool hasBeenFound = false;
		
		while(current != nullptr && !hasBeenFound)
		{
			if(current->getData() == getRidOfMe)
			{
				hasBeenFound = true;
			}
			else
			{
				previous = current;
				if(getRidOfMe < current->getData())
				{
					current = current->getLeftNode();
				}
				else
				{
					current = current->getRightNode();
				}
			}
		}
		
		if(current == nullptr)
		{
			cerr << "Item not found, removal unsuccessful" << endl;
		}
		else if(hasBeenFound)
		{
			if(current == this->root)
			{
				removeNode(this->root);
			}
			else if(getRidOfMe < previous->getData())
			{
				removeNode(previous->getLeftNode());
			}
			else
			{
				removeNode(previous->getRightNode());
			}
		}
	}
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
void BinarySearchTree<Type> :: removeNode(BinaryTreeNode<Type> * removeMe)
{
	BinaryTreeNode<Type> * current;
	BinaryTreeNode<Type> * previous;
	BinaryTreeNode<Type> * temp;
	
	previous = removeMe->getRootNode();
	
	// node is a leaf - no childrensss
	if(removeMe->getRightChild() == nullptr && removeMe->getLeftChild() == nullptr)
	{
		temp = removeMe;
		removeMe = nullptr;
		
		if(previous != nullptr && temp->getData() < previous->getData())
		{
			previous->setLeftChild(removeMe);
		}
		else if(previous != nullptr && temp->getData() > previous->getData())
		{
			previous->setRightChild(removeMe);
		}
		
		delete temp;
	}
	
	// only a left child
	else if(removeMe->getRightNode() == nullptr)
	{
		temp = removeMe;
		removeMe = removeMe->getLeftNode();
		
		if(previous != nullptr && temp->getData() < previous->getData())
		{
			previous->setLeftNode(removeMe);
		}
		else if(previous != nullptr && temp->getData() > previous->getData())
		{
			previous->setRightNode(removeMe);
		}
		
		removeMe->setRootNode(previous);
		
		delete temp;
	}
	
	// only a right child
	else if(removeMe->getLeftNode() == nullptr)
	{
		temp = removeMe;
		removeMe = removeMe->getRightNode();
		
		if(previous != nullptr && removeMe->getData() < previous->getData())
		{
			previous->setLeftNode(removeMe);
		}
		else if(previous != nullptr && removeMe->getData() > previous->getData())
		{
			previous->setRightNode(removeMe);
		}
		
		removeMe->setRootNode(previous);
		delete temp;
	}
	
	// node has both children
	else
	{
		current = getRightMostChild(removeMe->getLeftNode());
		
		previous = current->getRootNode();
		removeMe->setData(current->getData());
		
		if(previous == nullptr) // remove from root
		{
			removeMe->setLeftNode(current->getLeftNode());
		}
		else
		{
			previous->setRightNode(current->getLeftNode());
		}
		if(current->getLeftNode() != nullptr)
		{
			current->getLeftNode()->setRootNode(removeMe);
		}
		delete current;
	}
	
	if(removeMe == nullptr || removeMe->getRootNode() == nullptr)
	{
		this->root = removeMe;
	}
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild(BinaryTreeNode<Type> * startingNode)
{
	BinaryTreeNode<Type> * currentNode = startingNode;
	BinaryTreeNode<Type> * previous = nullptr;
	while (currentNode != nullptr)
	{
		previous = currentNode;
		currentNode = currentNode->getLeftNode();
	}
	
	return previous;
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinaryTreeNode<Type> * startingNode)
{
	BinaryTreeNode<Type> * currentNode = startingNode;
	BinaryTreeNode<Type> * previous = nullptr;
	while(currentNode != nullptr)
	{
		previous = currentNode;
		currentNode = currentNode->getRightNode();
	}
	
	return previous;
}


template <class Type>
Type BinarySearchTree<Type> :: findMaximum()
{
	assert(this->root != nullptr);
	return getRightMostChild(this->root)->getData();
}

template <class Type>
Type BinarySearchTree<Type> :: findMinimum()
{
	assert(this->root != nullptr);
	return getLeftMostChild(this->root)->getData();
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
