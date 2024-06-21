#include <iostream>

std::string dec2bin(int number) {
	if (number == 0) {
		return "";
	}

	return dec2bin(number / 2) + (char)((number % 2) + '0');
};


int main(void) {
	std::cout << dec2bin(12) << std::endl;

	return 0;
};