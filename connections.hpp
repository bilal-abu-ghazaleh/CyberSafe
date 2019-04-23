//  ---------------------------------------------------------------------------
//  Program for CyberSafe                                connections.hpp
//	This progam checks the output of the commands to see which programs are 
// 	remotely connected to host.
//  Created by Bilal Abu-Ghazaleh on Sun September 9, 2018
// ------------------------------------------------------------------------------------------------

#ifndef CONNECTIONS_HPP
#define CONNECTIONS_HPP

#include "tools.hpp"


class connections {
private:
	// ------------------------------------------------------------------------
	string UIDFile;
	string UID;
	string whoFile;
	string activeConnections[100];
	int connectionCount;
	string illegalConnections[100];
	int illegalConnectionCount;
	string illegalConnectionsPID[100];
	bool secure =true;
	string answer;

	// Get current user ID
	int getUID();
	// Get all active connections using who comamnd
	int getConnections();
	// Verify that all connections are current user and that there are no
	// remote connections and Kills necessary connections
	void verifyConnections();

public:
	// ------------------------------------------------------------------------
	connections() {connectionCount =0; illegalConnectionCount =0;}
	// ------------------------------------------------------------------------
	int run();

};
#endif	// CONNECTIONS_HPP


