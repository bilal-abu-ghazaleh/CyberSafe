//  ---------------------------------------------------------------------------
//  Program for CyberSafe                                passwords.hpp
//	This progam checks the output of the commands to see if password is secure
//	and if firmware password is being used.
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


