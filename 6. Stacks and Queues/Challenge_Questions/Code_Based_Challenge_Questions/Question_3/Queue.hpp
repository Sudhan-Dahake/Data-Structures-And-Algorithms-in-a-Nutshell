#ifndef QUEUE_HPP
#define QUEUE_HPP

typedef int QueueItem;

class CircularQueue {
	QueueItem* head;

	QueueItem* iFront;
	QueueItem* iRear;

	int size;
	int capacity;

	int iFrontIndex;
	int iRearIndex;

public:
	CircularQueue(int capacity);

	CircularQueue(QueueItem* circularQueue, int capacity);

	~CircularQueue();

	bool Enqueue(QueueItem item);

	QueueItem Dequeue();

	QueueItem peek();

	void print();
};

#endif	// QUEUE_HPP