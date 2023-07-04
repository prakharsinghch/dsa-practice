/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp){
        vector<Node*> n;
        Node* ans = new Node(node->val);
        mp[node] = ans;
        for(auto x: node->neighbors){
            if(mp.find(x) != mp.end()){
                n.push_back(mp[x]);
            }
            else n.push_back(dfs(x,mp));
        }
        ans->neighbors = n;
        return ans;

    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        if(node == NULL) return NULL;
        if(node->neighbors.size() == 0){
            Node* ans = new Node(node->val);
            return ans;
        }

        return dfs(node,mp);
    }
};