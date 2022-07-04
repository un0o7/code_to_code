/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
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
bool isMirror(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL)
        return true;
    if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
        return false;
    if(p->val != q->val) return false;
    //左子树是否一样
    return isMirror(p->left, q->right) && isMirror(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
    if(!root) return true;
    return isMirror(root->left, root->right);
}
// @lc code=end

