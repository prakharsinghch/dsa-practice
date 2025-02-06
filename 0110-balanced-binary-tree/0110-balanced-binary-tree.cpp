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
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        recr(root, ans);
        return ans;
    }

    int recr(TreeNode* root, bool& ans){
        if(root == NULL || ans == false) return 0;
        int l = recr(root->left,ans);
        int r =  recr(root->right,ans);

        if(abs(l-r) > 1) ans =false;

        return 1+max(l,r);
    }
};