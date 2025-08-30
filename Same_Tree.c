#define _CRT_SECURE_NO_WARNINGS 

//same tree

//https://leetcode.cn/problems/same-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //都为空返回true
    if (p == NULL && q == NULL)
    {
        return true;
    }

    //有一个为空
    if (p == NULL || q == NULL)
    {
        return false;
    }

    //都不为空
    if (p->val != q->val)
    {
        return false;
    }
    //比较下一个结点

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}

