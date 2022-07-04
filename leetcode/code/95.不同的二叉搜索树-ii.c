/*
 * @lc app=leetcode.cn id=95 lang=c
 *
 * [95] 不同的二叉搜索树 II
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //二叉搜索树中序遍历从小到大，
// base and length
struct TreeNode ** search(int*returnSize, int base, int n){
    //if(n==0) return NULL;
    if(n==0)
    {   
        *returnSize=1;
        struct TreeNode** ret = malloc(sizeof(struct TreeNode*));
        ret[0] = NULL;
        return ret;
    }
    struct TreeNode**result= malloc(sizeof(struct TreeNode*));
    
    int i,j,k;
    *returnSize = 0;
    for(i=1;i<=n;i++){
        int left=0,right=0;
        //应该是递归回来的时候一次赋值
        struct TreeNode**left_trees = search(&left,base,i-1);
        struct TreeNode**right_trees = search(&right,i+base,n-i);
        //result = realloc(result,sizeof(struct TreeNode*)*left*right);
        for(j=0;j<left;j++){
            for(k=0;k<right;k++){
                struct TreeNode *root=malloc(sizeof(struct TreeNode));
                root->val = i+base;
                root->left = left_trees[j];
                root->right = right_trees[k];
                result=realloc(result,sizeof(struct TreeNode *)*((*returnSize)+1));
                result[(*returnSize)++] = root;
            }
        }
    }
    return result;
}

struct TreeNode** generateTrees(int n, int* returnSize){
    printf("%d",n);
    *returnSize =0 ;
    struct TreeNode**result = search(returnSize,0,n);
    return result;
}
// @lc code=end

