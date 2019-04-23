//  ---------------------------------------------------------------------------
//  Program for CyberSafe                                encryptionAndFirewall.cpp
//	This progam checks if encryptionAndFirewall is on.
//  Created by Bilal Abu-Ghazaleh on Sun September 9, 2018
// ----------------------------------------------------------------------------
#include "encryptionAndFirewall.hpp"


// ----------------------------------------------------------------------------
int encryptionAndFirewall::
run(string typeOfCheck){

	if(DEBUG) {	
		lineSeparator();
		if(typeOfCheck == "encryption") (cout << "encryption cpp part\n");
		else cout << "firewall cpp part\n";
	}

	if(typeOfCheck == "encryption"){ 
		fileName = "FileVault.txt";
		system("fdesetup status > FileVault.txt");
	}else{
		fileName = "Firewall.txt";
		system("defaults read /Library/Preferences/com.apple.alf globalstate"
				" > Firewall.txt");
	}
	
	if(readFile(typeOfCheck) < 0){
		printf("Failed to open file: ");
		if(typeOfCheck == "encryption") cout << "FileVault.txt\n";
		else cout << "Firewall.txt\n";
		return -1;
	}

	if(DEBUG) lineSeparator();

	if(typeOfCheck == "encryption"){
		if (secure == true) return 1;
		return 0;
	}else{
		if (secure == true) return 1;
		return 0;	
	}	

}

int encryptionAndFirewall::
readFile(string typeOfCheck){
	ifstream in(fileName);
	if (!in) return -1;//Deal with this error later

	if(typeOfCheck == "encryption"){
		in >> cmdResponse >> cmdResponse >> cmdResponse;
		if (cmdResponse != "On.") secure = false;
	}else {
		in >> cmdResponse;
		if (cmdResponse != "1") secure = false;
	}
	if (DEBUG) cout << "Response: " << cmdResponse << endl;


	in.close();

	if(!DEBUG) {
		if(typeOfCheck == "encryption") system("rm FileVault.txt");
		else system("rm Firewall.txt");
	}
	return 0;
}


