#define _CRT_SECURE_NO_WARNINGS 
#include"Heap.h"
void test01()
{
	HP hp;
	HPInit(&hp);
	HPPush(&hp, 70);
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
	HPPrint(&hp);

	
	//HPDestroy(&hp);
}

int main()
{
	test01();
	return 0;
}
