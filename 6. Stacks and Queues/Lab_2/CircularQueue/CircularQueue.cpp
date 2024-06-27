#include "CircularQueue.hpp"

#include <iostream>

CircularQueue::CircularQueue() {
	this->capacity_ = 16;

	this->items_ = new QueueItem[sizeof(QueueItem) * this->capacity_];

	memset(this->items_, 0, (sizeof(QueueItem) * this->capacity_));

	this->head_ = 0;
	this->tail_ = 0;

	this->size_ = 0;
};


CircularQueue::CircularQueue(unsigned int capacity) {
	this->capacity_ = capacity;

	this->items_ = new QueueItem[sizeof(QueueItem) * this->capacity_];

	memset(this->items_, 0, (sizeof(QueueItem) * this->capacity_));


	this->head_ = 0;

	this->tail_ = 0;

	this->size_ = 0;
};


CircularQueue::~CircularQueue() {
	delete this->items_;

	this->items_ = nullptr;
};


bool CircularQueue::enqueue(QueueItem value) {
	if (this->size_ >= this->capacity_) {
		return false;
	};

	*(this->items_ + this->tail_) = value;

	this->tail_ = (this->tail_ + 1) % (this->capacity_);

	this->size_++;

	return true;
};


CircularQueue::QueueItem CircularQueue::dequeue() {
	if (this->size_ <= 0) {
		return this->EMPTY_QUEUE;
	};

	QueueItem qItem = *(this->items_ + this->head_);

	memset((this->items_ + this->head_), 0, sizeof(QueueItem));

	this->head_ = (this->head_ + 1) % (this->capacity_);


	this->size_--;


	return qItem;
};


CircularQueue::QueueItem CircularQueue::peek() const {
	if (this->size_ <= 0) {
		return this->EMPTY_QUEUE;
	};


	return *(this->items_ + this->head_);
};


bool CircularQueue::empty() const {
	if (this->size_ == 0) {
		return true;
	};


	return false;
};


bool CircularQueue::full() const {
	if (this->size_ == this->capacity_) {
		return true;
	};


	return false;
};


unsigned int CircularQueue::size() const {
	return this->size_;
};


void CircularQueue::print() const {
	std::cout << "Front of the Queue" << std::endl << std::endl;

	unsigned int iFront = this->head_;

	for (unsigned int i = 0; i < this->size_; i++) {
		std::cout << *(this->items_ + iFront) << std::endl;

		iFront = (iFront + 1) % this->capacity_;
	};


	std::cout << std::endl << "Back of the Queue" << std::endl << std::endl;
 };