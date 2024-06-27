#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

class CircularQueue {
	friend class CircularQueueTest;

public:
	// Can be seen outside as CircularQueue::QueueItem
	typedef int QueueItem;

	// Used as an indicator of empty queue.
	static const QueueItem EMPTY_QUEUE = -1;

	
	CircularQueue();

	CircularQueue(unsigned int capacity);

	~CircularQueue();


	bool enqueue(QueueItem value);

	QueueItem dequeue();

	QueueItem peek() const;


	bool empty() const;

	bool full() const;

	unsigned int size() const;

	void print() const;



private:
	// Override copy constructor and assignment operator in private so we can't use them
	CircularQueue(const CircularQueue& other) {};

	CircularQueue operator=(const CircularQueue& other) {};



private:
	QueueItem* items_;

	unsigned int head_;

	unsigned int tail_;

	unsigned int capacity_;

	unsigned int size_;
};

#endif // CIRCULAR_QUEUE_HPP
