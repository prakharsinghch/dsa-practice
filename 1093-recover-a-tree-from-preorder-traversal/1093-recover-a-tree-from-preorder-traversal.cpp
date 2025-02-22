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
    int i = 0;
    TreeNode* recr(string traversal, int dep){
        if(i>=traversal.size()){
            return NULL;
        }
        int d = 0;
        while(traversal[i] == '-'){
            i++;
            d++;
        }

        if(d < dep) {
            i-=d;
            return NULL;
        }

        string num = "";
        while('0'<= traversal[i] && traversal[i]<='9'){
            num+=traversal[i];
            i++;
        }
        int n = stoi(num);
        TreeNode* root = new TreeNode(n);
        root->left = recr(traversal,dep+1);
        root->right = recr(traversal,dep+1);
        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        return recr(traversal,0);
    }
};