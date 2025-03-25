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
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int h = 1;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto x = q.front();
                q.pop();
                if(ans.size() < h){
                    ans.push_back(x->val);
                }
                if(x->right)q.push(x->right);
                if(x->left) q.push(x->left);
            }
            h++;
        }

        return ans;
    }
};