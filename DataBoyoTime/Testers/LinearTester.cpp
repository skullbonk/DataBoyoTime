//
//  LinearTester.cpp
//  DataBoyoTime
//
//  Created by Fairbanks, Reagan on 2/13/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "LinearTester.hpp"

void LinearTester :: testVsSTL()
{
	Timer crimeTimerSTL, crimeTimerOOP, musicSTL, musicOOP;
	
	crimeTimerSTL.startTimer();
	vector<CrimeData> crimes = FileController :: readCrimeDataToVector();
	crimeTimerSTL.stopTimer();
	
	crimeTimerOOP.startTimer();
	LinkedList<CrimeData> moreCrimes = FileController :: readDataToList();
	crimeTimerOOP.stopTimer();
	
	cout << "This is the STL Read time: " << endl;
	crimeTimerSTL.displayInformation();
	cout << "this is the OOP Node Read time: " << endl;
	crimeTimerOOP.displayInformation();
	cout << "A difference of: " << crimeTimerOOP.getTimeInMicroseconds() - crimeTimerSTL.getTimeInMicroseconds() << " microseconds" << endl;
	
	musicSTL.startTimer();
	vector<Music> tunez = FileController :: musicDataToList();
	musicSTL.stopTimer();
	
	musicOOP.startTimer();
	LinkedList<Music> musicList = FileController :: musicDataToList();
	musicOOP.stopTimer();
	
	cout << "This is the STL Read time: " << endl;
	musicSTL.displayInformation();
	cout << "this is the OOP Node Read time: " << endl;
	musicOOP.displayInformation();
	cout << "A difference of: " << musicOOP.getTimeInMicroseconds() - musicSTL.getTimeInMicroseconds() << " microseconds" << endl;
	
	
	crimeTimerOOP.resetTimer();
	crimeTimerSTL.resetTimer();
	musicOOP.resetTimer();
	musicSTL.resetTimer();
}
