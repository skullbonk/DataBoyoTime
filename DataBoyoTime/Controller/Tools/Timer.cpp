//
//  Timer.cpp
//  DataBoyoTime
//
//  Created by Fairbanks, Reagan on 2/5/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "Timer.hpp"

using namespace std;

Timer :: Timer()
{
	executionTime = 0;
}

void Timer :: resetTimer()
{
	executionTime = 0;
}

void Timer :: startTimer()
{
	executionTime = clock();
}

void Timer :: stopTimer()
{
	assert(executionTime != 0);
	executionTime = clock() - executionTime;
}

void Timer :: displayInformation()
{
	cout << "execution time: " << executionTime << endl;
	cout << "actual time: " << double (executionTime)/CLOCKS_PER_SEC << "seconds" << endl;
}

long Timer :: getTimeInMircoseconds()
{
	return executionTime;
}
