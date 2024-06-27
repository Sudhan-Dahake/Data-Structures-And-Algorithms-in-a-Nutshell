#include "Stack.hpp"

#include <iostream>

int main(void) {
	Stack s(10);

	s.Push(5);
	s.Push(3);
	s.Push(8);
	s.Push(9);

	s.Print();

	std::cout << std::endl;
	std::cout << std::endl;

	s.Pop();
	s.Pop();
	s.Pop();

	s.Print();

	std::cout << std::endl;
	std::cout << std::endl;

	s.Push(1);
	s.Push(7);
	s.Push(2);

	s.Print();

	std::cout << std::endl;
	std::cout << std::endl;

	s.Pop();
	s.Pop();
	s.Pop();

	s.Print();

	std::cout << std::endl;
	std::cout << std::endl;
	
	return 0;
};