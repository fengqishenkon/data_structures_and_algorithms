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

////堆排序
////时间复杂度 O(n*logn)
//void HeapSort(int* arr,int n)
//{
//	//向下调整算法建堆  
//	//时间复杂度O(n)
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		int parent = i;
//		AdjustDown(arr, parent, n);
//	}
//
//	//向上调整算法建堆
//	//时间复杂度O(n*logn)
//	for (int i = 0; i < n ; i++)
//	{
//		AdjustUp(arr, i);
//	}
//
//	//堆排序
//	//通过堆顶来找到最大数据
//	//通过向下调整算法来再次调整堆，使之有序。
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
//时间复杂度 O(k+(n-k)logk)
void TopK()
{
	int k = 0;
	printf("请输入k:");
	scanf("%d", &k);
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");

	if (fout == NULL)
	{
		perror("fopen fail!");
		exit(1);
	}

	//找最大的前k个数据  建小堆
	//文件前k个数据组成堆结构
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

	//调整
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minHeap, i, k);
	}

	//遍历剩下的n-k个数据与堆顶比较，堆顶小则替换堆顶元素
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
	 //造数据
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

