//
//  LinkedList.hpp
//  DataBoyoTime
//
//  Created by Fairbanks, Reagan on 2/11/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "List.hpp"

using namespace std; // Used for keyword access, use to keep pointers pointing at the right stuff

#ifndef LinkedList_hpp
#define LinkedList_hpp

template <class Type>
class LinkedList : public List<Type>
{
protected:
	
	LinearNode<Type> * front;
	LinearNode<Type> * end;
	
public:
	// constructors
	LinkedList();
	// destructor
	virtual ~LinkedList(); // virtual so it can be overridden
	// helper methods
	int getSize() const;
	LinearNode<Type> * getFront();
	LinearNode<Type> * getEnd();
	
	// structure methods
	void add(Type item);
	void addAtIndex(int index, Type item);
	Type getFromIndex(int index);
	Type remove(int index);
	// type setAtIndex( int index, Type item);
	// bool contains(Type item);
};

LinkedList<Type> :: LinkedList()
{
	this->front = nullptr;
	this->end = nullptr;
	this->size = 0;
}

LinkedList<Type> :: ~LinkedList()
{
	LinearNode<Type> * destroyStructure = front;
	while (front != nullptr)
	{
		front = destroyStructure->getNextNode();
		delete destroyStructure;
		destroyStructure = front;
	}
}

void LinkedList<Type> :: add(Type item)
{
	LinearNode<Type> * newData = new LinearNode<Type>(item);
	
	if(this->size == 0)
	{
		this->front = newData;
	}
	else
	{
		this->end->setNextNode(newData);
	}
	this->end = newData;
	
	this->size += 1;
}

void LinkedList<Type> :: addAtIndex(int index, Type item)
{
	assert(index >= 0 && index <= this->size);
	if(index == this->size)
	{
		add(item);
	}
	else
	{
		LinearNode<Type> * toBeAdded = new LinearNode<Type>(item);
		if(index == 0)
		{
			toBeAdded->setNextNode(front);
			front = toBeAdded;
		}
		else
		{
			LinearNode<Type * previous = nullptr;
			LinearNode<Type> * current = front;
			for(int position = 0; position < index; position ++)
			{
				previous = current;
				current = current->getNextNode();
			}
			previous->setNextNode(toBeAdded);
			toBeAdded->setNextNode(current);
		}
		this->size++;
	}
}



template <class Type>
bool LinkedList<Type> :: contains(Type thingToFind)
{
	bool exists = false;
	
	LinearNode<Type> * searchPointer = front;
	
	for(int index = 0; index < getSize(); index ++)
	{
		if (searchPointer->getData() == thingToFind)
		{
			return true;
		}
		searchPointer = searchPOinter->getNextNode();
	}
	
	return exists;
}

#endif /* LinkedList_hpp */
