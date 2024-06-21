#include <iostream>

int bin2dec(std::string binaryString) {
	if (binaryString == "") {
		return 0;
	};

	int number = (binaryString[0] - '0') * (int)(pow(2.0, (double)(binaryString.length() - 1)));

	return bin2dec(binaryString.substr(1, binaryString.length() - 1)) + number;
};


int main(void) {
	std::cout << bin2dec("101") << std::endl;

	return 0;
};