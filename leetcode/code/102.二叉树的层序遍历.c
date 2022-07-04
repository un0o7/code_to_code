/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层序遍历
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 // 层次遍历的方法，非递归，使用队列
 // 遍历根，然后左子树和右子树入队，然后出队，直到队列为空
 // 最多2000个节点，那么队列最大长度为1000
#define MAX_QUEUE_LEN 10000
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(!root){
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode*queue[MAX_QUEUE_LEN] = {0};
    int **ret=NULL;
    int pre_rear;
    int i=0,j=0;
    int front=0,rear=0;
    struct TreeNode* p;
    queue[rear++] = root;
    int*returncolumns=NULL;
    *returnSize = 0;
    while(front<rear){ //每层
        pre_rear = rear;
        ret= realloc(ret, sizeof(int*)*(i+1));
        ret[i] = calloc(pre_rear-front, sizeof(int));
        returncolumns = realloc(returncolumns, sizeof(int)*(i+1));
        returncolumns[i] = pre_rear-front;
        // 遍历该层的每一个节点
        for(j=0;j<returncolumns[i];j++){
            p = queue[front++];
            ret[i][j] = p->val;
            if(p->left) {
                queue[rear++] = p->left;
            }
            if(p->right) {   
                queue[rear++] = p->right;   
            }
        }

        i++;

    }
    *returnSize = i;
    *returnColumnSizes = returncolumns;
    return ret;
}
// @lc code=end

