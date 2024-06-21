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
		head = nullptr;

		this->size = 0;
	}

	void InsertBack(DataItem data) {
		Node* newNode = new Node[sizeof(Node)];

		memset(newNode, 0, sizeof(Node));


		newNode->data = data;
		newNode->next = nullptr;

		if (this->size == 0) {
			this->head = newNode;
		}

		else {
			Node* temp = head;

			for (int i = 0; i < (this->size - 1); i++) {
				temp = temp->next;
			}

			temp->next = newNode;
		}

		this->size++;
	};


	void DeleteNode(Node* node) {
		Node* prev = nullptr;

		while (node->next != nullptr) {
			node->data = node->next->data;

			prev = node;

			node = node->next;
		}

		if (prev != nullptr) {
			prev->next = nullptr;
		}

		delete node;
		node = nullptr;

		this->size--;
	};

	Node* GiveAddressOfNodeToDelete() {
		return this->head->next;
	}


	void Print() {
		Node* temp = this->head;

		for (int i = 0; i < this->size; i++) {
			std::cout << temp->data << std::endl;

			temp = temp->next;
		}
	};
};


int main(void) {
	SinglyLinkedList sll;

	sll.InsertBack('b');
	sll.InsertBack('c');
	sll.InsertBack('a');

	sll.Print();

	sll.DeleteNode(sll.GiveAddressOfNodeToDelete());

	std::cout << "After Deleting the Node containing Data as 'c'" << std::endl;

	sll.Print();

	return 0;
};