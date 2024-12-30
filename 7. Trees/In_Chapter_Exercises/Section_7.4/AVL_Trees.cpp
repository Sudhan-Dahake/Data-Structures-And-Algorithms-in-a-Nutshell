#include <iostream>
#include <cmath>
#include "AVL_Trees.hpp"

AVL::AVL() {
	this->root = nullptr;
};

AVL::~AVL() {
	this->deleteWholeTree(&this->root)
};

void AVL::deleteWholeTree(Node** ptrToRoot) {
	if (*ptrToRoot == nullptr) {
		return;
	};

	deleteWholeTree((*ptrToRoot)->left);

	deleteWholeTree((*ptrToRoot)->right);

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
		(*temp)->height = 1 + max(0, (*temp)->right->height);
	}

	else if ((*temp)->right == nullptr) {
		(*temp)->height = 1 + max((*temp)->left->height, 0);
	}

	else {
		(*temp)->height = 1 + max((*temp)->left->height, (*temp)->right->height);
	};

	return true;
};

int AVL::balanceFactor(Node** ptrToNode) {
	int leftHeight = (*ptrToNode && (*ptrToNode)->left) ? (*ptrToNode)->left->height : 0;
	int rightHeight = (*ptrToNode && (**ptrToNode).right) ? (**ptrToNode).right->height : 0;

	return leftHeight - rightHeight;
};


Node* AVL::rightRotate(Node**) {

};

Node* AVL::leftRotate(Node**) {

};

Node* AVL::leftRightRotate(Node**) {

};

Node* AVL::rightLeftRotate(Node**) {

};