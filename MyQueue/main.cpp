#include "myQueue.h"

int main()
{
	myQueue *mq;
	mq = new myQueue(2, 5);
	mq->push(10);
	mq->push(13);
	mq->back();
	mq->front();
	mq->pop();
	mq->pop();
	mq->pop();
	mq->pop();
	mq->pop();
	mq->pop();
	mq->pop();
	mq->isEmpty();
	return 0;
}