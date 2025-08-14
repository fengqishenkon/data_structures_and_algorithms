#define _CRT_SECURE_NO_WARNINGS 
#include"queue.h"
//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//入队——队尾
void QueuePush(Queue* pq, QDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	//队列为空
	if (pq->phead ==NULL)
	{
		pq->phead = pq->ptail = newnode;

	}
	else//队列不为空
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}


//队列判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//出队——队头
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	//只有一个结点，phead和ptail都置为空
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QueueNode* prue = pq->phead;
		pq->phead = pq->phead->next;
		free(prue);
		prue = NULL;
	}
	pq->size--;

}

//队列有效元素个数
int QueueSize(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->size;
}

//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->phead->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->ptail->data;
}




////销毁队列
//void QueueDestroy(Queue* pq)
//{
//	QueueNode* pcur = pq->phead;
//	while (pcur)
//	{
//		QueueNode* next = pcur->next;
//		free(pcur);
//		pcur = next;
//	}
//	pq->phead = pq->ptail = NULL;
//	pq->size = 0;

//}
