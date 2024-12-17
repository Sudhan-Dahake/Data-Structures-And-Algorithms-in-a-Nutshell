#include <iostream>
#include "Binary_Search_Tree.hpp"
#include <iomanip>
#include <queue>
#include <cmath>

BST::BST() {
	this->root = nullptr;
};

BST::~BST() {
	this->deleteWholeTree(&(this->root));
};

void BST::deleteWholeTree(Node** node) {
	if ((*node) == nullptr) {
		return;
	};

	deleteWholeTree(&((*node)->leftChild));
	deleteWholeTree(&((*node)->rightChild));

	(*node)->leftChild = nullptr;
	(*node)->rightChild = nullptr;

	delete(*node);

	*node = nullptr;
};

Node* BST::search(int key) {
	Node* temp = this->root;

	if (temp == nullptr) {
		return temp;
	};

	while (temp->key != key) {
		if ((temp->leftChild != nullptr) && (temp->key > key)) {
			temp = temp->leftChild;
		}

		else if ((temp->rightChild != nullptr) && (temp->key < key)) {
			temp = temp->rightChild;
		}

		else {
			return nullptr;
		};
	};

	return temp;
};

Node* BST::findMax() {
	Node* temp = this->root;

	if (temp == nullptr) {
		return temp;
	};

	while (temp->rightChild != nullptr) {
		temp = temp->rightChild;
	};

	return temp;
};

Node* BST::findMin() {
	Node* temp = this->root;

	if (temp == nullptr) {
		return temp;
	};

	while (temp->leftChild != nullptr) {
		temp = temp->leftChild;
	};

	return temp;
};

bool BST::insert(Node** ptrToNewNode) {
	if (this->root == nullptr) {
		this->root = *ptrToNewNode;

		this->root->leftChild = nullptr;
		this->root->rightChild = nullptr;

		this->root->occurrence = 1;

		return true;
	};

	Node* temp = this->root;

	while (temp->key != (*ptrToNewNode)->key) {

		if (temp->key > (*ptrToNewNode)->key) {
			if (temp->leftChild != nullptr) {
				temp = temp->leftChild;
			}

			else {
				temp->leftChild = *ptrToNewNode;
				temp->leftChild->leftChild = nullptr;
				temp->leftChild->rightChild = nullptr;
				temp->leftChild->occurrence = 1;

				temp = temp->leftChild;

				return true;
			};
		}

		else if (temp->key < (*ptrToNewNode)->key) {
			if (temp->rightChild != nullptr) {
				temp = temp->rightChild;
			}

			else {
				temp->rightChild = *ptrToNewNode;
				temp->rightChild->leftChild = nullptr;
				temp->rightChild->rightChild = nullptr;
				temp->rightChild->occurrence = 1;

				temp = temp->rightChild;

				return true;
			};
		};
	};


	temp->occurrence++;

	return true;
};

bool BST::deleteNode(Node** node) {
	Node* temp = this->root;
	Node* parentTemp = this->root;

	if (temp == nullptr) {
		return false;
	};

	while (temp->key != (*node)->key) {
		if (temp->key > (**node).key) {
			if (temp->leftChild != nullptr) {
				parentTemp = temp;

				temp = temp->leftChild;
			}

			else {
				return false;
			}
		}

		else if (temp->key < (*node)->key) {
			if (temp->rightChild != nullptr) {
				parentTemp = temp;

				temp = temp->rightChild;
			}

			else {
				return false;
			}
		};
	};


	if (temp->occurrence > 1) {
		temp->occurrence--;
	}

	else {
		Node* replacement = temp->rightChild;
		Node* replacementParent = temp;

		if (replacement != nullptr) {
			while (replacement->leftChild != nullptr) {
				replacementParent = replacement;

				replacement = replacement->leftChild;
			};

			replacement->leftChild = temp->leftChild;

			if (replacement != temp->rightChild) {
				replacement->rightChild = temp->rightChild;
			}

			replacementParent->leftChild = nullptr;

			if (parentTemp->leftChild == temp) {
				parentTemp->leftChild = replacement;
			}

			else if (parentTemp->rightChild == temp) {
				parentTemp->rightChild = replacement;
			}

			if (temp == this->root) {
				this->root = replacement;
			};
		}

		else {
			if (parentTemp->leftChild == temp) {
				parentTemp->leftChild = temp->leftChild;
			}

			else if (parentTemp->rightChild == temp) {
				parentTemp->rightChild = temp->leftChild;
			};
		};


		temp->leftChild = nullptr;
		temp->rightChild = nullptr;

		delete(temp);
	};

	return true;
};

void BST::printTree() {
	this->printTreeByLevel(&(this->root));
};


void BST::printTreeByLevel(Node** node) {
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
				std::cout << current->key << "(" << current->occurrence << ")";
				q.push(current->leftChild);
				q.push(current->rightChild);
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


int BST::getMaxDepth(Node** triplePtrToNode) {
	if ((*triplePtrToNode) == nullptr) return 0;

	return 1 + std::max(getMaxDepth(&((*triplePtrToNode)->leftChild)), getMaxDepth(&((*triplePtrToNode)->rightChild)));
}