class Solution {
public:

    bool dfs(int i, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& path){
        vis[i] = true;
        path[i] = true;
        for(auto x : graph[i]){
            if(vis[x] == false && dfs(x,graph,vis,path) ) return true;
            else if(path[x]) return true;
        }

        path[i] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n,false);
        vector<bool> path(n,false);

        for(int i=0;i<n;i++){
            if(vis[i] == false) dfs(i,graph,vis, path);
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(path[i] == false) ans.push_back(i);
        }

        return ans;

    }   
};