#include <iostream>
#include "DoublyLinkedList.hpp"

int main(void) {
	DoublyLinkedList ll;

	ll.insert('a', 0);
	ll.insert('b', 1);
	ll.insert('c', 0);
	ll.insert_back('d');

	ll.remove_front();
	ll.remove_back();

	ll.insert('d', 1);

	ll.print();

	return 0;
};