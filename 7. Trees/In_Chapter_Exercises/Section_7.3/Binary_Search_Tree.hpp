struct Node {
	int key;
	int occurrence;
	Node* leftChild;
	Node* rightChild;
};

class BST {
	Node* root;

public:
	BST();

	~BST();

	Node* search(int);

	Node* findMin();

	Node* findMax();

	bool insert(Node**);

	bool deleteNode(Node**);

	void printTree();

private:
	void deleteWholeTree(Node**);

	void printTreeByLevel(Node**);

	int getMaxDepth(Node**);
};