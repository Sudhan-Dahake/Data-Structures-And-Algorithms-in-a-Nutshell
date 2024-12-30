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

	bool deleteNode(Node**);

	Node* search(int);

private:
	void deleteWholeTree(Node**);

	int returnHeightOfNode(Node**);

	int balanceFactor(Node**);

	bool updateHeightAlongPath(int, Node**);

	Node* rightRotate(Node**);

	Node* leftRotate(Node**);

	Node* leftRightRotate(Node**);

	Node* rightLeftRotate(Node**);
};