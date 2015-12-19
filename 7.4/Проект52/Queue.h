#pragma once

struct QueueElement
{
	char value;
	QueueElement *next;
};

struct Queue
{
	QueueElement *first;
	QueueElement *last;
};

QueueElement *makeElementofQ(char value, QueueElement *next);

Queue *createQueue();

void addQueue(char value, Queue *queue);

char deleteQueueEl(Queue *queue);

char lookQueue(Queue *queue);

bool queueEmpty(Queue *queue);

void deleteQueue(Queue *queue);