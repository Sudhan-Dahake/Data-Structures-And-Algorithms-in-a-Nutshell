#include <iostream>
#include <string>

int ascii2int(std::string strOfDigits) {
	if (strOfDigits.length() == 0) {
		return 0;
	};

	int lastDigit = strOfDigits[strOfDigits.length() - 1] - '0';

	strOfDigits = strOfDigits.substr(0, (strOfDigits.length() - 1));

	return (ascii2int(strOfDigits) * 10) + lastDigit;
};


int main(void) {
	std::cout << ascii2int("45612") << std::endl;
};