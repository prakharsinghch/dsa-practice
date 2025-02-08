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

    TreeNode* recr(int l,int r, vector<int>& nums){
        if(l>r) return NULL;

        int m = l+(r-l)/2;
        TreeNode* root = new TreeNode(nums[m]);

        root->left = recr(l,m-1,nums);
        root->right = recr(m+1,r,nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recr(0,nums.size()-1,nums);
    }
};