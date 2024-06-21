#include <iostream>

int gcd(int m, int n) {

	// If one of the numbers become zero, the GCD of both the numbers is the non-zero number.
	if (n == 0) {
		return m;
	};

	// Based on Euclid's algorithm
	// uses the principle that the GCD of the two numbers does not change
	// if you replace the larger of the two with the remainder of the division between the larger number and smaller number.
	return gcd(n, m % n);
};

int main(void) {
	std::cout << gcd(18, 32) << std::endl;

	return 0;
};