#include <iostream>
#include <cmath>
#include <iomanip>
#include <queue>
#include "AVL_Trees.hpp"

AVL::AVL()
{
	this->root = nullptr;
};

AVL::~AVL()
{
	this->deleteWholeTree(&this->root);
};

void AVL::deleteWholeTree(Node** ptrToRoot)
{
	if (*ptrToRoot == nullptr)
	{
		return;
	};

	deleteWholeTree(&((*ptrToRoot)->left));

	deleteWholeTree(&((*ptrToRoot)->right));

	(*ptrToRoot)->left = nullptr;
	(*ptrToRoot)->right = nullptr;

	delete (*ptrToRoot);

	*ptrToRoot = nullptr;
};

int AVL::returnHeightOfNode(Node** ptrToNode)
{
	if (*ptrToNode == nullptr)
	{
		return -1;
	}

	return (*ptrToNode)->height;
};

bool AVL::updateHeight(Node** temp)
{
	if ((*temp) == nullptr)
	{
		return false;
	};

	if (((*temp)->left == nullptr) && ((*temp)->right == nullptr))
	{
		(*temp)->height = 0;
	}

	else if ((*temp)->left == nullptr)
	{
		(*temp)->height = 1 + std::max(0, (*temp)->right->height);
	}

	else if ((*temp)->right == nullptr) {
		(*temp)->height = 1 + std::max((*temp)->left->height, 0);
	}

	else {
		(*temp)->height = 1 + std::max((*temp)->left->height, (*temp)->right->height);
	}

	return true;
};

bool AVL::updateHeightAlongPath(int key, Node** temp)
{
	if (*temp == nullptr)
	{
		return false;
	};

	if (key < (*temp)->key)
	{
		this->updateHeightAlongPath(key, &((*temp)->left));
	}

	else if (key > (*temp)->key)
	{
		this->updateHeightAlongPath(key, &((*temp)->right));
	};

	if ((*temp)->left == nullptr)
	{
		(*temp)->height = 1 + std::max(0, (*temp)->right->height);
	}

	else if ((*temp)->right == nullptr)
	{
		(*temp)->height = 1 + std::max((*temp)->left->height, 0);
	}

	else
	{
		(*temp)->height = 1 + std::max((*temp)->left->height, (*temp)->right->height);
	};

	return true;
};

int AVL::balanceFactor(Node** ptrToNode)
{
	int leftHeight = (*ptrToNode && (*ptrToNode)->left) ? (1 + (*ptrToNode)->left->height) : 0;
	int rightHeight = (*ptrToNode && (**ptrToNode).right) ? (1 + (**ptrToNode).right->height) : 0;

	return leftHeight - rightHeight;
};

Node* AVL::rightRotate(Node** currentHead)
{
	if ((currentHead == nullptr) || ((*currentHead) == nullptr) || ((*currentHead)->left == nullptr))
	{
		return nullptr;
	};

	// Performing Right Rotation.
	Node* newHead = (*currentHead)->left;

	(*currentHead)->left = newHead->right;

	newHead->right = (*currentHead);

	// updating the heights.
	(**currentHead).height = (((*currentHead)->left == nullptr) && ((*currentHead)->right == nullptr)) ? 0 : (1 + std::max(((*currentHead)->left ? (*currentHead)->left->height : 0), ((*currentHead)->right ? (*currentHead)->right->height : 0)));

	newHead->height = ((newHead->left == nullptr) && (newHead->right == nullptr)) ? 0 : (1 + std::max((newHead->left ? newHead->left->height : 0), (newHead->right ? newHead->right->height : 0)));

	return newHead;
};

Node* AVL::leftRotate(Node** currentHead)
{
	if ((currentHead == nullptr) || (*currentHead == nullptr) || ((*currentHead)->right == nullptr))
	{
		return nullptr;
	};

	// Performing Left Rotation.
	Node* newHead = (*currentHead)->right;

	(*currentHead)->right = newHead->left;

	newHead->left = (*currentHead);

	// updating the heights.
	(**currentHead).height = (((*currentHead)->left == nullptr) && ((*currentHead)->right == nullptr)) ? 0 : (1 + std::max(((*currentHead)->left ? (*currentHead)->left->height : 0), ((*currentHead)->right ? (*currentHead)->right->height : 0)));

	newHead->height = ((newHead->left == nullptr) && (newHead->right == nullptr)) ? 0 : (1 + std::max((newHead->left ? newHead->left->height : 0), (newHead->right ? newHead->right->height : 0)));

	return newHead;
};

Node* AVL::leftRightRotate(Node** currentHead)
{
	if ((currentHead == nullptr) || (*currentHead == nullptr))
	{
		return nullptr;
	};

	// Performing Left Rotation on Node's Left Child.
	(*currentHead)->left = this->leftRotate(&((*currentHead)->left));

	// Performing Right Rotation on currentHead.
	return this->rightRotate(currentHead);
};

Node* AVL::rightLeftRotate(Node** currentHead)
{
	if ((currentHead == nullptr) || (*currentHead == nullptr))
	{
		return nullptr;
	};

	// Performing Right Rotation on Node's Right Child.
	(*currentHead)->right = this->rightRotate(&((*currentHead)->right));

	// Performing Left Rotation on currentHead.
	return this->leftRotate(currentHead);
};

Node* AVL::search(int key)
{
	if (this->root == nullptr)
	{
		return nullptr;
	};

	Node* temp = this->root;

	while ((temp != nullptr) && (temp->key != key))
	{
		if (key > temp->key)
		{
			temp = temp->right;
		}

		else
		{
			temp = temp->left;
		};
	};

	return temp;
};

