#include <iostream>
#include "AVL_Trees.hpp"

int main() {
    // Create an AVL tree
    AVL tree;

    int arr[6] = { 10, 20, 30, 40, 50, 25 };

    // Test Insertions
    for (int i = 0; i < 6; i++) {
        Node* node = new Node[sizeof(Node)];

        if (node == nullptr) {
            return -1;
        };

        node->key = arr[i];

        tree.insert(&node);
    };

    std::cout << "Tree after insertions:\n";
    tree.printTree(); // Custom function to print the tree in some readable format

    // Test Deletion
    std::cout << "\nDeleting node 30 from AVL tree...\n";

    tree.deleteNode(nullptr, 30);

    std::cout << "Tree after deletion:\n";
    tree.printTree();

    // Test Search
    std::cout << "\nSearching for node with key 40...\n";
    Node* searchResult = tree.search(40);
    if (searchResult) {
        std::cout << "Node found: " << searchResult->key << "\n";
    }
    else {
        std::cout << "Node with key 40 not found.\n";
    }

    // Test FindMin and FindMax
    std::cout << "\nFinding minimum and maximum nodes in the AVL tree...\n";
    Node* minNode = tree.findMin();
    Node* maxNode = tree.findMax();

    if (minNode) {
        std::cout << "Minimum key: " << minNode->key << "\n";
    }
    else {
        std::cout << "Tree is empty; no minimum key.\n";
    }

    if (maxNode) {
        std::cout << "Maximum key: " << maxNode->key << "\n";
    }
    else {
        std::cout << "Tree is empty; no maximum key.\n";
    }

    return 0;
}
