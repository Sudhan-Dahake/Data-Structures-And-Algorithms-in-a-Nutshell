#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

class DoublyLinkedList {
	// Befriend so tests have access to variables.
	friend class DoublyLinkedListTest;


public:
	// Can be seen outside as DoublyLinkedList::DataType
	typedef char DataType;

	// This type of list can basically grow as large as we want it to,
	// so we'll just pick an arbitrary large value as the capacity for
	// all lists of this type.
	static const unsigned int CAPACITY = 65536;


private:
	// The node structure used for the DoublyLinkedList.
	struct Node {
		DataType value;
		Node* next;
		Node* prev;
	};


public:
	// Private method to get the node at an index. This is optional, but you 
	// will probably find it useful.
	Node* getNode(unsigned int index) const;


public:
	// Constructor/destructor
	DoublyLinkedList();
	~DoublyLinkedList();


	// Accessor methods.
	unsigned int size() const;

	unsigned int capacity() const;

	bool empty() const;

	bool full() const;

	DataType select(unsigned int index) const;

	unsigned int search(DataType val) const;

	void print() const;


	// Mutator methods.
	bool insert(DataType val, unsigned int index);

	bool insert_front(DataType val);

	bool insert_back(DataType val);

	bool remove(unsigned int index);

	bool remove_front();

	bool remove_back();

	bool replace(unsigned int index, DataType val);


private:
	// Member Variables.
	Node* head_;

	Node* tail_;

	unsigned int size_;


private:
	// Make copy constructor and assignment operator private.

	DoublyLinkedList(const DoublyLinkedList& rhs) {}
	DoublyLinkedList& operator=(const DoublyLinkedList& rhs) {}
};

#endif		// DOUBLY_LINKED_LIST_HPP