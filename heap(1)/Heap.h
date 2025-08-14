#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//堆的结构

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* arr;
	int size;//有效数据个数
	int capacity;//空间大小
}HP;

//堆结构的初始化
void HPInit(HP* php);

//销毁堆
void HPDestroy(HP* php);

//入堆
void HPPush(HP* php, HPDataType x);

//打印
void HPPrint(HP* php);

//向上调整算法
void AdjustUp(HPDataType* arr, int child);

//向下调整算法
void AdjustDown(HPDataType* arr, int parent, int n);
//交换
void Swap(int* x, int* y);

//出堆
void HPPop(HP* php);

//判空
bool HPEmpty(HP* php);