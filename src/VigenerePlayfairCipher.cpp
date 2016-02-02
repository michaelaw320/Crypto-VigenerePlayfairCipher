//============================================================================
// Name        : VigenerePlayfairCipher.cpp
// Author      : Michael 13512046
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "CommandLineParser.h"
#include "IOUtil.h"
#include "CipherAlgorithms.h"
using namespace std;

int main(int argc, char **argv) {
	//Command line parameter checking
	CommandLineParser parser;
	if(argc <= 1) {
		cout << "Run " << argv[0] << " -h for help" << endl;
		return 1;
	} else {
		if(!parser.PARSE_PARAM(argc, argv)) {
			cout << "Run " << argv[0] << " -h for help" << endl;
			return 1;
		}
	}
	//Passed parameter checking, begin main routine
	IOUtil utils;
	CipherAlgorithms cipher;

	//Load data
	if(stricmp(parser.INPUT_FILE, "stdin") == 0) {
		utils.readFromStdin();
	} else {
		try {
			utils.readFromFile(parser.INPUT_FILE, parser.BINARY_MODE);
		} catch (char const* e) {
			cerr << e << endl;
			return 1;
		}
	}
	//Choose cipher and do encrypt/decrypt

	//Set output data
	utils.setOutputData(utils.getInputData());

	//Format output data
	if(stricmp(parser.OPT_OUTPUT_FORMAT, parser.OUTPUT_FMT_NOSPACE) == 0) {
		utils.formatOutput(1);
	} else if (stricmp(parser.OPT_OUTPUT_FORMAT, parser.OUTPUT_FMT_FIVE) == 0) {
		utils.formatOutput(2);
	} else {
		//Normal format, do nothing
	}

	//Output data
	if(stricmp(parser.OUTPUT_FILE, "stdout") == 0) {
		utils.outputStdout();
	} else {
		try {
			utils.outputFile(parser.OUTPUT_FILE, parser.BINARY_MODE);
		} catch (char const* e) {
			cerr << e << endl;
			return 1;
		}
	}

	return 0;
}
