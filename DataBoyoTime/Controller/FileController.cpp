//
//  FileController.cpp
//  DataBoyoTime
//
//  Created by Fairbanks, Reagan on 2/5/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "FileController.hpp"
vector<CrimeData> FileController :: readCrimeDataToVector(string filename)
{
	std :: vector<CrimeData> crimeVector;
	string currentCSVLine;
	int rowCount = 0;
	
	ifstream dataFile(filename);
	
	//if the file is there
	if(dataFile.is_open())
	{
		//keep reading till the end
		while(!dataFile.eof())
		{
			//get each line
			getline(dataFile, currentCSVLine, '\r');
			//exclude header row
			if(rowCount != 0)
			{
				//make a crimeData instance, exclude blank lines
				if(currentCSVLine.length() != 0)
				{
					CrimeData row(currentCSVLine);
					crimeVector.push_back(row);
				}
			}
			rowCount++;
		}
		dataFile.close();
	}
	else
	{
		cerr << "NO FILE" << endl;
	}
	
	return crimeVector;
}
