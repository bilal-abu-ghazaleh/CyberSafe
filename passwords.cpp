//  ---------------------------------------------------------------------------
//  Program for CyberSafe                                lsofgrepProcessor.cpp
//	This progam checks the output of the commands to see which programs are 
// 		Currently using the camera.
//  Created by Bilal Abu-Ghazaleh on Sun September 9, 2018
// ----------------------------------------------------------------------------
#include "passwords.hpp"



int passwords::
run(){

	if (DEBUG) {lineSeparator(); cout << "password of passwords.cpp\n";}

	while(!correctPass){
		cout << "Please type in your password and make sure it is correct: ";
		cin >> password;

		string command = "echo ";
		command += password;
		command += " | sudo -S firmwarepasswd -check > firmware_output.txt";
		if (DEBUG)cout << command << endl;
		system(command.c_str());
		
		ifstream in(filename);
		if (!in){ cout <<  "Password is incorrect.\n"; continue;}
		correctPass = true;

	}

	string dictWord;

	//TODO FIX DICT WHEN RUN BY CLICKING
	ifstream dict("dictionary.txt"); 
	if (!dict){ cout <<  "Unable to open dict.\n";}

	securePass = true;
	while (dict.good()) {
	    dict >> dictWord;
	    if (dict.good() && (dictWord ==  password || password == " "))  {
	        securePass = false;
	        break;
    	}
	}

	if (DEBUG) {lineSeparator(); cout << "End of passwords.cpp\n";}

	if(securePass) return 1;
	return 0;
}
// ----------------------------------------------------------------------------
int passwords::
runfirm(){

	if (DEBUG) {lineSeparator(); cout << "firmware of passwords.cpp\n";}

	ifstream in(filename);
	if (!in){ cout <<  "Password is incorrect.\n"; return -1;}

	while(in >> response){}

	if(DEBUG) cout << response;
	if (response == "No") firmOn = false;
	else if (response == "Yes") firmOn = true;


	if (!DEBUG) system("rm firmware_output.txt");
	if (DEBUG) {lineSeparator(); cout << "End of passwords.cpp\n";}

	password = "nice try";
	if(firmOn) return 1;
	return 0;
}

