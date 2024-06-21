#include <iostream>

#include "SequentialList.hpp"

int main(void) {
	SequentialList sl1(3);
	SequentialList sl2(5);

	sl1.insert_front(5);
	sl1.insert(10, 0);
	sl1.insert(15, 2);
	sl1.insert_back(20);

	sl2.insert(25, 0);
	sl2.insert_back(50);
	sl2.insert_front(75);
	sl2.insert(100, 0);

	sl1.print();

	std::cout << std::endl;

	sl2.print();

	return 0;
}