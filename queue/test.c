#define _CRT_SECURE_NO_WARNINGS 
#include"queue.h"
void test01()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);

	/*QueuePop(&q);
	QueuePop(&q);*/
	/*QDataType a = QueueFront(&q);
	printf("%d", a);
	QDataType b=QueueBack(&q);
	printf("%d", b);*/
	/*int size=QueueSize(&q);
	printf("%d", size);*/
	QueueDestroy(&q);
}
int main()
{
	test01();
	return 0;
}