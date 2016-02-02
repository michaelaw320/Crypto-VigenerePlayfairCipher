/*
 * CipherAlgorithms.cpp
 *
 *  Created on: 1 Feb 2016
 *      Author: Michael
 */

#include "CipherAlgorithms.h"

using namespace std;

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
	plainText[len] = 0;
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

void CipherAlgorithms::playfair(bool encryptFlag) {
	preprocessPlayfairInput(encryptFlag);
	int direction;
	(encryptFlag) ? direction=1 : direction=-1;
	int a,b,c,d;
	string nt;
	for (string::const_iterator ti = playfairProcessed.begin(); ti != playfairProcessed.end(); ti++) {
		if (getCharPos (*ti++, a, b))
			if (getCharPos(*ti, c, d)) {
				if (a == c) {
					nt += getChar(a,b+direction);
					nt += getChar(c,d+direction);
				} else if (b == d) {
					nt += getChar(a+direction,b);
					nt += getChar(c+direction,d);
				} else {
					nt += getChar(c,b);
					nt += getChar(a,d);
				}
 			}
	}
	playfairProcessed = nt;
	postprocessPlayfair();
}

void CipherAlgorithms::generatePlayfairKey(char* key) {
	string k(key);
	k += "ABCDEFGHIJKLMNOPQRSTUVWZYZ";
	string nk = "";
	for (string::iterator si = k.begin(); si != k.end(); si++) {
		*si = toupper(*si); if (*si < 65 || *si > 90) continue;
		if (*si == 'J') continue;
		if (nk.find(*si) == -1) nk += *si;
	}
	copy (nk.begin(), nk.end(), &playfairKey[0][0]);
}

void CipherAlgorithms::preprocessPlayfairInput(bool encryptFlag) {
	string t(plainText);
	for (string::iterator si = t.begin(); si != t.end(); si++) {
		*si = toupper(*si); if (*si < 65 || *si > 90) continue;
		if (*si == 'J') *si = 'I';
		playfairProcessed += *si;
	}
	if (encryptFlag) {
		string nt = ""; size_t len = playfairProcessed.length();
		for (size_t x = 0; x < len; x += 2) {
			nt += playfairProcessed[x];
			if (x+1 < len) {
				if (playfairProcessed[x] == playfairProcessed[x+1]) playfairProcessed += 'Z';
				nt += playfairProcessed[x+1];
			}
		}
		playfairProcessed = nt;
	}
	if (playfairProcessed.length() & 1) playfairProcessed += 'Z';
}

bool CipherAlgorithms::getCharPos(char l, int& a, int& b) {
	for (int y=0; y < 5; y++)
		for (int x=0; x<5; x++)
			if (playfairKey[y][x] == l) {
				a = x;
				b = y;
				return true;
			}
	return false;
}

char CipherAlgorithms::getChar(int a, int b) {
	return playfairKey[(b+5)%5][(a+5)%5];
}

void CipherAlgorithms::postprocessPlayfair() {
	string output = "";
	string::iterator si = playfairProcessed.begin();
	int cnt = 0;
	while (si != playfairProcessed.end()) {
		output += *si; si++; output += *si; output += " "; si++;
		//if (++cnt >= 26) cnt=0;
	}
	cipherText = new char[output.length()];
	strcpy(cipherText, output.c_str());
}
