#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
//定义链式结构的二叉树
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* leftchild;
	struct BinaryTreeNode* rightchild;
}BTNode;
//前序遍历 根左右
void preorder(BTNode* root);
//中序遍历 左根右
void inorder(BTNode* root);
//后序遍历 左右根
void postorder(BTNode* root);


// ⼆叉树结点个数
int BinaryTreeSize(BTNode* root);
//int BinaryTreeSize(BTNode* root,int* psize);


// ⼆叉树叶⼦结点个数
int BinaryTreeLeafSize(BTNode* root);

// ⼆叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode* root, int k);

//⼆叉树的深度/⾼度
int BinaryTreeDepth(BTNode* root);

// ⼆叉树查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ⼆叉树销毁
void BinaryTreeDestory(BTNode** root);

//层序遍历
void leverOrder(BTNode* root);
