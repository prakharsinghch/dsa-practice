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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        map<int,map<int,vector<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        while(!q.empty()){
            int s = q.size();
            int c = 0;
            vector<int> res;
            for(int i=0;i<s;i++){
                TreeNode* n = q.front().first;
                c = q.front().second.first;
                int p = q.front().second.second;
                q.pop();
                res.push_back(n->val);
                if(n->left) q.push({n->left,{c+1,p-1}});
                if(n->right) q.push({n->right,{c+1,p+1}});
            }
            if(c%2 == 0) ans.push_back(res);
            else{
                reverse(res.begin(),res.end());
                ans.push_back(res);
            }
        }

        return ans;
    }
};