#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include "tree.h"

typedef struct BinaryTreeNode*  QDataType;	
//���н��ṹ
typedef struct QueueNode
{
	QDataType data; 
	struct QueueNode* next;
}QueueNode;

//���нṹ
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	int size;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);

//���ٶ���
void QueueDestroy(Queue* pq);

//��ӡ�����β
void QueuePush(Queue* pq, QDataType x);

//���ӡ�����ͷ
void QueuePop(Queue* pq);

//�����п�
bool QueueEmpty(Queue* pq);

//������ЧԪ�ظ���
int QueueSize(Queue* pq);

//ȡ��ͷ����
QDataType QueueFront(Queue* pq);

//ȡ��β����
QDataType QueueBack(Queue* pq);

