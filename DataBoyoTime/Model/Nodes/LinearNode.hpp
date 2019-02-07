//
//  LinerNode.hpp
//  DataBoyoTime
//
//  Created by Fairbanks, Reagan on 1/30/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef LinerNode_hpp
#define LinerNode_hpp

#include "Node.hpp"

template <class Type>
class LinearNode : public Node<Type>
{
	// available to subclasses of LinearNode
protected:
	LinearNode<Type> * next;
	
public:
	//Constructors
	LinearNode();
	LinearNode(Type data);
	LinearNode(Type data, LinearNode<Type> * next);
	//Methods
	void setNextNode(LinearNode<Type> * next);
	LinearNode<Type> * getNextNode();
};

//Constructors

/**
 This constructor is for building the raw structure before there are any values
 */
template <class Type>
LinearNode<Type> :: LinearNode() : Node<Type>()
{

}

/**
 This constructor is to create a referance to the instance with data
 */
template <class Type>
LinearNode<Type> :: LinearNode(Type data) : Node<Type>(data)
{
	this->next = nullptr;
}

/**
 This constructor is for creating a referance to an instance with data and known links
 */
template <class Type>
LinearNode<Type> :: LinearNode(Type data, LinearNode<Type> * next) : Node<Type>(data)
{
	this->next = next;
}

//Accessor methods

template <class Type>
void LinearNode<Type> :: setNextNode(LinearNode<Type> * nextNodePointer)
{
	this->next = nextNodePointer;
}

template <class Type>
LinearNode<Type> * LinearNode<Type> :: getNextNode()
{
	return next;
}


#endif /* LinerNode_hpp */
