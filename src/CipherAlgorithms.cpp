/*
 * CipherAlgorithms.cpp
 *
 *  Created on: 1 Feb 2016
 *      Author: Michael
 */

#include "CipherAlgorithms.h"

CipherAlgorithms::CipherAlgorithms() {
	SPACE = 32;
	CR = 13;
	LF = 10;
}

CipherAlgorithms::~CipherAlgorithms() {
}

void CipherAlgorithms::setPlainText(char* data, int len) {
	plainText = new char[len];
	memcpy(plainText, data, len);
	plainTextLen = len;
}

char* CipherAlgorithms::getCipherText() {
	return cipherText;
}

void CipherAlgorithms::expandVigenereKey(char* key) {
	expandedKey = new char[plainTextLen];
	expandedKeyLen = plainTextLen;
	int keylen = strlen(key);
	unsigned char ch;
	int i =0;
	int j =0;
	for (i = 0; i < plainTextLen ; i++) {
		ch = plainText[i];
		if (ch == 10 || ch == 13 || ch == 32) {
			expandedKey[i] = 0;
		} else {
			expandedKey[i] = key[j];
			if (j == keylen-1) {
				j = 0;
			} else {
				j++;
			}
		}
	}
}

void CipherAlgorithms::expandVigenereKeyForBinary(char* key) {
	expandedKey = new char[plainTextLen];
	expandedKeyLen = plainTextLen;
	int keylen = strlen(key);
	int i =0;
	int j =0;
	for (i = 0; i < plainTextLen ; i++) {
		expandedKey[i] = key[j];
		if (j == keylen-1) {
			j = 0;
		} else {
			j++;
		}
	}
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
	cipherText = new char[plainTextLen];
	int i;
	for (i = 0; i < plainTextLen ; i++) {
		cipherText[i] = (plainText[i] + expandedKey[i] - 2*'A') % 26 + 'A';
	}
	cipherText[plainTextLen] = 0;
}

void CipherAlgorithms::encryptVigenereExt() {
	cipherText = new char[plainTextLen];
	int i;
	for (i = 0; i < plainTextLen ; i++) {
		unsigned char ch = (plainText[i] + expandedKey[i]) % 255;
		cipherText[i] = ch;
	}
	cipherText[plainTextLen] = 0;
}

void CipherAlgorithms::encryptPlayfair() {

}

void CipherAlgorithms::decryptVigenereStd() {
	cipherText = new char[plainTextLen];
	int i;
	for (i = 0; i < plainTextLen ; i++) {
		cipherText[i] = (plainText[i] - expandedKey[i] + 26) % 26 + 'A';
	}
	cipherText[plainTextLen] = 0;
}

void CipherAlgorithms::decryptVigenereExt() {
	cipherText = new char[plainTextLen];
	int i;
	for (i = 0; i < plainTextLen ; i++) {
		unsigned char ch = (plainText[i] - expandedKey[i]) % 255;
		cipherText[i] = ch;
	}
	cipherText[plainTextLen] = 0;
}

void CipherAlgorithms::decryptPlayfair() {
}

void CipherAlgorithms::shiftPlaintextChar() {
	int i;
	for(i=0; i < strlen(plainText); i++) {
		plainText[i] -= 64;
	}
	for(i=0; i < strlen(plainText); i++) {
			printf("%d ", plainText[i]);
		}
	std::cout << std::endl;
}

void CipherAlgorithms::shiftKeyChar() {
	int i;
	for(i=0; i < expandedKeyLen; i++) {
		if (expandedKey[i] >= 65 && expandedKey[i] <= 90) {
			expandedKey[i] -= 64;
		}
	}

	for(i=0; i < expandedKeyLen; i++) {
		printf("%d ", expandedKey[i]);
	}
	std::cout << std::endl;
}

void CipherAlgorithms::shiftBackCipherChar() {
	int i;
	for(i=0; i < strlen(cipherText); i++) {
				printf("%d ", cipherText[i]);
			}
		std::cout << std::endl;
	for(i=0; i < strlen(cipherText); i++) {
		cipherText[i] += 64;
	}
	for(i=0; i < strlen(cipherText); i++) {
				printf("%d ", cipherText[i]);
			}
		std::cout << std::endl;
	std::cout << "Cipher: " << cipherText << std::endl;
}
