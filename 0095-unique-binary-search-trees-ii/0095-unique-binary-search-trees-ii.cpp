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

    vector<TreeNode*> recr(int size, int s, int e){
        if(size == 0) return {NULL};
        if(size == 1){
            TreeNode* t = new TreeNode(s);
            return {t};
        }

        vector<TreeNode*> ans;

        for(int i = s;i<=e;i++){
            vector<TreeNode*> l = recr(i-s,s,i-1);
            vector<TreeNode*> r = recr(e-i,i+1,e);
            for(int j = 0;j<l.size();j++){
                for(int k=0;k<r.size();k++){
                    TreeNode* t = new TreeNode(i);
                    t->left = l[j];
                    t->right = r[k];
                    ans.push_back(t);
                }
            }
        }



        return ans;



    }

    vector<TreeNode*> generateTrees(int n) {
        return recr(n,1,n);
    }
};