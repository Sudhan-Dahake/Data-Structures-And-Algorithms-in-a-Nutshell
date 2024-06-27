#include <iostream>
#include "Queue.hpp"

int main(void) {
	CircularQueue queue(5);

	queue.Enqueue(5);
	queue.Enqueue(3);
	queue.Enqueue(8);
	queue.Enqueue(9);
	queue.Enqueue(10);


	queue.Dequeue();


	queue.Enqueue(1);
	queue.Enqueue(7);
	//queue.Enqueue(2);


	//queue.Dequeue();
	//queue.Dequeue();
	//queue.Dequeue();
	//queue.Dequeue();

	queue.print();
};