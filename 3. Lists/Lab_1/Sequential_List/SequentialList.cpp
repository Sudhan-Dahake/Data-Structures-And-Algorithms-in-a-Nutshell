#include <iostream>
#include <memory>

#include "SequentialList.hpp"

SequentialList::SequentialList(unsigned int cap) {
	this->data_ = new DataType[cap * sizeof(DataType)];

	memset(this->data_, 0, (cap * sizeof(DataType)));

	this->capacity_ = cap;

	this->size_ = 0;
};

SequentialList::~SequentialList() {
	delete this->data_;

	this->data_ = nullptr;
};

unsigned int SequentialList::size() const {
	return this->size_;
};

unsigned int SequentialList::capacity() const {
	return this->capacity_;
};

bool SequentialList::empty() const {
	if (this->size_ == 0) {
		return true;
	}

	return false;
};

bool SequentialList::full() const {
	if (this->size_ == this->capacity_) {
		return true;
	}

	return false;
};

SequentialList::DataType SequentialList::select(unsigned int index) const {
	DataType* temp = this->data_;

	if (index < (this->size_ - 1)) {

		return *(temp + index);
	}

	return *(temp + (this->size_ - 1));
};

unsigned int SequentialList::search(DataType val) const {
	DataType* temp = this->data_;

	unsigned int index = 0;

	for (int i = 0; i < (this->size_ - 1); i++) {
		if ((*temp) == val) {
			return index;
		}

		temp++;
	}

	return this->size_;
};

void SequentialList::print() const {
	DataType* temp = this->data_;

	for (unsigned int i = 0; i < this->size_; i++) {
		std::cout << (*temp) << std::endl;

		temp++;
	}

	temp = nullptr;
};



bool SequentialList::insert(DataType val, unsigned int index) {
	if ((index > this->size_) || (this->size_ == this->capacity_)) {
		return false;
	};

	DataType* temp = this->data_ + this->size_;

	for (unsigned int i = 0; i <= (this->size_ - index); i++) {
		*temp = *(temp - 1);

		temp--;
	};

	*(temp + 1) = val;

	temp = nullptr;

	this->size_++;

	return true;
};


bool SequentialList::insert_front(DataType val) {
	if (this->size_ == this->capacity_) {
		return false;
	};

	DataType* temp = this->data_ + this->size_;

	while (temp != this->data_) {
		*temp = *(temp - 1);

		temp--;
	};

	*temp = val;

	temp = nullptr;

	this->size_++;

	return true;
};


bool SequentialList::insert_back(DataType val) {
	if (this->size_ == this->capacity_) {
		return false;
	};

	DataType* temp = this->data_ + this->size_;

	*temp = val;

	temp = nullptr;

	this->size_++;

	return true;
};


bool SequentialList::remove(unsigned int index) {
	if ((this->size_ == 0) || (this->size_ <= index)) {
		return false;
	};

	DataType* deleteNode = this->data_ + index;

	DataType* lastNode = this->data_ + (this->size_ - 1);

	while (deleteNode != lastNode) {
		*deleteNode = *(deleteNode + 1);

		deleteNode++;
	};

	memset(deleteNode, 0, sizeof(DataType));

	deleteNode = nullptr;

	this->size_--;

	return true;
};


bool SequentialList::remove_front() {
	if (this->size_ == 0) {
		return false;
	};

	DataType* temp = this->data_;

	for (int i = 0; i < (this->size_ - 1); i++) {
		*temp = *(temp + 1);

		temp++;
	};

	memset(temp, 0, sizeof(DataType));

	temp = nullptr;

	this->size_--;

	return true;
};


bool SequentialList::remove_back() {
	if (this->size_ == 0) {
		return false;
	};

	DataType* temp = this->data_ + (this->size_ - 1);

	memset(temp, 0, sizeof(DataType));

	temp = nullptr;

	this->size_--;

	return true;
};


bool SequentialList::replace(unsigned int index, DataType val) {
	if (this->size_ <= index) {
		return false;
	};

	DataType* temp = this->data_ + index;

	*temp = val;

	temp = nullptr;

	return true;
};


SequentialList::SequentialList(const SequentialList& rhs) {
	if (this->capacity_ == rhs.capacity_) {
		memset(this->data_, 0, (sizeof(DataType) * this->capacity_));
	}

	else {
		this->~SequentialList();

		this->data_ = new DataType[sizeof(DataType) * rhs.capacity_];

		memset(this->data_, 0, (sizeof(DataType) * rhs.capacity_));
	};

	memcpy(this->data_, rhs.data_, (sizeof(DataType) * rhs.size_));

	this->size_ = rhs.size_;
	this->capacity_ = rhs.capacity_;
};


SequentialList& SequentialList::operator=(const SequentialList& rhs) {
	if (this->capacity_ == rhs.capacity_) {
		memset(this->data_, 0, (sizeof(DataType) * this->capacity_));
	}

	else {
		this->~SequentialList();

		this->data_ = new DataType[sizeof(DataType) * rhs.capacity_];

		memset(this->data_, 0, (sizeof(DataType) * rhs.capacity_));
	};

	memcpy(this->data_, rhs.data_, (sizeof(DataType) * rhs.size_));

	this->size_ = rhs.size_;
	this->capacity_ = rhs.capacity_;

	return *this;
};