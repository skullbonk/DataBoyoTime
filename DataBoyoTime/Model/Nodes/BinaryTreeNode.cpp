//
//  BinaryTreeNode.cpp
//  DataBoyoTime
//
//  Created by Fairbanks, Reagan on 4/22/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include <stdio.h>
#include "BinaryTreeNode.hpp"

template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode() : Node<Type>()
{
	root = nullptr;
	left = nullptr;
	right = nullptr;
}

template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode(Type data) : Node<Type>(data)
{
	root = nullptr;
	left = nullptr;
	right = nullptr;
}
