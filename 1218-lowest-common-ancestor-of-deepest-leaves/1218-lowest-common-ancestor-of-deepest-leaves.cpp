/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int recr(TreeNode* root){
        if(root == NULL) return 0;
        return 1+max(recr(root->left), recr(root->right));
    }

    TreeNode* dfs(TreeNode* root,int max, int len){
        if(root == NULL )return NULL;
        if(max-1 == len) return root;
        TreeNode* left = dfs(root->left,max,len+1);
        TreeNode* right = dfs(root->right,max,len+1); 

        if(right && left) return root;
        return left ? left : right; 
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int max = recr(root);
        return dfs(root,max,0);
    }


};