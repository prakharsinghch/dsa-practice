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

    TreeNode* recr(vector<int>& preorder,int preStart,int preEnd, vector<int>& inorder,int inStart, int inEnd, unordered_map<int,int>&mp){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);

        int r = mp[root->val];
        int l = r - inStart;

        root->left = recr(preorder,preStart+1,preStart+l,inorder,inStart,r-1,mp);
        root->right = recr(preorder,preStart+l+1,preEnd,inorder,r+1,inEnd,mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int i=0;
        for(int i =0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }

        TreeNode* ans = recr(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return ans;


    }
};