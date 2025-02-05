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
    int widthOfBinaryTree(TreeNode* root) {
        map<int, vector<int>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,1}});
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto x = q.front();
                int y = x.second.first;
                long long z = x.second.second;
                q.pop();
                mp[x.second.first].push_back(z);
                if(x.first->left) q.push({x.first->left,{x.second.first+1,2*z+1}});
                if(x.first->right) q.push({x.first->right,{x.second.first+1,2*z+2}}); 
            }
        }
        int ans=INT_MIN;
        for(auto x: mp){
           ans = max( x.second[x.second.size()-1] - x.second[0] + 1, ans);
        }
        return ans;
    }
};