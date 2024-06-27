#include "DynamicStack.hpp"

#include <iostream>

int main(void) {
	DynamicStack ds(36);

	ds.push(10);
	ds.push(20);
	ds.push(30);
	ds.push(40);
	ds.push(50);
	ds.push(60);

	std::cout << ds.peek() << std::endl;

	std::cout << ds.capacity() << std::endl;

	ds.pop();
	std::cout << ds.capacity() << std::endl;

	ds.pop();
	std::cout << ds.capacity() << std::endl;

	ds.pop();
	std::cout << ds.capacity() << std::endl;

	ds.print();

	std::cout << ds.peek() << std::endl;
	
	return 0;
};