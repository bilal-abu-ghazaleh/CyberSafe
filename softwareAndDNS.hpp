//  ---------------------------------------------------------------------------
//  Program for CyberSafe                                softwareUpdate.hpp
//	This progam checks if softwareUpdate is on.
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


