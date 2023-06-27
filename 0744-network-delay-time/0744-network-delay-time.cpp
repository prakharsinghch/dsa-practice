class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if(times.size()<n-1)return -1;
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,1e9);
        dist[k-1]=0;
        vector<vector<int>>adj[n];
        for(int i=0;i<times.size();i++){
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int w=times[i][2];
            vector<int>vec;
            vec.push_back(v);
            vec.push_back(w);
            adj[u].push_back(vec);
        }
        pq.push({0,k-1});
        vis[k-1]=1;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            vis[node]=1;
            pq.pop();
            for(auto it:adj[node]){
                int edw=it[1];
                int adjNode=it[0];
                if(d+edw<dist[adjNode]){
                    dist[adjNode]=d+edw;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int res=dist[0];
        for(int i=0;i<n;i++){
            res=max(res,dist[i]);
            if(!vis[i])return -1;
        }
        return res;
    }
};