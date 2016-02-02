#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
	char* test;
	test = (char*) malloc(10*sizeof(char));
	test[0] = 255;
	test[1] = 254;
	test[2] = 255;
	test[3] = 254;
	test[4] = 255;
	test[5] = 254;
	test[6] = 255;
	test[7] = 254;
	test[8] = 255;
	test[9] = 254;
	test[10] = '\0';
	cout << test;
	return 0;
}