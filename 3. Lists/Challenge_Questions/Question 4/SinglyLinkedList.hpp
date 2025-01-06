struct Node {
	int data;
	Node* next;
};

class List {
	Node* head;		// Pointer to the Head of the List
	Node* tail;		// Pointer to the Tail of the List

	int size;

public:
	List();

	bool insert(int, int);

	bool insertFront(int);

	bool insertBack(int);

	bool removeByPosition(int);

	bool removeByValue(int);

	bool removeFront();

	bool removeBack();

	int select(int);

	bool replace(int, int);

	int listSize();

	void display();
};