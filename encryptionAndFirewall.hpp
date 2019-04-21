//  ---------------------------------------------------------------------------
//  Program for CyberSafe                                encryptionAndFirewall.hpp
//	This progam checks if encryptionAndFirewall is on.
//  Created by Bilal Abu-Ghazaleh on Sun September 9, 2018
// ----------------------------------------------------------------------------

#ifndef ENCRYPTIONANDFIREWALL_HPP
#define ENCRYPTIONANDFIREWALL_HPP

#include "tools.hpp"


class encryptionAndFirewall {
private:
	// ------------------------------------------------------------------------
	bool secure;
	string fileName;
	string cmdResponse;
	int readFile(string typeOfCheck);

public:
	// ------------------------------------------------------------------------
	encryptionAndFirewall() {secure=true;}
	// ------------------------------------------------------------------------
	int run(string typeOfCheck);

};
#endif	// ENCRYPTIONANDFIREWALL_HPP


