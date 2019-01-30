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
private:
	LinearNode : public Node<Type>

private:
	LinearNode<Type> * next;
public:
	LinearNode();
	LinearNode(Type data);
	LinearNode(Type data, LinearNode<Type> * next);
	LinearNode<Type> * getNext();
	void setNext(LinearNode<Type> * next);
};

//Implementing templates
template <class Type>
LinearNode<Type> :: LinearNode() : Node()
{
	
}

template <class Type>
LinearNode<Type> :: LinearNode(Type data) : Node<Type>(data)
{
	this->next = nullptr;
}


#endif /* LinerNode_hpp */
