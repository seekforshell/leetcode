/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct stack_res {
    int top;
    int *res;
}ST_RES;

void nodeTravel(struct TreeNode* root, ST_RES *res) {
    
    if (root == NULL) return;
    
    if (root->left != NULL) {
        nodeTravel(root->left, res);
    }
    
    res->res[res->top++] = root->val; 
    
    if (root->right != NULL) {
        nodeTravel(root->right, res);
    }
        
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    ST_RES *st_res = (ST_RES *)malloc(sizeof(ST_RES));
    st_res->res = (int *)malloc(1024*sizeof(int));
    st_res->top = 0;
    
    nodeTravel(root, st_res);
    
    *returnSize = st_res->top;
    return st_res->res;
}

