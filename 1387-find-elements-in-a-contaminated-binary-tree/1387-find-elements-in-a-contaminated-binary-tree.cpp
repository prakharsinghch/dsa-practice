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
class FindElements {
public:

    set<int> s;

    void recr(TreeNode* root){
        if(root == NULL) return;
        if(root->left) {
            root->left->val = 2*root->val +1;
            s.insert(root->left->val);
        }
        if(root->right){
            root->right->val = 2*root->val+2;
            s.insert(root->right->val);
        } 
        recr(root->left);
        recr(root->right);
    }

    FindElements(TreeNode* root) {
        if(root != NULL){
            root->val = 0;
            s.insert(root->val);
            recr(root);
        } 
    }
    
    bool find(int target) {
        return s.find(target) != s.end(); 
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */