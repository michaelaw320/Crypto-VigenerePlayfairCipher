/*
 * CipherAlgorithms.h
 *
 *  Created on: 1 Feb 2016
 *      Author: Michael
 */

#ifndef CIPHERALGORITHMS_H_
#define CIPHERALGORITHMS_H_

class CipherAlgorithms {
public:
	CipherAlgorithms();
	virtual ~CipherAlgorithms();
	void setPlainText(char* data);
	char* getCipherText();
	void expandVigenereKey(char* key);
	void generatePlayfairKey(char* key);
	bool checkInputAlphabetOnly(char* inputData);
private:
	char* plainText;
	char* cipherText;
	char* expandedKey;
	char* playfairKey;
	char SPACE;
	char CR;
	char LF;
	void shiftInputChar(char* inputData);
	void shiftBackChar();
};

#endif /* CIPHERALGORITHMS_H_ */
