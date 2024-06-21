#include <iostream>

typedef int DataItem;

struct Node {
	DataItem data;
	Node* next;
};


// Functions Prototypes
Node* ListSearch(DataItem value, Node* head);
void InsertNewLast(DataItem value, Node** L);
void DeleteLastNode(Node** L);
void PrintList(Node* head);




// This function searches for a node in the list whose data field
// equals to value. It returns a pointer to sucn node if it finds it.
// Otherwise, it returns nullptr.

Node* ListSearch(DataItem value, Node* head) {
	Node** temp = &head;

	while ((*temp) != nullptr) {
		if ((*temp)->data == value) {
			return *temp;
		}

		(*temp) = (*temp)->next;
	}

	return nullptr;
}



// This function inserts a new node with data field set to
// value at the end of the list. L points to the pointer of the first
// node, or nullptr if the list is empty.

void InsertNewLast(DataItem value, Node** L) {
	Node* newNode = new Node();

	newNode->data = value;
	newNode->next = nullptr;

	if (*L == nullptr) {
		*L = newNode;
	}

	else {
		Node* temp = *L;

		while (temp->next != nullptr) {
			temp = temp->next;
		}

		temp->next = newNode;
	}
}



// This function deletes a node from the back end (tail) of the list.
// L points to the pointer of the first node, or NULL if the list is empty.

void DeleteLastNode(Node** L) {
	if ((L == nullptr) || ((*L) == nullptr)) {
		return;
	}

	if (((*L) != nullptr) && ((*L)->next) != nullptr) {
		Node* temp = *L;

		while (temp->next->next != nullptr) {
			temp = temp->next;
		}

		delete temp->next;

		temp->next = nullptr;
	}

	else if ((*L) != nullptr) {
		delete (*L);

		*L = nullptr;
	}
}



// This function displays the current elements of the list.

void PrintList(Node* head) {
	Node* temp = head;

	if (temp == nullptr) {
		return;
	}

	else {
		while (temp != nullptr) {
			std::cout << "Node's Value: " << temp->data << std::endl;

			temp = temp->next;
		}
	}
}



int main(void) {
	Node* head;		// Declare list header as a pointer to Node

	Node* nodePtr;		// used as return value for ListSearch

	DataItem searchValue;

	head = nullptr;		// set list to empty



	// Some examples of function calls:
	// Printing and Inserting...

	PrintList(head);
	InsertNewLast(10, &head);

	PrintList(head);
	InsertNewLast(20, &head);

	PrintList(head);
	InsertNewLast(30, &head);

	PrintList(head);
	InsertNewLast(40, &head);

	PrintList(head);
	InsertNewLast(50, &head);

	PrintList(head);



	// Searching...
	searchValue = 20;

	nodePtr = ListSearch(searchValue, head);

	if (nodePtr != nullptr) {
		std::cout << "Search value " << searchValue << " was FOUND" << std::endl;
	}

	else {
		std::cout << "Search value " << searchValue << " was NOT FOUND" << std::endl;
	}



	searchValue = 5;

	nodePtr = ListSearch(searchValue, head);

	if (nodePtr != nullptr) {
		std::cout << "Search value " << searchValue << " was FOUND\n";
	}

	else {
		std::cout << "Search value " << searchValue << " was NOT FOUND\n";
	}



	searchValue = 40;

	nodePtr = ListSearch(searchValue, head);

	if (nodePtr != nullptr) {
		std::cout << "Search value " << searchValue << " was FOUND\n";
	}

	else {
		std::cout << "Search value " << searchValue << " was NOT FOUND\n";
	}



	// Deleting and Printing...

	DeleteLastNode(&head);
	PrintList(head);

	DeleteLastNode(&head);
	PrintList(head);

	DeleteLastNode(&head);
	PrintList(head);

	DeleteLastNode(&head);
	PrintList(head);

	DeleteLastNode(&head);
	PrintList(head);



	system("pause");

	return 0;
}

