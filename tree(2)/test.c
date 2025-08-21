#define _CRT_SECURE_NO_WARNINGS 
#include"tree.h"
BTNode* buyNode(char x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (malloc == NULL)
	{
		printf("malloc fail!");
		exit(1);
	}
	node->data = x;
	node->leftchild = node->rightchild = NULL;
	return node;
}


BTNode* CreateBinaryTree()
{
	BTNode* nodeA = buyNode('A');//这一块地方为什么要定义  结构体指针类型的变量，可不可以直接定义  结构体类型的变量不行吗
	BTNode* nodeB = buyNode('B');
	BTNode* nodeC = buyNode('C');
	BTNode* nodeD = buyNode('D');
	BTNode* nodeE = buyNode('E');
	BTNode* nodeF = buyNode('F');
	nodeA->leftchild = nodeB;
	nodeA->rightchild = nodeC;

	nodeB->leftchild = nodeD;

	nodeC->leftchild = nodeE;
	nodeC->rightchild = nodeF;
	return nodeA;
}


void test01()
{
	BTNode* root=CreateBinaryTree(); 
	//preorder(root);
	//inorder(root);
	//postorder(root);
	/*int a=BinaryTreeSize(root);
	printf("%d ", a);*/
	/*int a=BinaryTreeLeafSize(root);
	printf("%d ", a); */
	/*int a=BinaryTreeLevelKSize(root,2);
	printf("%d\n", a);*/
	printf("depth: %d", BinaryTreeDepth(root));
}

int main()
{
	test01();
	return 0;
}

