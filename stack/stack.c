#define _CRT_SECURE_NO_WARNINGS 
#include"stack.h"
//初始化栈
void StackInit(ST* ps)
{
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}


//入栈---栈顶
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		//增容
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* tmp =(STDataType*)realloc(ps->arr, newCapacity*sizeof(STDataType));//realloc函数开辟一个空间，要是ps后面空闲的空间足够，
		                                                                          //返回的地址tmp就是ps的地址，要是ps后面的空闲空间不
																				 //够就返回一个新地址，并且把原有的数据拷贝到新地址上
		if (tmp == NULL)
		{
			printf("realloc fail!");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
	ps->arr[ps->top++] = x;
}

//判断栈是否为空
bool StackEmpty(ST* ps)
{
	return ps->top == 0;
}

//出栈——栈顶
void StackPop(ST* ps)
{
	assert(!StackEmpty(ps));
	ps->top--;
}

//取栈顶元素
STDataType StackTop(ST* ps)
{
	assert(!StackEmpty(ps));
	return ps->arr[ps->top - 1];
}

//获取栈中有效元素个数
int StackSize(ST* ps)
{
	return ps->top;
}

//销毁
void StackDestroy(ST* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}