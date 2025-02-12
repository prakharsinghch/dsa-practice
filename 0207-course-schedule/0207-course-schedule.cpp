class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        if( prerequisites.size() == 0) return true;
        vector<int> vis(n,0);
        unordered_map<int,vector<int>> mp;
        for(auto x: prerequisites){
            mp[x[1]].push_back(x[0]);
        }
        queue<int> q;
        q.push(prerequisites[0][1]);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int x = q.front();
                q.pop();
                vis[x] = 1;
                for(auto y: mp[x]){
                    q.push(y);
                    if(vis[y] == 1) return false;
                }
            }
        }

        for(auto x: vis) if(x == 0) return false;

        return true;
    }
};