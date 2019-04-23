//  ---------------------------------------------------------------------------
//  Program for CyberSafe                                softwareAndDNS.cpp
//	This progam checks the output of the commands to see if software needs
// 	and update and if DNS is enabled.
//  Created by Bilal Abu-Ghazaleh on Sun September 9, 2018
// ----------------------------------------------------------------------------
#include "softwareAndDNS.hpp"


// ----------------------------------------------------------------------------
int softwareAndDNS::
run(string typeOfCheck){

	if(DEBUG){ 	
		lineSeparator();
		if(typeOfCheck == "software") (cout << "softwareUpdate part of cpp\n");
		else cout << "DNS part of cpp\n";
	}

	if (typeOfCheck == "software"){
		fileName = "softwareUpdate.txt";

		system("softwareupdate -l > softwareUpdateOutput.txt");
		system("if grep -Eo 'Software Update found the following new or updated" 
				"software:' softwareUpdateOutput.txt > temp.txt"
					"\nthen echo true > softwareUpdate.txt;"
				"\nelse echo false > softwareUpdate.txt;"
			"\nfi");
	}else{
		fileName = "dns.txt";
		
		system("networksetup -getdnsservers Wi-Fi > dnsoutput.txt");
		system("if grep -Eo \"There aren't any DNS Servers set on Wi-Fi.\" dnsoutput.txt > temp.txt"
					"\nthen echo false > dns.txt;"
				"\nelse echo true > dns.txt;"
				"\nfi");
	}

	if(readFile(typeOfCheck) < 0){
		cout << ("Failed to open file: ");
		if(typeOfCheck == "software") cout << "softwareUpdate.txt";
		else cout << "dns.txt";
		return -1;
	}

	if (DEBUG) {
		lineSeparator();
		if (typeOfCheck == "software") cout << "\nEnd of softwareUpdate part cpp\n";
		else cout << "\nEnd of DNS part cpp\n";
	}

	if (typeOfCheck == "software"){
		if (!update) return 1;
		return 0;
	}else{
		if (exists) return 1;
		return 0;
	}


}

// ----------------------------------------------------------------------------
int softwareAndDNS::
readFile(string typeOfCheck){
	ifstream in(fileName);
	if (!in) return -1;//Deal with this error later

	in >> cmdResponse;

	if(typeOfCheck == "software") {if (cmdResponse != "true") update = false;}
	else {if (cmdResponse != "true") exists = false;}

	if (DEBUG) cout << "Response: " << cmdResponse << endl;

	in.close();

	if(!DEBUG) {
		system("rm temp.txt");
		if(typeOfCheck == "software"){
			system("rm softwareUpdate.txt");
			system("rm softwareUpdateOutput.txt");
		}else{
			system("rm dns.txt");
			system("rm dnsoutput.txt");
		}
	}
	return 0;
}

