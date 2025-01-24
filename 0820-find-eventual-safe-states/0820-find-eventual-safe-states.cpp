class Solution {
public:

    bool dfs(int i, vector<vector<int>>& graph, vector<int>& vis, vector<int>& inStack){
        if(inStack[i]) return true;
        if(vis[i]) return false;

        vis[i] = 1;
        inStack[i] = 1;
        for(auto x:graph[i]){
            if(dfs(x,graph,vis,inStack)) return true;
        }
        inStack[i] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0), inStack(n,0);
        for(int i=0;i<n;i++){
            dfs(i,graph,vis,inStack);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(inStack[i] == 0) ans.push_back(i); 
        }

        return ans;
    }
};