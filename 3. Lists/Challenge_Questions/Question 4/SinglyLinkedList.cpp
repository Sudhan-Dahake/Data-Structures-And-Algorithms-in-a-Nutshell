#include "SinglyLinkedList.hpp"
#include <iostream>
#include <memory>
#include <cstring>

List::List() {
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
};

bool List::insert(int position, int value) {
	if (position > this->size) {
		return false;
	};

	if ((position == this->size) && (this->size > 0)) {
		return this->insertBack(value);
	};

	if ((this->size == 0) || (position == 0)) {
		return this->insertFront(value);
	};

	Node* newNode = new Node[sizeof(Node)];

	memset(newNode, 0, sizeof(Node));

	newNode->data = value;
	newNode->next = nullptr;


	Node* temp = this->head;

	for (int i = 0; i < (position - 1); i++) {
		temp = temp->next;
	};

	newNode->next = temp->next;

	temp->next = newNode;

	this->size += 1;

	return true;
};


bool List::insertFront(int value) {
	Node* newNode = new Node[sizeof(Node)];

	memset(newNode, 0, sizeof(Node));

	newNode->data = value;
	newNode->next = nullptr;

	if (this->size == 0) {
		this->head = newNode;

		this->tail = this->head;
	}

	else {
		newNode->next = this->head;

		this->head = newNode;
	};

	this->size += 1;

	return true;
};


bool List::insertBack(int value) {
	Node* newNode = new Node[sizeof(Node)];

	memset(newNode, 0, sizeof(Node));

	newNode->data = value;
	newNode->next = nullptr;

	if (this->size == 0) {
		this->tail = newNode;

		this->head = this->tail;
	}

	else {
		this->tail->next = newNode;

		this->tail = newNode;
	};

	this->size += 1;

	return true;
};


bool List::removeFront() {
	if (this->size == 0) {
		return false;
	};

	if (this->size == 1) {
		delete(this->head);

		this->head = nullptr;
		this->tail = nullptr;

		this->size -= 1;

		return true;
	};

	Node* temp = this->head;

	this->head = temp->next;

	delete(temp);

	temp = nullptr;

	this->size -= 1;

	return true;
};


bool List::removeBack() {
	if (this->size == 0) {
		return false;
	};

	if (this->size == 1) {
		delete(this->tail);

		this->tail = nullptr;
		this->head = nullptr;

		this->size -= 1;

		return true;
	};

	Node* temp = this->tail;

	this->tail = this->head;

	for (int i = 0; i < (this->size - 2); i++) {
		this->tail = this->tail->next;
	};

	this->tail->next = nullptr;

	delete(temp);

	temp = nullptr;

	this->size -= 1;

	return true;
};


bool List::removeByValue(int value) {
	if (this->size <= 0) {
		return false;
	};

	if (this->size == 1) {
		if (this->head->data == value) {
			delete(this->head);

			this->head = nullptr;
			this->tail = nullptr;

			this->size -= 1;

			return true;
		};

		return false;
	};

	Node* temp = this->head;

	while ((temp->next != nullptr) && (temp->next->data != value)) {
		temp = temp->next;
	};

	if (temp->next == nullptr) {
		return false;
	};

	Node* nodeToBeDeleted = temp->next;

	temp->next = nodeToBeDeleted->next;

	nodeToBeDeleted->next = nullptr;

	delete(nodeToBeDeleted);

	nodeToBeDeleted = nullptr;

	this->size -= 1;

	return true;
};


bool List::removeByPosition(int position) {
	if (position >= this->size) {
		return false;
	};

	if (position == 0) {
		return this->removeFront();
	};

	if (position == (this->size - 1)) {
		return this->removeBack();
	};


	Node* temp = this->head;

	Node* ptrToDeleteNode = nullptr;

	for (int i = 0; i < (position - 1); i++) {
		temp = temp->next;
	};

	ptrToDeleteNode = temp->next;

	temp->next = ptrToDeleteNode->next;

	ptrToDeleteNode->next = nullptr;

	delete(ptrToDeleteNode);

	ptrToDeleteNode = nullptr;
	temp = nullptr;

	this->size -= 1;

	return true;
};


int List::select(int position) {
	if (position >= this->size) {
		return -1;
	};

	if (position == (this->size - 1)) {
		return this->tail->data;
	};

	Node* temp = this->head;

	for (int i = 0; i < position; i++) {
		temp = temp->next;
	};

	return temp->data;
};


bool List::replace(int position, int value) {
	if (position >= this->size) {
		return false;
	};

	if (position == (this->size - 1)) {
		this->tail->data = value;

		return true;
	};

	Node* temp = this->head;

	for (int i = 0; i < position; i++) {
		temp = temp->next;
	};

	temp->data = value;

	return true;
};


int List::listSize() {
	return this->size;
};


void List::display() {
	if (this->size == 0) {
		std::cout << "Empty List" << std::endl;

		return;
	};

	Node* temp = this->head;

	std::cout << temp->data << " ";

	for (int i = 0; i < (this->size - 1); i++) {
		temp = temp->next;

		std::cout << temp->data << " ";
	};

	std::cout << std::endl;
};