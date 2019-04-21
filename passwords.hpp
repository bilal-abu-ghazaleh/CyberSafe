//  ---------------------------------------------------------------------------
//  Program for CyberSafe                                softwareUpdate.hpp
//	This progam checks if softwareUpdate is on.
//  Created by Bilal Abu-Ghazaleh on Sun September 9, 2018
// ----------------------------------------------------------------------------

#ifndef PASSWORDS_HPP
#define PASSWORDS_HPP

#include "tools.hpp"


class passwords {
private:
	// ------------------------------------------------------------------------
	string password;
	string filename;
	string response;
	bool securePass;
	bool correctPass;
	bool firmOn;

public:
	// ------------------------------------------------------------------------
	passwords() {
		filename = "firmware_output.txt";
		 correctPass = false;
		 firmOn = false;
	}
	// ------------------------------------------------------------------------
	int run();
	int runfirm();

};
#endif	// PASSWORDS_HPP


