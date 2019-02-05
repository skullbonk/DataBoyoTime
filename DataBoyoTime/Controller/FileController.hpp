//
//  FileController.hpp
//  DataBoyoTime
//
//  Created by Fairbanks, Reagan on 2/5/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include <stdio.h>
#include "../Resources/CrimeData.hpp"
#include "../Resources/Music.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

class FileController
{
public:
	static vector<CrimeData> readCrimeDataToVector(string filename);
	static vector<Music> musicDataToVector(string filename);
};


#endif /* FileController_hpp */
