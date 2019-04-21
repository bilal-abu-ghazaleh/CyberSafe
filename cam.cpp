//  ---------------------------------------------------------------------------
//  Program for CyberSafe                                lsofgrepProcessor.cpp
//	This progam checks the output of the commands to see which programs are 
// 		Currently using the camera.
//  Created by Bilal Abu-Ghazaleh on Sun September 9, 2018
// ----------------------------------------------------------------------------
#include "cam.hpp"

// Sean O'Brian

// ----------------------------------------------------------------------------
int cam::
run(){
	if (DEBUG) {lineSeparator(); cout << "cam.cpp\n";}

	system("echo > lsofOutput.txt");
	system("lsof | grep -e \"VDC\" -e \"AppleCamera\" -e \"iSight\" >>"
		" lsofOutput.txt");

	if (DEBUG) system("cat lsofOutput.txt");

	system("if grep -Eo '[a-zA-z]+[\\x20-\\x7E]*[ ]+[0-9]{2,6}' lsofOutput.txt"
			" > lsofHumanOutput.txt"
				"\nthen grep -Eo '[a-zA-z]+[\\x20-\\x7E]*[ ]+[0-9]{2,6}' "
				"lsofOutput.txt > lsofHumanOutput.txt;"
			"\nfi");

	system("touch lsofProcessorInternal.txt");

	check();

	system("emptyCAM=($(wc -c lsofProcessorInternal.txt))"
		"\nif ((\"$emptyCAM\" != 0 )); then"
			"\nwhile read i ; do kill $i ; done < lsofProcessorInternal.txt;"
		"\nfi");

	if (!DEBUG) {
		system("rm lsofProcessorInternal.txt");
		system("rm lsofOutput.txt");
		system("rm lsofHumanOutput.txt");
	}

	if (DEBUG) {lineSeparator(); cout << "\nEnd of CAM.cpp\n";}
	if(secure) return 1;
	return 0;
}

// ----------------------------------------------------------------------------
void cam::
check(){

	//Get list of running processes
	if(runningProcesses() < 0){
		printf("Failed to open file: lsofHumanOutput\n");
		return;
	}

	// Acceptable processes here
	acceptableProcesses[acceptableCount++] = "Safari";
	acceptableProcesses[acceptableCount++] = "avconfere";
	acceptableProcesses[acceptableCount++] = "Google";
	acceptableProcesses[acceptableCount++] = "Google Chrome";


	// Check if they are acceptable
	checkAcceptable();
	return;
}


// ----------------------------------------------------------------------------
int cam::
runningProcesses(){
	string processesFileName = "lsofHumanOutput.txt";
	ifstream in(processesFileName);
	if (!in) return -1;//Deal with this error later

	//Get list of running processes
	if (DEBUG) {cout << "\nProcesses running Webcam:\n";}
	while (in >> processes[count]) {
	    in >> processesNumbers[count++];
	    if (DEBUG) {
	    	cout << processes[count-1] <<' '<< processesNumbers[count-1] 
	    	<< endl;
	    }
	}

	in.close();
	return 0;
}


// ----------------------------------------------------------------------------
void cam::
checkAcceptable(){
	//File for output
	ofstream myfile;
  	myfile.open ("lsofProcessorInternal.txt");

  	//Check to see if all acceptable
	for (int i = 0; i < count; i++){
		int exists = 0;
		for (int j = 0; j < acceptableCount; j++){
			if (processes[i] == acceptableProcesses[j]){
				exists = 1;
				break;
			}
		}
		if (exists == 0){
			cout << "Terminating Illegal Program: \t" << processes[i] << "\n";
			myfile << processesNumbers[i] << "\n";
			secure = false;
			cout << ("\nPlease type in n for next: ");
			string input;
			cin >> input;
			while(input != "n" && input != "N"){
				cout << ("Please type in n for next: ");
				cin >> input;
			}
		}
	}

	myfile.close();
}



