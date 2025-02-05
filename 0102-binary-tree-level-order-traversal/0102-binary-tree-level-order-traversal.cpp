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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>>q;
        if(root == NULL) return ans;
        q.push({root,0});

        while(!q.empty()){
            int s = q.size();
            vector<int> x;
            for(int i=0;i<s;i++){
               auto p = q.front();
               q.pop();
               x.push_back(p.first->val);
               if(p.first->left) q.push({p.first->left,p.second+1});
               if(p.first->right) q.push({p.first->right,p.second+1});
            }
            ans.push_back(x);
        }

        return ans;

    }
};