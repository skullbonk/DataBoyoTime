//
//  LinearTester.hpp
//  DataBoyoTime
//
//  Created by Fairbanks, Reagan on 2/13/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef LinearTester_hpp
#define LinearTester_hpp

#include "../Controller/Tools/Timer.hpp"
#include "../Controller/FileController.hpp"
#include "../Model/Linear/Stack.hpp"
#include "../Model/Linear/Queue.hpp"
#include "../Model/Linear/LinkedList.hpp"

#include <iostream>
using namespace std;

//template <class Type>
class LinearTester
{
public:
	// constructor
	LinearTester();
	// destructor
	virtual ~LinearTester();
	
	void testVsSTL();
	void testVsStack();
	void testVsQueue();
	void testVsDouble();
};

#endif /* LinearTester_hpp */
