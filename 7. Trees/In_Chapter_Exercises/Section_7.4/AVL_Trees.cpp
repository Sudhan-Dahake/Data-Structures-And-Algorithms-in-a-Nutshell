#include <iostream>
#include <cmath>
#include "AVL_Trees.hpp"

AVL::AVL() {
	this->root = nullptr;
};

AVL::~AVL() {
	this->deleteWholeTree(&this->root);
};

void AVL::deleteWholeTree(Node** ptrToRoot) {
	if (*ptrToRoot == nullptr) {
		return;
	};

	deleteWholeTree(&((*ptrToRoot)->left));

	deleteWholeTree(&((*ptrToRoot)->right));

	(*ptrToRoot)->left = nullptr;
	(*ptrToRoot)->right = nullptr;

	delete(*ptrToRoot);

	*ptrToRoot = nullptr;
};

int AVL::returnHeightOfNode(Node** ptrToNode) {
	if (*ptrToNode == nullptr) {
		return -1;
	}

	return (*ptrToNode)->height;
};

bool AVL::updateHeightAlongPath(int key, Node** temp) {
	if (*temp == nullptr) {
		return false;
	};

	if (key < (*temp)->key) {
		this->updateHeightAlongPath(key, &((*temp)->left));
	}

	else if (key > (*temp)->key) {
		this->updateHeightAlongPath(key, &((*temp)->right));
	};



	if ((*temp)->left == nullptr) {
		(*temp)->height = 1 + std::max(0, (*temp)->right->height);
	}

	else if ((*temp)->right == nullptr) {
		(*temp)->height = 1 + std::max((*temp)->left->height, 0);
	}

	else {
		(*temp)->height = 1 + std::max((*temp)->left->height, (*temp)->right->height);
	};

	return true;
};

int AVL::balanceFactor(Node** ptrToNode) {
	int leftHeight = (*ptrToNode && (*ptrToNode)->left) ? (*ptrToNode)->left->height : 0;
	int rightHeight = (*ptrToNode && (**ptrToNode).right) ? (**ptrToNode).right->height : 0;

	return leftHeight - rightHeight;
};


Node* AVL::rightRotate(Node** currentHead) {
	if ((currentHead == nullptr) || ((*currentHead) == nullptr) || ((*currentHead)->left == nullptr)) {
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

Node* AVL::leftRotate(Node** currentHead) {
	if ((currentHead == nullptr) || (*currentHead == nullptr) || ((*currentHead)->right == nullptr)) {
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

Node* AVL::leftRightRotate(Node** currentHead) {
	if ((currentHead == nullptr) || (*currentHead == nullptr)) {
		return nullptr;
	};

	// Performing Left Rotation on Node's Left Child.
	(*currentHead)->left = this->leftRotate(&((*currentHead)->left));

	// Performing Right Rotation on currentHead.
	return this->rightRotate(currentHead);

};

Node* AVL::rightLeftRotate(Node** currentHead) {
	if ((currentHead == nullptr) || (*currentHead == nullptr)) {
		return nullptr;
	};

	// Performing Right Rotation on Node's Right Child.
	(*currentHead)->right = this->rightRotate(&((*currentHead)->right));

	// Performing Left Rotation on currentHead.
	return this->leftRotate(currentHead);
};