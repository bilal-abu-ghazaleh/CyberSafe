// ---------------------------------------------------------------------------
//  Main program for CyberSafe.                                CyberSafe.sh
//  Created by Bilal Abu-Ghazaleh on Mon April 1, 2019
// ----------------------------------------------------------------------------

#include "tools.hpp"
#include "cam.hpp"
#include "connections.hpp"
#include "encryptionAndFirewall.hpp"
#include "softwareAndDNS.hpp"
#include "passwords.hpp"

void run();

// ----------------------------------------------------------------------------
int main (int argc, char** argv) {
	banner();
	run();
	bye();
	return 0;
}


//  ---------------------------------------------------------------------------
void run(){
	int outputs[10] = {0};

	nextFunction(0);

	// Remote connections check
	printf("1/8 Checking Remote connections:\n");
	connections conn;
	outputs[0] = conn.run();
	nextFunction(1);

	// Continue with Webcam
	printf("2/8 Checking Webcam:\nPlease wait...\n");
	cam Webcam;
	outputs[1] = Webcam.run();
	nextFunction(1);

	// Check file encryption
	printf("3/8 Checking Encryption:...\n");
	encryptionAndFirewall e;
	outputs[2] = e.run("encryption");
	nextFunction(1);

	// Check if firewall is on
	printf("4/8 Checking Firewall:...\n");
	encryptionAndFirewall f;
	outputs[3] = f.run("firewall");
	nextFunction(1);

	// Check if Software update needed
	printf("5/8 Checking for Software Update:\nPlease wait...\n");
	softwareAndDNS su;
	outputs[4] = su.run("software");
	nextFunction(1);

	// Checking DNS usage
	printf("6/8 Checking DNS usage:...\n");
	softwareAndDNS dns;
	outputs[5] = dns.run("dns");
	nextFunction(1);

	// Checking Password Security
	printf("7/8 Checking Password Security:...\n");
	passwords p;
	outputs[6] = p.run();
	nextFunction(1);

	// Checking Firmware Password
	printf("8/8 Checking Firmware Password:...\n");
	outputs[7] = p.runfirm();

	banner();
	for(int i = 0; i < 8; i++){
		printFunctions(i, outputs[i]);
	}
	



	// Unauthorized users
	// dscl . list /Users | grep -v '_'
}





