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
private:
	char* plainText;
	char* cipherText;
};

#endif /* CIPHERALGORITHMS_H_ */
