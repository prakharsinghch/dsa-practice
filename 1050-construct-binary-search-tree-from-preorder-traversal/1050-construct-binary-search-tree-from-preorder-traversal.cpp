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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]);
        s.push(root);
        for(int i=1;i<preorder.size();i++){
            TreeNode* n = new TreeNode(preorder[i]);
            if(s.top()->val > n->val){
                s.top()->left = n;
                s.push(n);
            }
            else{
                TreeNode* prev = new TreeNode();
                while(!s.empty() && s.top()->val<n->val){
                    prev = s.top();
                    s.pop();
                }
                prev->right = n;
                s.push(n);
            }
        }

        return root;
    }
};