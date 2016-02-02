/*
 * CipherAlgorithms.cpp
 *
 *  Created on: 1 Feb 2016
 *      Author: Michael
 */

#include "CipherAlgorithms.h"

CipherAlgorithms::CipherAlgorithms() {
	// TODO Auto-generated constructor stub
	SPACE = 32;
	CR = 13;
	LF = 10;

}

CipherAlgorithms::~CipherAlgorithms() {
	// TODO Auto-generated destructor stub
}

void CipherAlgorithms::setPlainText(char* data) {
	std::cout << data << std::endl;
	plainText = new char[strlen(data)];
	strcpy(plainText, data);
	cipherText = plainText;
	std::cout << cipherText << std::endl;
}

char* CipherAlgorithms::getCipherText() {
	return cipherText;
}

void CipherAlgorithms::expandVigenereKey(char* key) {

}

void CipherAlgorithms::generatePlayfairKey(char* key) {
}

bool CipherAlgorithms::checkInputAlphabetOnly(char* inputData) {
	char ch;
	int i=0;
	ch = inputData[0];
	while (ch != '\0') {
		if (ch >= 65 && ch <= 90) {
			i++;
			ch = inputData[i];
		} else {
			return false;
		}
	}
	return true;
}

void CipherAlgorithms::encryptVigenereStd() {
}

void CipherAlgorithms::encryptVigenereExt() {
}

void CipherAlgorithms::encryptPlayfair() {
}

void CipherAlgorithms::decryptVigenereStd() {
}

void CipherAlgorithms::decryptVigenereExt() {
}

void CipherAlgorithms::decryptPlayfair() {
}

void CipherAlgorithms::shiftInputChar(char* inputData) {
}

void CipherAlgorithms::shiftBackChar() {
}
