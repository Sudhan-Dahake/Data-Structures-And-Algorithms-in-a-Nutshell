#include "CircularQueue.hpp"

#include <iostream>

int main(void) {
	CircularQueue cq(3);

	cq.enqueue(10);
	cq.enqueue(20);
	cq.enqueue(30);
	
	cq.dequeue();
	cq.dequeue();

	cq.print();
	
	return 0;
};