#include "Queue.hpp"

#include <iostream>
#include <memory>

CircularQueue::CircularQueue(int capacity) {
	this->head = new QueueItem[sizeof(QueueItem) * capacity];

	memset(this->head, 0, (sizeof(QueueItem) * capacity));

	this->capacity = capacity;
	this->size = 0;

	this->iFront = this->head;
	this->iRear = this->head;

	this->iFrontIndex = 0;
	this->iRearIndex = 0;
};


CircularQueue::CircularQueue(QueueItem* circularQueue, int capacity) {
	this->capacity = capacity;
	this->size = 0;

	this->head = circularQueue;

	this->iFront = this->head;
	this->iRear = this->head;

	this->iFrontIndex = 0;
	this->iRearIndex = 0;
};


CircularQueue::~CircularQueue() {
	this->iFront = nullptr;

	this->iRear = nullptr;

	delete this->head;

	this->head = nullptr;
};


bool CircularQueue::Enqueue(QueueItem item) {
	if (this->size >= this->capacity) {
		return false;
	};

	*(this->iRear) = item;

	this->iRearIndex = (this->iRearIndex + 1) % this->capacity;

	this->iRear = this->head + this->iRearIndex;

	this->size++;


	return true;
};


QueueItem CircularQueue::Dequeue() {
	if (this->size <= 0) {
		return -1;
	};

	QueueItem item = *(this->iFront);

	this->iFrontIndex = (this->iFrontIndex + 1) % this->capacity;

	this->iFront = this->head + this->iFrontIndex;

	this->size--;


	return item;
};


QueueItem CircularQueue::peek() {
	if (this->size <= 0) {
		return -1;
	};

	return *(this->iFront);
};


void CircularQueue::print() {
	QueueItem* temp = this->iFront;

	int temp_iFrontIndex = this->iFrontIndex;

	for (unsigned int i = 0; i < this->size; i++) {
		std::cout << *(temp) << std::endl;

		temp_iFrontIndex = (temp_iFrontIndex + 1) % this->capacity;

		temp = this->head + temp_iFrontIndex;
	};
};