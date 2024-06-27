#include "Stack.hpp"

#include <iostream>

Stack::Stack(unsigned int capacity) {
	this->capacity = capacity;

	this->head = new StackItem[sizeof(StackItem) * this->capacity];

	memset(this->head, 0, (sizeof(StackItem) * this->capacity));

	this->size = 0;

	this->tail = this->head + this->capacity;

	this->topOfStack = nullptr;
};


Stack::Stack(StackItem* stack, unsigned int capacity) {
	this->capacity = capacity;

	this->head = stack;

	memset(this->head, 0, (sizeof(StackItem) * this->capacity));

	this->tail = this->head + this->capacity;

	this->size = 0;

	this->topOfStack = nullptr;
};


Stack::~Stack() {
	this->tail = nullptr;

	this->topOfStack = nullptr;

	delete this->head;

	this->head = nullptr;
};


bool Stack::Push(StackItem sItem) {
	if (this->size >= this->capacity) {
		return false;
	}

	else if (this->size == 0) {
		this->topOfStack = this->head;
	}

	else {
		this->topOfStack++;
	}


	*(this->topOfStack) = sItem;

	this->size++;


	return true;
};


StackItem Stack::Pop() {
	if (this->size <= 0) {
		return -1;
	};

	StackItem sItem = *(this->topOfStack);

	memset(this->topOfStack, 0, sizeof(StackItem));

	this->topOfStack--;

	this->size--;


	return sItem;
};


StackItem Stack::Peek() {
	if (this->size <= 0) {
		return -1;
	};

	return *(this->topOfStack);
};


void Stack::Print() {
	std::cout << "Top of the Stack" << std::endl << std::endl;

	StackItem* temp = this->topOfStack;

	for (unsigned int i = 0; i < this->size; i++) {
		std::cout << *temp << std::endl;

		temp--;
	};

	std::cout << std::endl << "Bottom of the Stack" << std::endl;
};