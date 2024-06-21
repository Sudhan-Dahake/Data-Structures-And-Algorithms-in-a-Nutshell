#include <iostream>

typedef char DataItem;

class SequentialList {
	DataItem* head = nullptr;
	unsigned int capacity;
	unsigned int size;

public:
	SequentialList(unsigned int capacity) {
		if (capacity < 3) {
			capacity = 3;
		}

		this->capacity = capacity;
		this->size = 0;

		this->head = new DataItem[sizeof(DataItem) * this->capacity];

		memset(this->head, 0, (sizeof(DataItem) * this->capacity));
	}

	void insert(DataItem value, int index) {
		if ((this->capacity == 0) || (index > this->size)) {
			return;
		}

		else if (this->capacity == this->size) {
			resize_Increase();
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
			resize_Increase();
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


		if (((float)(this->size)) < ((float)(this->capacity) / 3.0)) {
			resize_decrease();
		}
	};


	void delete_back() {
		if (this->size == 0) {
			return;
		}

		this->size--;

		if ((float)this->size < ((1 / 3) * (float)this->capacity)) {
			resize_decrease();
		}
	}


	void resize_Increase() {
		DataItem* newListPtr = new DataItem[sizeof(DataItem) * (2 * this->capacity)];

		memset(newListPtr, 0, (sizeof(DataItem) * (2 * this->capacity)));

		DataItem* temp = newListPtr;

		DataItem* tempOriginalList = this->head;

		for (int i = 0; i < this->size; i++) {
			*temp = *tempOriginalList;

			temp++;
			tempOriginalList++;
		}

		temp = nullptr;

		tempOriginalList = this->head;

		this->head = newListPtr;

		this->capacity = 2 * this->capacity;

		delete tempOriginalList;

		tempOriginalList = nullptr;
	}


	void resize_decrease() {
		DataItem* newListTemp = new DataItem[(unsigned int)(0.5 * this->capacity)];

		memset(newListTemp, 0, ((unsigned int)(0.5 * this->capacity)));

		DataItem* temp = newListTemp;

		DataItem* oldListTemp = this->head;

		for (int i = 0; i < this->size; i++) {
			*temp = *oldListTemp;

			oldListTemp++;
			temp++;
		}

		oldListTemp = this->head;

		temp = nullptr;

		this->head = newListTemp;

		this->capacity = (unsigned int)(0.5 * this->capacity);

		delete oldListTemp;

		oldListTemp = nullptr;
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
	SequentialList ll(1);

	ll.insert('a', 0);
	ll.insert('b', 1);
	ll.insert('c', 0);
	ll.insert_back('d');

	ll.delete_front();
	ll.delete_back();
	ll.delete_front();
	ll.delete_back();

	ll.insert('e', 0);

	ll.print();

	return 0;
}