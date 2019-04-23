//  ---------------------------------------------------------------------------
//  Program for CyberSafe                                softwareAndDNS.hpp
//	This progam checks the output of the commands to see if software needs
// 	and update and if DNS is enabled.
//  Created by Bilal Abu-Ghazaleh on Sun September 9, 2018
// ----------------------------------------------------------------------------

#ifndef SOFTWAREUPDATE_HPP
#define SOFTWAREUPDATE_HPP

#include "tools.hpp"


class softwareAndDNS {
private:
	// ------------------------------------------------------------------------
	bool update;
	bool exists;
	string fileName;
	string cmdResponse;
	int readFile(string typeOfCheck);

public:
	// ------------------------------------------------------------------------
	softwareAndDNS() {update=true; exists=true;}
	// ------------------------------------------------------------------------
	int run(string typeOfCheck);

};
#endif	// SOFTWAREUPDATE_HPP


