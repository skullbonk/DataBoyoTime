//
//  Controller.cpp
//  DataBoyoTime
//
//  Created by Fairbanks, Reagan on 1/28/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "Controller.hpp"
#include "../Model/Nodes/Node.hpp"

void Controller :: start()
{
	cout << "I am a big stunky dungus" << endl;
	usingNodes();
}

void Controller :: usingNodes()
{
	Node<int> mine(5);
	Node<string> wordHolder("words can be in this");
	cout << mine.getData() << endl;
	wordHolder.setData("replaced text");
	cout << wordHolder.getData() << endl;
}

/*
void Controller :: testLinear()
{
	
}
*/
