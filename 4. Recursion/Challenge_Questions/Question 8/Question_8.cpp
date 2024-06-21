#include <iostream>

std::string int2ascii(int number) {
	if (number == 0) {
		return "";
	}

	int lastDigit = number % 10;

	return int2ascii(number / 10) + char(lastDigit + '0');
};


int main(void) {
	std::cout << int2ascii(12112002) << std::endl;

	return 0;
};