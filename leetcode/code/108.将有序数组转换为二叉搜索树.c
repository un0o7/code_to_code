/*
 * @lc app=leetcode.cn id=108 lang=c
 *
 * [108] 将有序数组转换为二叉搜索树
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


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize==0)return NULL;
    int in = numsSize / 2 +1 ;

    struct TreeNode* root =(struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->val = nums[in-1];
    root->left = sortedArrayToBST(nums,in-1);
    root->right = sortedArrayToBST(&nums[in],numsSize - in);
    return root;

}
// @lc code=end

