//
//  Graph.hpp
//  DataBoyoTime
//
//  Created by Fairbanks, Reagan on 3/4/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <set>
#include <queue>
#include <assert.h>

using namespace std;
template <class Type>
class Graph
{
private:
	static const int MAXIMUM = 50;
	bool adjacencyMatrix [MAXIMUM][MAXIMUM];
	int weightCostMatrix [MAXIMUM][MAXIMUM];
	Type graphData[MAXIMUM];
	int vertexCound;
	void depthFirstTraversal(Graph<Type> & graph, int vertex, bool markedVertices[]);
	
public:
	Graph();
	// graph operations
	
	void addVertex(const Type& value);
	
	// connect vertices
	void addEdge(int source, int target);
	void addEdgeUndirected(int source, int target);
	void addEdgeCost(int source, int target, int cost);
	// disconnect vertices
	void removeEdge(int source, int target);
	void removeEdgeUndirected(int source, int target);
	void removeEdgeCost(int source, int target);
	
	// accessors
	Type& operator [] (int vertex);
	Type operator [] (int vertex) const;
	int size() const;
	
	// check connections
	bool hasUndirectedConnection(int source, int target) const;
	std::set<int> neighbors(int vertex) const;
	
	// traversals
	coid depthFirstTraversal(Graph<Type> & graph, int vertex);
	void breadthFirstTraversal(Graph<Type> & graph, int vertex);
	int costTraversal(Graph<Type> & graph, int vertex);
}

#endif /* Graph_hpp */
