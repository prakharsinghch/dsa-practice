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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int d;
        int ans = 0;
        while(!q.empty()){
            ans++;
         
                auto x =  q.front().first;
                d = q.front().second;
                q.pop();
                if(x->left == NULL && x->right == NULL) return d;
                if(x->left) q.push({x->left, d+1});
                if(x->right) q.push({x->right,d+1});

            
        }

        return 0;
    }
};