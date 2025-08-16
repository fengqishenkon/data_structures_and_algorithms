#define _CRT_SECURE_NO_WARNINGS 
#include"Heap.h"
void test01()
{
	HP hp;
	HPInit(&hp);
	HPPush(&hp, 70);
	int a=HPSize(&hp);
	printf("%d", a);
	/*HPPush(&hp, 70);
	HPPush(&hp, 30);
	HPPush(&hp, 56);
	HPPush(&hp, 25);
	HPPush(&hp, 15);
	HPPush(&hp, 10);
	HPPush(&hp, 5);
	HPPrint(&hp);

	HPPop(&hp);
	HPPrint(&hp);

	HPPop(&hp);
	HPPrint(&hp);

	HPPop(&hp);
	HPPrint(&hp);

	HPPop(&hp);
	HPPrint(&hp);

	HPPop(&hp);
	HPPrint(&hp);

	HPPop(&hp);
	HPPrint(&hp);

	HPPop(&hp);
	HPPrint(&hp);*/

	
	//HPDestroy(&hp);
}

////������
////ʱ�临�Ӷ� O(n*logn)
//void HeapSort(int* arr,int n)
//{
//	//���µ����㷨����  
//	//ʱ�临�Ӷ�O(n)
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		int parent = i;
//		AdjustDown(arr, parent, n);
//	}
//
//	//���ϵ����㷨����
//	//ʱ�临�Ӷ�O(n*logn)
//	for (int i = 0; i < n ; i++)
//	{
//		AdjustUp(arr, i);
//	}
//
//	//������
//	//ͨ���Ѷ����ҵ��������
//	//ͨ�����µ����㷨���ٴε����ѣ�ʹ֮����
//	int end = n - 1;
//	while (end>0)
//	{
//		Swap(&arr[0], &arr[end]);
//		AdjustDown(arr, 0, end);
//		end--;
//	}
//
//}
//
//void arrprint(int* arr, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//


//topk
//ʱ�临�Ӷ� O(k+(n-k)logk)
void TopK()
{
	int k = 0;
	printf("������k:");
	scanf("%d", &k);
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");

	if (fout == NULL)
	{
		perror("fopen fail!");
		exit(1);
	}

	//������ǰk������  ��С��
	//�ļ�ǰk��������ɶѽṹ
	HPDataType* minHeap = (HPDataType*)malloc(sizeof(HPDataType) * k);
	if (minHeap == NULL)
	{
		perror("malloc fail!");
		exit(2);
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}

	//����
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minHeap, i, k);
	}

	//����ʣ�µ�n-k��������Ѷ��Ƚϣ��Ѷ�С���滻�Ѷ�Ԫ��
	int x = 0;
	while (fscanf(fout, "%d", &x)!=EOF)
	{
		if (x > minHeap[0])
		{
			minHeap[0] = x;
			AdjustDown(minHeap, 0, k);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}
	fclose(fout);
}
void CreateNDate()
{
	 //������
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		int x = (rand() + i) % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

int main()
{
	CreateNDate();
	TopK();
	return 0;
}

//
//
//int main()
//{
//	test01();
//	/*int arr[6] = { 19,15,20,17,13,10 };
//	int n = 6;
//	arrprint(arr, n);
//
//
//	HeapSort(arr,n);
//	arrprint(arr, n);*/
//	return 0;
//}

