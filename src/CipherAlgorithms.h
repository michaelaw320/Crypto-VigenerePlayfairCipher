/*
 * CipherAlgorithms.h
 *
 *  Created on: 1 Feb 2016
 *      Author: Michael
 */

#ifndef CIPHERALGORITHMS_H_
#define CIPHERALGORITHMS_H_

#include <cstring>
#include <iostream>

class CipherAlgorithms {
public:
	CipherAlgorithms();
	virtual ~CipherAlgorithms();
	void setPlainText(char* data, int len);
	char* getCipherText();
	void expandVigenereKey(char* key);
	void expandVigenereKeyForBinary(char* key);
	void generatePlayfairKey(char* key);
	bool checkInputAlphabetOnly(char* inputData);
	void encryptVigenereStd();
	void encryptVigenereExt();
	void encryptPlayfair();
	void decryptVigenereStd();
	void decryptVigenereExt();
	void decryptPlayfair();
private:
	char* plainText;
	int plainTextLen;
	char* cipherText;
	char* expandedKey;
	int expandedKeyLen;
	char playfairKey[5][5];
	char SPACE;
	char CR;
	char LF;
	void shiftPlaintextChar();
	void shiftKeyChar();
	void shiftBackCipherChar();
};

#endif /* CIPHERALGORITHMS_H_ */
