/*
 * @lc app=leetcode.cn id=106 lang=c
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if(inorderSize == 0) return NULL;
    struct TreeNode * root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int no = postorder[postorderSize-1];
    root->val = no;
    int left_len = 0;
    for(int i = 0; i < inorderSize; i++){
        if(inorder[i] == no){
            left_len = i;
            break;
        }
    }
    int right_len = inorderSize - left_len - 1;
    root->left = buildTree(inorder,left_len,postorder,left_len);
    root->right = buildTree(&inorder[left_len+1],right_len,&postorder[left_len],right_len);
    return root;
}
// @lc code=end

