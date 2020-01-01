#pragma once

typedef struct queuexy{
	int row;
	int col;
	queuexy *next;
} queuexy;

class Queue
{
private:
	queuexy *front;
	queuexy *rear;

public:
	Queue();
	~Queue();

	void enqueue(queuexy& node);
	void dequeue(queuexy& node);
	queuexy *peek();
};

