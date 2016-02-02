/*
 * CipherAlgorithms.h
 *
 *  Created on: 1 Feb 2016
 *      Author: Michael
 */

#ifndef CIPHERALGORITHMS_H_
#define CIPHERALGORITHMS_H_

#include <cstring>
#include <string>
#include <iostream>

class CipherAlgorithms {
public:
	CipherAlgorithms();
	virtual ~CipherAlgorithms();
	void setPlainText(char* data, int len);
	char* getCipherText();
	void expandVigenereKey(char* key);
	void expandVigenereKeyForBinary(char* key);
	bool checkInputAlphabetOnly(char* inputData);
	void encryptVigenereStd();
	void encryptVigenereExt();
	void decryptVigenereStd();
	void decryptVigenereExt();
	void generatePlayfairKey(char* key);
	void playfair(bool encryptFlag);
private:
	char* plainText;
	int plainTextLen;
	char* cipherText;
	char* expandedKey;
	int expandedKeyLen;
	char playfairKey[5][5];
	std::string playfairProcessed;
	char SPACE;
	char CR;
	char LF;
	void preprocessPlayfairInput(bool encryptFlag);
	bool getCharPos( char l, int &a, int &b);
	char getChar(int a, int b);
	void postprocessPlayfair();
};

#endif /* CIPHERALGORITHMS_H_ */
