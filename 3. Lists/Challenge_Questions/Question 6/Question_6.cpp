#include <iostream>

typedef char DataItem;

struct Node {
	DataItem data;
	Node* next;
};

class SinglyLinkedList {
	Node* head;

	unsigned int size;

public:
	SinglyLinkedList() {
		this->head = nullptr;
		this->size = 0;
	}

	void insertEnd(DataItem data) {
		Node* newNode = new Node[sizeof(Node)];

		memset(newNode, 0, sizeof(Node));

		newNode->data = data;
		newNode->next = nullptr;

		if (this->size == 0) {
			this->head = newNode;
		}

		else {
			Node* temp = this->head;

			for (int i = 0; i < (this->size - 1); i++) {
				temp = temp->next;
			}

			temp->next = newNode;
		}

		this->size++;
	};


	void insertNodeAtEnd(Node* node) {
		if (this->size == 0) {
			this->head = node;
		}

		else {
			Node* temp = this->head;

			for (int i = 0; i < (this->size - 1); i++) {
				temp = temp->next;
			};

			temp->next = node;
		};

		this->size++;
	};

	unsigned int getSize() {
		return this->size;
	}


	Node* getHead() {
		return this->head;
	}


	void print() {
		Node* temp = this->head;

		for (int i = 0; i < this->size; i++) {
			std::cout << temp->data << std::endl;

			temp = temp->next;
		};
	};
};


Node* firstCommonNode(SinglyLinkedList* sll1, SinglyLinkedList* sll2) {
	if ((sll1->getSize() == 0) || (sll2->getSize() == 0)) {
		return nullptr;
	};

	Node* temp_moreNodes = nullptr;
	Node* temp_lessNodes = nullptr;

	if (sll1->getSize() >= sll2->getSize()) {
		temp_moreNodes = sll1->getHead();

		temp_lessNodes = sll2->getHead();
	}

	else {
		temp_moreNodes = sll2->getHead();
		temp_lessNodes = sll1->getHead();
	};

	while (temp_moreNodes != nullptr) {
		Node* dummyLessNodes = temp_lessNodes;

		while (dummyLessNodes != nullptr) {
			if (temp_moreNodes == dummyLessNodes) {
				return temp_moreNodes;
			}

			dummyLessNodes = dummyLessNodes->next;
		}

		temp_moreNodes = temp_moreNodes->next;
	};

	return nullptr;
};


int main(void) {
	SinglyLinkedList sll1;
	SinglyLinkedList sll2;

	sll1.insertEnd('a');
	sll1.insertEnd('b');
	sll1.insertEnd('c');
	sll1.insertEnd('d');

	sll2.insertEnd('z');
	sll2.insertEnd('y');
	sll2.insertEnd('x');


	Node* node1 = new Node[sizeof(Node)];
	memset(node1, 0, sizeof(Node));

	Node* node2 = new Node[sizeof(Node)];
	memset(node2, 0, sizeof(Node));

	Node* node3 = new Node[sizeof(Node)];
	memset(node3, 0, sizeof(Node));


	node1->data = 's';
	node1->next = nullptr;

	node2->data = 't';
	node2->next = nullptr;

	node3->data = 'u';
	node3->next = nullptr;



	sll1.insertNodeAtEnd(node1);
	sll1.insertNodeAtEnd(node2);
	sll1.insertNodeAtEnd(node3);

	sll2.insertNodeAtEnd(node1);
	sll2.insertNodeAtEnd(node2);
	sll2.insertNodeAtEnd(node3);


	std::cout << "First Linked List" << std::endl;
	sll1.print();

	std::cout << std::endl << "Second Linked List" << std::endl;
	sll2.print();


	Node* commonNode = firstCommonNode(&sll1, &sll2);

	if (commonNode != nullptr) {
		std::cout << std::endl << "First Common Node Address: " << commonNode << std::endl;

		std::cout << "Common Node Data: " << commonNode->data << std::endl;
	}

	else {
		std::cout << std::endl << "No Common Node Found" << std::endl;
	};

	return 0;
};