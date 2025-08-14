#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//�ѵĽṹ

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* arr;
	int size;//��Ч���ݸ���
	int capacity;//�ռ��С
}HP;

//�ѽṹ�ĳ�ʼ��
void HPInit(HP* php);

//���ٶ�
void HPDestroy(HP* php);

//���
void HPPush(HP* php, HPDataType x);

//��ӡ
void HPPrint(HP* php);

//���ϵ����㷨
void AdjustUp(HPDataType* arr, int child);

//���µ����㷨
void AdjustDown(HPDataType* arr, int parent, int n);
//����
void Swap(int* x, int* y);

//����
void HPPop(HP* php);

//�п�
bool HPEmpty(HP* php);