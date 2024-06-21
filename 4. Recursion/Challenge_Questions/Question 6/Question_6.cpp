#include <iostream>

double sumFractions(unsigned int n) {
	if (n <= 1) {
		return 1.0;
	}

	return ((1.0 / n) + sumFractions((n - 1)));
};


int main(void) {
	std::cout << sumFractions(5) << std::endl;

	return 0;
};