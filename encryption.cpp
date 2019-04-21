//  ---------------------------------------------------------------------------
//  Program for CyberSafe                                encryption.cpp
//	This progam checks if encryption is on.
//  Created by Bilal Abu-Ghazaleh on Sun September 9, 2018
// ----------------------------------------------------------------------------
#include "encryption.hpp"


// ----------------------------------------------------------------------------
void encryption::
run(){
	if(DEBUG) {	lineSeparator();(cout << "encryption.cpp\n");}

	system("fdesetup status > FileVault.txt");
	
	if(readFile() < 0){
		printf("Failed to open file: FileVault.txt\n");
		return;
	}

	if (secure == true) cout << "Your files are encrypted and secure.\n";
	else {
		cout << "\nYour files are unencrypted.\n\n"
			<< "To encrypt your files do the following:\n"
			<< "1. Choose Apple menu () > System Preferences, then click Security & Privacy.\n"
			<< "2. Click the FileVault tab.\n"
			<< "3. Click on the Lock, then enter an administrator name and password.\n"
			<< "4. Click Turn On FileVault.\n"
			<< "More details can be found at: https://support.apple.com/en-us/HT204837\n";
	}	

	if(DEBUG) lineSeparator();
	return;
}

int encryption::
readFile(){
	ifstream in(fileName);
	if (!in) return -1;//Deal with this error later

	in >> cmdResponse >> cmdResponse >> cmdResponse;
	if (DEBUG) cout << "Response: " << cmdResponse << endl;

	if (cmdResponse != "On.") secure = false;

	in.close();

	if(!DEBUG) system("rm FileVault.txt");
	return 0;
}
