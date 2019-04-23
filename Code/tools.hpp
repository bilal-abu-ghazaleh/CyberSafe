// ---------------------------------------------------------------------------
//  Tools program for CyberSafe.                                tools.hpp
//  Created by Bilal Abu-Ghazaleh on Mon April 1, 2019
// ----------------------------------------------------------------------------
//#pragma once

#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#include <string.h>
#include <cerrno>
#include <cmath>
#include <ctime>
#include <cctype>      // for isspace() and isdigit()
#include <cstdarg>     // for functions with variable # of arguments
#include <unistd.h>

using namespace std;


// ----------------------------------------------------------------------------
#define DEBUG 0


// Banner that welcomes user
void banner();

//
void printLogo();

// Goodbye message at the end of the program
void bye();

// Print seperator
void lineSeparator();

// Clears terminal screen
void nextFunction(int in);

// Prints output and inputs depending on result of test
void printFunctions(int functionNumber, int ret);

// Get nth word from string from http://www.cplusplus.com/
string GetNthWord(string s, size_t n);

