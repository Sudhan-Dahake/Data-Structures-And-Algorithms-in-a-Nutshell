#include <iostream>
#include "SinglyLinkedList.hpp"

int main(void) {
    // Create a new List object
    List myList;

    // Test Insertions
    std::cout << "Inserting at the front: 10, 20, 30" << std::endl;
    myList.insertFront(10);
    myList.insertFront(20);
    myList.insertFront(30);
    myList.display();

    std::cout << "\nInserting at the back: 40, 50" << std::endl;
    myList.insertBack(40);
    myList.insertBack(50);
    myList.display();

    std::cout << "\nInserting at position 2: 25" << std::endl;
    myList.insert(2, 25);  // Insert 25 at index 2 (0-based)
    myList.display();

    // Test Removals
    std::cout << "\nRemoving from the front:" << std::endl;
    myList.removeFront();
    myList.display();

    std::cout << "\nRemoving from the back:" << std::endl;
    myList.removeBack();
    myList.display();

    std::cout << "\nRemoving element 25:" << std::endl;
    myList.removeByValue(25);  // Remove element with value 25
    myList.display();

    // Test Selection
    std::cout << "\nSelecting element at index 2:" << std::endl;
    std::cout << "Element at index 2: " << myList.select(2) << std::endl;

    // Test Replacement
    std::cout << "\nReplacing element at index 1 with 100:" << std::endl;
    if (myList.replace(1, 100)) {
        std::cout << "Replacement successful." << std::endl;
    }
    else {
        std::cout << "Replacement failed." << std::endl;
    }
    myList.display();

    // Test Size
    std::cout << "\nSize of the list: " << myList.listSize() << std::endl;

    // Edge Cases
    std::cout << "\nAttempting to remove from an empty list:" << std::endl;
    while (myList.listSize() > 0) {
        myList.removeFront();
    }
    myList.display();

    if (!myList.removeFront()) {
        std::cout << "List is empty, no element to remove." << std::endl;
    }

    std::cout << "\nFinal State of the List:" << std::endl;
    myList.display();
	
	return 0;
};