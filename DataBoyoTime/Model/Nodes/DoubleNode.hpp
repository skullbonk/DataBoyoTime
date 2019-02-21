//
//  DoubleNode.hpp
//  DataBoyoTime
//
//  Created by Fairbanks, Reagan on 2/21/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef DoubleNode_hpp
#define DoubleNode_hpp

#include "Node.hpp"

template <class Type>
class DoubleNode : public Node<Type>
{
protected:
	DoubleNode<Type> * next;
	DoubleNode<Type> * previous;
	
public:
	// constructors
	DoubleNode();
	DoubleNode(Type data);
	DoubleNode(Type data, DoubleNode<Type> * next, DoubleNode<Type> * next);
	
	DoubleNode<Type> * getNext();
	DoubleNode<Type> * getPrevious();
	
	void setNext(DoubleNode<Type> * previous);
	void setNext(DoubleNode<Type> * next);
}

template <class Type>
DoubleNode<Type> :: DoubleNode() : Node<Type>()
{
	next = nullptr;
	previous = nullptr;
}

template <class Type>
DoubleNode<Type> :: DoubleNode(Type data) : Node<Type>(data)
{
	next = nullptr;
	previous = nullptr;
}

template <class Type>
void DoubleNode<Type> :: setNext(DoubleNode<Type> * next)
{
	this->next = next;
}

template <class Type>
void DoubleNode<Type> :: setPrevious(DoubleNode<Type> * previous)
{
	this->previous = previous;
}

template <class Type>
DoubleNode<Type> * DoubleNode<Type> :: getNext()
{
	return next;
}

template <class Type>
DoubleNode<Type> * DoubleNode<Type> :: getPrevious()
{
	return previous;
}


#endif /* DoubleNode_h */
