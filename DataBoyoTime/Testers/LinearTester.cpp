////
////  LinearTester.cpp
////  DataBoyoTime
////
////  Created by Fairbanks, Reagan on 2/13/19.
////  Copyright © 2019 CTEC. All rights reserved.
////
//
//#include "LinearTester.hpp"
//#include "../Controller/FileController.hpp"
//
//LinearTester :: LinearTester()
//{
//	
//}
//
//
//void LinearTester :: testVsSTL()
//{
//	Timer crimeTimerSTL, crimeTimerOOP, musicSTL, musicOOP;
//	
//	crimeTimerSTL.startTimer();
//	vector<CrimeData> crimes = FileController :: readCrimeDataToVector();
//	crimeTimerSTL.stopTimer();
//	
//	crimeTimerOOP.startTimer();
//	LinkedList<CrimeData> moreCrimes = FileController :: readDataToList();
//	crimeTimerOOP.stopTimer();
//	
//	cout << "This is the STL Read time: " << endl;
//	crimeTimerSTL.displayInformation();
//	cout << "this is the OOP Node Read time: " << endl;
//	crimeTimerOOP.displayInformation();
//	cout << "A difference of: " << crimeTimerOOP.getTimeInMircoseconds() - crimeTimerSTL.getTimeInMicroseconds() << " microseconds" << endl;
//	
//	musicSTL.startTimer();
//	vector<Music> tunez = FileController :: musicDataToList();
//	musicSTL.stopTimer();
//	
//	musicOOP.startTimer();
//	LinkedList<Music> musicList = FileController :: musicDataToList();
//	musicOOP.stopTimer();
//	
//	cout << "This is the STL Read time: " << endl;
//	musicSTL.displayInformation();
//	cout << "this is the OOP Node Read time: " << endl;
//	musicOOP.displayInformation();
//	cout << "A difference of: " << musicOOP.getTimeInMircoseconds() - musicSTL.getTimeInMicroseconds() << " microseconds" << endl;
//	
//	
//	crimeTimerOOP.resetTimer();
//	crimeTimerSTL.resetTimer();
//	musicOOP.resetTimer();
//	musicSTL.resetTimer();
//	
//	int randomIndex = rand() % moreCrimes.getSize();
//	
//	crimeTimerSTL.startTimer();
//	crimes[randomIndex];
//	crimeTimerSTL.stopTimer();
//}
//
//void LinearTester :: testVsStack()
//{
//	
//}
//
//void LinearTester :: testVsQueue()
//{
//	
//}
//
//void LinearTester :: testVsDouble()
//{
//	
//}
//
