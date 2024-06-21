#include <iostream>

#include "DoublyLinkedList.hpp"

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
	if ((this->size_ == 0) || (index >= this->size_)) {
		return nullptr;
	}

	Node* temp = this->head_;

	for (unsigned int i = 0; i < index; i++) {
		temp = temp->next;
	}

	return temp;
};


DoublyLinkedList::DoublyLinkedList() {
	this->head_ = nullptr;
	this->tail_ = nullptr;

	this->size_ = 0;
};


DoublyLinkedList::~DoublyLinkedList() {
	Node* current = this->head_;
	Node* nextNode = nullptr;

	for (unsigned int i = 0; i < (this->size_); i++) {
		nextNode = current->next;

		current->next = nullptr;
		current->prev = nullptr;

		delete current;
		current = nullptr;


		current = nextNode;
	};
};



unsigned int DoublyLinkedList::size() const {
	return this->size_;
};


unsigned int DoublyLinkedList::capacity() const {
	return this->CAPACITY;
};


bool DoublyLinkedList::empty() const {
	if (this->size_ == 0) {
		return true;
	}

	return false;
};


bool DoublyLinkedList::full() const {
	if (this->size_ == this->CAPACITY) {
		return true;
	}

	return false;
};


DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
	if (index >= this->size_) {
		return this->tail_->value;
	};

	Node* desiredNode = nullptr;

	if (((float)this->size_ / 2.0) < ((float)index)) {
		desiredNode = this->tail_;

		for (unsigned int i = 0; i < ((this->size_ - 1) - index); i++) {
			desiredNode = desiredNode->prev;
		};
	}

	else {
		desiredNode = this->head_;

		for (unsigned int i = 0; i < index; i++) {
			desiredNode = desiredNode->next;
		};
	};


	return desiredNode->value;
};


unsigned int DoublyLinkedList::search(DataType val) const {
	Node* temp = this->head_;

	for (unsigned int i = 0; temp != nullptr; i++) {
		if (temp->value == val) {
			return i;
		};

		temp = temp->next;
	};


	return this->size_;
};


void DoublyLinkedList::print() const {
	Node* temp = this->head_;

	for (unsigned int i = 0; i < (this->size_); i++) {
		std::cout << temp->value << std::endl;

		temp = temp->next;
	};
};



bool DoublyLinkedList::insert(DataType val, unsigned int index) {
	if (index > this->size_) {
		return false;
	}

	Node* newNode = new Node[sizeof(Node)];

	if (newNode == nullptr) {
		return false;
	};

	memset(newNode, 0, sizeof(Node));

	newNode->prev = nullptr;
	newNode->next = nullptr;
	newNode->value = val;


	Node* temp = nullptr;

	if (this->size_ == 0) {
		this->head_ = newNode;
		this->tail_ = newNode;
	}

	else if (this->size_ == index) {
		temp = this->tail_;

		temp->next = newNode;

		newNode->prev = temp;
		newNode->next = this->head_;

		this->head_->prev = newNode;

		this->tail_ = newNode;
	}

	else {
		if ((((float)this->size_) / 2.0) < index) {
			temp = this->tail_;

			for (unsigned int i = 0; i < ((this->size_ - 1) - index); i++) {
				temp = temp->prev;
			};
		}

		else {
			temp = this->head_;

			for (unsigned int i = 0; i < index; i++) {
				temp = temp->next;
			};

			if (index == 0) {
				this->head_ = newNode;
			};
		};

		newNode->prev = temp->prev;
		newNode->next = temp;

		temp->prev->next = newNode;
		temp->prev = newNode;
	};


	this->size_++;


	return true;
};


bool DoublyLinkedList::insert_front(DataType val) {
	Node* newNode = new Node[sizeof(Node)];

	if (newNode == nullptr) {
		return false;
	};

	memset(newNode, 0, sizeof(Node));

	newNode->prev = nullptr;
	newNode->next = nullptr;
	newNode->value = val;

	if (this->size_ == 0) {
		this->head_ = newNode;
		this->tail_ = newNode;
	}

	else {
		Node* head_temp = this->head_;

		newNode->prev = head_temp->prev;
		newNode->next = head_temp;

		head_temp->prev->next = newNode;
		head_temp->prev = newNode;

		this->head_ = newNode;
	};


	this->size_++;


	return true;
};


bool DoublyLinkedList::insert_back(DataType val) {
	Node* newNode = new Node[sizeof(Node)];

	if (newNode == nullptr) {
		return false;
	};

	memset(newNode, 0, sizeof(Node));

	newNode->prev = nullptr;
	newNode->next = nullptr;
	newNode->value = val;


	if (this->size_ == 0) {
		this->head_ = newNode;
		this->tail_ = newNode;
	}

	else {
		Node* temp_tail = this->tail_;

		newNode->prev = temp_tail;
		newNode->next = temp_tail->next;

		temp_tail->next->prev = newNode;
		temp_tail->next = newNode;

		this->tail_ = newNode;
	};


	this->size_++;


	return true;
};


bool DoublyLinkedList::remove(unsigned int index) {
	if ((this->size_ == 0) || (index >= this->size_)) {
		return false;
	};

	Node* temp = nullptr;

	if (this->size_ == 1) {
		temp = this->head_;

		this->head_ = nullptr;
		this->tail_ = nullptr;
	}

	else {
		if ((((float)this->size_) / 2.0) > index) {
			temp = this->tail_;

			for (unsigned int i = 0; i < ((this->size_ - 1) - index); i++) {
				temp = temp->prev;
			};

			if ((this->size_ - 1) == index) {
				this->tail_ = temp->prev;
			};
		}

		else {
			temp = this->head_;

			for (unsigned int i = 0; i < index; i++) {
				temp = temp->next;
			};

			if (index == 0) {
				this->head_ = temp->next;
			};
		}


		temp->prev->next = temp->next;

		temp->next->prev = temp->prev;
	};


	temp->prev = nullptr;
	temp->next = nullptr;

	delete temp;
	temp = nullptr;


	this->size_--;

	return true;
};


bool DoublyLinkedList::remove_front() {
	if (this->size_ == 0) {
		return false;
	};

	Node* temp = this->head_;

	temp->next->prev = temp->prev;

	temp->prev->next = temp->next;

	this->head_ = temp->next;


	temp->prev = nullptr;
	temp->next = nullptr;

	delete temp;
	temp = nullptr;


	this->size_--;

	return true;
};


bool DoublyLinkedList::remove_back() {
	if (this->size_ == 0) {
		return false;
	};

	Node* temp = this->tail_;

	temp->prev->next = temp->next;

	temp->next->prev = temp->prev;

	this->tail_ = temp->prev;


	temp->prev = nullptr;
	temp->next = nullptr;

	delete temp;
	temp = nullptr;

	this->size_--;

	return true;
};


bool DoublyLinkedList::replace(unsigned int index, DataType val) {
	if (this->size_ >= index) {
		return false;
	};

	Node* temp = nullptr;

	if ((((float)this->size_) / 2.0) < index) {
		temp = this->tail_;

		for (unsigned int i = 0; i < ((this->size_ - 1) - index); i++) {
			temp = temp->prev;
		};
	}

	else {
		temp = this->head_;

		for (unsigned int i = 0; i < index; i++) {
			temp = temp->next;
		};
	};


	temp->value = val;

	return true;
};