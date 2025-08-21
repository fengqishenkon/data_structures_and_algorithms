#define _CRT_SECURE_NO_WARNINGS 
#include"tree.h"
//前序遍历 根左右
void preorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	preorder(root->leftchild);
	preorder(root->rightchild);
}

//中序遍历 左根右
void inorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	inorder(root->leftchild);
	printf("%c ",root->data);
	inorder(root->rightchild);
}


//后序遍历 左右根
void postorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	postorder(root->leftchild);
	postorder(root->rightchild);
	printf("%c ", root->data);
}

//⼆叉树结点个数
//二叉树结点个数 = 根节点个数 + 左孩子结点个数 + 右孩子节点个数
//在此处根节点个数可以确定为1，然后右孩子节点个数 = 根节点个数 + 左孩子结点个数 + 右孩子节点个数，以此类推
//所以可以递归解决这个问题
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + BinaryTreeSize(root->leftchild) + BinaryTreeSize(root->rightchild);
}


// ⼆叉树叶⼦结点个数
// ⼆叉树叶⼦结点个数 = 左孩子结点叶子节点个数+右孩子叶子节点个数。
//要是根节点就是叶子结点就返回1。
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->leftchild == NULL && root->rightchild == NULL)
	{
		return 1;
	}

	return  BinaryTreeLeafSize(root->leftchild) + BinaryTreeLeafSize(root->rightchild);
}


// ⼆叉树第k层结点个数
//⼆叉树第k层结点个数 = 左孩子k层结点个数 + 右孩子k层结点个数。
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->leftchild, k - 1) + BinaryTreeLevelKSize(root->rightchild, k - 1);

}


//⼆叉树的深度/⾼度
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftdepth = BinaryTreeDepth(root->leftchild);
	int rightdepth = BinaryTreeDepth(root->rightchild);
	return 1 + (leftdepth > rightdepth ? leftdepth : rightdepth);
}




