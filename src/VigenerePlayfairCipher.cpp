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
		utils.readFromStdin(parser.ENCRYPT_FLAG);
	} else {
		try {
			utils.readFromFile(parser.INPUT_FILE, parser.BINARY_MODE);
		} catch (char const* e) {
			cerr << e << endl;
			return 1;
		}
	}
	//Choose cipher and do encrypt/decrypt
	//Check key validity
	if (stricmp(parser.OPT_ALGO, parser.ALGO_VIG_STD) == 0) {
		if(!cipher.checkInputAlphabetOnly(parser.KEY)){
				cerr << "KEY Error! Only Capital Alphabet is allowed" << endl;
				return 1;
		}
		if(!cipher.checkInputAlphabetOnly(utils.getInputData())) {
			cerr << "Input Error! Only Capital Alphabet is allowed in this mode" << endl;
			return 1;
		}
		//Cal vig_std method
		cipher.setPlainText(utils.getInputData(), utils.getInputLen());
		cipher.expandVigenereKey(parser.KEY);
		if (parser.ENCRYPT_FLAG) {
			cipher.encryptVigenereStd();
		}
		if (parser.DECRYPT_FLAG) {
			cipher.decryptVigenereStd();
		}
	} else if (stricmp(parser.OPT_ALGO, parser.ALGO_VIG_EXT) == 0) {
		if(!cipher.checkInputAlphabetOnly(parser.KEY)){
				cerr << "KEY Error! Only Capital Alphabet is allowed" << endl;
				return 1;
		}
		cipher.setPlainText(utils.getInputData(), utils.getInputLen());
		if(parser.BINARY_MODE) {
			cipher.expandVigenereKeyForBinary(parser.KEY);
		} else {
			cipher.expandVigenereKey(parser.KEY);
		}
		if (parser.ENCRYPT_FLAG) {
			cipher.encryptVigenereExt();
		}
		if (parser.DECRYPT_FLAG) {
			cipher.decryptVigenereExt();
		}
	} else if (stricmp(parser.OPT_ALGO, parser.ALGO_PLAYFAIR) == 0) {
		cipher.setPlainText(utils.getInputData(), utils.getInputLen());
		cipher.generatePlayfairKey(parser.KEY);
		if (parser.ENCRYPT_FLAG) {
			cipher.playfair(parser.ENCRYPT_FLAG);
		} else {
			cipher.playfair(parser.ENCRYPT_FLAG);
		}
	} else {
		//Mode not recognized, should be error
		return 1;
	}

	//Set output data
	utils.setOutputData(cipher.getCipherText());

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
		utils.outputStdout(parser.ENCRYPT_FLAG);
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
