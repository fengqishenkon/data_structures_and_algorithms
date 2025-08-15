#define _CRT_SECURE_NO_WARNINGS 
#include"Heap.h"

//初始化堆
void HPInit(HP* php)
{
	php->arr = NULL;
	php->capacity = php->size = 0;
}

//销毁堆
void HPDestroy(HP* php)
{
	free(php->arr);
	php->arr = NULL;
	php->capacity = php->size = 0;
}

//交换
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整算法
void AdjustUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		//arr[child] > arr[parent]调整，是大根堆。
		//arr[child] < arr[parent]调整，是小根堆。
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
		}
		child = parent;
		parent = (child - 1) / 2;
	}
}

//向下调整算法
void AdjustDown(HPDataType* arr, int parent, int n)
{
	int child = parent * 2 + 1;//左孩子
	while (child < n)
	{
		//大堆：<
		//小堆：>		
		if (child+1<n && arr[child] < arr[child + 1])
		{
			child++;
		}
		//大堆：>
		//小堆: <
		if (arr[child] > arr[parent])
		{
			//调整
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else 
		{
			break;
		}
		
	}
}


//入堆
void HPPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->arr, newcapacity*sizeof(HPDataType));
		if (tmp == NULL)
		{
			printf("realloc fail!");
			exit(1);
		}
		php->arr = tmp;
		php->capacity = newcapacity;
	}
	//存储x
	php->arr[php->size] = x;

	//向上调整x
	AdjustUp(php->arr,php->size);

	php->size++;
}

//打印
void HPPrint(HP* php)
{
	int i = 0;
	for (i = 0; i < php->size; i++)
	{
		printf("%d ", php->arr[i]);
	}
	printf("\n");
}

//判空
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}


//出堆
//在堆结构里，删除操作，只能操作堆顶。
void HPPop(HP* php)
{
	assert(!HPEmpty(php));
	//只操作堆顶
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;

	//操作完堆顶后，向下调整。
	AdjustDown(php->arr, 0, php->size);
}

//取堆顶数据
HPDataType HPTop(HP* php)
{
	assert(!HPEmpty(php));
	return php->arr[0];
}

//求size
int HPSize(HP* php)
{
	assert(php);
	return php->size;
}