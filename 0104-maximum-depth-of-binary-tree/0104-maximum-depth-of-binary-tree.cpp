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
    int maxDepth(TreeNode* root) {
        int ans = 0 ;
        if(root == NULL) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto x = q.front();
                q.pop();
                ans = max(ans,x.second);
                if(x.first->left) q.push({x.first->left,x.second+1});
                if(x.first->right) q.push({x.first->right,x.second+1});
            }
        }

        return ans;
    }
};