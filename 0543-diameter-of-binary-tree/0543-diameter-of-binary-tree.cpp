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

    int recr(TreeNode* root,int& ans){
        if(!root) return 0;
        int l = recr(root->left,ans);
        int r = recr(root->right,ans);
        ans = max(ans,l+r);
        return 1+max(l,r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        recr(root,ans);
        return ans;
    }
};