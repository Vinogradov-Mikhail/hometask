#include "Queue.h"

QueueElement *makeElementofQ(char value, QueueElement *next)
{
	QueueElement *newQueueElement = new QueueElement;
	newQueueElement->value = value;
	newQueueElement->next = next;
	return newQueueElement;
}

Queue *createQueue()
{
	Queue *newQueue = new Queue;
	newQueue->last = makeElementofQ(0, nullptr);
	newQueue->first = makeElementofQ(0, newQueue->last);
	return newQueue;
}

void addQueue(char value, Queue *queue)
{
	QueueElement *temp = queue->first;
	while (temp->next != queue->last)
	{
		temp = temp->next;
	}
	QueueElement *newQueueElement = makeElementofQ(value, queue->last);
	temp->next = newQueueElement;
}

char deleteQueueEl(Queue *queue)
{
	char result = queue->first->next->value;
	QueueElement *queueElement = queue->first->next;
	queue->first->next = queue->first->next->next;
	delete queueElement;
	return result;
}

char lookQueue(Queue *queue)
{
	return queue->first->next->value;
}

bool queueEmpty(Queue *queue)
{
	return queue->first->next == queue->last;
}

void deleteQueue(Queue *queue)
{
	while (!queueEmpty(queue))
		deleteQueueEl(queue);
	delete queue->first;
	delete queue->last;
	delete queue;
}


