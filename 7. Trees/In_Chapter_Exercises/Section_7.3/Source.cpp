#include <iostream>
#include "Binary_Search_Tree.hpp"

int main(void) {
	BST bst;

	int arr[9] = { 10, 5, 20, 1, 7, 30, 9, 25, 8 };

	for (int i = 0; i < 9; i++) {
		Node* node = new Node[sizeof(Node)];

		if (node == nullptr) {
			return -1;
		};

		node->key = arr[i];

		bst.insert(&node);
	};


	Node* node5 = new Node[sizeof(Node)];

	node5->key = 10;

	bst.insert(&node5);


	std::cout << "Min Value: " << bst.findMin()->key << std::endl;
	std::cout << "Max Value: " << bst.findMax()->key << std::endl;

	std::cout << "Value at right of 20: " << bst.search(20)->rightChild->key << std::endl << std::endl << std::endl;





	std::cout << "Original Binary Tree Structure: " << std::endl << std::endl;

	bst.printTree();




	std::cout << std::endl << std::endl << std::endl;


	std::cout << "Deleting the node with value 10: " << std::endl << std::endl;

	Node* node = new Node[sizeof(Node)];

	node->key = 10;

	bst.deleteNode(&node);

	bst.printTree();



	std::cout << std::endl << std::endl << std::endl;



	std::cout << "Deleting the node with value 20: " << std::endl << std::endl;

	Node* node2 = new Node[sizeof(Node)];

	node2->key = 20;

	bst.deleteNode(&node2);

	bst.printTree();




	return 0;
};