//
//  GraphTester.hpp
//  DataBoyoTime
//
//  Created by Fairbanks, Reagan on 3/18/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef GraphTester_hpp
#define GraphTester_hpp

#include "../Model/NonLinear/Graph.hpp"
#include <iostream>

class GraphTester
{
private:
	Graph<string> puzzle;
	void setup();
	void compareTraversals();
	void findCheapestTraversal();

public:
	void testGraphs();
};

template <class Type>
Graph<Type> :: Graph()
{
	this->vertexCound = 0;

	for(int index = 0; index < MAXIMUM; index ++)
	{
		int * row = weightCostMatrix[index];
		std::fill_n(row, MAXIMUM, 0);
	}
}

#endif /* GraphTester_hpp */
