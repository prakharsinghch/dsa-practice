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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        queue<pair<TreeNode*,int>> q;
        int curr = -1;
        q.push({root,0});
        vector<int> ans;
        while(!q.empty()){
            auto x =q.front();
            q.pop();
            int l = x.second;
            if(curr< l){
                curr = l;
                ans.push_back(x.first->val);
            }
            if(x.first->right) q.push({x.first->right,l+1});
            if(x.first->left) q.push({x.first->left,l+1});
            
        }

        return ans;
    }
};