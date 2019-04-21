// ---------------------------------------------------------------------------
//  Tools program for CyberSafe.                                tools.hpp
//  Created by Bilal Abu-Ghazaleh on Mon April 1, 2019
// ----------------------------------------------------------------------------

#include "tools.hpp"

// Banner that welcomes user
void banner() {
	system("printf %b '\e[40m' '\e[8]' '\e[H\e[J'");
	system("echo -e \"Default \e[97mWhite\"");
	system("clear");
	cout << ("Welcome to CyberSafe\n");
	printLogo();
	lineSeparator();
}

void printLogo(){
	cout << " _______ __   _  ______  _______ ______  ______  ______  ______  ______" << endl;;
	cout << "| _____/| |  | ||  __  || _____/|  __  ||  ____||  __  || _____/| _____/"<< endl;;
	cout << "| |      \\ \\ | || |__| || |___  | |__| || |____ | |__| || |___  | |___  "<< endl;;
	cout << "| |       \\ \\| ||  __  /|  ___| |  __  /|____  ||  __  ||  ___| |  ___|"<< endl;;
	cout << "| |_____ _ \\ | || |__| || |_____| |  | | ____| || |  | || |     | |_____"<< endl;;
	cout << "|______/|______||______/|______/|_|  |_||______||_|  |_||_|     |______/"<< endl;;
	cout << endl;
}

// Goodbye message at the end of the program
void bye() {
	lineSeparator();

	cout << ("Thanks for coming.\nPlease type in q to quit: ");
	string input;
	cin >> input;
	while(input != "q" && input != "Q"){
		cout << ("Please type in q to quit: ");
		cin >> input;
	}
}

void lineSeparator() {
		cout << "-------------------------------------------------------------"
		<< "------------------\n";
}

void nextFunction(int in){
	system("clear");
}

void printFunctions(int functionNumber, int ret){
	switch (functionNumber)
{
    case 0: // code to be executed if n = 1;
    	printf("\n1. Remote connections:\n");
    	if(ret){
    		cout << "Remote connections secure.\n";
    	}else{
    		cout << "Warning!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    		cout << "Illegal connection detected, not secure.\n";
    	}
        break;
    case 1: // code to be executed if n = 2;
    	printf("\n2. Webcam monitoring:\n");
        if(ret){
        	cout << "Webcam is secure.\n";
    	}else{
    		cout << "Warning!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    		cout << "Illegal Webcam monitoring detected and terminated.\n";
    	}
    	break;
    case 2: // code to be executed if n = 1;
    	printf("\n3. Encryption status:\n");
        if(ret){
        	cout << "Your files are encrypted and secure.\n";
    	}else{
    		cout << "Warning!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			cout << "\nYour files are unencrypted.\n\n"
			<< "To encrypt your files do the following:\n"
			<< "1. Choose Apple menu () > System Preferences, then click "
			<< "Security & Privacy.\n"
			<< "2. Click the FileVault tab.\n"
			<< "3. Click on the Lock, then enter an administrator name and"
			<< " password.\n"
			<< "4. Click Turn On FileVault.\n"
			<< "More details can be found at: https://support.apple.com/"
			<< "en-us/HT204837\n";
    	}
    	break;
    case 3: // code to be executed if n = 2;
    	printf("\n4. Firewall status:\n");
        if(ret){
        	cout << "Your Firewall is turned on and secure.\n";
    	}else{
    		cout << "Warning!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
	    	cout << "\nYour Firewall is tuned off.\n\n"
			<< "Use these steps to enable the application firewall:\n"
			<< "1. Choose System Preferences from the Apple menu.\n"
			<< "2. Click Security or Security & Privacy.\n"
			<< "3. Click the Firewall tab.\n"
			<< "4. Unlock the pane by clicking the lock in the lower-left"
			<< " corner and enter the administrator username and password.\n"
			<< "5. Click \"Turn On Firewall\" or \"Start\" to enable the "
			<< "firewall.\n"
			<< "6. Click Advanced to customize the firewall configuration.\n"
			<< "More details can be found at: https://support.apple.com/"
			<< "en-us/HT201642\n";
    	}
    	break;
    case 4: // code to be executed if n = 1;
    	printf("\n5. Software Update:\n");
        if(ret){
        	cout << "Your software is up to date and secure.\n";
    	}else{
    		cout << "Warning!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    		cout << "\nYour software needs to be updated to increase your "
			<< "security.\n\nTo update your software do the following:\n" 
			<< "1. Choose System Preferences from the Apple () menu, then "
			<< "click Software Update to check for updates.\n"
			<< "2. If any updates are available, click the Update Now button "
			<< "to install them. Or click \"More info\"to see details about "
			<< "each update and select specific updates to install.\n"
			<< "3. When Software Update says that your Mac is up to date, "
			<< "macOS and all of its apps are also up to date. That includes "
			<< "Safari, iTunes, Books, Messages, Mail, Calendar, Photos,"
			<< " and FaceTime.\n"
			<< "More information can be found at: https://support.apple.com/"
			<< "en-us/HT201541\n";
    	}
    	break;
    case 5: // code to be executed if n = 2;
    	printf("\n6. DNS usage:\n");
        if(ret){
        	cout << "You are using a DNS server. This is secure.\n";
    	}else{
    		cout << "Warning!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    		cout << "\nYou need to use a DNS server to increase your security."
			<< "\nIt is recommended you use Google's DNS server. This "
			<< "increases both speed and reliability.\nTo do so, do the "
			<< "following:\n"
			<< "1. Choose System Preferences from the Apple () menu, then "
			<< "click the Network icon."
			<< "\n2. Click the Advanced button near the bottom right corner."
			<< "And click the DNS tab."
			<< "\n3. Click the + symbol at the bottom to add new ones. "
			<< "Add 8.8.8.8 and then 8.8.4.4. These are the Google servers."
			<< "\n4. Click ok then click apply.\n"
			<< "\nDNS servers such as google's are important because "
			<< "\"they offer phishing protection and stronger security against"
			<< " things like DNS poisoning, spoofing and DDoS attacks.\""
			<< " More information can be found at: https://www.howtogeek.com/"
			<< "howto/38793/how-to-switch-mac-os-x-to-use-opendns-or-google-"
			<< "dns/ and https://lifehacker.com/how-to-make-your-mac-as-secure"
			<< "-as-possible-1829531978\n";
    	}
    	break;
    case 6: // code to be executed if n = 1;
    	printf("\n7. Password Security:\n");
        if(ret){
        	cout << "You password is not in the dictionary. This is secure.\n";
    	}else{
    		cout << "Warning!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    		cout << "Your password is in the dictionary. This is insecure.\n";
    	}
    	break;
    case 7: // code to be executed if n = 2;
    	printf("\n8. Checking Firmware Password:\n");
        if(ret){
        	cout << "You have a firmware password. This is secure.\n";
    	}else{
    		cout << "Warning!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    		cout << "You do not have a firmware password. This is insecure.\n";
    	}
    	break;
    default: // code to be executed if n doesn't match any cases
    	break;
}
}


string GetNthWord(string s, size_t n)
{
    std::istringstream iss (s);
    while(n-- > 0 && (iss >> s));
    return s;
}

