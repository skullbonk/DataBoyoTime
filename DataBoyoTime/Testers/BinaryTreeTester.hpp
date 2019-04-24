//
//  BinaryTreeTester.hpp
//  TreeThing
//
//  Created by Fairbanks, Reagan on 4/16/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef BinaryTreeTester_hpp
#define BinaryTreeTester_hpp

#include "../Model/Nodes/BinaryTreeNode.hpp"
#include "../Model/NonLinear/BinarySearchTree.hpp"

class BinaryTreeTester
{
private:
	BinaryTreeNode<int> testNode;
	BinarySearchTree<int> testTree;
public:
	void doTreeStuff();
};

#endif /* BinaryTreeTester_hpp */
