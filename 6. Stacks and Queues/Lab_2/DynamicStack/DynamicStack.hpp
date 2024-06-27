#ifndef DYNAMIC_STACK_HPP
#define DYNAMIC_STACK_HPP

class DynamicStack {
	friend class DynamicStackTest;

public:
	// Can be seen outside as DynamicStack::StackItem
	typedef int StackItem;

	// Used as an indicator of empty stack.
	static const StackItem EMPTY_STACK = -1;


	DynamicStack();

	DynamicStack(unsigned int capacity);

	~DynamicStack();


	void push(StackItem value);

	StackItem pop();

	bool empty() const;

	unsigned int size() const;

	StackItem peek() const;

	void print() const;

	unsigned int capacity() const;


private:
	// Make copy constructor and assignment operator private.
	DynamicStack(const DynamicStack& other) {};

	DynamicStack operator=(const DynamicStack& other) {};


private:
	StackItem* items_;

	unsigned int capacity_;

	unsigned int size_;

	unsigned int init_capacity_;
};

#endif // DYNAMIC_STACK_HPP
