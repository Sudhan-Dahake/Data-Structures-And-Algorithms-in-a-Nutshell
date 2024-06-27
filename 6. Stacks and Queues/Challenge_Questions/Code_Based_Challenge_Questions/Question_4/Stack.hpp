#ifndef STACK_HPP
#define	STACK_HPP

typedef int StackItem;

class Stack {
	StackItem* head;
	StackItem* tail;

	StackItem* topOfStack;

	unsigned int capacity;
	unsigned int size;

public:
	Stack(unsigned int capacity);

	Stack(StackItem* stack, unsigned int capacity);

	~Stack();

	bool Push(StackItem sItem);

	StackItem Pop();

	StackItem Peek();

	void Print();
};

#endif	// STACK_HPP