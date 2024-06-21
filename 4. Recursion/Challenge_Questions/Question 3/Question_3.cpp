#include <iostream>

bool IsPalindrome(char sequence[], int len) {
	if (len <= 1) {
		return true;
	};

	if (sequence[0] != sequence[len - 1]) {
		return false;
	};

	sequence++;
	len = len - 2;

	return IsPalindrome(sequence, len);
};


int main(void) {
	char sequence[] = { 'r', 'a', 'c', 'e', 'c', 'a', 'r' };

	std::cout << IsPalindrome(sequence, 7);

	return 0;
};