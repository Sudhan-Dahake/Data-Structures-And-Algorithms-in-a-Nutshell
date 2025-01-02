struct Node {
	int key;
	int height;
	Node* left;
	Node* right;
};


class AVL {
	Node* root;

public:
	AVL();

	~AVL();

	bool insert(Node**);

	Node* deleteNode(Node* temp = nullptr, int key = 0);

	Node* search(int);

	Node* findMin(Node** node = nullptr);

	Node* findMax(Node** node = nullptr);

	void printTree();

private:
	void deleteWholeTree(Node**);

	int returnHeightOfNode(Node**);

	int balanceFactor(Node**);

	bool updateHeight(Node**);

	bool updateHeightAlongPath(int, Node**);

	Node* rightRotate(Node**);

	Node* leftRotate(Node**);

	Node* leftRightRotate(Node**);

	Node* rightLeftRotate(Node**);

	Node* RecursiveInsertionAndBalancing(Node*, Node*);

	void printTreeByLevel(Node**);

	int getMaxDepth(Node**);
};