/*
 * IOUtil.cpp
 *
 *  Created on: 1 Feb 2016
 *      Author: Michael
 */

#include "IOUtil.h"

using namespace std;

IOUtil::IOUtil() {
	inputData = NULL;
	inputLen = 0;
	outputData = NULL;
}

IOUtil::~IOUtil() {
}

char* IOUtil::getInputData() {
	return inputData;
}

int IOUtil::getInputLen() {
	return inputLen;
}

void IOUtil::setOutputData(char* data) {
	outputData = data;
}

void IOUtil::readFromStdin(bool isEncrypt) {
	string input;
	if (isEncrypt) cout << "Input string to encrypt" << endl;
	else cout << "Input string to decrypt" << endl;
	getline(cin,input);
	inputLen = input.length();
	inputData = new char[inputLen];
	strncpy(inputData, input.c_str(), inputLen);
	inputData[inputLen] = 0;
}

void IOUtil::readFromFile(char* filename, bool isBinaryMode) {
	ifstream inputFile;
	if (isBinaryMode) {
		inputFile.open(filename, ios::in|ios::binary|ios::ate);
		if(inputFile.is_open()) {
			streampos size;
			size = inputFile.tellg();
			inputData = new char[size];
			inputLen = size;
			inputFile.seekg(0, ios::beg);
			inputFile.read(inputData, size);
			inputFile.close();
		} else {
			throw "Cannot open input file!";
		}
	} else {
		inputFile.open(filename, ios::in|ios::ate);
		if (inputFile.is_open()) {
			streampos size;
			size = inputFile.tellg();
			inputData = new char[size];
			inputLen = size;
			inputFile.seekg(0, ios::beg);
			inputFile.get(inputData, size+1, '\0');
			inputFile.close();
			int n = 0;
		} else {
			throw "Cannot open input file!";
		}
	}
}

void IOUtil::formatOutput(int option) {
	//option 1 = no space, option 2 = five
	//Trim spaces, cr, lf
	string processing = "";
	for(unsigned int i = 0; i <= strlen(outputData); i++) {
		if(outputData[i] == 10 || outputData[i] == 13 || outputData[i] == 32) {
			//not adding
		} else {
			processing += outputData[i];
		}
	}
	if (option == 2) {
		int count = 0;
		string processing2 = "";
		for (unsigned int i=0; i < processing.length(); i++) {
			if (count == 4) {
				processing2 += processing[i];
				processing2 += ' ';
				count = 0;
			} else {
				processing2 += processing[i];
				count++;
			}
		}
		processing = processing2;
	}
	delete[] outputData;
	outputData = new char[strlen(processing.c_str())];
	strcpy(outputData, processing.c_str());
}

void IOUtil::outputStdout(bool isEncrypt) {
	if (isEncrypt) {
	cout << "Plaintext:" << endl;
	cout << inputData << endl;
	cout << "Ciphertext:" << endl;
	cout << outputData << endl;
	} else {
	cout << "Ciphertext:" << endl;
	cout << inputData << endl;
	cout << "Plaintext:" << endl;
	cout << outputData << endl;
	}
}

void IOUtil::outputFile(char* filename, bool isBinaryMode) {
	ofstream outputFile;
		if (isBinaryMode) {
			outputFile.open(filename, ios::out|ios::binary);
			if(outputFile.is_open()) {
				outputFile.write(outputData, inputLen);
				outputFile.close();
			} else {
				throw "Cannot open output file!";
			}
		} else {
			outputFile.open(filename, ios::out);
			if (outputFile.is_open()) {
				outputFile << outputData;
				outputFile.close();
			} else {
				throw "Cannot open output file!";
			}
		}
}
