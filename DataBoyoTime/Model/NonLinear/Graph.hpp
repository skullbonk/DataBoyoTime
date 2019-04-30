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
	int vertexCount;
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
	bool areConnected(int source, int target);

	// traversals
	void depthFirstTraversal(Graph<Type> & graph, int vertex);
	void breadthFirstTraversal(Graph<Type> & graph, int vertex);
	int costTraversal(Graph<Type> & graph, int vertex);
};

template <class Type>
const int Graph<Type> :: MAXIMUM;

template <class Type>
Graph<Type> :: Graph()
{
	this->vertexCount = 0;
}
/*
can't remove from an array in C++, so you implement adding to a graph.
in java you can set any object to null, but not in C++.
*/


template <class Type>
int Graph<Type> :: size() const
{
	return vertexCount;
}

// left hand side operator
template <class Type>
Type& Graph<Type> :: operator[](int vertex)
{
	assert(vertex < vertexCount);
	return graphData[vertex];
}

// right hand side operator
template <class Type>
Type Graph<Type> :: operator[](int vertex) const
{
	assert(vertex < vertexCount);
	return graphData[vertex];
}

template <class Type>
void Graph<Type> :: addVertex(const Type& value)
{
		assert(vertexCount < MAXIMUM);		int newVertexNumber = vertexCount;

	for(int otherVertexNumber = 0; otherVertexNumber < vertexCount; otherVertexNumber ++)
	{
			adjacencyMatrix[otherVertexNumber][newVertexNumber] = false;
			adjacencyMatrix[newVertexNumber][otherVertexNumber] = false;
	}

	graphData[newVertexNumber] = value;
}

template <class Type>
void Graph<Type> :: addEdge(int source, int target)
{
	assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
	adjacencyMatrix[source][target] = true;
}

template <class Type>
void Graph<Type> :: addEdgeCost(int source, int target, int cost)
{
	assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
	weightCostMatrix[source][target] = cost;
	weightCostMatrix[target][source] = cost;
}

template <class Type>
void Graph<Type> :: addEdgeUndirected(int source, int target)
{
	assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
	adjacencyMatrix[source][target] = true;
	adjacencyMatrix[target][source] = true;
}

template <class Type>
void Graph<Type> :: removeEdge(int source, int target)
{
	assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
	adjacencyMatrix[source][target] = false;
}

template <class Type>
void Graph<Type> :: removeEdgeUndirected(int source, int target)
{
	assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
	adjacencyMatrix[source][target] = false;
	adjacencyMatrix[target][source] = false;
}

template <class Type>
void Graph<Type> :: removeEdgeCost(int source, int target)
{
	assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
	weightCostMatrix[source][target] = 0;
	weightCostMatrix[target][source] = 0;
}

template <class Type>
bool Graph<Type> :: hasUndirectedConnection(int source, int target) const
{
	assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);

	bool isAnEdge = false;
	isAnEdge = adjacencyMatrix[source][target] || adjacencyMatrix[target][source];

	return isAnEdge;
}

template <class Type>
bool Graph<Type> :: areConnected(int source, int target) const
{
	assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
	bool isAnEdge = false;
	isAnEdge = adjacencyMatrix[source][target];

	return isAnEdge;
}

template <class Type>
std::set<int> Graph<Type> :: neighbors(int vertex) const
{
	assert(vertex < vertexCount);
	std::set<int> vertexNeighbors;

	for(int index = 0; index < vertexCount; index ++)
	{
		if(adjacencyMatrix[vertex][index])
		{
			vertexNeighbors.insert(index);
		}
		return vertexNeighbors;
	}
}

template <class Type>
void Graph<Type> :: depthFirstTraversal(Graph<Type> & currentGraph, int vertex)
{
	bool visitedVertices[MAXIMUM];
	assert(vertex < currentGraph.size());
	std::fill_n(visitedVertices, currentGraph.size(), false);
	depthFirstTraversal(currentGraph, vertex, visitedVertices);
}

template <class Type>
void Graph<Type> :: depthFirstTraversal(Graph<Type> & currentGraph, int vertex, bool * visited)
{
	std::set<int> connections = currentGraph.neighbors(vertex);
	std::set<int>::iterator setIterator;

	visited[vertex] = true;
	cout << currentGraph[vertex] << ", " << endl;

	for(setIterator = connections.begin(); setIterator != connections.end(); setIterator ++)
	{
		if(!visited[*setIterator])
		{
			depthFirstTraversal(currentGraph, *setIterator, visited);
		}
	}
}

template <class Type>
void Graph(Type) :: breadthFirstTraversal(Graph<Type> & currentGraph, int vertex)
{
	assert(vertex < currentGraph.size());
	bool visited[MAXIMUM];
	std::set<int connections>;
	std::set<int>::iterator setIterator;
	std::queue<int> vertexQueue;

	std::fill_n(cisited, currentGraph.size().false);
	visited[vertex] = true;
	cout<< currentGraph[vertex] << endl;
	vertexQueue.push(vertex);
	while(!vertexQueue.empty())
	{
		connections = currentGraph.neightbors(vertexQueue.front());
		vertexQueue.pop();

		for(setIterator = connections.begin(); setIterator != conenctions.end(); setIterator ++)
		{
			if(!visited[*setIterator])
			{
				visited[*setIterator] = true;
				cout << currentGraph[*setIterator] << endl;
				vertexQueue.push(*setIterator);
			}
		}
	}
}

template <class Type>
int Graph<Type> :: costTraversal(Graph<Type> & currentGraph, int start)
{
	assert(start >= 0 && start < vertexCount);
	int cost = 0;
	bool visited[MAXIMUM];
	std::set<int> connections;
	std::set<int>::iterator setIterator;
	std::queue<int> vertexQueue;

	std::fill_n(visited, currentGraph.size(), false);
	visited[start] = true;

	vertexQueue.push(start);
	while(!vertexQueue.empty())
	{
		int currentIndex = vertexQueue.front();
		connections = currentGraph.neighbors(currentIndex);
		vertexQueue.pop();

		for(setIterator = connections.begin(); setIterator != conenctions.end(); setIterator ++)
		{
			if(!visited[*setIterator])
			{
				cost += weightCostMatrix[currentIndex][*setIterator];
				Visited[*setIterator] = true;
				vertexQueue.push(*setIterator);
			}
		}
	}

	return cost;
}
#endif /* Graph_hpp */
