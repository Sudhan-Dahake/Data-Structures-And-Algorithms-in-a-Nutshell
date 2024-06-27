#include "DynamicStack.hpp"

#include <iostream>

DynamicStack::DynamicStack() {
	this->init_capacity_ = 16;

	this->capacity_ = this->init_capacity_;

	this->items_ = new StackItem[sizeof(StackItem) * this->capacity_];

	memset(this->items_, 0, (sizeof(StackItem) * this->capacity_));

	this->size_ = 0;
};


DynamicStack::DynamicStack(unsigned int capacity) {
	this->init_capacity_ = 16;

	if (capacity <= 0) {
		this->capacity_ = this->init_capacity_;
	}

	else {
		this->capacity_ = capacity;
	}


	this->items_ = new StackItem[sizeof(StackItem) * this->capacity_];

	memset(this->items_, 0, (sizeof(StackItem) * this->capacity_));

	this->size_ = 0;
};


DynamicStack::~DynamicStack() {
	delete this->items_;

	this->items_ = nullptr;
};


void DynamicStack::push(StackItem value) {
	if (this->size_ >= this->capacity_) {
		StackItem* temp = new StackItem[(sizeof(StackItem)) * (2 * this->capacity_)];

		memset(temp, 0, sizeof(StackItem) * (2 * this->capacity_));

		memcpy(temp, this->items_, (sizeof(StackItem) * this->size_));

		this->capacity_ *= 2;

		delete this->items_;

		this->items_ = nullptr;

		this->items_ = temp;
	};

	StackItem* temp = this->items_;

	for (unsigned int i = 0; i <= this->size_; i++) {
		temp++;
	};


	*(temp) = value;

	this->size_++;

	temp = nullptr;
};


DynamicStack::StackItem DynamicStack::pop() {
	if (this->size_ <= 0) {
		return this->EMPTY_STACK;
	};


	StackItem sItem;

	StackItem* temp = this->items_;

	for (unsigned int i = 0; i < this->size_; i++) {
		temp++;
	};

	sItem = *(temp);

	memset(temp, 0, sizeof(StackItem));

	temp = nullptr;

	this->size_--;



	if (((float)(this->size_) <= (0.25 * (float)(this->capacity_))) && ((0.5 * (float)(this->capacity_)) >= (float)(this->init_capacity_))) {
		this->capacity_ = (unsigned int)(0.5 * (float)(this->capacity_));

		StackItem* newArray = new StackItem[sizeof(StackItem) * this->capacity_];

		memset(newArray, 0, (sizeof(StackItem) * this->capacity_));


		memcpy(newArray, this->items_, (sizeof(StackItem) * this->size_));


		delete this->items_;

		this->items_ = nullptr;


		this->items_ = newArray;

		newArray = nullptr;
	};


	return sItem;
};


DynamicStack::StackItem DynamicStack::peek() const {
	StackItem* topOfStack = this->items_;

	for (unsigned int i = 0; i < this->size_; i++) {
		topOfStack++;
	};

	return *(topOfStack);
};


bool DynamicStack::empty() const {
	if (this->size_ <= 0) {
		return true;
	};


	return false;
};


unsigned int DynamicStack::size() const {
	return this->size_;
};


void DynamicStack::print() const {
	std::cout << "Top of the Stack" << std::endl << std::endl;

	for (unsigned int i = this->size_; i > 0; i--) {
		std::cout << *(this->items_ + i) << std::endl;
	};


	std::cout << std::endl << "Bottom of the Stack" << std::endl << std::endl << std::endl;
};


unsigned int DynamicStack::capacity() const {
	return this->capacity_;
}