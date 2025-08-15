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

int main()
{
	test01();
	/*int arr[6] = { 19,15,20,17,13,10 };
	int n = 6;
	arrprint(arr, n);


	HeapSort(arr,n);
	arrprint(arr, n);*/
	return 0;
}

