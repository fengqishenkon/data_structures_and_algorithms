#define _CRT_SECURE_NO_WARNINGS 
#include"queue.h"
//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//��ӡ�����β
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
	//����Ϊ��
	if (pq->phead ==NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else//���в�Ϊ��
	{
		pq->ptail->next = newnode;
		pq->ptail = pq->ptail->next;
	}
	pq->size++;
}


//�����п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//���ӡ�����ͷ
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	//ֻ��һ����㣬phead��ptail����Ϊ��
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}

//������ЧԪ�ظ���
int QueueSize(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->size;
}

//ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->phead->data;
}

//ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->ptail->data;
}


//���ٶ���
void QueueDestroy(Queue* pq)
{
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}