bool AVL::insert(Node** ptrToNode)
{
	if ((ptrToNode != nullptr) && ((*ptrToNode) != nullptr)) {
		(*ptrToNode)->height = 0;
		(*ptrToNode)->left = nullptr;
		(*ptrToNode)->right = nullptr;
	}

	else {
		return false;
	}

	if (this->root == nullptr)
	{
		this->root = *ptrToNode;

		return true;
	};


	Node* result = this->RecursiveInsertionAndBalancing(this->root, *ptrToNode);

	this->root = result;

	return (result != nullptr);
};

Node* AVL::RecursiveInsertionAndBalancing(Node* temp, Node* nodeToInsert)
{
	if (temp == nullptr)
	{
		return nodeToInsert;
	};

	if (nodeToInsert->key > temp->key)
	{
		temp->right = RecursiveInsertionAndBalancing(temp->right, nodeToInsert);
	}

	else if (nodeToInsert->key < temp->key)
	{
		temp->left = RecursiveInsertionAndBalancing(temp->left, nodeToInsert);
	}

	else
	{ // This block will be triggered when the key in nodeToInsert is already present in the AVL Tree.
		// Duplicates are not allowed in AVL Trees.
		return nodeToInsert;
	};

	this->updateHeight(&temp);

	int balance = this->balanceFactor(&temp);


	if ((balance > 1) && ((*nodeToInsert).key < temp->left->key)) {
		return this->rightRotate(&temp);
	}

	else if ((balance < -1) && ((*nodeToInsert).key > temp->right->key)) {
		return this->leftRotate(&temp);
	}

	else if ((balance > 1) && ((*nodeToInsert).key > temp->left->key)) {
		return this->leftRightRotate(&temp);
	}

	else if ((balance < -1) && ((*nodeToInsert).key < temp->right->key)) {
		return this->rightLeftRotate(&temp);
	}

	else {
		return temp;
	};
};


Node* AVL::findMin(Node** node) {
	if (node == nullptr) {
		node = &(this->root);
	};

	if ((*node)->left == nullptr) {
		return *node;
	};

	return this->findMin(&((*node)->left));
};

Node* AVL::findMax(Node** node) {
	if (node == nullptr) {
		node = &(this->root);
	};

	if ((*node)->right == nullptr) {
		return *node;
	};

	return this->findMax(&((*node)->right));
};


Node* AVL::deleteNode(Node* temp, int key) {
	if (temp == nullptr) {
		temp = this->root;
	};

	if (key == 0) {
		return nullptr;
	};

	if (key < temp->key) {
		temp->left = this->deleteNode(temp->left, key);
	}

	else if (key > temp->key) {
		temp->right = this->deleteNode(temp->right, key);
	}

	else {
		if ((temp->left == nullptr) && (temp->right == nullptr)) {
			delete temp;

			return nullptr;
		};


		if (temp->left == nullptr) {
			Node* temp2 = temp->right;

			delete temp;
			temp = nullptr;

			return temp2;
		}

		else if (temp->right == nullptr) {
			Node* temp2 = temp->left;

			delete temp;
			temp = nullptr;

			return temp2;
		};


		Node* temp2 = findMin(&(temp->right));

		temp->key = temp2->key;

		temp->right = this->deleteNode(temp->right, temp2->key);
	};


	this->updateHeight(&temp);

	int balance = this->balanceFactor(&temp);

	if ((balance > 1) && (this->balanceFactor(&(temp->left)) >= 0)) {
		return this->rightRotate(&temp);
	}

	else if ((balance < -1) && (this->balanceFactor(&(temp->right)) <= 0)) {
		return this->leftRotate(&temp);
	}

	else if ((balance > 1) && (this->balanceFactor(&(temp->left)) < 0)) {
		return this->leftRightRotate(&temp);
	}

	else if ((balance < -1) && (this->balanceFactor(&(temp->right)) > 0)) {
		return this->rightLeftRotate(&temp);
	}

	else {
		return temp;
	};
};


void AVL::printTree() {
	this->printTreeByLevel(&(this->root));
};


void AVL::printTreeByLevel(Node** node) {
	if (*node == nullptr) {
		return; // Tree is empty
	};

	std::queue<Node*> q; // Queue for BFS
	q.push(*node);
	int depth = 0; // Track depth for spacing

	int maxDepth = getMaxDepth(node); // Get the tree depth for proper spacing
	int totalWidth = pow(2, maxDepth + 1); // Total width for alignment

	while (!q.empty()) {
		int levelSize = q.size(); // Number of nodes at the current level
		int spaceBetween = totalWidth / (levelSize + 1); // Dynamic spacing

		std::cout << std::setw(spaceBetween / 2) << ""; // Leading space before first node

		for (int i = 0; i < levelSize; ++i) {
			Node* current = q.front();
			q.pop();

			// Print the current node
			if (current) {
				std::cout << current->key << "(" << current->height << ")";
				q.push(current->left);
				q.push(current->right);
			}
			else {
				std::cout << " ";
				q.push(nullptr);
				q.push(nullptr);
			};

			std::cout << std::setw(spaceBetween) << ""; // Space between nodes
		};

		std::cout << std::endl;

		depth++;

		if (depth >= maxDepth) break; // Stop when max depth is reached
	};
};


int AVL::getMaxDepth(Node** triplePtrToNode) {
	if ((*triplePtrToNode) == nullptr) return 0;

	return 1 + std::max(getMaxDepth(&((*triplePtrToNode)->left)), getMaxDepth(&((*triplePtrToNode)->right)));
};