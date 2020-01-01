#include "Queue.h"
#include <iostream>

Queue::Queue(void)
{
	front = NULL;
	rear = NULL;
}


Queue::~Queue(void)
{
	while (front != NULL) {
		queuexy *next_node = front->next;
		delete front;
		front = next_node;
	}
}

void Queue::enqueue(queuexy& node)
{
	queuexy *temp = new queuexy;
	temp->row = node.row;
	temp->col = node.col;
	temp->next = NULL;

	if(front == NULL) {
		front = temp;
		rear = temp;
	} else {
		rear->next = temp;
		rear = temp;
	}
}

void Queue::dequeue(queuexy& node)
{
	if (front == NULL)
		return;

	node.row = front->row;
	node.col = front->col;

	queuexy *temp = front;
	front = front->next;
	delete temp;

	if (front == NULL)
		rear = NULL;
}

queuexy* Queue::peek()
{
	return front;
}

