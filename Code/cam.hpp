//  ---------------------------------------------------------------------------
//  Program for CyberSafe                                CAM.hpp
//	This progam checks the output of the commands to see which programs are 
// 		Currently using the camera.
//  Created by Bilal Abu-Ghazaleh on Sun September 9, 2018
// ----------------------------------------------------------------------------

#ifndef CAM_HPP
#define CAM_HPP

#include "tools.hpp"


class cam {
private:
	// ------------------------------------------------------------------------
	string processes[100];
	int processesNumbers[100];
	int count;
	string acceptableProcessesFile;
	string acceptableProcesses[100];
	int acceptableCount;
	bool secure = true;

	//	Checks for cam usage using functions bellow
	void check();
	// Finds the currently running processes
	int runningProcesses();
	// Checks whether the processes are inside the acceptable list
	void checkAcceptable();

public:
	// ------------------------------------------------------------------------
	cam() {
		for (int i = 0; i < 100; ++i) { processesNumbers[i] = -1; }
		count = 0;
		acceptableProcessesFile = "acceptableCam.txt";
		acceptableCount = 0;
	}
	// ------------------------------------------------------------------------
	int run();


};
#endif	// cam_HPP


