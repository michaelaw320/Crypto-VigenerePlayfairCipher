//============================================================================
// Name        : VigenerePlayfairCipher.cpp
// Author      : Michael 13512046
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <iostream>
#include <cstdlib>
#include "CommandLineParser.h"
using namespace std;


int main(int argc, char **argv) {
	if(argc > 1) {
		if(!PARSE_PARAM(argc, argv)) {
			cout << "Run " << argv[0] << " -h for help" << endl;
			return 1;
		}
	} else {
		printf("noparam");
	}
	return 0;
}
