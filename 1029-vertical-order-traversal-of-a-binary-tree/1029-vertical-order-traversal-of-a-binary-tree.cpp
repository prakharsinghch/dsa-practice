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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,priority_queue<int,vector<int>,greater<int>>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
        
                TreeNode* n = q.front().first;
                auto p = q.front().second;
                q.pop();
                mp[p.first][p.second].push(n->val);
                if(n->left) q.push({n->left, {p.first-1,p.second+1}});
                if(n->right) q.push({n->right, {p.first+1,p.second+1}});
            
        }

        for(auto x: mp){
            vector<int> z;
            for(auto y: x.second){
                while(!y.second.empty()){
                    z.push_back(y.second.top());
                    y.second.pop();
                }
            }
            ans.push_back(z);
        }

        return ans;

    }
};