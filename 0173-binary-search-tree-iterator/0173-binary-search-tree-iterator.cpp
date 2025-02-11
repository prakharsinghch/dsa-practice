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
class BSTIterator {
public:

    priority_queue<int,vector<int>,greater<int>> pq;
    void recr(TreeNode* root){
        if(root == NULL) return;
        recr(root->left);
        pq.push(root->val);
        recr(root->right);
    }
    BSTIterator(TreeNode* root) {
        recr(root);
    }
    
    int next() {
        int x = pq.top();
        pq.pop();
        return x;        
    }
    
    bool hasNext() {
        return pq.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */