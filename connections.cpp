//  ---------------------------------------------------------------------------
//  Program for CyberSafe                                lsofgrepProcessor.cpp
//	This progam checks the output of the commands to see which programs are 
// 		Currently using the camera.
//  Created by Bilal Abu-Ghazaleh on Sun September 9, 2018
// ----------------------------------------------------------------------------
#include "connections.hpp"


// ----------------------------------------------------------------------------
int connections::
run(){

	if(DEBUG){ 	lineSeparator(); (cout << "connections.cpp\n");}

	if(getUID() < 0){
		printf("Failed to open file: user.id\n");
		return -1;
	}

	if(getConnections() < 0){
		printf("Failed to open file: who.txt\n");
		return -1;
	}

	verifyConnections();
	if (DEBUG) { lineSeparator(); cout << "\nEnd of connections.cpp\n";}

	if (secure) return 1;
	return 0;
}

// ----------------------------------------------------------------------------
int connections::
getUID(){
	system("whoami > user.id");

	UIDFile = "user.id";
	ifstream in(UIDFile);
	if (!in) return -1;//Deal with this error later

	if(in.good()) in >> UID; 
	else return -1;
	if (DEBUG) cout << "UID: " << UID << "\n";


	in.close();
	if(!DEBUG) system("rm user.id");
	return 0;
}

// ----------------------------------------------------------------------------
int connections::
getConnections(){
	system("who -u > who.txt");

	whoFile = "who.txt";
	ifstream in(whoFile);
	if (!in) return -1;//Deal with this error later

	if(DEBUG) cout << "\nActive Connections:\n";
	while (getline (in, activeConnections[connectionCount++])){
		if (DEBUG) cout << activeConnections[connectionCount - 1] <<"--"<<endl;
	}

	in.close();
	if(!DEBUG) system("rm who.txt");
	return 0;

}

// ----------------------------------------------------------------------------
void connections::
verifyConnections(){
	for(int i = 0; i < connectionCount -1 ; i++){	// -1 because final is \n
		size_t found = activeConnections[i].find("(");
		if(found != -1){
			illegalConnections[illegalConnectionCount] 
			  = activeConnections[i].substr(found);
			illegalConnectionsPID[illegalConnectionCount++]
			 = GetNthWord(activeConnections[i], 7);
		}
	}

		int temp = illegalConnectionCount;
		while(temp > 0){
			if (DEBUG){
				cout << "\n\n// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
					<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
		 			<< "\nIllegal connection detected from host: " 
		 			<< illegalConnections[temp - 1] << " With PID " 
		 			<< illegalConnectionsPID[temp - 1] << "\n";
		 	}
		 	cout << "A remote connection has been detected. If you did not"
		 	 << " approve of this or you are unsure what this is, please type"
		 	 << " in yes and the connection will be terminated.\n"
		 	 << "Would you like to kill the connection?"
		 	 << " Please type in yes or no: ";
		 	cin >> answer;
		 	while(answer != "yes" && answer != "no"){
				cout << ("\nPlease type in yes or no: ");
				cin >> answer;
			}

			if (answer == "yes"){
		 		string killCommand = "kill";
		 		killCommand += " ";
		 		killCommand += illegalConnectionsPID[temp - 1];

		 		system(killCommand.c_str());
		 		cout << killCommand << "--Illegal Connection killed.\n";
	 		}
	 		temp--;
	 		secure =false;
		}

}




