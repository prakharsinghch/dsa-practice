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
    int recr(TreeNode* root,int& mx){
        if(root == NULL) return 0;
        int l = max(0,recr(root->left,mx));
        int r = max(0,recr(root->right,mx));
        mx = max(mx,l+r+root->val);

        return max(l,r) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        recr(root,mx);
        return mx;
    }
};