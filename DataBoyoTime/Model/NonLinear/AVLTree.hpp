//
//  Header.hpp
//  DataBoyoTime
//
//  Created by Fairbanks, Reagan on 4/30/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include "BinarySearchTree.hpp"

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
	BinaryTreeNode<Type> * leftRotation (BinaryTreeNode<Type> * parent);
	BinaryTreeNode<Type> * rightRotaion (BinaryTreeNode<Type> * parent);
	BinaryTreeNode<Type> * leftRightRotaion (BinaryTreeNode<Type> * parent);
	BinaryTreeNoe<Type> * rightLeftRotation (BianryTreeNode<Type> * parent);
	
public: AVLTree();
	
	void insert(Type itemToInsert);
	void remove(Type value);
};

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: insertNode(BinaryTreeNode<Type> * parent, Type inserted)
{
	if(parent == nullptr)
	{
		parent = new BinaryTreeNode<Type>(inserted);
		if (this->getRoot() == nullptr)
		{
			this->setRoot(parent);
		}
		return parent;
	}
	else if(inserted < parent->getNodeData())
	{
		parent->setLeftChild(insertNode(parent->getLeftChild(), inserted));
		parent = balanceSubTree(parent);
	}
	else if(inserted > parent->getData())
	{
		parent->setRightChild(insertedNode(parent->getRightChild(), inserted));
		parent = balanceSubTree(parent);
	}
	return parent;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: removeNode(BinaryTreeNode<Type> * parent, Type inserted)
{
	if(parent == nullptr)
	{
		return parent;
	}
	if(inserted < parent->getData())
	{
		parent->setLeftChild(removeNode(parent->getLeftChild(), inserted));
	}
	else if(inserted > parent->getData())
	{
		parent->setRightChild(removeNode(parent->getRightChild(), inserted));
	}
	else
	{
		BinaryTreeNode<Type> * temp;
		if(parent->getLeftChild() == nullptr && parent->getRightChild() == nullptr)
		{
			temp = parent;
			delete temp;
		}
		else if(parent->getLeftChild() == nullptr)
		{
			*parent = *parent->getRightChild();
		}
		else if(parent->getRightChild() == nullptr)
		{
			*parent = *parent->getLeftChild();
		}
		else
		{
			BinaryTreeNode<Type> * leftMost = this->getLeftMostChild(parent->getRightChild());
			parent->setData(leftMost->getData());
			parent->setDRightChild(removeNode(parent->getRightChild(), inserted));
		}
	}
	if(parent == nullptr)
	{
		return parent;
	}
	return balancedSubTreeParent(parent);
}

template<class Type>
int AVLTree<Type> :: heightDifference(BinaryTreeNode<Type> * node)
{
	int balance;
	int leftHeight = this->calculateHeight(node->getLeftChild());
	int rightHeight = this->calculateHeight(node->getRightChild());
	balance = leftHeight - rightHeight;
	return balance;
}

template<class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: balanceSubTree(BinaryTreeNode<Type> * parent)
{
	int balanceFactor = heightDifference(parent);
	
	if(balanceFactor > 1)
	{
		if(heightDifference(parent->getLeftChild()) > 0)
		{
			parent = leftRotation(parent);
		}
		else
		{
			parent = leftRightRotation(parent);
		}
	}
	else if(balanceFactor < -1)
	{
		if(heightDifference(parent->getRightChild()) > 0)
		{
			parent = rightLeftRotation(parent);
		}
		else
		{
			parent = rightRotation(parent);
		}
	}
	
	return parent;
}

template<class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftHeavyRotation (BinaryTreeNode<Type> * parent)
{
	BinaryTreeNode<Type> * changedNode;
	changedNode = parent->getLeftChild();
	
	parent->setleftChild(changedNode->getRightChild());
	
	changedNode->setRightChild(parent);
	parent->setRootNode(changedNode);
	
	return changedNode;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightRotation (BinaryTreeNode<Type> * parent)
{
	BinareTreeNode<Type> * changedNode;
	changedNode = parent->getRightChild(parent);
	
	parent->setRightChild(changedNode->getLeftChild());
	
	changedNode->setLeftChild(parent);
	parent->setRootNode(changedNode);
	
	return changedNode;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightLeftRotation (BinaryTreeNode<Type> * parent)
{
	BinaryTreeNode<Type> * changedNode;
	changedNode = parent->getRightChild();
	
	parent->setRightChild(leftRotation(changedNode));
	
	return rightRotation(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftRightRotation (BinaryTreeNode<Type> * parent)
{
	BinaryTreeNode<Type> * changedNode;
	changedNode = parent->getLeftChild();
	
	parent->setLeftChild(leftRotation(changedNode));
	
	return leftRotation(parent);
}


#endif /* Header_hpp */
