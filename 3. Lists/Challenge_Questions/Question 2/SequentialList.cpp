#include <iostream>

typedef char DataItem;

class SequentialList {
	DataItem* head = nullptr;
	unsigned int capacity;
	unsigned int size;

public:
	SequentialList(unsigned int capacity) {
		this->capacity = capacity;
		this->size = 0;

		this->head = new DataItem[sizeof(DataItem) * this->capacity];

		memset(this->head, 0, (sizeof(DataItem) * this->capacity));
	}

	void insert(DataItem value, int index) {
		if ((this->capacity == 0) || (this->capacity == this->size) || (index > this->size)) {
			return;
		}

		DataItem* temp = this->head;

		for (int i = 0; i < index; i++) {
			temp = temp++;
		}

		DataItem* leftShiftTemp = this->head + (sizeof(DataItem) * this->size);

		while (leftShiftTemp != temp) {
			*leftShiftTemp = *(leftShiftTemp - sizeof(DataItem));

			leftShiftTemp = leftShiftTemp - sizeof(DataItem);
		}

		*temp = value;


		this->size++;
	}


	void insert_back(DataItem value) {
		if (this->size == this->capacity) {
			return;
		}

		DataItem* temp = this->head + (sizeof(DataItem) * this->size);

		*temp = value;

		this->size++;
	}


	void delete_front() {
		if (this->size == 0) {
			return;
		}

		DataItem* temp = this->head;

		for (int i = 0; i < (this->size - 1); i++) {
			*temp = *(temp + sizeof(DataItem));

			temp++;
		}


		this->size--;
	};


	void delete_back() {
		if (this->size == 0) {
			return;
		}

		this->size--;
	}


	void print() {
		DataItem* temp = this->head;

		for (int i = 0; i < this->size; i++) {
			std::cout << *temp << std::endl;

			temp = temp++;
		}
	}
};


int main(void) {
	SequentialList ll(3);

	ll.insert('a', 0);
	ll.insert('b', 1);
	ll.insert('c', 0);
	ll.insert_back('d');

	ll.delete_front();
	ll.delete_back();

	ll.insert('d', 1);

	ll.print();

	return 0;
}