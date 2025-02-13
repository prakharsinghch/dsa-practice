class Solution {
public:

    bool bfs(int i, vector<vector<int>>& graph, vector<int>& vis){
        queue<int> q;
        vis[i] = -1;
        q.push(i);

        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(auto y: graph[x]){
                if(vis[y] == 0){
                    vis[y]= vis[x] == -1? 1:-1;
                    q.push(y);
                }
                if(vis[y] != 0 && vis[y] == vis[x]) return false;
            }
        }

        return true;
        
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                if(!bfs(i,graph,vis)) return false;
            }
        }

        return true;

    }
};