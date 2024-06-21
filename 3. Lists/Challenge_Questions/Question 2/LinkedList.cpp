#include <iostream>

struct Node {
	Node* prev;
	char data;
	Node* next;
};


class list {
	Node* head;
	int size;
	Node* tail;

public:

	list() {
		head = nullptr;
		this->size = 0;
	}

	void insert(char letter, int index) {
		if (((this->head == nullptr) && (index != 0)) || (this->size < index)) {
			return;
		}

		Node* node = new Node[sizeof(Node)];

		node->prev = nullptr;
		node->data = letter;
		node->next = nullptr;


		Node* temp = head;

		for (int i = 0; (i < index) && (this->size > (i + 1)); i++) {
			temp = temp->next;
		}

		if (this->size == 0) {
			this->head = node;
			this->tail = node;

			node->next = node;
			node->prev = node;
		}

		else if (this->size == index) {
			node->next = temp->next;
			node->prev = temp;
			temp->next = node;

			this->tail = node;
		}

		else if (index == 0) {
			node->prev = temp->prev;
			node->next = temp;
			temp->prev = node;

			this->head = node;
		}

		else {
			node->prev = temp->prev;
			node->next = temp;

			temp->prev->next = node;
			temp->prev = node;
		}


		this->size++;
	}


	void insert_back(char letter) {
		Node* temp = this->tail;

		Node* node = new Node[sizeof(Node)];

		node->prev = nullptr;
		node->data = letter;
		node->next = nullptr;


		if (this->size == 0) {
			this->head = node;
			this->tail = node;

			node->next = node;
			node->prev = node;
		}

		else {
			node->prev = temp;
			node->next = temp->next;

			temp->next = node;

			this->tail = node;
		}


		this->size++;
	}


	void delete_front() {
		if (this->size == 0) {
			return;
		}

		Node* temp = this->head;

		this->head = temp->next;

		this->tail->next = this->head;

		this->head->prev = this->tail;


		temp->prev = nullptr;
		temp->next = nullptr;

		delete temp;
		temp = nullptr;


		this->size--;
	}


	void delete_back() {
		if (this->size == 0) {
			return;
		}

		else if (this->head == this->tail) {
			Node* temp = this->head;

			head->next = nullptr;
			head->prev = nullptr;

			delete this->head;
			this->head = nullptr;
			this->tail = nullptr;
		}

		else {
			Node* temp = this->tail;

			this->tail = temp->prev;

			this->tail->next = this->head;

			this->head->prev = this->tail;

			temp->prev = nullptr;
			temp->next = nullptr;

			delete temp;
			temp = nullptr;
		}


		this->size--;
	}


	void print() {
		Node* temp = this->head;

		for (int i = 0; i < this->size; i++) {
			std::cout << temp->data << std::endl;

			temp = temp->next;
		}
	}
};


int main(void) {
	list ll;

	ll.insert('a', 0);
	ll.insert('b', 1);
	ll.insert('c', 0);
	ll.insert_back('d');

	ll.delete_front();
	ll.delete_back();

	ll.insert('d', 1);

	ll.print();

	return 0;
}