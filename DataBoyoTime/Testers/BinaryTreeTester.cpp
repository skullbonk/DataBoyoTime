//
//  BinaryTreeTester.cpp
//  TreeThing
//
//  Created by Fairbanks, Reagan on 4/16/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include <stdio.h>
#include "BinaryTreeTester.hpp"



void BinaryTreeTester :: doTreeStuff()
{
	testTree.insert(4);
	testTree.insert(43);
	testTree.insert(6);
	testTree.insert(19);
	testTree.insert(54);
	testTree.insert(9);
	testTree.insert(3);
	testTree.insert(7);
	testTree.insert(0);
	testTree.insert(1);
	testTree.insert(47);
	
	testTree.inOrderTraversal();
}
