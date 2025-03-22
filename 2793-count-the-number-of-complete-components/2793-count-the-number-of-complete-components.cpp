class Solution {
public:

    void bfs(int node, vector<int>& vis, vector<int>& comp, unordered_map<int,vector<int>>& mp){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            comp.push_back(x);
            for(auto y: mp[x]){
                if(vis[y]==0){
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        unordered_map<int,vector<int>> mp;
        for(auto x: edges){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            bool val = true;
            if(vis[i]==0){
                vector<int> comp;
                vis[i] = 1;
                bfs(i,vis,comp,mp);
                for(auto x: comp){
                    if(mp[x].size() != comp.size()-1){
                        val = false;
                        break;
                    }
                }
                if(val) ans++;
            }
        }

        return ans;
    }
};