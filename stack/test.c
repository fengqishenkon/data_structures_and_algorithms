#define _CRT_SECURE_NO_WARNINGS 
#include"stack.h"

void test01()
{
	ST st;
	StackInit(&st);

	/*StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);*/

	/*StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);*/
	/*STDataType value = StackTop(&st);
	printf("%d", value);*/
	/*int size=StackSize(&st);
	printf("%d", size);*/
	StackDestroy(&st);
}
bool isValid(char* s)
{
    ST st;
    StackInit(&st);
    char* pi = s;
    while (*pi != '\n')
    {
        if (*pi == '(' || *pi == '[' || *pi == '{')
        {
            StackPush(&st, *pi);
        }
        else
        {
            STDataType value = StackTop(&st);
            if (*pi == ')' && value == '('
                || *pi == ']' && value == '['
                || *pi == '}' && value == '{')
            {
                StackPop(&st);
            }
            else
            {
                return false;
            }
        }
        pi++;
    }
    return true;
    StackDestroy(&st);
}

int main()
{
	//test01();
    char arr[] = '()';
    isValid(arr);
	return 0;
}
