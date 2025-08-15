#define _CRT_SECURE_NO_WARNINGS 
#include"Heap.h"

//��ʼ����
void HPInit(HP* php)
{
	php->arr = NULL;
	php->capacity = php->size = 0;
}

//���ٶ�
void HPDestroy(HP* php)
{
	free(php->arr);
	php->arr = NULL;
	php->capacity = php->size = 0;
}

//����
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//���ϵ����㷨
void AdjustUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		//arr[child] > arr[parent]�������Ǵ���ѡ�
		//arr[child] < arr[parent]��������С���ѡ�
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
		}
		child = parent;
		parent = (child - 1) / 2;
	}
}

//���µ����㷨
void AdjustDown(HPDataType* arr, int parent, int n)
{
	int child = parent * 2 + 1;//����
	while (child < n)
	{
		//��ѣ�<
		//С�ѣ�>		
		if (child+1<n && arr[child] < arr[child + 1])
		{
			child++;
		}
		//��ѣ�>
		//С��: <
		if (arr[child] > arr[parent])
		{
			//����
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


//���
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
	//�洢x
	php->arr[php->size] = x;

	//���ϵ���x
	AdjustUp(php->arr,php->size);

	php->size++;
}

//��ӡ
void HPPrint(HP* php)
{
	int i = 0;
	for (i = 0; i < php->size; i++)
	{
		printf("%d ", php->arr[i]);
	}
	printf("\n");
}

//�п�
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}


//����
//�ڶѽṹ�ɾ��������ֻ�ܲ����Ѷ���
void HPPop(HP* php)
{
	assert(!HPEmpty(php));
	//ֻ�����Ѷ�
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;

	//������Ѷ������µ�����
	AdjustDown(php->arr, 0, php->size);
}

//ȡ�Ѷ�����
HPDataType HPTop(HP* php)
{
	assert(!HPEmpty(php));
	return php->arr[0];
}

//��size
int HPSize(HP* php)
{
	assert(php);
	return php->size;
}