#include <iostream>

float exponent(int m, int n) {
	float currentValue = 0;

	if (n == 0) {
		return 1;
	};

	if (n < 0) {
		currentValue = exponent(m, ((-n) - 1));
	}

	else {
		currentValue = exponent(m, (n - 1));
	};


	currentValue = currentValue * m;

	if (n < 0) {
		return (1 / currentValue);
	};

	return currentValue;
};


int main(void) {
	std::cout << exponent(5, -3);

	return 0;
};